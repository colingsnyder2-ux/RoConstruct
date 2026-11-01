// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
namespace G3D {
class Vector3 {
public:
	float x, y, z;
	Vector3() {}
	Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {}
	Vector3& operator=(const Vector3& o) { x = o.x; y = o.y; z = o.z; return *this; }
};
}
namespace RBX {
struct QuadVolumeParams {
	G3D::Vector3 a;
	int i;
	G3D::Vector3 b;
	float d, e;
};
struct BrickBuilderStatics : public QuadVolumeParams {
	float f2;
	int i2;
	float f2c;
	int i30, i34, i38;
	float f3c;
	bool flag;
	G3D::Vector3 g;
	float h, k;
};
class QuadVolumeBuilder {
public:
	__forceinline QuadVolumeBuilder(int owner, const BrickBuilderStatics& p) : owner(owner), params(p), f(p.f2) {}
	virtual ~QuadVolumeBuilder() {}
	int owner;
	QuadVolumeParams params;
	float f;
};
class BrickBuilder : public QuadVolumeBuilder, public BrickBuilderStatics {
public:
	BrickBuilder(int owner, const BrickBuilderStatics& s);
};
BrickBuilder::BrickBuilder(int owner, const BrickBuilderStatics& s) : QuadVolumeBuilder(owner, s)
{
	static_cast<BrickBuilderStatics&>(*this) = s;
}
}
