#pragma once
#include <string>
#include <Windows.h>
#include "auth.hpp"

using namespace KeyAuth;

inline std::string name = "";
inline std::string ownerid = "";
inline std::string secret = "";
inline std::string version = "1.0";
inline std::string url = "https://keyauth.win/api/1.1/";
inline std::string sslPin = "ssl pin key (optional)";

std::string tm_to_readable_time(tm ctx);
inline static std::time_t string_to_timet(std::string timestamp);
inline static std::tm timet_to_tm(time_t timestamp);

inline api KeyAuthApp(name, ownerid, secret, version, url, sslPin);
