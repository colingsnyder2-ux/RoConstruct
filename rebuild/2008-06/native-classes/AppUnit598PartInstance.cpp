// 2008-06 native recovery (inactive): v8datamodel/PartInstance.cpp rows of the application range 00598000..0059c000.
// Built by tests/record_native_app_unit598.py against the committed read-only
// native-headers/part-embedded/v8datamodel/PartInstance.h (Primitive embedded at +0x228, ahead of native-headers on
// the include path) with document-swap flags, VS2008 RTM 21022, /fp:fast and /U_RELEASEASSERT (the 2008 ~IMoving
// assert is compiled out: ~PartInstance 0059b970 has no iMovingManager test). Bodies follow the donor
// tools/rbxgs PartInstance.cpp shape; every offset comes from the shared native headers, none is invented here.
// Each definition names the original row it reproduces; the recorder verifies bytes and every call/data target.
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"
#include "AppDraw/Draw.h"
#include "AppDraw/HitTest.h"
#include "tool/Dragger.h"
#include "util/Math.h"

namespace RBX
{
	// 0059b970: the vtable stores, the ContentId (+0x3c8) / Primitive (+0x228) / IRenderable (+0x1cc) / Notifier member
	// teardown and the tail call of ~DescribedCreatable<PartInstance, PVInstance, sPart> (00598df0 / 00599ea0).
	PartInstance::~PartInstance()
	{
	}

	// 00598de0
	Surfaces& PartInstance::getSurfaces()
	{
		return surfaces;
	}

	// 005995f0
	bool PartInstance::nonNullInWorkspace(boost::shared_ptr<PartInstance> part)
	{
		return part.get() && part->myWorld;
	}

	// 00598c70 (BoundFuncDesc "BreakJoints" initializer 007f44be)
	void PartInstance::destroyJoints()
	{
		World* world = Workspace::getWorldIfInWorkspace(this);
		if (world)
			world->destroyJoints(&primitive);
	}

	// 00598c90 (BoundFuncDesc "MakeJoints" initializer 007f44fe)
	void PartInstance::join()
	{
		World* world = Workspace::getWorldIfInWorkspace(this);
		if (world)
			world->createJoints(&primitive);
	}

	// 00599640: SurfaceType 6 / 7 / 8 tests through Surfaces::operator[] 005ecc00 and Surface::getSurfaceType 005f1290
	bool PartInstance::computeSurfacesNeedAdorn() const
	{
		for (int i = 0; i < 6; i++)
		{
			Surface& current = surfaces[(NormalId)i];
			if (current.getSurfaceType() == ROTATE || current.getSurfaceType() == ROTATE_P || current.getSurfaceType() == ROTATE_V)
				return true;
		}
		return false;
	}

	// 00599730: parentState * *legacyOffset (scoped_ptr +0x19c), then Primitive::setGridCorner 005e8500
	void PartInstance::legacyTraverseState(const G3D::CoordinateFrame& parentState)
	{
		G3D::CoordinateFrame myState = parentState * *legacyOffset;
		primitive.setGridCorner(myState);
	}

	// 00599770: the IControllable override (this = PartInstance + 0x130)
	bool PartInstance::isControllable() const
	{
		for (int i = 0; i < 6; i++)
		{
			Surface& current = surfaces[(NormalId)i];
			if ((current.getSurfaceType() == ROTATE_P || current.getSurfaceType() == ROTATE_V) && current.isControllable())
				return true;
		}
		return false;
	}

	// 005997c0: PersistentPart +0x398, IsControllable +0x141, SurfacesNeedAdorn +0x3b1, then IRenderable 005dd540
	void PartInstance::onSurfaceChanged(RBX::NormalId surfId)
	{
		PersistentPart.setDirty();
		IsControllable.setDirty();
		SurfacesNeedAdorn.setDirty();
		shouldRenderSetDirty();
	}

	// 005997f0
	void PartInstance::setPhysics(const G3D::CoordinateFrame& value)
	{
		if (value != getCoordinateFrame())
		{
			primitive.setCoordinateFrame(value);
			PersistentPart.setDirty();
			onExtentsChanged();
		}
	}

	// 00598cb0
	const G3D::CoordinateFrame& PartInstance::getCoordinateFrame() const
	{
		return primitive.getCoordinateFrame();
	}

	// 00598cd0: Geometry grid size (Primitive geometry +0x9c, i.e. PartInstance +0x2c4)
	const G3D::Vector3& PartInstance::getPartSizeXml() const
	{
		return primitive.getGeometry()->getGridSize();
	}

	// 00598ce0
	G3D::Vector3 PartInstance::getPartSizeUi() const
	{
		return getPartSizeXml();
	}

	// 00598d10: Primitive dragging +0xa8 (+0x2d0)
	bool PartInstance::getDragging() const
	{
		return primitive.getDragging();
	}

	// 00598d40: Primitive anchored +0xa9 (+0x2d1)
	bool PartInstance::getAnchored() const
	{
		return primitive.getAnchor();
	}

	// 00598d50: Primitive friction +0xb0 (+0x2d8)
	float PartInstance::getFriction() const
	{
		return primitive.getFriction();
	}

	// 00598d60: Primitive elasticity +0xb4 (+0x2dc)
	float PartInstance::getElasticity() const
	{
		return primitive.getElasticity();
	}

	// 005993e0
	G3D::CoordinateFrame PartInstance::worldSnapLocation() const
	{
		G3D::Vector3 halfSize = getPartSizeXml() * 0.5f;

		G3D::Vector3 snapInPart;
		snapInPart.y = -halfSize.y;
		snapInPart.x = halfSize.x - G3D::iRound(floorf(halfSize.x));
		snapInPart.z = halfSize.z - G3D::iRound(floorf(halfSize.z));

		G3D::CoordinateFrame localSnapLocation(snapInPart);
		return primitive.getCoordinateFrame() * localSnapLocation;
	}

	// 005994c0: Math::snapToGrid 005def40 with Dragger::dragSnap 00640470, Math::fuzzyEq 005de2a0
	bool PartInstance::aligned() const
	{
		G3D::CoordinateFrame myCoord = worldSnapLocation();
		G3D::CoordinateFrame myCoordSnapped = Math::snapToGrid(myCoord, Dragger::dragSnap());

		return Math::fuzzyEq(myCoord, myCoordSnapped, 0.00001, 0.00001);
	}

	// 00599220: Surfaces::surf6 (COMDAT placed in this unit; the native Surfaces.h declares it without a body)
	Vector6<SurfaceType> Surfaces::surf6() const
	{
		Vector6<SurfaceType> answer;
		for (int i = 0; i < 6; i++)
			answer[i] = (*const_cast<Surfaces*>(this))[(NormalId)i].getSurfaceType();
		return answer;
	}

	// 00599690: Part(type, size, Color4, surf6, cframe) 00598ad0
	Part PartInstance::computePersistentPart() const
	{
		const G3D::CoordinateFrame& cframe = primitive.getCoordinateFrame();
		float transparency = 1.0f - alpha();

		return Part(partType, getPartSizeXml(), G3D::Color4(getColor3(), transparency), surfaces.surf6(), cframe);
	}

	// 00599eb0: Math::iRoundVector3 005de090, BRICK * 1.2f (00832a18) / PLATE * 0.4f (00827278)
	G3D::Vector3 PartInstance::uiToXmlSize(const G3D::Vector3& uiSize) const
	{
		G3D::Vector3 gridUiSize = Math::iRoundVector3(uiSize.max(G3D::Vector3(1.0f, 1.0f, 1.0f)));
		G3D::Vector3 xmlSize = gridUiSize;

		switch (formFactor)
		{
		case BRICK:
			xmlSize.y *= 1.2f;
			break;
		case PLATE:
			xmlSize.y *= 0.4f;
			break;
		}

		return xmlSize;
	}

	// 0059aa90: ComputeProp<Part, PartInstance>::getValue 00599b70
	const Part& PartInstance::getPart() const
	{
		const Part& part = PersistentPart.getValueRef();
		part.coordinateFrame = primitive.getCoordinateFrame();
		return part;
	}

	// 00599f80: Primitive myOwner +0xa4 is the IMoving base at PartInstance +0x1c0
	const RBX::PartInstance* PartInstance::fromPrimitiveConst(const Primitive* p)
	{
		if (p)
			return static_cast<const PartInstance*>(p->getOwner());
		else
			return NULL;
	}

	// 0059a040: __RTDynamicCast, then the recursion over Instance::numChildren 0048ae20
	bool PartInstance::getLocked(Instance* instance)
	{
		PartInstance* thisPart = dynamic_cast<PartInstance*>(instance);

		if (thisPart)
		{
			return thisPart->locked;
		}
		else
		{
			for (size_t i = 0; i < instance->numChildren(); i++)
			{
				if (getLocked(instance->getChild(i)))
					return true;
			}
			return false;
		}
	}

	// 0059ab80: PVInstance::onParentControllerChanged 00608d10, Primitive::setController 005e85e0
	void PartInstance::onParentControllerChanged()
	{
		PVInstance::onParentControllerChanged();
		PersistentPart.setDirty();
		primitive.setController(getTopPVController());
	}

	// 0059b4d0: Notifier<PartInstance, CanAggregateChanged>::raise 0059b220, IRenderable::shouldRenderSetDirty 005dd540
	void PartInstance::onCanAggregateChanged(bool canAggregate)
	{
		Notifier<PartInstance, CanAggregateChanged>::raise(canAggregate);
		shouldRenderSetDirty();
	}

	// 0059aae0
	void PartInstance::onAncestorChanged(const AncestorChanged& event)
	{
		Instance::onAncestorChanged(event);

		World* world = Workspace::getWorldIfInWorkspace(this);
		if (world != myWorld)
		{
			if (myWorld)
			{
				setMovingManager(NULL);
				myWorld->removePrimitive(&primitive);
			}

			myWorld = world;

			if (world)
			{
				world->insertPrimitive(&primitive);
				setMovingManager(Workspace::getMyWorkspaceFast(this));
				primitive.setController(getTopPVController());
			}
		}
	}

	// 00598c60: `jmp PVInstance::onChildAdded` 00608a60
	void PartInstance::onChildAdded(Instance* child)
	{
		PVInstance::onChildAdded(child);
	}

	// 0059abb0: Draw::selectionBox 00677030
	void PartInstance::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		Draw::selectionBox(getPart(), adorn, selectState);
	}

	// 0059abe0: HitTest::hitTest 00677380
	bool PartInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)
	{
		const G3D::CoordinateFrame& cframe = primitive.getCoordinateFrame();
		G3D::Ray rayInPartCoords = cframe.toObjectSpace(worldRay);
		G3D::Vector3 hitPointInPartCoords;

		if (HitTest::hitTest(getPart(), rayInPartCoords, hitPointInPartCoords, 1.0f))
		{
			const G3D::CoordinateFrame& cframe = primitive.getCoordinateFrame();
			worldHitPoint = cframe.pointToWorldSpace(hitPointInPartCoords);
			return true;
		}
		else
		{
			return false;
		}
	}

	// 0059aa40: SignalDesc::findSignalInstance 0056b620 on event_Touched 00976164
	bool PartInstance::reportTouches() const
	{
		return !event_Touched.empty(this);
	}
}
