// =============================================================================
// Tool.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Tool.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
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
		// INFERRED: 005fd3d0 is a Tool member whose 5-byte body tail-calls 00642fc0; the original
		void sub_005fd3d0();
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
