// from server: 100% by EspClaude
// roc 2009-06 004703f0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004703f0
//
// 004703f0  6aff                 push -1
// 004703f2  68b43a8500           push 0x853ab4
// 004703f7  64a100000000         mov eax, dword ptr fs:[0]
// 004703fd  50                   push eax
// 004703fe  64892500000000       mov dword ptr fs:[0], esp
// 00470405  83ec1c               sub esp, 0x1c
// 00470408  53                   push ebx
// 00470409  684cd88b00           push 0x8bd84c
// 0047040e  8d4c2408             lea ecx, [esp + 8]
// 00470412  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0047041a  ff15b4e48900         call dword ptr [0x89e4b4]
// 00470420  8d442404             lea eax, [esp + 4]
// 00470424  50                   push eax
// 00470425  8d4c2434             lea ecx, [esp + 0x34]
// 00470429  51                   push ecx
// 0047042a  c644243001           mov byte ptr [esp + 0x30], 1
// 0047042f  e82c2f0000           call 0x473360
// 00470434  83c408               add esp, 8
// 00470437  85c0                 test eax, eax
// 00470439  8d4c2404             lea ecx, [esp + 4]
// 0047043d  0f94c3               sete bl
// 00470440  c644242800           mov byte ptr [esp + 0x28], 0
// 00470445  ff15c4e48900         call dword ptr [0x89e4c4]
// 0047044b  84db                 test bl, bl
// 0047044d  7426                 je 0x470475
// 0047044f  8d4c2430             lea ecx, [esp + 0x30]
// 00470453  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0047045b  ff15c4e48900         call dword ptr [0x89e4c4]
// 00470461  33c0                 xor eax, eax
// 00470463  5b                   pop ebx
// 00470464  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00470468  64890d00000000       mov dword ptr fs:[0], ecx
// 0047046f  83c428               add esp, 0x28
// 00470472  c21c00               ret 0x1c
// 00470475  6858318b00           push 0x8b3158
// 0047047a  8d4c2408             lea ecx, [esp + 8]
// 0047047e  ff15b4e48900         call dword ptr [0x89e4b4]
// 00470484  8d542404             lea edx, [esp + 4]
// 00470488  52                   push edx
// 00470489  8d442434             lea eax, [esp + 0x34]
// 0047048d  50                   push eax
// 0047048e  c644243002           mov byte ptr [esp + 0x30], 2
// 00470493  e8c82e0000           call 0x473360
// 00470498  83c408               add esp, 8
// 0047049b  85c0                 test eax, eax
// 0047049d  8d4c2404             lea ecx, [esp + 4]
// 004704a1  0f94c3               sete bl
// 004704a4  c644242800           mov byte ptr [esp + 0x28], 0
// 004704a9  ff15c4e48900         call dword ptr [0x89e4c4]
// 004704af  84db                 test bl, bl
// 004704b1  7429                 je 0x4704dc
// 004704b3  8d4c2430             lea ecx, [esp + 0x30]
// 004704b7  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 004704bf  ff15c4e48900         call dword ptr [0x89e4c4]
// 004704c5  b801000000           mov eax, 1
// 004704ca  5b                   pop ebx
// 004704cb  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004704cf  64890d00000000       mov dword ptr fs:[0], ecx
// 004704d6  83c428               add esp, 0x28
// 004704d9  c21c00               ret 0x1c
// 004704dc  6840d88b00           push 0x8bd840
// 004704e1  8d4c2408             lea ecx, [esp + 8]
// 004704e5  ff15b4e48900         call dword ptr [0x89e4b4]
// 004704eb  8d4c2404             lea ecx, [esp + 4]
// 004704ef  51                   push ecx
// 004704f0  8d542434             lea edx, [esp + 0x34]
// 004704f4  52                   push edx
// 004704f5  c644243003           mov byte ptr [esp + 0x30], 3
// 004704fa  e8612e0000           call 0x473360
// 004704ff  83c408               add esp, 8
// 00470502  85c0                 test eax, eax
// 00470504  8d4c2404             lea ecx, [esp + 4]
// 00470508  0f94c3               sete bl
// 0047050b  c644242800           mov byte ptr [esp + 0x28], 0
// 00470510  ff15c4e48900         call dword ptr [0x89e4c4]
// 00470516  8d4c2430             lea ecx, [esp + 0x30]
// 0047051a  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00470522  ff15c4e48900         call dword ptr [0x89e4c4]
// 00470528  b802000000           mov eax, 2
// 0047052d  84db                 test bl, bl
// 0047052f  7505                 jne 0x470536
// 00470531  b8e7030000           mov eax, 0x3e7
// 00470536  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0047053a  5b                   pop ebx
// 0047053b  64890d00000000       mov dword ptr fs:[0], ecx
// 00470542  83c428               add esp, 0x28
// 00470545  c21c00               ret 0x1c
// copied from an identical function in another client (function ?mapColor@ns_ROCX00003c@@YGHUString@1@@Z)

namespace ns_ROCX00003c {
struct String {
    unsigned char storage[28];
    String(const char*);
    ~String();
};

extern void (__thiscall *string_construct)(String*, const char*);
extern void (__thiscall *string_destroy)(String*);
extern int __cdecl compare(const String&, const String&);

inline String::String(const char* text)
{
    string_construct(this, text);
}

inline String::~String()
{
    string_destroy(this);
}

int __stdcall mapColor(String value)
{
    if (compare(value, String("ball")) == 0)
        return 0;
    if (compare(value, String("block")) == 0)
        return 1;
    if (compare(value, String("cylinder")) == 0)
        return 2;
    return 999;
}
}
