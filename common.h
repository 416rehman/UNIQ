#pragma once
// debug only print

namespace common
{
	enum class PayloadOperation
	{
		GenericReadMemory,
		GenericWriteMemory,
		RequestBaseAddress
	};

	typedef struct _PAYLOAD
	{
		ULONG pid = 0;
		UINT_PTR targetAddress = 0;
		PayloadOperation operation = PayloadOperation::GenericReadMemory;
		void* output = NULL;
		ULONGLONG outputSize = 0;
		void* input = NULL;
		ULONGLONG inputSize = 0;
	} PAYLOAD;

	inline LPCSTR hookedLibrary = "win32u.dll";
	inline LPCSTR hookedModuleName = "\\SystemRoot\\System32\\drivers\\dxgkrnl.sys";
	inline LPCSTR hookedRoutineName = "NtOpenCompositionSurfaceSectionInfo";
	inline ULONG memoryTag = 'UNIQ';
	inline const char* targetProcessModuleName = "Notepad.exe";
}
