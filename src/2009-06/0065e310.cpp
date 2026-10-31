// from server: 100% by EspClaude
// from server: 99% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_99f08710f1c4acd3.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
#include <G3D/Ray.h>
namespace RBX {
class Part;
class HitTest {
public:
    static bool hitTest(const Part& part, G3D::Ray& rayInPartCoords, G3D::Vector3& hitPointInPartCoords, float gridToReal);
};
class Primitive {
public:
    __declspec(noinline) const G3D::CoordinateFrame& getCoordinateFrame() const;
};
template<class T> class scoped_ptr { public: T* px; T* operator->() const { return px; } };
class PartInstance {
public:
    virtual bool hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint);
    const Part& getPart() const;
    char pad[0x114];
    scoped_ptr<Primitive> primitive;
};
	bool PartInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)
	{
		const G3D::CoordinateFrame& cframe = primitive->getCoordinateFrame();
		G3D::Ray rayInPartCoords = cframe.toObjectSpace(worldRay);
		G3D::Vector3 hitPointInPartCoords;

		if (HitTest::hitTest(getPart(), rayInPartCoords, hitPointInPartCoords, 1.0f))
		{
			const G3D::CoordinateFrame& cframe = primitive->getCoordinateFrame();
			worldHitPoint = cframe.pointToWorldSpace(hitPointInPartCoords);
			return true;
		}
		else
		{
			return false;
		}
	}
}
