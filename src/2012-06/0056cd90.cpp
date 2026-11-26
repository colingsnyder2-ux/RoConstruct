// from server: 100% by Xemicl
// roc 2012-06 0056cd90  unit: RBX::Network::IdSerializer  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056cd90
//
// 0056cd90  56                   push esi
// 0056cd91  8b742408             mov esi, dword ptr [esp + 8]
// 0056cd95  57                   push edi
// 0056cd96  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0056cd9a  d907                 fld dword ptr [edi]
// 0056cd9c  51                   push ecx
// 0056cd9d  d91c24               fstp dword ptr [esp]
// 0056cda0  56                   push esi
// 0056cda1  e8eaf6ffff           call 0x56c490
// 0056cda6  d94704               fld dword ptr [edi + 4]
// 0056cda9  83c404               add esp, 4
// 0056cdac  d91c24               fstp dword ptr [esp]
// 0056cdaf  56                   push esi
// 0056cdb0  e8dbf6ffff           call 0x56c490
// 0056cdb5  d94708               fld dword ptr [edi + 8]
// 0056cdb8  83c404               add esp, 4
// 0056cdbb  d91c24               fstp dword ptr [esp]
// 0056cdbe  56                   push esi
// 0056cdbf  e8ccf6ffff           call 0x56c490
// 0056cdc4  83c408               add esp, 8
// 0056cdc7  5f                   pop edi
// 0056cdc8  8bc6                 mov eax, esi
// 0056cdca  5e                   pop esi
// 0056cdcb  c3                   ret 
// copied from an identical function in another client (function ??6Network@RBX@@YAAAVBitStream@RakNet@@AAV23@ABVVector3@G3D@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RakNet { class BitStream { int bits; }; }
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX { namespace Network {
RakNet::BitStream& operator<<(RakNet::BitStream& stream, float value);
RakNet::BitStream& operator<<(RakNet::BitStream& stream, const G3D::Vector3& value)
{
    stream << value.x;
    stream << value.y;
    stream << value.z;
    return stream;
}
} }