#pragma once
#include "keyauth.h"
#include <random>
#include <filesystem>

void downloadFile(std::string keyauthID, std::string fileOutput);
const std::string randomString(size_t length);
const std::string path();