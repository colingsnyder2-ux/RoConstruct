// from server: 69% by EspClaude
// roc-flags: /O1 /EHsc /MD
// from server: 60% by colin
// roc 2007-08 0072538a  unit: CXTIconHandle  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0072538a
//
// 0072538a  ff742404             push dword ptr [esp + 4]
// 0072538e  e81cffffff           call 0x7252af
// 00725393  59                   pop ecx
// 00725394  c20400               ret 4
// 00725397  833db4988c0000       cmp dword ptr [0x8c98b4], 0
// 0072539e  56                   push esi
// 0072539f  7509                 jne 0x7253aa
// 007253a1  e82fffffff           call 0x7252d5
// 007253a6  85c0                 test eax, eax
// 007253a8  7443                 je 0x7253ed
// 007253aa  a1b4988c00           mov eax, dword ptr [0x8c98b4]
// 007253af  83f801               cmp eax, 1
// 007253b2  7517                 jne 0x7253cb
// 007253b4  6a0d                 push 0xd
// 007253b6  6a00                 push 0
// 007253b8  ff15b0d27700         call dword ptr [0x77d2b0]
// 007253be  50                   push eax
// 007253bf  ff15a8d27700         call dword ptr [0x77d2a8]
// 007253c5  85c0                 test eax, eax
// 007253c7  7424                 je 0x7253ed
// 007253c9  5e                   pop esi
// 007253ca  c3                   ret 
// 007253cb  50                   push eax
// 007253cc  ff15bc988c00         call dword ptr [0x8c98bc]
// 007253d2  85c0                 test eax, eax
// 007253d4  755f                 jne 0x725435
// 007253d6  6a40                 push 0x40
// 007253d8  b800100000           mov eax, 0x1000
// 007253dd  50                   push eax
// 007253de  50                   push eax
// 007253df  6a00                 push 0
// 007253e1  ff15c4d17700         call dword ptr [0x77d1c4]
// 007253e7  8bf0                 mov esi, eax
// 007253e9  85f6                 test esi, esi
// 007253eb  7504                 jne 0x7253f1
// 007253ed  33c0                 xor eax, eax
// 007253ef  5e                   pop esi
// 007253f0  c3                   ret 
// 007253f1  8b06                 mov eax, dword ptr [esi]
// 007253f3  57                   push edi
// 007253f4  ff35b4988c00         push dword ptr [0x8c98b4]
// 007253fa  ff15bc988c00         call dword ptr [0x8c98bc]
// 00725400  8bf8                 mov edi, eax
// 00725402  85ff                 test edi, edi
// 00725404  7412                 je 0x725418
// 00725406  6800800000           push 0x8000
// 0072540b  6a00                 push 0
// 0072540d  56                   push esi
// 0072540e  ff15c0d17700         call dword ptr [0x77d1c0]
// 00725414  8bc7                 mov eax, edi
// 00725416  eb1c                 jmp 0x725434
// 00725418  8dbef00f0000         lea edi, [esi + 0xff0]
// 0072541e  56                   push esi
// 0072541f  ff35b4988c00         push dword ptr [0x8c98b4]
// 00725425  ff15b8988c00         call dword ptr [0x8c98b8]
// 0072542b  83c610               add esi, 0x10
// 0072542e  3bf7                 cmp esi, edi
// 00725430  72ec                 jb 0x72541e
// 00725432  8bc6                 mov eax, esi
// 00725434  5f                   pop edi
// 00725435  5e                   pop esi
// 00725436  c3                   ret 

// NOTE: target range covers two functions: 0x72538a (stdcall 1-arg wrapper
// around cdecl 0x7252af, ret 4) and 0x725397 (thunk allocator below).

extern "C" {
    __declspec(dllimport) void* __stdcall GetProcessHeap(void);
    __declspec(dllimport) void* __stdcall HeapAlloc(void*, unsigned long, unsigned long);
    __declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned long, unsigned long, unsigned long);
    __declspec(dllimport) int __stdcall VirtualFree(void*, unsigned long, unsigned long);
}

struct SListEntry { SListEntry *Next; };

// 16-byte pool entries (add esi,0x10; last = page + 0xff0)
struct ThunkEntry
{
    SListEntry entry;
    unsigned char thunk[12];
};

typedef SListEntry *(__stdcall *PopFn)(void *);
typedef SListEntry *(__stdcall *PushFn)(void *, SListEntry *);

extern "C" void *g_ThunkPool;          // 0x8c98b4 (1 = use heap)
extern "C" PushFn g_PushEntrySList;    // 0x8c98b8
extern "C" PopFn g_PopEntrySList;      // 0x8c98bc
extern "C" int __cdecl InitializeThunkPool(void);  // 0x7252d5

extern "C" void *__cdecl AllocStdCallThunk_cmn(void)
{
    ThunkEntry *lastThunkEntry;
    ThunkEntry *thunkEntry;
    ThunkEntry *thunkPage;

    if (g_ThunkPool == 0)
    {
        if (InitializeThunkPool() == 0)
        {
            goto ThunkAllocFailed;
        }
    }
    if (g_ThunkPool == (void *)1)
    {
        thunkEntry = (ThunkEntry *)HeapAlloc(GetProcessHeap(), 0, 0xd);
        if (thunkEntry == 0)
        {
            goto ThunkAllocFailed;
        }
        return thunkEntry;
    }

    thunkEntry = (ThunkEntry *)g_PopEntrySList(g_ThunkPool);
    if (thunkEntry != 0)
    {
        return thunkEntry;
    }

    thunkPage = (ThunkEntry *)VirtualAlloc(0, 0x1000, 0x1000, 0x40);
    if (thunkPage == 0)
    {
        goto ThunkAllocFailed;
    }
    *(volatile int *)thunkPage;   // target: mov eax,[esi] (load kept)

    thunkEntry = (ThunkEntry *)g_PopEntrySList(g_ThunkPool);
    if (thunkEntry != 0)
    {
        VirtualFree(thunkPage, 0, 0x8000);
        return thunkEntry;
    }

    thunkEntry = thunkPage;
    lastThunkEntry = thunkPage + 0xff;
    do
    {
        g_PushEntrySList(g_ThunkPool, &thunkEntry->entry);
        thunkEntry += 1;
    } while (thunkEntry < lastThunkEntry);
    return thunkEntry;

ThunkAllocFailed:
    return 0;
}
