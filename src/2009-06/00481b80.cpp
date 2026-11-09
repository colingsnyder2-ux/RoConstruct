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
