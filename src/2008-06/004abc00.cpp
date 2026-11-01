// from server: 100% by colin
// from server: 99% by king_originala
// roc 2008-06 004abc00  unit: RBX::Network::Replicator  size: 279 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004abc00
//
// 004abc00  6aff                 push -1
// 004abc02  68f6827c00           push 0x7c82f6
// 004abc07  64a100000000         mov eax, dword ptr fs:[0]
// 004abc0d  50                   push eax
// 004abc0e  64892500000000       mov dword ptr fs:[0], esp
// 004abc15  81ec34010000         sub esp, 0x134
// 004abc1b  8b842444010000       mov eax, dword ptr [esp + 0x144]
// 004abc22  8b5014               mov edx, dword ptr [eax + 0x14]
// 004abc25  56                   push esi
// 004abc26  8bf1                 mov esi, ecx
// 004abc28  8b480c               mov ecx, dword ptr [eax + 0xc]
// 004abc2b  6a00                 push 0
// 004abc2d  51                   push ecx
// 004abc2e  52                   push edx
// 004abc2f  8d4c2430             lea ecx, [esp + 0x30]
// 004abc33  e8e894ffff           call 0x4a5120
// 004abc38  6a08                 push 8
// 004abc3a  8d4c2428             lea ecx, [esp + 0x28]
// 004abc3e  c784244401000000000000 mov dword ptr [esp + 0x144], 0
// 004abc49  e82298ffff           call 0x4a5470
// 004abc4e  8d442408             lea eax, [esp + 8]
// 004abc52  50                   push eax
// 004abc53  8d4c2428             lea ecx, [esp + 0x28]
// 004abc57  51                   push ecx
// 004abc58  e873a6ffff           call 0x4a62d0
// 004abc5d  8d54240f             lea edx, [esp + 0xf]
// 004abc61  52                   push edx
// 004abc62  8d442430             lea eax, [esp + 0x30]
// 004abc66  50                   push eax
// 004abc67  e814a7ffff           call 0x4a6380
// 004abc6c  83c410               add esp, 0x10
// 004abc6f  807c240750           cmp byte ptr [esp + 7], 0x50
// 004abc74  7431                 je 0x4abca7
// 004abc76  8d4c2424             lea ecx, [esp + 0x24]
// 004abc7a  c7842440010000ffffffff mov dword ptr [esp + 0x140], 0xffffffff
// 004abc85  e81695ffff           call 0x4a51a0
// 004abc8a  b801000000           mov eax, 1
// 004abc8f  5e                   pop esi
// 004abc90  8b8c2434010000       mov ecx, dword ptr [esp + 0x134]
// 004abc97  64890d00000000       mov dword ptr fs:[0], ecx
// 004abc9e  81c440010000         add esp, 0x140
// 004abca4  c20400               ret 4
// 004abca7  8b862c2d0000         mov eax, dword ptr [esi + 0x2d2c]
// 004abcad  6a00                 push 0
// 004abcaf  50                   push eax
// 004abcb0  8d4c2414             lea ecx, [esp + 0x14]
// 004abcb4  e8c7821100           call 0x5c3f80
// 004abcb9  8b442408             mov eax, dword ptr [esp + 8]
// 004abcbd  8b8e842b0000         mov ecx, dword ptr [esi + 0x2b84]
// 004abcc3  8b11                 mov edx, dword ptr [ecx]
// 004abcc5  8b5208               mov edx, dword ptr [edx + 8]
// 004abcc8  50                   push eax
// 004abcc9  8d442428             lea eax, [esp + 0x28]
// 004abccd  50                   push eax
// 004abcce  c684244801000001     mov byte ptr [esp + 0x148], 1
// 004abcd6  ffd2                 call edx
// 004abcd8  8d4c240c             lea ecx, [esp + 0xc]
// 004abcdc  c684244001000000     mov byte ptr [esp + 0x140], 0
// 004abce4  e8e7851100           call 0x5c42d0
// 004abce9  8d4c2424             lea ecx, [esp + 0x24]
// 004abced  c7842440010000ffffffff mov dword ptr [esp + 0x140], 0xffffffff
// 004abcf8  e8a394ffff           call 0x4a51a0
// 004abcfd  8b8c2438010000       mov ecx, dword ptr [esp + 0x138]
// 004abd04  33c0                 xor eax, eax
// 004abd06  5e                   pop esi
// 004abd07  64890d00000000       mov dword ptr fs:[0], ecx
// 004abd0e  81c440010000         add esp, 0x140
// 004abd14  c20400               ret 4

struct Packet {
    unsigned char reserved0[12];
    unsigned int length;
    unsigned int reserved1;
    unsigned char* data;
};

struct BitStream {
    unsigned int bitsUsed;
    unsigned int bitsAllocated;
    unsigned int readOffset;
    unsigned char* data;
    bool ownsData;
    unsigned char buffer[256];

    BitStream(unsigned char*, unsigned int, bool);
    ~BitStream();
    void IgnoreBits(int);
};

extern bool __cdecl ReadUnsigned(BitStream*, unsigned int*);
extern bool __cdecl ReadByte(BitStream*, unsigned char*);

struct Guard {
    unsigned char storage[24];

    Guard(void*, int);
    ~Guard();
};

struct Receiver {
    virtual void slot0();
    virtual void slot1();
    virtual void receive(BitStream*, unsigned int);
};

struct S {
    unsigned char reserved0[0x2b84];
    Receiver* receiver;
    unsigned char reserved1[0x2d2c - 0x2b88];
    void* guardObject;

    int process(Packet*);
};

int S::process(Packet* packet)
{
    BitStream stream(packet->data, packet->length, false);
    stream.IgnoreBits(8);

    unsigned int value;
    unsigned char type;
    ReadUnsigned(&stream, &value);
    ReadByte(&stream, &type);

    if (type != 0x50)
        return 1;

    void* object = guardObject;
    Guard guard(object, 0);
    receiver->receive(&stream, value);
    return 0;
}
