// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
	float x, y, z;
	Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};
}
namespace RBX {
class Pair {
public:
	const G3D::Vector3& getPosition() const;
	G3D::Vector3 position() const;
};
G3D::Vector3 Pair::position() const
{
	return getPosition();
}
}
