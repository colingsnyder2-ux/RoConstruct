// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX {
namespace Math { inline float pi() { return 3.1415927f; } }
class Geometry {
protected:
	G3D::Vector3 gridSize;
public:
	virtual ~Geometry() {}
	virtual float getGridVolume() const;
};
class Ball : public Geometry {
	float realRadius;
public:
	virtual float getGridVolume() const;
};
float Ball::getGridVolume() const
{
	// volume of a sphere = 4/3 * pi * radius^3
	float radius = this->gridSize.x * 0.5f;
	return (4.0f/3.0f) * Math::pi() * radius * radius * radius;
}
}
