// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
	float x, y, z;
	Vector3() {}
	Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
	Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
	static const Vector3& unitY() { static Vector3 v(0, 1, 0); return v; }
};
}
namespace RBX {
class A0 { public: virtual void a0(); char pad[0x10]; };
class A1 { public: virtual void a1(); };
class A2 { public: virtual void a2(); void* d; };
class A3 { public: virtual void a3(); char pad[8]; };
class Instance : public A0, public A1, public A2, public A3 { public: char ipad[0x8c - 0x2c]; };
class B1 { public: virtual void b1(); char pad[0x1c]; };
class B2 { public: virtual void b2(); char pad[0x74]; };
class B3 { public: virtual void b3(); char pad[0x28]; };
class __declspec(novtable) BodyMover : public Instance, public B1, public B2, public B3 {
public:
	BodyMover(const char* name);
};
class BodyForce : public BodyMover {
	G3D::Vector3 force;
public:
	BodyForce();
	virtual void a0();
};
BodyForce::BodyForce() : BodyMover("BodyForce"), force(G3D::Vector3::unitY())
{
}
}
