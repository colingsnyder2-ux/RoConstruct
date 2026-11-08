#pragma once
// >>> native-status (generated) -- do not edit >>>
// Tool | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src ee173960 | roc native-status --write
// 2008-06 native RBX::Tool (inactive). Shape after the donor tools/rbxgs v8datamodel/Tool.h; the one change is the
// class-name template argument (a const char array, RTTI $1?sTool@2@3QBDB). Every base, field and size below is read
// from the 2008-06 binary (tests/record_native_hopper.py checks them):
//   RTTI       vtable 00841a4c .?AVTool@RBX@@ (32 bases) -> DescribedCreatable<Tool, BackpackItem, sTool> ->
//              BackpackItem (non-virtual part 0x1a0) + IEquipable +0x1a0 + IRenderable +0x1b0, virtual ILocation and
//              ISelectable3d through the vbptr at +0x1c0 (vbtable offsets 4 and 8).
//   size       0x270: Creatable<Instance>::create<Tool> 00578400 allocates 0x270 and calls 00600240 with the
//              most-derived flag; the non-virtual part ends at +0x268 (Flag's fields start there), the virtual bases
//              are at +0x268 / +0x26c (vtable 0084199c, vtordisp thunk 005fe6a0 for getLocation).
//   fields     constructor 00600240 / destructor 005fe4b0: backendToolState +0x1c4 = NOTHING, frontendActivationState
//              +0x1c8 = 0, grip +0x1cc (CoordinateFrame() 004782d0), enabled +0x1fc = true, toolMouseCommand +0x200
//              = NULL, scoped_connections handleTouched +0x204, characterChildAdded +0x218, characterChildRemoved
//              +0x22c, torsoChildAdded +0x240, torsoChildRemoved +0x254 (~scoped_connection 005954b0 in reverse
//              order); setName(sTool) with the class-name array 008416d0. No asserts in the 2008 destructor.
//   accessors  getBackendToolState 005fd3b0 (+0x1c4), getFrontendActivationState 005fd3a0 (+0x1c8), getGrip 005fd3c0
//              (+0x1cc), getGripPos 005fd500 (+0x1f0), drawSelected 005fe600 (backendToolState >= EQUIPPED).
//   descriptors (dynamic initializers 007f7640..007f7990, category "Appearance" 008329ac): prop_Grip (STREAMING),
//              prop_GripPos, prop_GripForward, prop_GripUp, prop_GripRight (UI), prop_BackendToolState and
//              prop_FrontendActivationState ("ActivationState", STREAMING), Tool::prop_Enabled (BoundProp<bool,1> 0097b84c,
//              "Enabled"/"State", member +0x1fc, STANDARD), event_Equipped ("Equipped"/"mouse"), event_Unequipped,
//              event_Activated, event_Deactivated.
// The unit needs /fp:fast (getGripForward 005fd530 keeps the -1.0f product in x87 registers).
#include "v8datamodel/Hopper.h"
#include "v8datamodel/IEquipable.h"
#include "util/IRenderable.h"
#include "util/ILocation.h"
#include "util/ISelectable3d.h"

struct NativeHopperLayout;

namespace RBX
{
	namespace Network
	{
		class Player;
	}
	class ModelInstance;
	class Mouse;
	class ToolMouseCommand;

	extern const char sTool[];
	class Tool : public DescribedCreatable<Tool, BackpackItem, sTool>,
				 public IEquipable,
				 public IRenderable,
				 public virtual ILocation,
				 public virtual ISelectable3d
	{
		friend struct ::NativeHopperLayout;

	private:
		enum ToolState
		{
			NOTHING,
			HAS_HANDLE,
			IN_WORKSPACE,
			IN_CHARACTER,
			HAS_TORSO,
			EQUIPPED,
			ACTIVATED
		};

	private:
		ToolState backendToolState;                         // +0x1c4
		int frontendActivationState;                        // +0x1c8
		G3D::CoordinateFrame grip;                          // +0x1cc
		bool enabled;                                       // +0x1fc
		ToolMouseCommand* toolMouseCommand;                 // +0x200
		boost::signals::scoped_connection handleTouched;         // +0x204
		boost::signals::scoped_connection characterChildAdded;   // +0x218
		boost::signals::scoped_connection characterChildRemoved; // +0x22c
		boost::signals::scoped_connection torsoChildAdded;       // +0x240
		boost::signals::scoped_connection torsoChildRemoved;     // +0x254
	public:
		static Reflection::BoundProp<bool, 1> prop_Enabled;

	private:
		int getNumToolsInCharacter();
		void onEvent_AddedBackend(boost::shared_ptr<Instance> child);
		void onEvent_RemovedBackend(boost::shared_ptr<Instance> child);
		void onEvent_HandleTouched(boost::shared_ptr<Instance> other);
		boost::shared_ptr<Mouse> getMouse();
		ToolState computeDesiredState(Instance* testParent);
		ToolState computeDesiredState();
		void setDesiredState(ToolState, const ServiceProvider*);
		void setBackendToolStateNoReplicate(int value);
		void rebuildBackendState();
		void connectTouchEvent();
		void upTo_Activated();
		void upTo_Equipped();
		void upTo_HasTorso();
		void upTo_InCharacter();
		void upTo_InWorkspace();
		void upTo_HasHandle();
		void downFrom_Activated();
		void downFrom_Equipped();
		void downFrom_HasTorso();
		void downFrom_InCharacter();
		void downFrom_InWorkspace();
		void downFrom_HasHandle();
		void onEquipping();
		void onUnequipped();
		void onChildAdded();
		void onChildRemoved();
		virtual void onAncestorChanged(const AncestorChanged&);

		virtual bool askSetParent(const Instance* instance) const
		{
			return true;
		}

		virtual bool askAddChild(const Instance* instance) const
		{
			return true;
		}

		virtual void readProperty(const XmlElement* propertyElement, IReferenceBinder& binder);
		virtual const G3D::CoordinateFrame getLocation() const;    // 005fd770

		virtual bool drawSelected() const
		{
			return backendToolState >= EQUIPPED; // EQUIPPED or ACTIVATED
		}

		virtual void onLocalClicked();
		virtual void onLocalOtherClicked();
		virtual void render3dSelect(Adorn* adorn, SelectState selectState); // 005fdaf0 (not attempted)
	public:
		Tool();                                             // 00600240
		virtual ~Tool();                                    // 005fe4b0
	public:
		virtual bool canUnequip()
		{
			return true;
		}

		virtual bool canBePickedUpByPlayer(Network::Player* p)
		{
			return true;
		}

		PartInstance* getHandle();
		const PartInstance* getHandleConst() const;
		void setFrontendActivationState(int value);

		int getFrontendActivationState() const
		{
			return frontendActivationState;
		}

		void setBackendToolState(int value);

		int getBackendToolState() const
		{
			return backendToolState;
		}

		const G3D::CoordinateFrame& getGrip() const
		{
			return grip;
		}

		void setGrip(const G3D::CoordinateFrame& value);
		void activate();
		void deactivate();
		const G3D::Vector3 getGripPos() const;
		const G3D::Vector3 getGripForward() const;
		const G3D::Vector3 getGripUp() const;
		const G3D::Vector3 getGripRight() const;
		void setGripPos(const G3D::Vector3& v);
		void setGripForward(const G3D::Vector3& v);
		void setGripUp(const G3D::Vector3&);
		void setGripRight(const G3D::Vector3&);

	private:
		static void moveAllToolsToBackpack(Network::Player* player);
		static ToolState characterCanPickUpTool(Instance*);
		static bool characterCanUnequipTool(ModelInstance* character);
	public:
		static void dropAll(ModelInstance*);
	};
}
