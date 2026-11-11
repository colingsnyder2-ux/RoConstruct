// from server: 100% by EspClaude
// roc 2007-08 007252d5  unit: CXTIconHandle  size: 181 bytes
// roc-flags: /O1 /GS- /MD
// ATL atlthunk.cpp __InitializeThunkPool (VS2005 ATL 8.0 copy); body follows the shipped ATL 9.0 source.
typedef int BOOL;
typedef void VOID;
typedef void* PVOID;
typedef void* HANDLE;
typedef char CHAR, *PCHAR;
typedef unsigned long DWORD;
typedef long LONG;
typedef struct HINSTANCE__ *HMODULE;
typedef int (__stdcall *FARPROC)();
typedef struct _SINGLE_LIST_ENTRY { struct _SINGLE_LIST_ENTRY *Next; } SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY;
typedef union _SLIST_HEADER {
    unsigned __int64 Alignment;
    struct { SINGLE_LIST_ENTRY Next; unsigned short Depth; unsigned short Sequence; };
} SLIST_HEADER, *PSLIST_HEADER;
#define NULL 0
#define TRUE 1
#define FALSE 0
extern "C" {
__declspec(dllimport) BOOL __stdcall IsProcessorFeaturePresent(DWORD);
__declspec(dllimport) HMODULE __stdcall LoadLibraryA(const char*);
__declspec(dllimport) FARPROC __stdcall GetProcAddress(HMODULE, const char*);
__declspec(dllimport) HANDLE __stdcall GetProcessHeap(void);
__declspec(dllimport) PVOID __stdcall HeapAlloc(HANDLE, DWORD, unsigned long);
__declspec(dllimport) BOOL __stdcall HeapFree(HANDLE, DWORD, PVOID);
__declspec(dllimport) LONG __stdcall InterlockedCompareExchange(LONG volatile*, LONG, LONG);
unsigned long __readfsdword(unsigned long);
}

typedef PSINGLE_LIST_ENTRY (__stdcall *PINTERLOCKED_PUSH_ENTRY_SLIST)(PSLIST_HEADER, PSINGLE_LIST_ENTRY);
typedef PSINGLE_LIST_ENTRY (__stdcall *PINTERLOCKED_POP_ENTRY_SLIST)(PSLIST_HEADER);

PSLIST_HEADER __AtlThunkPool = NULL;
PINTERLOCKED_PUSH_ENTRY_SLIST __AtlInterlockedPushEntrySList = NULL;
PINTERLOCKED_POP_ENTRY_SLIST  __AtlInterlockedPopEntrySList = NULL;

#define PEB_POINTER_OFFSET 0x34

BOOL __declspec(noinline) __InitializeThunkPool(VOID)
{
    PSLIST_HEADER *atlThunkPoolPtr;
    PSLIST_HEADER atlThunkPool;
    HMODULE kernel32Module;
    BOOL result;

    result = IsProcessorFeaturePresent(12);
    if (result == FALSE) {
        __AtlThunkPool = (PSLIST_HEADER)1;
        return TRUE;
    }
    kernel32Module = LoadLibraryA("kernel32.dll");
    if (kernel32Module != NULL) {
        __AtlInterlockedPushEntrySList = (PINTERLOCKED_PUSH_ENTRY_SLIST)
            GetProcAddress(kernel32Module, "InterlockedPushEntrySList");
        __AtlInterlockedPopEntrySList = (PINTERLOCKED_POP_ENTRY_SLIST)
            GetProcAddress(kernel32Module, "InterlockedPopEntrySList");
    }
    if (__AtlInterlockedPushEntrySList == NULL ||
        __AtlInterlockedPopEntrySList == NULL) {
        return FALSE;
    }
    atlThunkPoolPtr = (PSLIST_HEADER *)((PCHAR)(*(PVOID*)((PCHAR)__readfsdword(0x18) + 0x30)) + PEB_POINTER_OFFSET);
    atlThunkPool = *atlThunkPoolPtr;
    if (atlThunkPool == NULL) {
        atlThunkPool = (PSLIST_HEADER)HeapAlloc(GetProcessHeap(), 0, sizeof(SLIST_HEADER));
        if (atlThunkPool == NULL) {
            return FALSE;
        }
        atlThunkPool->Alignment = 0;
        if ((PVOID)InterlockedCompareExchange((LONG volatile *)atlThunkPoolPtr, (LONG)atlThunkPool, (LONG)NULL) != NULL) {
            HeapFree(GetProcessHeap(), 0, atlThunkPool);
        }
        atlThunkPool = *atlThunkPoolPtr;
    }
    __AtlThunkPool = atlThunkPool;
    return TRUE;
}
