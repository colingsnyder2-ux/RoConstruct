// from server: 100% by EspClaude
// from server: 86% by EspClaude
// roc 2009-06 0040dae0  unit: VCBrowserViewExternal::?$CProxy_IBrowserViewExternalEvents  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040dae0
//
// 0040dae0  6aff                 push -1
// 0040dae2  68c8d38400           push 0x84d3c8
// 0040dae7  64a100000000         mov eax, dword ptr fs:[0]
// 0040daed  50                   push eax
// 0040daee  64892500000000       mov dword ptr fs:[0], esp
// 0040daf5  51                   push ecx
// 0040daf6  56                   push esi
// 0040daf7  8bf1                 mov esi, ecx
// 0040daf9  89742404             mov dword ptr [esp + 4], esi
// 0040dafd  c70634e18a00         mov dword ptr [esi], 0x8ae134
// 0040db03  8d8eb0020000         lea ecx, [esi + 0x2b0]
// 0040db09  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040db11  ff1510fd8900         call dword ptr [0x89fd10]
// 0040db17  8b86a8020000         mov eax, dword ptr [esi + 0x2a8]
// 0040db1d  85c0                 test eax, eax
// 0040db1f  7408                 je 0x40db29
// 0040db21  8b08                 mov ecx, dword ptr [eax]
// 0040db23  8b5108               mov edx, dword ptr [ecx + 8]
// 0040db26  50                   push eax
// 0040db27  ffd2                 call edx
// 0040db29  8d8e00010000         lea ecx, [esi + 0x100]
// 0040db2f  e8acc83200           call 0x73a3e0
// 0040db34  8bce                 mov ecx, esi
// 0040db36  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0040db3e  e88df4ffff           call 0x40cfd0
// 0040db43  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040db47  5e                   pop esi
// 0040db48  64890d00000000       mov dword ptr fs:[0], ecx
// 0040db4f  83c410               add esp, 0x10
// 0040db52  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 00410950  unit: UIEnumConnections::V?$CComEnum::?$CComObject  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00410950
//
// 00410950  6aff                 push -1
// 00410952  68f6d57b00           push 0x7bd5f6
// 00410957  64a100000000         mov eax, dword ptr fs:[0]
// 0041095d  50                   push eax
// 0041095e  64892500000000       mov dword ptr fs:[0], esp
// 00410965  51                   push ecx
// 00410966  56                   push esi
// 00410967  8bf1                 mov esi, ecx
// 00410969  89742404             mov dword ptr [esp + 4], esi
// 0041096d  c70614d88000         mov dword ptr [esi], 0x80d814
// 00410973  8d8ecc020000         lea ecx, [esi + 0x2cc]
// 00410979  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00410981  ff15143f8000         call dword ptr [0x803f14]
// 00410987  8b86c4020000         mov eax, dword ptr [esi + 0x2c4]
// 0041098d  85c0                 test eax, eax
// 0041098f  7408                 je 0x410999
// 00410991  8b08                 mov ecx, dword ptr [eax]
// 00410993  8b5108               mov edx, dword ptr [ecx + 8]
// 00410996  50                   push eax
// 00410997  ffd2                 call edx
// 00410999  8d8e1c010000         lea ecx, [esi + 0x11c]
// 0041099f  e80c152b00           call 0x6c1eb0
// 004109a4  8d8efc000000         lea ecx, [esi + 0xfc]
// 004109aa  c644241000           mov byte ptr [esp + 0x10], 0
// 004109af  e83cdc1400           call 0x55e5f0
// 004109b4  8bce                 mov ecx, esi
// 004109b6  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004109be  e86dd8ffff           call 0x40e230
// 004109c3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004109c7  5e                   pop esi
// 004109c8  64890d00000000       mov dword ptr fs:[0], ecx
// 004109cf  83c410               add esp, 0x10
// 004109d2  c3                   ret 

struct Base {
    virtual ~Base();
    char storage[0xFC];
};

struct Member {
    char storage[0x20];
    ~Member();
};

struct Buffer {
    char storage[0x1A8];
    void cleanup();
};

struct Interface {
    virtual long __stdcall QueryInterface(void *, void **) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

extern void (__thiscall *destroyLock)(void *);

struct S : Base {
    Buffer buffer;
    Interface *connection;
    unsigned long reserved;
    char lock[4];

    virtual ~S();
};

S::~S()
{
    destroyLock(lock);
    if (connection)
        connection->Release();
    buffer.cleanup();
}
