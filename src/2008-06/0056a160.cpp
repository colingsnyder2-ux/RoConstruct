// from server: 100% by colin
// from server: 98% by colin
// roc 2008-06 0056a160  unit: RBX::StandardOut  size: 381 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056a160
//
// 0056a160  64a100000000         mov eax, dword ptr fs:[0]
// 0056a166  6aff                 push -1
// 0056a168  688bf97c00           push 0x7cf98b
// 0056a16d  50                   push eax
// 0056a16e  b84c120000           mov eax, 0x124c
// 0056a173  64892500000000       mov dword ptr fs:[0], esp
// 0056a17a  e8a1731300           call 0x6a1520
// 0056a17f  8d4c2408             lea ecx, [esp + 8]
// 0056a183  e8c8c4e9ff           call 0x406650
// 0056a188  8b0d70b38000         mov ecx, dword ptr [0x80b370]
// 0056a18e  6a04                 push 4
// 0056a190  51                   push ecx
// 0056a191  8d542410             lea edx, [esp + 0x10]
// 0056a195  b850000000           mov eax, 0x50
// 0056a19a  6a21                 push 0x21
// 0056a19c  52                   push edx
// 0056a19d  c784244012000002000000 mov dword ptr [esp + 0x1240], 2
// 0056a1a8  c784244412000004000000 mov dword ptr [esp + 0x1244], 4
// 0056a1b3  668984243e120000     mov word ptr [esp + 0x123e], ax
// 0056a1bb  ff15b8288000         call dword ptr [0x8028b8]
// 0056a1c1  50                   push eax
// 0056a1c2  e8a9f6ffff           call 0x569870
// 0056a1c7  8b842470120000       mov eax, dword ptr [esp + 0x1270]
// 0056a1ce  83c414               add esp, 0x14
// 0056a1d1  6a00                 push 0
// 0056a1d3  50                   push eax
// 0056a1d4  8d4c2410             lea ecx, [esp + 0x10]
// 0056a1d8  e883e7e9ff           call 0x408960
// 0056a1dd  8b842430120000       mov eax, dword ptr [esp + 0x1230]
// 0056a1e4  85c0                 test eax, eax
// 0056a1e6  7421                 je 0x56a209
// 0056a1e8  83f801               cmp eax, 1
// 0056a1eb  7e05                 jle 0x56a1f2
// 0056a1ed  83f803               cmp eax, 3
// 0056a1f0  7e17                 jle 0x56a209
// 0056a1f2  32c0                 xor al, al
// 0056a1f4  8b8c244c120000       mov ecx, dword ptr [esp + 0x124c]
// 0056a1fb  64890d00000000       mov dword ptr fs:[0], ecx
// 0056a202  81c458120000         add esp, 0x1258
// 0056a208  c3                   ret 
// 0056a209  53                   push ebx
// 0056a20a  56                   push esi
// 0056a20b  8d4c2431             lea ecx, [esp + 0x31]
// 0056a20f  51                   push ecx
// 0056a210  8d4c240c             lea ecx, [esp + 0xc]
// 0056a214  e8074cffff           call 0x55ee20
// 0056a219  8d4c2408             lea ecx, [esp + 8]
// 0056a21d  c784245c12000000000000 mov dword ptr [esp + 0x125c], 0
// 0056a228  e8b3fdffff           call 0x569fe0
// 0056a22d  6a0a                 push 0xa
// 0056a22f  8d542410             lea edx, [esp + 0x10]
// 0056a233  52                   push edx
// 0056a234  8d4c2410             lea ecx, [esp + 0x10]
// 0056a238  e823fbffff           call 0x569d60
// 0056a23d  8b00                 mov eax, dword ptr [eax]
// 0056a23f  6890f58200           push 0x82f590
// 0056a244  50                   push eax
// 0056a245  ff153c288000         call dword ptr [0x80283c]
// 0056a24b  83c408               add esp, 8
// 0056a24e  85c0                 test eax, eax
// 0056a250  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0056a254  0f94c3               sete bl
// 0056a257  83c0f0               add eax, -0x10
// 0056a25a  83ceff               or esi, 0xffffffff
// 0056a25d  8d480c               lea ecx, [eax + 0xc]
// 0056a260  8bd6                 mov edx, esi
// 0056a262  f00fc111             lock xadd dword ptr [ecx], edx
// 0056a266  4a                   dec edx
// 0056a267  85d2                 test edx, edx
// 0056a269  7f0a                 jg 0x56a275
// 0056a26b  8b08                 mov ecx, dword ptr [eax]
// 0056a26d  8b11                 mov edx, dword ptr [ecx]
// 0056a26f  50                   push eax
// 0056a270  8b4204               mov eax, dword ptr [edx + 4]
// 0056a273  ffd0                 call eax
// 0056a275  8b442408             mov eax, dword ptr [esp + 8]
// 0056a279  83c0f0               add eax, -0x10
// 0056a27c  89b4245c120000       mov dword ptr [esp + 0x125c], esi
// 0056a283  8d480c               lea ecx, [eax + 0xc]
// 0056a286  f00fc131             lock xadd dword ptr [ecx], esi
// 0056a28a  4e                   dec esi
// 0056a28b  84db                 test bl, bl
// 0056a28d  7427                 je 0x56a2b6
// 0056a28f  85f6                 test esi, esi
// 0056a291  7f0a                 jg 0x56a29d
// 0056a293  8b08                 mov ecx, dword ptr [eax]
// 0056a295  8b11                 mov edx, dword ptr [ecx]
// 0056a297  50                   push eax
// 0056a298  8b4204               mov eax, dword ptr [edx + 4]
// 0056a29b  ffd0                 call eax
// 0056a29d  5e                   pop esi
// 0056a29e  b001                 mov al, 1
// 0056a2a0  5b                   pop ebx
// 0056a2a1  8b8c244c120000       mov ecx, dword ptr [esp + 0x124c]
// 0056a2a8  64890d00000000       mov dword ptr fs:[0], ecx
// 0056a2af  81c458120000         add esp, 0x1258
// 0056a2b5  c3                   ret 
// 0056a2b6  85f6                 test esi, esi
// 0056a2b8  7f0a                 jg 0x56a2c4
// 0056a2ba  8b08                 mov ecx, dword ptr [eax]
// 0056a2bc  8b11                 mov edx, dword ptr [ecx]
// 0056a2be  50                   push eax
// 0056a2bf  8b4204               mov eax, dword ptr [edx + 4]
// 0056a2c2  ffd0                 call eax
// 0056a2c4  8b8c2454120000       mov ecx, dword ptr [esp + 0x1254]
// 0056a2cb  5e                   pop esi
// 0056a2cc  32c0                 xor al, al
// 0056a2ce  5b                   pop ebx
// 0056a2cf  64890d00000000       mov dword ptr fs:[0], ecx
// 0056a2d6  81c458120000         add esp, 0x1258
// 0056a2dc  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


extern "C" int (__cdecl* _mbsnbcpy_s)(
    unsigned char*, unsigned int, const unsigned char*, unsigned int);
extern "C" __declspec(dllimport) int __cdecl _mbscmp(
    const unsigned char*, const unsigned char*) throw();
extern "C" void __cdecl checkError(int);

extern const unsigned char* prefix;

struct Header;

struct Allocator
{
    virtual void unused() = 0;
    virtual void release(Header*) = 0;
};

struct Header
{
    Allocator* allocator;
    unsigned int size;
    unsigned int capacity;
    volatile long references;
};

struct TemporaryString
{
    unsigned char* data;
    TemporaryString(const TemporaryString&);
    ~TemporaryString() throw()
    {
        Header* h = reinterpret_cast<Header*>(data - 16);
        if (_InterlockedDecrement(&h->references) <= 0)
            h->allocator->release(h);
    }
};

struct String
{
    unsigned char* data;

    String(const char*);
    void normalize();
    TemporaryString substring(int);

    ~String()
    {
        Header* h = reinterpret_cast<Header*>(data - 16);
        if (_InterlockedDecrement(&h->references) <= 0)
            h->allocator->release(h);
    }
};

struct VCContent_CComAggObject
{
    unsigned char data[0x1226];
    unsigned short port;
    int kind;
    int flags;
    int field1230;
    int field1234;
    int field1238;
    int field123c;
    int field1240;

    void Init();
    void f(int, unsigned int);
};

bool verifyAddress(int value)
{
    VCContent_CComAggObject content;
    content.Init();
    content.kind = 2;
    content.flags = 4;
    content.port = 80;
    checkError(_mbsnbcpy_s(content.data, 33, prefix, 4));
    content.f(value, 0);

    if (content.kind != 0 &&
        (content.kind <= 1 || content.kind > 3))
        return false;

    String host(reinterpret_cast<const char*>(content.data + 0x21));
    host.normalize();

    bool matched = _mbscmp(
        host.substring(10).data,
        reinterpret_cast<const unsigned char*>("roblox.com")) == 0;

    if (matched)
        return true;
    return false;
}
