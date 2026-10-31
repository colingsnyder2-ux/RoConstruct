// from server: 85% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a6250  unit: RBX::VHint::?$FactoryProduct::Creator  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a6250
//
// 004a6250  64a100000000         mov eax, dword ptr fs:[0]
// 004a6256  6aff                 push -1
// 004a6258  68b9fe7c00           push 0x7cfeb9
// 004a625d  50                   push eax
// 004a625e  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a6262  64892500000000       mov dword ptr fs:[0], esp
// 004a6269  83ec44               sub esp, 0x44
// 004a626c  56                   push esi
// 004a626d  8b742458             mov esi, dword ptr [esp + 0x58]
// 004a6271  6a01                 push 1
// 004a6273  6a20                 push 0x20
// 004a6275  50                   push eax
// 004a6276  8bce                 mov ecx, esi
// 004a6278  e893efffff           call 0x4a5210
// 004a627d  84c0                 test al, al
// 004a627f  7534                 jne 0x4a62b5
// 004a6281  689c3c8200           push 0x823c9c
// 004a6286  8d4c2408             lea ecx, [esp + 8]
// 004a628a  ff1558248000         call dword ptr [0x802458]
// 004a6290  8d4c2404             lea ecx, [esp + 4]
// 004a6294  51                   push ecx
// 004a6295  8d4c2424             lea ecx, [esp + 0x24]
// 004a6299  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004a62a1  e8aa3af6ff           call 0x409d50
// 004a62a6  68c81b8d00           push 0x8d1bc8
// 004a62ab  8d542424             lea edx, [esp + 0x24]
// 004a62af  52                   push edx
// 004a62b0  e8d7b21f00           call 0x6a158c
// 004a62b5  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004a62b9  8bc6                 mov eax, esi
// 004a62bb  5e                   pop esi
// 004a62bc  64890d00000000       mov dword ptr fs:[0], ecx
// 004a62c3  83c450               add esp, 0x50
// 004a62c6  c3                   ret 

struct String;
extern void (__thiscall *string_construct)(String *, const char *);

struct String {
    unsigned char data[28];
    String(const char *text) { string_construct(this, text); }
    ~String();
};

struct RuntimeError {
    unsigned char data[40];
    RuntimeError(const String &message);
    RuntimeError(const RuntimeError &other);
    ~RuntimeError();
};

struct BitStream {
    bool readBits(unsigned char *destination, int count, bool align);
};

BitStream &readInt(BitStream &stream, int &value)
{
    if (!stream.readBits(reinterpret_cast<unsigned char *>(&value), 32, true))
        throw RuntimeError(String("BitStream >> int failed"));
    return stream;
}
