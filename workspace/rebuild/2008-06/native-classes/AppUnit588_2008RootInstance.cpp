// native-flags: document-swap profile, VS2008 RTM 21022, /fp:fast /U_RELEASEASSERT (tests/record_native_app_unit588_2008.py)
// 2008-06 RBX::RootInstance unit 00590030..005917bb (inactive), against the committed native
// v8datamodel/RootInstance.h (read-only). Bodies follow the donor tools/rbxgs RootInstance.cpp; every spelling below
// that differs from the donor is read from the 2008-06 bytes:
//   * RootInstance layout (from the bytes, matched by the native header): ICameraOwner at +0x288 (vtable 00831c94,
//     its weak_ptr vector destroyed at +0x28c by ~RootInstance 00590630), ControllersUsed ComputeProp +0x2a8..+0x2c7
//     (dirty flag +0x2b0, object +0x2b4, computeControllersUsed 00590300 at +0x2b8), insertPoint +0x2c8, viewPort
//     +0x2d4 (800 x 600, 00831e24 / 00831e20), world auto_ptr +0x2e4.
//   * moveToIdeInsertPoint 00590240, moveToCharacterInsertPoint 00590b50 and insert3dView 00590f90 test
//     `size() > 0` (sar / test); insertToTree 00590c10 and insertIdeView 00590e70 test `!empty()` (test 0xfffffff8).
//   * computeCharacterInsertPoint 00590800 reads the camera through ICameraOwner slot 2 (getGCamera, then
//     GCamera::getCoordinateFrame 005107b0), zeroes look.y and halfSize.y and multiplies componentwise; the reads of
//     the zeroed components into named locals fix the x87 schedule of the bytes (without them: 478 B, lookVector
//     product order differs).
//   * RootInstance() 00591580: everything matches except `new World` (0x114 in the original, sizeof donor World
//     0xb8): not counted, World.h proposal in the receipt.
//   * insertSpawnLocation 005910a0 reads SpawnLocation::neutral at +0x400, which needs the 2008 PartInstance of
//     native-headers/part-embedded (pending build only).
//   * insertInstances 005911d0 is not built: its 2008 shape (an early setParent loop for a foreign requestedParent,
//     an extra dynamic_cast branch, a final ChangeHistory waypoint 0058c5c0 "Insert") differs from the donor.
#include "v8datamodel/RootInstance.h"
#include "v8datamodel/PartInstance.h"
#include "tool/Dragger.h"
#include "tool/MegaDragger.h"
#include "tool/DragUtilities.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/Tool.h"
#include "v8datamodel/Lighting2008.h"
#include "v8datamodel/Sky.h"
#include "Network/Players.h"
#include <boost/bind.hpp>

namespace RBX
{
	// ServiceProvider::create<T>(const Instance*) is declared by v8tree/Service.h without a body; the 2008 bodies
	// 00590d80 (StarterPackService), 00590dd0 (Teams) and 00590e20 (Lighting) walk the parent chain (+0x104) with
	// dynamic_cast<const ServiceProvider*> and tail-call create<T>() (same definition as LocalBackpack2008.cpp).
	template<class Class> Class* ServiceProvider::create(const Instance* context)
	{
		for (const Instance* instance = context; instance; instance = instance->getParent())
		{
			if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(instance))
				return provider->create<Class>();
		}
		return NULL;
	}
	// 00590e20 is called only by insertInstances 005911d0 (not built here: 2008 shape), so it is instantiated
	// explicitly.
	template Lighting* ServiceProvider::create<Lighting>(const Instance* context);

	RootInstance::~RootInstance()
	{
	}

	void RootInstance::onDescendentAdded(Instance* instance)
	{
		ModelInstance::onDescendentAdded(instance);
		ControllersUsed.setDirty();
	}

	void RootInstance::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
	{
		ControllersUsed.setDirty();
		ModelInstance::onDescendentRemoving(instance);
	}

	void RootInstance::setInsertPoint(const G3D::Vector3& topCenter)
	{
		insertPoint = Dragger::toGrid(topCenter);
	}

	G3D::Vector3 RootInstance::computeIdeInsertPoint() const
	{
		insertPoint.y = G3D::max(0.0f, insertPoint.y);
		float tempY = insertPoint.y;
		G3D::Vector3 newInsertPoint = getExtentsWorld().clip(insertPoint);
		insertPoint = newInsertPoint;
		insertPoint.y = tempY;
		insertPoint = Dragger::toGrid(insertPoint);
		return insertPoint;
	}

	void RootInstance::moveSafe(MegaDragger& megaDragger, G3D::Vector3 move, MoveType moveType)
	{
		megaDragger.startDragging();
		megaDragger.alignAndCleanParts();
		if (moveType == MOVE_DROP)
			megaDragger.safeMoveYDrop(move);
		else
			megaDragger.safeMoveNoDrop(move);
		megaDragger.finishDragging();
	}

	void RootInstance::moveSafe(std::vector<boost::weak_ptr<PartInstance> >& partArray, G3D::Vector3 move, MoveType moveType)
	{
		MegaDragger megaDragger(NULL, partArray, this);
		moveSafe(megaDragger, move, moveType);
	}

	void RootInstance::moveToIdeInsertPoint(std::vector<boost::weak_ptr<PartInstance> >& partArray)
	{
		if (partArray.size() > 0)
		{
			Extents extents = DragUtilities::computeExtents(partArray);
			G3D::Vector3 insertPoint = computeIdeInsertPoint();
			G3D::Vector3 moveToInsert = Dragger::toGrid(insertPoint - extents.bottomCenter());
			moveSafe(partArray, moveToInsert, MOVE_DROP);
		}
	}

	void RootInstance::insertToTree(const std::vector<boost::shared_ptr<Instance> >& instances, Instance* requestedParent)
	{
		std::vector<boost::weak_ptr<PartInstance> > partArray;
		insertRaw(instances, requestedParent, partArray);
		if (!partArray.empty())
			moveSafe(partArray, G3D::Vector3::zero(), MOVE_NO_DROP);
	}

	G3D::Vector3 RootInstance::computeCharacterInsertPoint(const Extents& extents) const
	{
		ModelInstance* character = Network::Players::findLocalCharacter(this);
		if (character)
		{
			G3D::Vector3 cameraLook = getGCamera().getCoordinateFrame().lookVector();
			float lookY = cameraLook.y;
			cameraLook.y = 0.0f;
			cameraLook.unitize();

			G3D::Vector3 halfSize = extents.size() * 0.5f;
			float halfY = halfSize.y;
			halfSize.y = 0.0f;

			std::vector<boost::weak_ptr<PartInstance> > partArray;
			PartInstance::findParts(character, partArray);

			Extents modelExtents = DragUtilities::computeExtents(partArray);

			G3D::Vector3 insertPoint = modelExtents.bottomCenter() + cameraLook * 7.0f + G3D::Vector3(halfSize.x * cameraLook.x, halfSize.y * cameraLook.y, cameraLook.z * halfSize.z);
			insertPoint = Dragger::toGrid(insertPoint);

			return insertPoint;
		}
		else
		{
			RBXASSERT(0);
			return computeIdeInsertPoint();
		}
	}
	void RootInstance::moveToPoint(PVInstance* pv, G3D::Vector3 point)
	{
		if (this->contains(pv))
		{
			RBXASSERT(pv->getPrimaryPart());

			std::vector<PVInstance*> pvInstances;
			pvInstances.push_back(pv);

			G3D::Vector3 move = Dragger::toGrid(point - pv->getLocation().translation);

			MegaDragger megaDragger(pv->getPrimaryPart(), pvInstances, this);
			moveSafe(megaDragger, move, MOVE_NO_DROP);
		}
	}
	void RootInstance::moveToCharacterInsertPoint(std::vector<boost::weak_ptr<PartInstance> >& partArray)
	{
		if (partArray.size() > 0)
		{
			Extents extents = DragUtilities::computeExtents(partArray);

			G3D::Vector3 characterInsertPoint = computeCharacterInsertPoint(extents);
			G3D::Vector3 moveToInsert = Dragger::toGrid(characterInsertPoint - extents.bottomCenter());

			moveSafe(partArray, moveToInsert, MOVE_DROP);
		}
	}
	void RootInstance::insertRaw(const std::vector<boost::shared_ptr<Instance> >& instances, Instance* requestedParent, std::vector<boost::weak_ptr<PartInstance> >& partArray)
	{
		RBXASSERT(requestedParent && this->contains(requestedParent));

		std::for_each(instances.begin(), instances.end(), boost::bind(&Instance::setParent, _1, requestedParent));

		for (size_t i = 0; i < instances.size(); ++i)
			PartInstance::findParts(instances[i].get(), partArray);

		DragUtilities::join(partArray);
	}
	void RootInstance::insertCharacterView(const std::vector<boost::shared_ptr<Instance> >& instances, std::vector<boost::weak_ptr<PartInstance> >& partArray)
	{
		RBXASSERT(instances.size() > 0);

		if (instances.size() == 1)
		{
			Instance* instance = instances[0].get();
			if (dynamic_cast<HopperBin*>(instance))
			{
				Network::Player* localPlayer = Network::Players::findLocalPlayer(this);
				if (localPlayer)
				{
					instance->setParent(localPlayer->getPlayerBackpack());
					return;
				}
			}
		}

		insertRaw(instances, this, partArray);
		moveToCharacterInsertPoint(partArray);
	}
	void RootInstance::insertIdeView(const std::vector<boost::shared_ptr<Instance> >& instances, std::vector<boost::weak_ptr<PartInstance> >& partArray, PromptMode promptMode)
	{
		RBXASSERT(instances.size() > 0);

		if (instances.size() == 1)
		{
			Instance* instance = instances[0].get();
			if (dynamic_cast<HopperBin*>(instance))
			{
				instance->setParent(ServiceProvider::create<StarterPackService>(this));
				return;
			}
			else if (dynamic_cast<Tool*>(instance))
			{
				if (promptMode == ALLOW_PROMPTS && MessageBoxA(NULL, "Put this tool into the starter pack (otherwise drop into the 3d view)?", "Inserting Tool", MB_YESNO) == IDYES)
				{
					instance->setParent(ServiceProvider::create<StarterPackService>(this));
					return;
				}
			}
		}

		insertRaw(instances, this, partArray);
		if (!partArray.empty())
		{
			moveToIdeInsertPoint(partArray);
			Extents extents = DragUtilities::computeExtents(partArray);
			getCamera()->lookAt(extents.center());
		}
	}
	void RootInstance::insert3dView(const std::vector<boost::shared_ptr<Instance> >& instances, PromptMode promptMode)
	{
		RBXASSERT(instances.size() > 0);

		std::vector<boost::weak_ptr<PartInstance> > partArray;
		if (Network::Players::findLocalCharacter(this))
			insertCharacterView(instances, partArray);
		else
			insertIdeView(instances, partArray, promptMode);

		if (partArray.size() > 0)
		{
			Extents extents = DragUtilities::computeExtents(partArray);
			getCamera()->zoomExtents(extents, viewPort, Camera::ZOOM_OUT_ONLY);
		}
	}
	void RootInstance::insertSpawnLocation(SpawnLocation* s)
	{
		if (!s->neutral)
		{
			Teams* teams = ServiceProvider::create<Teams>(this);
			if (!teams->teamExists(s->getTeamColor()))
			{
				boost::shared_ptr<Team> team = Creatable<Instance>::create<Team>();
				team->setParent(teams);
				team->setTeamColor(s->getTeamColor());
				team->setName(s->getTeamColor().name() + " Team");
			}
		}
	}
	ControllerTypeArray RootInstance::computeControllersUsed() const
	{
		ControllerTypeArray array;
		for (size_t i = 0; i < numChildren(); ++i)
		{
			const PVInstance* pvChild = dynamic_cast<const PVInstance*>(getChild(i));
			if (pvChild)
			{
				if (pvChild->isControllable())
					array.setController(pvChild->getControllerType(), true);
			}
		}
		return array;
	}
}
#include "v8world/World.h"
namespace RBX {
#pragma warning (push)
#pragma warning (disable : 4355)
	RootInstance::RootInstance()
		: ControllersUsed(this, &RootInstance::computeControllersUsed),
		  insertPoint(G3D::Vector3::zero()),
		  viewPort(G3D::Vector2(800.0f, 600.0f)),
		  world(new World())
	{
	}
#pragma warning (pop)
}
