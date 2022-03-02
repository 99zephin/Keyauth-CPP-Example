#include "keyauth.h"
#include "print.h"
#include "xor.h"
#include "util.h"
#include "protection.h"

/*
CREDITS :
ShadowMonster99 -> Anti DLL Injection
Чихуахуа -> Hide Thread
*/

int main()
{
	int option;
	std::string key;

	std::string randomstr = randomString(6);
	std::rename(path().c_str(), randomstr.c_str());

	SetConsoleTitleA("Loader");
	print::set_warning(xor ("\n\n  [*] Connecting..."));

	//BLOCK ALL DLL INJECTIONS (MOST) :
	/*
	if (Capture::HookLdrInitializeThunk())
		print::set_ok(xor ("\n\n  [+] Hook -> Success"));
	else
		print::set_error(xor ("\n\n  [+] Hook -> Failure"));

	std::promise<void>().get_future().wait();

	*/

	//Hide Thread Useful for debuggers etc.
	//__forceinline bool HideThread(HANDLE hThread);

	KeyAuthApp.init();
	if (!KeyAuthApp.data.success)
	{
		print::set_error(xor ("\n\n [-] Initialization Failure : "));
		std::cout << KeyAuthApp.data.message;
		Sleep(2000);
		exit(0);
	}

	print::set_warning(xor ("\n  [*] Enter license: "));
	std::cin >> key;
	KeyAuthApp.license(key);

	if (!KeyAuthApp.data.success)
	{
		print::set_error(xor ("\n\n [-] Authentication Failure : "));
		std::cout << KeyAuthApp.data.message;
		Sleep(2000);
		exit(0);
	}
	
	//run all your code functions here

	print::set_ok(xor ("\n\n [+] Program Execution Finished : Closing in 10 seconds"));
	Sleep(10000);
	exit(0);
}

std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}
