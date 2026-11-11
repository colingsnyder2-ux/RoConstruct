// from server: 100% by EspClaude
// from server: 90% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0049aa60  unit: RBX::VInstance::V?$shared_ptr::V?$vector::?$sp_counted_impl_p  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049aa60
//
// 0049aa60  6aff                 push -1
// 0049aa62  6868e37c00           push 0x7ce368
// 0049aa67  64a100000000         mov eax, dword ptr fs:[0]
// 0049aa6d  50                   push eax
// 0049aa6e  64892500000000       mov dword ptr fs:[0], esp
// 0049aa75  51                   push ecx
// 0049aa76  56                   push esi
// 0049aa77  8bf1                 mov esi, ecx
// 0049aa79  57                   push edi
// 0049aa7a  89742408             mov dword ptr [esp + 8], esi
// 0049aa7e  e8edbdffff           call 0x496870
// 0049aa83  8bf8                 mov edi, eax
// 0049aa85  e816feffff           call 0x49a8a0
// 0049aa8a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0049aa8e  8b542420             mov edx, dword ptr [esp + 0x20]
// 0049aa92  51                   push ecx
// 0049aa93  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0049aa97  52                   push edx
// 0049aa98  51                   push ecx
// 0049aa99  57                   push edi
// 0049aa9a  50                   push eax
// 0049aa9b  8bce                 mov ecx, esi
// 0049aa9d  e8ae1b0d00           call 0x56c650
// 0049aaa2  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0049aaa6  8b442428             mov eax, dword ptr [esp + 0x28]
// 0049aaaa  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0049aaae  52                   push edx
// 0049aaaf  50                   push eax
// 0049aab0  51                   push ecx
// 0049aab1  8d54243c             lea edx, [esp + 0x3c]
// 0049aab5  52                   push edx
// 0049aab6  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0049aabe  c7068c288200         mov dword ptr [esi], 0x82288c
// 0049aac4  c7461884288200       mov dword ptr [esi + 0x18], 0x822884
// 0049aacb  e8e0c8ffff           call 0x4973b0
// 0049aad0  8b08                 mov ecx, dword ptr [eax]
// 0049aad2  c70000000000         mov dword ptr [eax], 0
// 0049aad8  8b442440             mov eax, dword ptr [esp + 0x40]
// 0049aadc  83c410               add esp, 0x10
// 0049aadf  894e1c               mov dword ptr [esi + 0x1c], ecx
// 0049aae2  85c0                 test eax, eax
// 0049aae4  7409                 je 0x49aaef
// 0049aae6  50                   push eax
// 0049aae7  e88e5b2000           call 0x6a067a
// 0049aaec  83c404               add esp, 4
// 0049aaef  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0049aaf3  5f                   pop edi
// 0049aaf4  8bc6                 mov eax, esi
// 0049aaf6  5e                   pop esi
// 0049aaf7  64890d00000000       mov dword ptr fs:[0], ecx
// 0049aafe  83c410               add esp, 0x10
// 0049ab01  c21800               ret 0x18

extern void* __cdecl getFirstDescriptor();
extern void* __cdecl getSecondDescriptor();
void __cdecl operator delete(void*);

extern const char primaryTable[];
extern const char secondaryTable[];

struct Owner {
    void* p;

    ~Owner();
    void* release();
};

inline Owner::~Owner()
{
    operator delete(p);
}

inline void* Owner::release()
{
    void* result = p;
    p = 0;
    return result;
}

extern Owner __cdecl makeOwner(int, int, int);

extern const char middleTable[];

struct Second {
    const void* secondary;
    Second() { secondary = middleTable; }
};

struct Base {
    const void* primary;
    char padding[20];

    Base(int, int, int);
    void initialize(void*, void*, int, int, int);
    ~Base();
};

__forceinline Base::Base(int a, int b, int f)
{
    void* first = getFirstDescriptor();
    void* second = getSecondDescriptor();
    initialize(second, first, a, b, f);
}

struct S : Base, Second {
    void* value;

    S(int, int, int, int, int, int);
};

S::S(int a, int b, int c, int d, int e, int f)
    : Base(a, b, f), Second()
{
    primary = primaryTable;
    secondary = secondaryTable;
    value = makeOwner(c, d, e).release();
}
