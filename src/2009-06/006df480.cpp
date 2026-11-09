// from server: 100% by EspClaude
// from server: 79% by EspClaude
// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_eae2e8304ea40792.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/Ray.h>
#include <G3D/g3dmath.h>
#include <vector>
namespace RBX {
class Primitive;
class Instance { public: virtual ~Instance(); };
class HitTestFilter { public: enum Result { a }; virtual Result filterResult(const Primitive*) const = 0; };
class ContactManager {
public:
	static bool ignoreBool;
	Primitive* getHit(const G3D::Ray& worldRay, const std::vector<Primitive const*>* ignorePrim, const HitTestFilter* filter, G3D::Vector3& hitPoint, bool& inside = ignoreBool) const;
};
class World { char pad[0xb0]; ContactManager* contactManager; public: ContactManager& getContactManager() { return *contactManager; } };
class Workspace { public: static World* getWorldIfInWorkspace(const Instance* context); };
class __declspec(novtable) ILocation { public: virtual const G3D::CoordinateFrame getLocation() const = 0; };
class __declspec(novtable) CameraSubject : public virtual ILocation {
public:
	virtual ~CameraSubject() {}
	virtual void onCameraNear(float distance) {}
	virtual void getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives) {}
	virtual float getLerp() const { return 0.9f; }
	ContactManager* getContactManager()
	{
		if (Instance* instance = dynamic_cast<Instance*>(this))
			if (World* world = Workspace::getWorldIfInWorkspace(instance))
				return &world->getContactManager();
		return NULL;
	}
};
class __declspec(novtable) ICharacterSubject : public CameraSubject {
	static G3D::CoordinateFrame getFocusLookingAtGoal(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal);
	bool testOcclusion(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal, float& distance);
public:
	virtual void getIgnorePrims(std::vector<const Primitive*>&);
};
class FilterCharacterOcclusion: public HitTestFilter {public: FilterCharacterOcclusion(int); virtual Result filterResult(const Primitive*) const;};
	bool ICharacterSubject::testOcclusion(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal, float& distance)
	{
		ContactManager* contactManager = getContactManager();
		if (!contactManager) return false;
		{
			std::vector<const Primitive*> ignorePrims;
			getIgnorePrims(ignorePrims);

			G3D::CoordinateFrame manLookCamera = getFocusLookingAtGoal(cameraFocus, cameraGoal);
			G3D::Vector3 pointOnMan = manLookCamera.leftVector();

			int hits = 0;
			float originalDistance = (cameraGoal.translation - cameraFocus.translation).magnitude();
			distance = originalDistance;

			FilterCharacterOcclusion filter(0);
			for (int x = -2; x <= 2; x += 2)
			{
				G3D::Vector3 r = manLookCamera.translation + (float)x * pointOnMan;
				G3D::Ray manToCamera = G3D::Ray::fromOriginAndDirection(r, cameraGoal.translation - r);

				G3D::Vector3 hitPoint;
				if (contactManager->getHit(manToCamera, &ignorePrims, &filter, hitPoint))
				{
					hits++;
					float thisDistance = (hitPoint - r).magnitude();
					distance = G3D::min(distance, thisDistance);
				}
			}

			if (hits > 1)
			{
				distance -= 1.0f;
				distance = G3D::max(distance, 0.5f);
				distance = G3D::min(distance, 1000.0f);
				return true;
			}
			else
			{
				distance = originalDistance;
				return false;
			}
		}

	}


}
