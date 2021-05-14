#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <shlobj.h>

#pragma region Proxy
#define FUNCTION_COUNT 17

extern "C" uintptr_t functions[FUNCTION_COUNT] = { 0 };
std::string functionNames[] =
{
	"GetFileVersionInfoA",
	"GetFileVersionInfoByHandle",
	"GetFileVersionInfoExA",
	"GetFileVersionInfoExW",
	"GetFileVersionInfoSizeA",
	"GetFileVersionInfoSizeExA",
	"GetFileVersionInfoSizeExW",
	"GetFileVersionInfoSizeW",
	"GetFileVersionInfoW",
	"VerFindFileA",
	"VerFindFileW",
	"VerInstallFileA",
	"VerInstallFileW",
	"VerLanguageNameA",
	"VerLanguageNameW",
	"VerQueryValueA",
	"VerQueryValueW"
};

// [index: 000] [ordinal: 001] GetFileVersionInfoA
#pragma comment(linker, "/EXPORT:GetFileVersionInfoA=func_fe4c7fdb42a74533b75718c1a0d72a32,@1")
extern "C" void func_fe4c7fdb42a74533b75718c1a0d72a32();

// [index: 001] [ordinal: 002] GetFileVersionInfoByHandle
#pragma comment(linker, "/EXPORT:GetFileVersionInfoByHandle=func_78e5d8c052c4411ead75ffc003aa15c2,@2")
extern "C" void func_78e5d8c052c4411ead75ffc003aa15c2();

// [index: 002] [ordinal: 003] GetFileVersionInfoExA
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExA=func_7db5a5a62d3840cc90b54aa102d2bcea,@3")
extern "C" void func_7db5a5a62d3840cc90b54aa102d2bcea();

// [index: 003] [ordinal: 004] GetFileVersionInfoExW
#pragma comment(linker, "/EXPORT:GetFileVersionInfoExW=func_d358f83b33cb4691a579fce03067ae51,@4")
extern "C" void func_d358f83b33cb4691a579fce03067ae51();

// [index: 004] [ordinal: 005] GetFileVersionInfoSizeA
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeA=func_9f825301df494579abfc09f03f3c54d7,@5")
extern "C" void func_9f825301df494579abfc09f03f3c54d7();

// [index: 005] [ordinal: 006] GetFileVersionInfoSizeExA
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExA=func_d2be5693a866477d88eb95b38bcc43bc,@6")
extern "C" void func_d2be5693a866477d88eb95b38bcc43bc();

// [index: 006] [ordinal: 007] GetFileVersionInfoSizeExW
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeExW=func_afd0da792aec4d07bea827125e0ac78f,@7")
extern "C" void func_afd0da792aec4d07bea827125e0ac78f();

// [index: 007] [ordinal: 008] GetFileVersionInfoSizeW
#pragma comment(linker, "/EXPORT:GetFileVersionInfoSizeW=func_71105ab8658e4b6db0b52a07968b528b,@8")
extern "C" void func_71105ab8658e4b6db0b52a07968b528b();

// [index: 008] [ordinal: 009] GetFileVersionInfoW
#pragma comment(linker, "/EXPORT:GetFileVersionInfoW=func_342c1a6a00aa4d46b83df34943550a9e,@9")
extern "C" void func_342c1a6a00aa4d46b83df34943550a9e();

// [index: 009] [ordinal: 010] VerFindFileA
#pragma comment(linker, "/EXPORT:VerFindFileA=func_072a04327c64486c8425c21254736100,@10")
extern "C" void func_072a04327c64486c8425c21254736100();

// [index: 010] [ordinal: 011] VerFindFileW
#pragma comment(linker, "/EXPORT:VerFindFileW=func_b48fcd678a404a7c968d9022fbdac04b,@11")
extern "C" void func_b48fcd678a404a7c968d9022fbdac04b();

// [index: 011] [ordinal: 012] VerInstallFileA
#pragma comment(linker, "/EXPORT:VerInstallFileA=func_c173057a0e1f4deca76facd39bd3a41b,@12")
extern "C" void func_c173057a0e1f4deca76facd39bd3a41b();

// [index: 012] [ordinal: 013] VerInstallFileW
#pragma comment(linker, "/EXPORT:VerInstallFileW=func_a14eafed955447c48f67df119f1d3fcb,@13")
extern "C" void func_a14eafed955447c48f67df119f1d3fcb();

// [index: 013] [ordinal: 014] VerLanguageNameA
#pragma comment(linker, "/EXPORT:VerLanguageNameA=func_9523acace69b47adaad7bd5c6e9e46c9,@14")
extern "C" void func_9523acace69b47adaad7bd5c6e9e46c9();

// [index: 014] [ordinal: 015] VerLanguageNameW
#pragma comment(linker, "/EXPORT:VerLanguageNameW=func_df1cf354a542489cbee049bc15fb16f1,@15")
extern "C" void func_df1cf354a542489cbee049bc15fb16f1();

// [index: 015] [ordinal: 016] VerQueryValueA
#pragma comment(linker, "/EXPORT:VerQueryValueA=func_61afd6e9c83741bb9378beb2d8117e29,@16")
extern "C" void func_61afd6e9c83741bb9378beb2d8117e29();

// [index: 016] [ordinal: 017] VerQueryValueW
#pragma comment(linker, "/EXPORT:VerQueryValueW=func_78983027b5ce46ff863ec460565f99c8,@17")
extern "C" void func_78983027b5ce46ff863ec460565f99c8();
#pragma endregion

std::wstring GetDesktopPath()
{
	wchar_t path[MAX_PATH + 1];
	if (SHGetSpecialFolderPath(HWND_DESKTOP, path, CSIDL_DESKTOP, FALSE))
	{
		return path;
	}
	else
	{
		return std::wstring();
	}
}

BOOL WINAPI DllMain(HINSTANCE hinstModule, DWORD dwReason, LPVOID lpvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hinstModule);

		wchar_t buffer[MAX_PATH];
		auto len = GetSystemDirectory(buffer, MAX_PATH);
		std::wstring originalModulePath(buffer, len);
		auto moduleHandle = LoadLibrary(originalModulePath.append(L"\\version.dll").c_str());
		if (moduleHandle != nullptr)
		{
			for (auto i = 0; i < FUNCTION_COUNT; i++)
			{
				auto address = GetProcAddress(moduleHandle, functionNames[i].c_str());
				functions[i] = reinterpret_cast<uintptr_t>(address);
			}
		}

		auto desktopPath = GetDesktopPath();
		if (!desktopPath.empty() && std::filesystem::exists(desktopPath))
		{
			std::filesystem::remove(desktopPath.append(L"\\Arad.lnk"));
		}

		return TRUE;
	}
	else
	{
		return TRUE;
	}
}
