// from server: 100% by colin
// from server: 73% by king_originala
// roc 2008-06 007a601d  unit: _AllocateThunk  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007a601d
// 007a601d  833d08f39700         cmp dword ptr [0x3979f08], 0
// 007a6023  56                   push esi
// 007a6024  7509                 jne 0x7a602f
// 007a6026  e82affffff           call sym
// 007a602b  85c0                 test eax, eax
// 007a602d  7443                 je 0x7a6072
// 007a602f  a108f39700           mov eax, dword ptr [0x3979f08]
// 007a6034  83f801               cmp eax, 1
// 007a6037  7517                 jne 0x7a6050
// 007a6039  6a0d                 push 0xd
// 007a603b  6a00                 push 0
// 007a603d  ff15b8228000         call dword ptr [0x8022b8]
// 007a6043  50                   push eax
// 007a6045  ff15f8218000         call dword ptr [0x8021f8]
// 007a604b  85c0                 test eax, eax
// 007a604d  7424                 je 0x7a6073
// 007a604f  5e                   pop esi
// 007a6050  ret
// 007a6051  50                   push eax
// 007a6052  ff1510f39700         call dword ptr [0x3979f10]
// 007a6058  85c0                 test eax, eax
// 007a605a  755f                 jne 0x7a60bb
// 007a605c  6a40                 push 0x40
// 007a605e  b800100000           mov eax, 0x1000
// 007a6063  50                   push eax
// 007a6064  50                   push eax
// 007a6066  6a00                 push 0
// 007a6068  ff1548238000         call dword ptr [0x802348]
// 007a606e  8bf0                 mov esi, eax
// 007a6070  85f6                 test esi, esi
// 007a6072  7504                 jne 0x7a6078
// 007a6074  33c0                 xor eax, eax
// 007a6076  5e                   pop esi
// 007a6077  c3                   ret
// 007a6078  8b06                 mov eax, dword ptr [esi]
// 007a607a  57                   push edi
// 007a607b  ff3508f39700         push dword ptr [0x3979f08]
// 007a6081  ff1510f39700         call dword ptr [0x3979f10]
// 007a6087  8bf8                 mov edi, eax
// 007a6089  85ff                 test edi, edi
// 007a608b  7410                 je 0x7a609d
// 007a608d  6800800000           push 0x8000
// 007a608f  6a00                 push 0
// 007a6091  56                   push esi
// 007a6093  ff1544238000         call dword ptr [0x802344]
// 007a6099  eb1c                 jmp 0x7a60b7
// 007a609b  8bfe                 mov edi, esi
// 007a609d  81c6f00f0000         add esi, 0xff0
// 007a60a3  56                   push edi
// 007a60a4  ff3508f39700         push dword ptr [0x3979f08]
// 007a60aa  ff150cf39700         call dword ptr [0x3979f0c]
// 007a60b0  83c710               add edi, 0x10
// 007a60b3  3bfe                 cmp edi, esi
// 007a60b5  72ec                 jb 0x7a609b
// 007a60b7  8bc7                 mov eax, edi
// 007a60b9  5f                   pop edi
// 007a60ba  5e                   pop esi
// 007a60bb  c3                   ret
extern "C" void __cdecl FreeThunkData(void*);
extern "C" int __cdecl InitializeThunkHeap();

extern unsigned long thunkHeap;
extern void* (__stdcall *allocateThunk)(unsigned long);
extern void (__stdcall *releaseThunk)(unsigned long, void*);

extern unsigned long (__stdcall *GetProcessHeap)();
extern void* (__stdcall *HeapAlloc)(unsigned long, unsigned long, unsigned long);
extern void* (__stdcall *VirtualAlloc)(void*, unsigned long, unsigned long, unsigned long);
extern int (__stdcall *VirtualFree)(void*, unsigned long, unsigned long);

#pragma optimize("y", off)
extern "C" void __stdcall FreeThunk(void* data)
{
    FreeThunkData(data);
}
#pragma optimize("y", on)
#pragma optimize("s", on)

extern "C" void* __cdecl AllocateThunk()
{
    unsigned char* page;
    unsigned char* result;

    if (thunkHeap == 0)
    {
        if (!InitializeThunkHeap())
            goto failure;
    }

    if (thunkHeap == 1)
    {
        result = (unsigned char*)HeapAlloc(GetProcessHeap(), 0, 13);
        if (!result)
            goto failure;
        return result;
    }

    result = (unsigned char*)allocateThunk(thunkHeap);
    if (result)
        return result;

    page = (unsigned char*)VirtualAlloc(0, 4096, 4096, 64);
    if (!page)
    {
failure:
        return 0;
    }

    (void)*(volatile unsigned long*)page;
    result = (unsigned char*)allocateThunk(thunkHeap);
    if (result)
    {
        VirtualFree(page, 0, 32768);
    }
    else
    {
        result = page;
        page += 4080;
        do
        {
            releaseThunk(thunkHeap, result);
            result += 16;
        } while (result < page);
    }
    return result;
}
