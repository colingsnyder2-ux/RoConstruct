// from server: 95% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00601f00  unit: RBX::UnifiedImageWidget  size: 200 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00601f00
//
// 00601f00  6aff                 push -1
// 00601f02  682e837d00           push 0x7d832e
// 00601f07  64a100000000         mov eax, dword ptr fs:[0]
// 00601f0d  50                   push eax
// 00601f0e  64892500000000       mov dword ptr fs:[0], esp
// 00601f15  83ec28               sub esp, 0x28
// 00601f18  53                   push ebx
// 00601f19  33db                 xor ebx, ebx
// 00601f1b  56                   push esi
// 00601f1c  895c2408             mov dword ptr [esp + 8], ebx
// 00601f20  6884010000           push 0x184
// 00601f25  885c2410             mov byte ptr [esp + 0x10], bl
// 00601f29  ff15b0288000         call dword ptr [0x8028b0]
// 00601f2f  8bf0                 mov esi, eax
// 00601f31  83c404               add esp, 4
// 00601f34  89742410             mov dword ptr [esp + 0x10], esi
// 00601f38  c744243801000000     mov dword ptr [esp + 0x38], 1
// 00601f40  85f6                 test esi, esi
// 00601f42  7435                 je 0x601f79
// 00601f44  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 00601f48  50                   push eax
// 00601f49  8d4c2418             lea ecx, [esp + 0x18]
// 00601f4d  ff1558248000         call dword ptr [0x802458]
// 00601f53  8b542448             mov edx, dword ptr [esp + 0x48]
// 00601f57  8b442444             mov eax, dword ptr [esp + 0x44]
// 00601f5b  8d4c2414             lea ecx, [esp + 0x14]
// 00601f5f  51                   push ecx
// 00601f60  52                   push edx
// 00601f61  bb01000000           mov ebx, 1
// 00601f66  50                   push eax
// 00601f67  8bce                 mov ecx, esi
// 00601f69  c644244402           mov byte ptr [esp + 0x44], 2
// 00601f6e  895c2414             mov dword ptr [esp + 0x14], ebx
// 00601f72  e8c9d30400           call 0x64f340
// 00601f77  eb02                 jmp 0x601f7b
// 00601f79  33c0                 xor eax, eax
// 00601f7b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00601f7f  8b742440             mov esi, dword ptr [esp + 0x40]
// 00601f83  51                   push ecx
// 00601f84  50                   push eax
// 00601f85  8bce                 mov ecx, esi
// 00601f87  c744244003000000     mov dword ptr [esp + 0x40], 3
// 00601f8f  e84cf4ffff           call 0x6013e0
// 00601f94  83cb02               or ebx, 2
// 00601f97  c744243800000000     mov dword ptr [esp + 0x38], 0
// 00601f9f  f6c301               test bl, 1
// 00601fa2  7411                 je 0x601fb5
// 00601fa4  83e3fe               and ebx, 0xfffffffe
// 00601fa7  8d4c2414             lea ecx, [esp + 0x14]
// 00601fab  895c2408             mov dword ptr [esp + 8], ebx
// 00601faf  ff1568248000         call dword ptr [0x802468]
// 00601fb5  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00601fb9  8bc6                 mov eax, esi
// 00601fbb  5e                   pop esi
// 00601fbc  5b                   pop ebx
// 00601fbd  64890d00000000       mov dword ptr fs:[0], ecx
// 00601fc4  83c434               add esp, 0x34
// 00601fc7  c3                   ret 

typedef unsigned int size_t;

extern "C" void* (__cdecl *allocate)(size_t);

inline void* __cdecl operator new(size_t size)
{
    return allocate(size);
}

void __cdecl operator delete(void*);

namespace std {
    class string;
}

extern void (__thiscall *constructString)(std::string*, const char*);
extern void (__thiscall *destroyString)(std::string*);

namespace std {
    class string {
        char storage[28];
    public:
        string(const char*);
        ~string();
    };

    inline string::string(const char* text)
    {
        constructString(this, text);
    }

    inline string::~string()
    {
        destroyString(this);
    }
}

struct EmptyDeleter {};

struct Object {
    char storage[388];
    Object(int, int, const std::string&);
};

struct Result {
    void* object;
    void* owner;

    Result(Object*, EmptyDeleter);
    ~Result();
};

Result __cdecl create(int first, int second, const char* name);

Result __cdecl create(int first, int second, const char* name)
{
    return Result(new Object(first, second, std::string(name)),
                  EmptyDeleter());
}
