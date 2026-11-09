// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2009-06 00690840  unit: RBX::VBlockMesh::?$FactoryProduct  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00690840
//
// 00690840  64a100000000         mov eax, dword ptr fs:[0]
// 00690846  6aff                 push -1
// 00690848  68f5e78600           push 0x86e7f5
// 0069084d  50                   push eax
// 0069084e  64892500000000       mov dword ptr fs:[0], esp
// 00690855  81ec88000000         sub esp, 0x88
// 0069085b  56                   push esi
// 0069085c  8bf1                 mov esi, ecx
// 0069085e  56                   push esi
// 0069085f  e8ccd9f9ff           call 0x62e230
// 00690864  83c404               add esp, 4
// 00690867  85c0                 test eax, eax
// 00690869  7537                 jne 0x6908a2
// 0069086b  68b0688e00           push 0x8e68b0
// 00690870  8d4c2424             lea ecx, [esp + 0x24]
// 00690874  ff15b4e48900         call dword ptr [0x89e4b4]
// 0069087a  8d442420             lea eax, [esp + 0x20]
// 0069087e  50                   push eax
// 0069087f  8d4c2440             lea ecx, [esp + 0x40]
// 00690883  c784249800000000000000 mov dword ptr [esp + 0x98], 0
// 0069088e  e87d8bd7ff           call 0x409410
// 00690893  6850a79700           push 0x97a750
// 00690898  8d4c2440             lea ecx, [esp + 0x40]
// 0069089c  51                   push ecx
// 0069089d  e8a8910800           call 0x719a4a
// 006908a2  6a01                 push 1
// 006908a4  56                   push esi
// 006908a5  e88636e3ff           call 0x4c3f30
// 006908aa  83c408               add esp, 8
// 006908ad  84c0                 test al, al
// 006908af  7437                 je 0x6908e8
// 006908b1  6884688e00           push 0x8e6884
// 006908b6  8d4c2408             lea ecx, [esp + 8]
// 006908ba  ff15b4e48900         call dword ptr [0x89e4b4]
// 006908c0  8d542404             lea edx, [esp + 4]
// 006908c4  52                   push edx
// 006908c5  8d4c2468             lea ecx, [esp + 0x68]
// 006908c9  c784249800000001000000 mov dword ptr [esp + 0x98], 1
// 006908d4  e8378bd7ff           call 0x409410
// 006908d9  6850a79700           push 0x97a750
// 006908de  8d442468             lea eax, [esp + 0x68]
// 006908e2  50                   push eax
// 006908e3  e862910800           call 0x719a4a
// 006908e8  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 006908ef  c6865c01000001       mov byte ptr [esi + 0x15c], 1
// 006908f6  5e                   pop esi
// 006908f7  64890d00000000       mov dword ptr fs:[0], ecx
// 006908fe  81c494000000         add esp, 0x94
// 00690904  c3                   ret 

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
    unsigned char padding[0x15c];
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
