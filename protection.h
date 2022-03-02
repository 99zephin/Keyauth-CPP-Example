#pragma once
#include "keyauth.h"
#include "xor.h"

#include <iostream>
#include <Psapi.h>
#include <TlHelp32.h>

#include <chrono>
#include <future>

#pragma comment(lib, "psapi.lib")

typedef NTSTATUS(WINAPI* lpQueryInfo)(HANDLE, LONG, PVOID, ULONG, PULONG);

namespace Capture
{
	PVOID DetourFunc(BYTE* src, const BYTE* dst, const int len);
	void Thread();
	BOOL HookLdrInitializeThunk();
}

__forceinline bool HideThread(HANDLE hThread);