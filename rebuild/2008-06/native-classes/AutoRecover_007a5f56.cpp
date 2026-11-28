// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>
#include <intrin.h>

// INFERRED: ATL thunk pool init (atlthunk.obj, _InitThunkPool).
extern "C" void* g_0097f308;
extern "C" FARPROC g_0097f30c;
extern "C" FARPROC g_0097f310;

extern "C" BOOL fn_007a5f56(void)
{
    if (IsProcessorFeaturePresent(12) == FALSE)
    {
        g_0097f308 = (void*)1;
        return TRUE;
    }

    HMODULE hKernel = LoadLibraryA("kernel32.dll");
    if (hKernel != NULL)
    {
        g_0097f30c = GetProcAddress(hKernel, "InterlockedPushEntrySList");
        g_0097f310 = GetProcAddress(hKernel, "InterlockedPopEntrySList");
    }

    if (g_0097f30c == NULL || g_0097f310 == NULL)
        return FALSE;

    // INFERRED: &NtCurrentTeb()->ProcessEnvironmentBlock->AtlThunkSListPtr32
    void* volatile* pHeader = (void* volatile*)(*(char**)((char*)__readfsdword(0x18) + 0x30) + 0x34);
    void* pool = *pHeader;
    if (pool == NULL)
    {
        LONG* block = (LONG*)HeapAlloc(GetProcessHeap(), 0, 8);
        if (block == NULL)
            return FALSE;
        block[0] = 0;
        block[1] = 0;
        if (InterlockedCompareExchange((volatile LONG*)pHeader, (LONG)block, 0) != 0)
            HeapFree(GetProcessHeap(), 0, block);
        pool = *pHeader;
    }
    g_0097f308 = pool;
    return TRUE;
}
