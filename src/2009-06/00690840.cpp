// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0062e1c0  unit: RBX::VDecal::?$FactoryProduct  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0062e1c0
//
// 0062e1c0  64a100000000         mov eax, dword ptr fs:[0]
// 0062e1c6  6aff                 push -1
// 0062e1c8  68a59b7d00           push 0x7d9ba5
// 0062e1cd  50                   push eax
// 0062e1ce  64892500000000       mov dword ptr fs:[0], esp
// 0062e1d5  81ec88000000         sub esp, 0x88
// 0062e1db  56                   push esi
// 0062e1dc  8bf1                 mov esi, ecx
// 0062e1de  56                   push esi
// 0062e1df  e89c51f7ff           call 0x5a3380
// 0062e1e4  83c404               add esp, 4
// 0062e1e7  85c0                 test eax, eax
// 0062e1e9  7537                 jne 0x62e222
// 0062e1eb  68006b8400           push 0x846b00
// 0062e1f0  8d4c2424             lea ecx, [esp + 0x24]
// 0062e1f4  ff1558248000         call dword ptr [0x802458]
// 0062e1fa  8d442420             lea eax, [esp + 0x20]
// 0062e1fe  50                   push eax
// 0062e1ff  8d4c2440             lea ecx, [esp + 0x40]
// 0062e203  c784249800000000000000 mov dword ptr [esp + 0x98], 0
// 0062e20e  e83dbbddff           call 0x409d50
// 0062e213  68c81b8d00           push 0x8d1bc8
// 0062e218  8d4c2440             lea ecx, [esp + 0x40]
// 0062e21c  51                   push ecx
// 0062e21d  e86a330700           call 0x6a158c
// 0062e222  6a01                 push 1
// 0062e224  56                   push esi
// 0062e225  e8367ce6ff           call 0x495e60
// 0062e22a  83c408               add esp, 8
// 0062e22d  84c0                 test al, al
// 0062e22f  7437                 je 0x62e268
// 0062e231  68d06a8400           push 0x846ad0
// 0062e236  8d4c2408             lea ecx, [esp + 8]
// 0062e23a  ff1558248000         call dword ptr [0x802458]
// 0062e240  8d542404             lea edx, [esp + 4]
// 0062e244  52                   push edx
// 0062e245  8d4c2468             lea ecx, [esp + 0x68]
// 0062e249  c784249800000001000000 mov dword ptr [esp + 0x98], 1
// 0062e254  e8f7baddff           call 0x409d50
// 0062e259  68c81b8d00           push 0x8d1bc8
// 0062e25e  8d442468             lea eax, [esp + 0x68]
// 0062e262  50                   push eax
// 0062e263  e824330700           call 0x6a158c
// 0062e268  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 0062e26f  c6864801000001       mov byte ptr [esi + 0x148], 1
// 0062e276  5e                   pop esi
// 0062e277  64890d00000000       mov dword ptr fs:[0], ecx
// 0062e27e  81c494000000         add esp, 0x94
// 0062e284  c3                   ret 

struct String;
typedef void (__thiscall *StringConstructor)(String *, const char *);
extern StringConstructor constructString;

struct String
{
    unsigned char storage[28];
    String(const char *);
    ~String();
};

inline String::String(const char *text)
{
    constructString(this, text);
}

struct Error
{
    unsigned char storage[40];
    Error(const String &);
};

extern unsigned char errorType;
extern "C" __declspec(noreturn) void __stdcall
ThrowError(void *, void *);

struct S
{
    unsigned char padding[0x148];
    bool fired;
    void fire();
};

extern int __cdecl isInWorkspace(S *);
extern bool __cdecl isClient(S *, int);

void S::fire()
{
    if (!isInWorkspace(this))
    {
        String message("Rocket:Fire may only be called when the Rocket is in the Workspace");
        Error error(message);
        ThrowError(&error, &errorType);
    }

    if (isClient(this, 1))
    {
        String message("Rocket:Fire may not be called from a client");
        Error error(message);
        ThrowError(&error, &errorType);
    }

    fired = true;
}
