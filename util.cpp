#include "util.h"

void downloadFile(std::string keyauthID, std::string fileOutput) // Example : downloadFile(175182, "C://file.exe"
{
	std::vector<std::uint8_t> bytes = KeyAuthApp.download(keyauthID);
	std::ofstream file(fileOutput, std::ios_base::out | std::ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();
}

const std::string randomString(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

const std::string path()
{
	char path1[_MAX_PATH];
	GetModuleFileNameA(NULL, path1, _MAX_PATH);
	return std::string(path1);
}