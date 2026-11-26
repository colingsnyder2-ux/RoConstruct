// from server: 100% by Xemicl
// roc 2012-06 0056c5d0  unit: RBX::Network::IdSerializer  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056c5d0
//
// 0056c5d0  64a100000000         mov eax, dword ptr fs:[0]
// 0056c5d6  6aff                 push -1
// 0056c5d8  6889c9ac00           push 0xacc989
// 0056c5dd  50                   push eax
// 0056c5de  8b442414             mov eax, dword ptr [esp + 0x14]
// 0056c5e2  64892500000000       mov dword ptr fs:[0], esp
// 0056c5e9  83ec44               sub esp, 0x44
// 0056c5ec  56                   push esi
// 0056c5ed  8b742458             mov esi, dword ptr [esp + 0x58]
// 0056c5f1  50                   push eax
// 0056c5f2  8bce                 mov ecx, esi
// 0056c5f4  e887faffff           call 0x56c080
// 0056c5f9  84c0                 test al, al
// 0056c5fb  7534                 jne 0x56c631
// 0056c5fd  687c51b700           push 0xb7517c
// 0056c602  8d4c2408             lea ecx, [esp + 8]
// 0056c606  ff154826b200         call dword ptr [0xb22648]
// 0056c60c  8d4c2404             lea ecx, [esp + 4]
// 0056c610  51                   push ecx
// 0056c611  8d4c2424             lea ecx, [esp + 0x24]
// 0056c615  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0056c61d  e87efae9ff           call 0x40c0a0
// 0056c622  686c80cd00           push 0xcd806c
// 0056c627  8d542424             lea edx, [esp + 0x24]
// 0056c62b  52                   push edx
// 0056c62c  e8136b4100           call 0x983144
// 0056c631  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0056c635  8bc6                 mov eax, esi
// 0056c637  5e                   pop esi
// 0056c638  64890d00000000       mov dword ptr fs:[0], ecx
// 0056c63f  83c450               add esp, 0x50
// 0056c642  c3                   ret 
// copied from an identical function in another client (function ?readDouble@ns_ROCX00001f@@YAAAUStream@1@AAU21@AAN@Z)

namespace ns_ROCX00001f {
// from server: 85% by EspClaude
// roc 2009-06 004dd430  unit: RBX::Network::ConcurrentRakPeer::PacketJob  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004dd430
//
// 004dd430  64a100000000         mov eax, dword ptr fs:[0]
// 004dd436  6aff                 push -1
// 004dd438  6849b88500           push 0x85b849
// 004dd43d  50                   push eax
// 004dd43e  8b442414             mov eax, dword ptr [esp + 0x14]
// 004dd442  64892500000000       mov dword ptr fs:[0], esp
// 004dd449  83ec44               sub esp, 0x44
// 004dd44c  56                   push esi
// 004dd44d  8b742458             mov esi, dword ptr [esp + 0x58]
// 004dd451  50                   push eax
// 004dd452  8bce                 mov ecx, esi
// 004dd454  e8c7f7ffff           call 0x4dcc20
// 004dd459  84c0                 test al, al
// 004dd45b  7534                 jne 0x4dd491
// 004dd45d  6818668c00           push 0x8c6618
// 004dd462  8d4c2408             lea ecx, [esp + 8]
// 004dd466  ff15b4e48900         call dword ptr [0x89e4b4]
// 004dd46c  8d4c2404             lea ecx, [esp + 4]
// 004dd470  51                   push ecx
// 004dd471  8d4c2424             lea ecx, [esp + 0x24]
// 004dd475  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004dd47d  e88ebff2ff           call 0x409410
// 004dd482  6850a79700           push 0x97a750
// 004dd487  8d542424             lea edx, [esp + 0x24]
// 004dd48b  52                   push edx
// 004dd48c  e8b9c52300           call 0x719a4a
// 004dd491  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 004dd495  8bc6                 mov eax, esi
// 004dd497  5e                   pop esi
// 004dd498  64890d00000000       mov dword ptr fs:[0], ecx
// 004dd49f  83c450               add esp, 0x50
// 004dd4a2  c3                   ret 

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
    bool read(double &);
};

Stream &readDouble(Stream &stream, double &value)
{
    if (!stream.read(value)) {
        String message("BitStream >> double failed");
        throw Error(message);
    }
    return stream;
}
}
