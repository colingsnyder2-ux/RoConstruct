// from server: 100% by Xemicl
// roc 2012-06 0091e6b0  unit: RBX::Motor6DJoint  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0091e6b0
//
// 0091e6b0  83ec78               sub esp, 0x78
// 0091e6b3  56                   push esi
// 0091e6b4  6a00                 push 0
// 0091e6b6  8d442450             lea eax, [esp + 0x50]
// 0091e6ba  50                   push eax
// 0091e6bb  8bf1                 mov esi, ecx
// 0091e6bd  e84e22fdff           call 0x8f0910
// 0091e6c2  6a01                 push 1
// 0091e6c4  8d4c2420             lea ecx, [esp + 0x20]
// 0091e6c8  51                   push ecx
// 0091e6c9  8bce                 mov ecx, esi
// 0091e6cb  e84022fdff           call 0x8f0910
// 0091e6d0  d9057cdab700         fld dword ptr [0xb7da7c]
// 0091e6d6  51                   push ecx
// 0091e6d7  8d542444             lea edx, [esp + 0x44]
// 0091e6db  d91c24               fstp dword ptr [esp]
// 0091e6de  52                   push edx
// 0091e6df  8d442478             lea eax, [esp + 0x78]
// 0091e6e3  50                   push eax
// 0091e6e4  e807eae9ff           call 0x7bd0f0
// 0091e6e9  83c40c               add esp, 0xc
// 0091e6ec  5e                   pop esi
// 0091e6ed  84c0                 test al, al
// 0091e6ef  743e                 je 0x91e72f
// 0091e6f1  d9057cdab700         fld dword ptr [0xb7da7c]
// 0091e6f7  51                   push ecx
// 0091e6f8  d91c24               fstp dword ptr [esp]
// 0091e6fb  6a02                 push 2
// 0091e6fd  8d4c2408             lea ecx, [esp + 8]
// 0091e701  51                   push ecx
// 0091e702  8d4c2424             lea ecx, [esp + 0x24]
// 0091e706  e8d5dbd0ff           call 0x62c2e0
// 0091e70b  50                   push eax
// 0091e70c  6a02                 push 2
// 0091e70e  8d542418             lea edx, [esp + 0x18]
// 0091e712  52                   push edx
// 0091e713  8d4c2458             lea ecx, [esp + 0x58]
// 0091e717  e8c4dbd0ff           call 0x62c2e0
// 0091e71c  50                   push eax
// 0091e71d  e8cee9e9ff           call 0x7bd0f0
// 0091e722  83c40c               add esp, 0xc
// 0091e725  84c0                 test al, al
// 0091e727  7406                 je 0x91e72f
// 0091e729  b001                 mov al, 1
// 0091e72b  83c478               add esp, 0x78
// 0091e72e  c3                   ret 
// 0091e72f  32c0                 xor al, al
// 0091e731  83c478               add esp, 0x78
// 0091e734  c3                   ret 
// copied from an identical function in another client (function ?isAligned@MotorJoint@RBX@@QAE_NXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z; };
class Matrix3 { public: float elt[3][3]; Vector3 getColumn(int iCol) const; };
class CoordinateFrame { public: Matrix3 rotation; Vector3 translation; };
}
using namespace G3D;
namespace RBX {
class Math { public: static bool fuzzyEq(const Vector3& v0, const Vector3& v1, float epsilon); };
class MotorJoint {
public:
    CoordinateFrame getJointWorldCoord(int i);
    bool isAligned();
};
bool MotorJoint::isAligned()
{
    CoordinateFrame baseWorld = getJointWorldCoord(0);
    CoordinateFrame rotorWorld = getJointWorldCoord(1);
    if (Math::fuzzyEq(baseWorld.translation, rotorWorld.translation, 1.0e-5f) &&
        Math::fuzzyEq(baseWorld.rotation.getColumn(2), rotorWorld.rotation.getColumn(2), 1.0e-5f))
        return true;
    return false;
}
}