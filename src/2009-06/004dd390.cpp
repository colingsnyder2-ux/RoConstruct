// from server: 100% by EspClaude
// from server: 85% by EspClaude
// roc 2009-06 004dd390  unit: RBX::Network::ConcurrentRakPeer::PacketJob  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004dd390
//
// 004dd390  64a100000000         mov eax, dword ptr fs:[0]
// 004dd396  6aff                 push -1
// 004dd398  6849b88500           push 0x85b849
// 004dd39d  50                   push eax
// 004dd39e  8b442414             mov eax, dword ptr [esp + 0x14]
// 004dd3a2  64892500000000       mov dword ptr fs:[0], esp
// 004dd3a9  83ec44               sub esp, 0x44
// 004dd3ac  56                   push esi
// 004dd3ad  8b742458             mov esi, dword ptr [esp + 0x58]
// 004dd3b1  50                   push eax
// 004dd3b2  8bce                 mov ecx, esi
// 004dd3b4  e8a7f7ffff           call 0x4dcb60
// 004dd3b9  84c0                 test al, al
// 004dd3bb  7534                 jne 0x4dd3f1
// 004dd3bd  68fc658c00           push 0x8c65fc
// 004dd3c2  8d4c2408             lea ecx, [esp + 8]
// 004dd3c6  ff15b4e48900         call dword ptr [0x89e4b4]
// 004dd3cc  8d4c2404             lea ecx, [esp + 4]
// 004dd3d0  51                   push ecx
// 004dd3d1  8d4c2424             lea ecx, [esp + 0x24]
// 004dd3d5  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004dd3dd  e82ec0f2ff           call 0x409410
// 004dd3e2  6850a79700           push 0x97a750
// 004dd3e7  8d542424             lea edx, [esp + 0x24]
// 004dd3eb  52                   push edx
// 004dd3ec  e859c62300           call 0x719a4a
// 004dd3f1  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004dd3f5  8bc6                 mov eax, esi
// 004dd3f7  5e                   pop esi
// 004dd3f8  64890d00000000       mov dword ptr fs:[0], ecx
// 004dd3ff  83c450               add esp, 0x50
// 004dd402  c3                   ret 

// from server: 100% by king_originala
// roc 2008-06 004a6430  unit: RBX::VHint::?$FactoryProduct::Creator  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a6430
//
// 004a6430  64a100000000         mov eax, dword ptr fs:[0]
// 004a6436  6aff                 push -1
// 004a6438  68b9fe7c00           push 0x7cfeb9
// 004a643d  50                   push eax
// 004a643e  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a6442  64892500000000       mov dword ptr fs:[0], esp
// 004a6449  83ec44               sub esp, 0x44
// 004a644c  56                   push esi
// 004a644d  8b742458             mov esi, dword ptr [esp + 0x58]
// 004a6451  6a01                 push 1
// 004a6453  6a20                 push 0x20
// 004a6455  50                   push eax
// 004a6456  8bce                 mov ecx, esi
// 004a6458  e8b3edffff           call 0x4a5210
// 004a645d  84c0                 test al, al
// 004a645f  7534                 jne 0x4a6495
// 004a6461  68f43c8200           push 0x823cf4
// 004a6466  8d4c2408             lea ecx, [esp + 8]
// 004a646a  ff1558248000         call dword ptr [0x802458]
// 004a6470  8d4c2404             lea ecx, [esp + 4]
// 004a6474  51                   push ecx
// 004a6475  8d4c2424             lea ecx, [esp + 0x24]
// 004a6479  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004a6481  e8ca38f6ff           call 0x409d50
// 004a6486  68c81b8d00           push 0x8d1bc8
// 004a648b  8d542424             lea edx, [esp + 0x24]
// 004a648f  52                   push edx
// 004a6490  e8f7b01f00           call 0x6a158c
// 004a6495  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004a6499  8bc6                 mov eax, esi
// 004a649b  5e                   pop esi
// 004a649c  64890d00000000       mov dword ptr fs:[0], ecx
// 004a64a3  83c450               add esp, 0x50
// 004a64a6  c3                   ret 

struct String;
typedef void (__thiscall *StringConstructor)(String *, const char *);
extern StringConstructor constructString;

struct String {
    unsigned char storage[28];
    String(const char *);
    ~String();
};

inline String::String(const char *text)
{
    constructString(this, text);
}

struct ReadError {
    unsigned char storage[40];
    ReadError(const String &);
    ReadError(const ReadError &);
    ~ReadError();
};

struct BitStream {
    bool read(float &);
};

BitStream &__cdecl readFloat(BitStream &stream, float &value)
{
    if (!stream.read(value)) {
        String message("BitStream >> float failed");
        throw ReadError(message);
    }
    return stream;
}
