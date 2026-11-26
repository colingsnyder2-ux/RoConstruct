// from server: 100% by Xemicl
// roc 2012-06 00506d90  unit: RBX::VForceField::?$FactoryProduct::Creator  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00506d90
//
// 00506d90  ba01000000           mov edx, 1
// 00506d95  8bc1                 mov eax, ecx
// 00506d97  841500dde100         test byte ptr [0xe1dd00], dl
// 00506d9d  751d                 jne 0x506dbc
// 00506d9f  091500dde100         or dword ptr [0xe1dd00], edx
// 00506da5  b9ffffff7f           mov ecx, 0x7fffffff
// 00506daa  890df4dce100         mov dword ptr [0xe1dcf4], ecx
// 00506db0  890df8dce100         mov dword ptr [0xe1dcf8], ecx
// 00506db6  890dfcdce100         mov dword ptr [0xe1dcfc], ecx
// 00506dbc  8b0df4dce100         mov ecx, dword ptr [0xe1dcf4]
// 00506dc2  8908                 mov dword ptr [eax], ecx
// 00506dc4  8b0df8dce100         mov ecx, dword ptr [0xe1dcf8]
// 00506dca  894804               mov dword ptr [eax + 4], ecx
// 00506dcd  8b0dfcdce100         mov ecx, dword ptr [0xe1dcfc]
// 00506dd3  894808               mov dword ptr [eax + 8], ecx
// 00506dd6  841510dde100         test byte ptr [0xe1dd10], dl
// 00506ddc  751d                 jne 0x506dfb
// 00506dde  091510dde100         or dword ptr [0xe1dd10], edx
// 00506de4  b900000080           mov ecx, 0x80000000
// 00506de9  890d04dde100         mov dword ptr [0xe1dd04], ecx
// 00506def  890d08dde100         mov dword ptr [0xe1dd08], ecx
// 00506df5  890d0cdde100         mov dword ptr [0xe1dd0c], ecx
// 00506dfb  8b1504dde100         mov edx, dword ptr [0xe1dd04]
// 00506e01  89500c               mov dword ptr [eax + 0xc], edx
// 00506e04  8b0d08dde100         mov ecx, dword ptr [0xe1dd08]
// 00506e0a  894810               mov dword ptr [eax + 0x10], ecx
// 00506e0d  8b150cdde100         mov edx, dword ptr [0xe1dd0c]
// 00506e13  895014               mov dword ptr [eax + 0x14], edx
// 00506e16  c3                   ret 
// copied from an identical function in another client (function ??0Extents3int32@RBX@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3int32 {
public:
	int x, y, z;
	Vector3int32(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {}
	static const Vector3int32& maxValue() { static const Vector3int32 v(0x7fffffff, 0x7fffffff, 0x7fffffff); return v; }
	static const Vector3int32& minValue() { static const Vector3int32 v((int)0x80000000, (int)0x80000000, (int)0x80000000); return v; }
};
}
namespace RBX {
class Extents3int32 {
public:
	G3D::Vector3int32 low, high;
	Extents3int32();
};
Extents3int32::Extents3int32() : low(G3D::Vector3int32::maxValue()), high(G3D::Vector3int32::minValue()) {}
}