
#pragma once

#include "pch.h"
#include <vector>
#include <windows.h>
#include <TlHelp32.h>

//https://guidedhacking.com

DWORD GetProcId(const wchar_t* procName);

uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName);
