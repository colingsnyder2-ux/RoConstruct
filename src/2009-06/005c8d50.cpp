// from server: 100% by EspClaude
// roc 2009-06 005c8d50  unit: seg_005c0000  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c8d50
//
// 005c8d50  6aff                 push -1
// 005c8d52  688cf58500           push 0x85f58c
// 005c8d57  64a100000000         mov eax, dword ptr fs:[0]
// 005c8d5d  50                   push eax
// 005c8d5e  64892500000000       mov dword ptr fs:[0], esp
// 005c8d65  83ec3c               sub esp, 0x3c
// 005c8d68  53                   push ebx
// 005c8d69  56                   push esi
// 005c8d6a  8d4c240c             lea ecx, [esp + 0xc]
// 005c8d6e  c744240800000000     mov dword ptr [esp + 8], 0
// 005c8d76  ff15c0e48900         call dword ptr [0x89e4c0]
// 005c8d7c  6868418d00           push 0x8d4168
// 005c8d81  8d4c242c             lea ecx, [esp + 0x2c]
// 005c8d85  c744245001000000     mov dword ptr [esp + 0x50], 1
// 005c8d8d  ff15b4e48900         call dword ptr [0x89e4b4]
// 005c8d93  8d44240c             lea eax, [esp + 0xc]
// 005c8d97  50                   push eax
// 005c8d98  8d4c242c             lea ecx, [esp + 0x2c]
// 005c8d9c  51                   push ecx
// 005c8d9d  c644245402           mov byte ptr [esp + 0x54], 2
// 005c8da2  e889741400           call 0x710230
// 005c8da7  83c408               add esp, 8
// 005c8daa  8d4c2428             lea ecx, [esp + 0x28]
// 005c8dae  8ad8                 mov bl, al
// 005c8db0  c644244c01           mov byte ptr [esp + 0x4c], 1
// 005c8db5  ff15c4e48900         call dword ptr [0x89e4c4]
// 005c8dbb  8b742454             mov esi, dword ptr [esp + 0x54]
// 005c8dbf  8bce                 mov ecx, esi
// 005c8dc1  84db                 test bl, bl
// 005c8dc3  740d                 je 0x5c8dd2
// 005c8dc5  8d54240c             lea edx, [esp + 0xc]
// 005c8dc9  52                   push edx
// 005c8dca  ff15b8e48900         call dword ptr [0x89e4b8]
// 005c8dd0  eb0b                 jmp 0x5c8ddd
// 005c8dd2  6800758c00           push 0x8c7500
// 005c8dd7  ff15b4e48900         call dword ptr [0x89e4b4]
// 005c8ddd  8d4c240c             lea ecx, [esp + 0xc]
// 005c8de1  c744240801000000     mov dword ptr [esp + 8], 1
// 005c8de9  c644244c00           mov byte ptr [esp + 0x4c], 0
// 005c8dee  ff15c4e48900         call dword ptr [0x89e4c4]
// 005c8df4  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 005c8df8  8bc6                 mov eax, esi
// 005c8dfa  5e                   pop esi
// 005c8dfb  5b                   pop ebx
// 005c8dfc  64890d00000000       mov dword ptr fs:[0], ecx
// 005c8e03  83c448               add esp, 0x48
// 005c8e06  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX00001c@@QAE?AUString@2@XZ)

namespace ns_ROCX00001c {
struct String;

extern void (__thiscall *stringDefaultConstruct)(String *);
extern void (__thiscall *stringTextConstruct)(String *, const char *);
extern void (__thiscall *stringCopyConstruct)(String *, const String &);
extern void (__thiscall *stringDestroy)(String *);

extern const char productNameKey[];
extern const char fallbackName[];

struct String {
    unsigned char storage[28];

    String();
    String(const char *);
    String(const String &);
    ~String();
};

inline String::String() {
    stringDefaultConstruct(this);
}

inline String::String(const char *text) {
    stringTextConstruct(this, text);
}

inline String::String(const String &other) {
    stringCopyConstruct(this, other);
}

inline String::~String() {
    stringDestroy(this);
}

extern bool __cdecl readProductName(const String &, String &);

struct S {
    String f();
};

String S::f() {
    String result;
    bool found = readProductName(String(productNameKey), result);
    if (found)
        return result;
    return String(fallbackName);
}
}
