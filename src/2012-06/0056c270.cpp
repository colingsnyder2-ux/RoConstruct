// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 0056c1d0  unit: RBX::Network::IdSerializer  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056c1d0
//
// 0056c1d0  64a100000000         mov eax, dword ptr fs:[0]
// 0056c1d6  6aff                 push -1
// 0056c1d8  6889c9ac00           push 0xacc989
// 0056c1dd  50                   push eax
// 0056c1de  8b442414             mov eax, dword ptr [esp + 0x14]
// 0056c1e2  64892500000000       mov dword ptr fs:[0], esp
// 0056c1e9  83ec44               sub esp, 0x44
// 0056c1ec  56                   push esi
// 0056c1ed  8b742458             mov esi, dword ptr [esp + 0x58]
// 0056c1f1  50                   push eax
// 0056c1f2  8bce                 mov ecx, esi
// 0056c1f4  e827feffff           call 0x56c020
// 0056c1f9  84c0                 test al, al
// 0056c1fb  7534                 jne 0x56c231
// 0056c1fd  68c850b700           push 0xb750c8
// 0056c202  8d4c2408             lea ecx, [esp + 8]
// 0056c206  ff154826b200         call dword ptr [0xb22648]
// 0056c20c  8d4c2404             lea ecx, [esp + 4]
// 0056c210  51                   push ecx
// 0056c211  8d4c2424             lea ecx, [esp + 0x24]
// 0056c215  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0056c21d  e87efee9ff           call 0x40c0a0
// 0056c222  686c80cd00           push 0xcd806c
// 0056c227  8d542424             lea edx, [esp + 0x24]
// 0056c22b  52                   push edx
// 0056c22c  e8136f4100           call 0x983144
// 0056c231  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0056c235  8bc6                 mov eax, esi
// 0056c237  5e                   pop esi
// 0056c238  64890d00000000       mov dword ptr fs:[0], ecx
// 0056c23f  83c450               add esp, 0x50
// 0056c242  c3                   ret 
// copied from an identical function in another client (function ??5@YAAAVBitStream@RakNet@@AAV01@AAJ@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
namespace RakNet {
class BitStream {
public:
    template<class T> bool Read(T& var);
};
}
RakNet::BitStream& operator>>(RakNet::BitStream& stream, long& value)
{
    if (!stream.Read(value))
        throw std::runtime_error("BitStream >> RakNet::Time failed");
    return stream;
}