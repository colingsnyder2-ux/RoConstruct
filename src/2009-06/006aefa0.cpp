// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D {
class Vector3 {
public:
	float x, y, z;
	Vector3() : x(0), y(0), z(0) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	Vector3& operator=(const Vector3& r) { x = r.x; y = r.y; z = r.z; return *this; }
	static const Vector3& zero() { static Vector3 v(0, 0, 0); return v; }
};
}
namespace RBX {
class KernelIndex {
public:
	int kernelIndex;
	KernelIndex() : kernelIndex(-1) {}
};
class Connector : public KernelIndex {
public:
	virtual ~Connector() {}
	virtual void computeForce(bool throttling) = 0;
};
template<class T> class Allocator {};
class GeoPair {
public:
	GeoPair() throw();
	int g[9];
};
class ContactConnector : public Connector, public Allocator<ContactConnector> {
protected:
	GeoPair geoPair;
	float k;
	float kFriction;
	float kNeg;
	float firstApproach;
	float threshold;
	float forceMagLast;
	G3D::Vector3 frictionOffset;
public:
	ContactConnector(float _k, float _kNeg, float _kFriction);
	virtual void computeForce(bool throttling);
};
ContactConnector::ContactConnector(float _k, float _kNeg, float _kFriction)
	: geoPair()
{
	this->k = _k;
	this->kNeg = _kNeg;
	this->kFriction = _kFriction;
	this->frictionOffset = G3D::Vector3::zero();
	this->firstApproach = 0;
	this->threshold = 0;
	this->forceMagLast = 0;
}
}
