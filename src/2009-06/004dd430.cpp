// from server: 85% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a64e0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a64e0
//
// 004a64e0  64a100000000         mov eax, dword ptr fs:[0]
// 004a64e6  6aff                 push -1
// 004a64e8  68b9fe7c00           push 0x7cfeb9
// 004a64ed  50                   push eax
// 004a64ee  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a64f2  64892500000000       mov dword ptr fs:[0], esp
// 004a64f9  83ec44               sub esp, 0x44
// 004a64fc  56                   push esi
// 004a64fd  8b742458             mov esi, dword ptr [esp + 0x58]
// 004a6501  6a01                 push 1
// 004a6503  6a40                 push 0x40
// 004a6505  50                   push eax
// 004a6506  8bce                 mov ecx, esi
// 004a6508  e803edffff           call 0x4a5210
// 004a650d  84c0                 test al, al
// 004a650f  7534                 jne 0x4a6545
// 004a6511  68103d8200           push 0x823d10
// 004a6516  8d4c2408             lea ecx, [esp + 8]
// 004a651a  ff1558248000         call dword ptr [0x802458]
// 004a6520  8d4c2404             lea ecx, [esp + 4]
// 004a6524  51                   push ecx
// 004a6525  8d4c2424             lea ecx, [esp + 0x24]
// 004a6529  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004a6531  e81a38f6ff           call 0x409d50
// 004a6536  68c81b8d00           push 0x8d1bc8
// 004a653b  8d542424             lea edx, [esp + 0x24]
// 004a653f  52                   push edx
// 004a6540  e847b01f00           call 0x6a158c
// 004a6545  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004a6549  8bc6                 mov eax, esi
// 004a654b  5e                   pop esi
// 004a654c  64890d00000000       mov dword ptr fs:[0], ecx
// 004a6553  83c450               add esp, 0x50
// 004a6556  c3                   ret 

struct String {
    unsigned char storage[28];
    String(const char *);
    ~String();
};

typedef void (__thiscall *StringConstructor)(String *, const char *);
extern StringConstructor stringConstructor;

__forceinline String::String(const char *text)
{
    stringConstructor(this, text);
}

struct Error {
    unsigned char storage[40];
    Error(const String &);
    Error(const Error &);
    ~Error();
};

struct Stream {
    bool readBits(void *, int, bool);
};

Stream &readDouble(Stream &stream, double &value)
{
    if (!stream.readBits(&value, 64, true)) {
        String message("BitStream >> double failed");
        throw Error(message);
    }
    return stream;
}
