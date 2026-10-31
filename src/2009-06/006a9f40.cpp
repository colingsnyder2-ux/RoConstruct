// from server: 95% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00601fd0  unit: RBX::UnifiedImageWidget  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00601fd0
//
// 00601fd0  6aff                 push -1
// 00601fd2  682e837d00           push 0x7d832e
// 00601fd7  64a100000000         mov eax, dword ptr fs:[0]
// 00601fdd  50                   push eax
// 00601fde  64892500000000       mov dword ptr fs:[0], esp
// 00601fe5  83ec28               sub esp, 0x28
// 00601fe8  53                   push ebx
// 00601fe9  33db                 xor ebx, ebx
// 00601feb  56                   push esi
// 00601fec  895c2408             mov dword ptr [esp + 8], ebx
// 00601ff0  685c010000           push 0x15c
// 00601ff5  885c2410             mov byte ptr [esp + 0x10], bl
// 00601ff9  ff15b0288000         call dword ptr [0x8028b0]
// 00601fff  8bf0                 mov esi, eax
// 00602001  83c404               add esp, 4
// 00602004  89742410             mov dword ptr [esp + 0x10], esi
// 00602008  c744243801000000     mov dword ptr [esp + 0x38], 1
// 00602010  85f6                 test esi, esi
// 00602012  7432                 je 0x602046
// 00602014  8b442444             mov eax, dword ptr [esp + 0x44]
// 00602018  50                   push eax
// 00602019  8d4c2418             lea ecx, [esp + 0x18]
// 0060201d  ff1558248000         call dword ptr [0x802458]
// 00602023  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00602027  6a00                 push 0
// 00602029  51                   push ecx
// 0060202a  8d54241c             lea edx, [esp + 0x1c]
// 0060202e  bb01000000           mov ebx, 1
// 00602033  52                   push edx
// 00602034  8bce                 mov ecx, esi
// 00602036  c644244402           mov byte ptr [esp + 0x44], 2
// 0060203b  895c2414             mov dword ptr [esp + 0x14], ebx
// 0060203f  e86c1cf7ff           call 0x573cb0
// 00602044  eb02                 jmp 0x602048
// 00602046  33c0                 xor eax, eax
// 00602048  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0060204c  8b742440             mov esi, dword ptr [esp + 0x40]
// 00602050  51                   push ecx
// 00602051  50                   push eax
// 00602052  8bce                 mov ecx, esi
// 00602054  c744244003000000     mov dword ptr [esp + 0x40], 3
// 0060205c  e82ff4ffff           call 0x601490
// 00602061  83cb02               or ebx, 2
// 00602064  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0060206c  f6c301               test bl, 1
// 0060206f  7411                 je 0x602082
// 00602071  83e3fe               and ebx, 0xfffffffe
// 00602074  8d4c2414             lea ecx, [esp + 0x14]
// 00602078  895c2408             mov dword ptr [esp + 8], ebx
// 0060207c  ff1568248000         call dword ptr [0x802468]
// 00602082  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00602086  8bc6                 mov eax, esi
// 00602088  5e                   pop esi
// 00602089  5b                   pop ebx
// 0060208a  64890d00000000       mov dword ptr fs:[0], ecx
// 00602091  83c434               add esp, 0x34
// 00602094  c3                   ret 

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
    char storage[348];
    Object(const std::string&, int, bool);
};

struct Result {
    void* object;
    void* owner;

    Result(Object*, EmptyDeleter);
    ~Result();
};

Result __cdecl create(const char* name, int value);

Result __cdecl create(const char* name, int value)
{
    return Result(new Object(std::string(name), value, false),
                  EmptyDeleter());
}
