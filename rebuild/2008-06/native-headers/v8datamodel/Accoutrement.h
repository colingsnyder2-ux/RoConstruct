#pragma once
// 2008-06 native layout of RBX::Accoutrement and RBX::Hat. Inactive: no build list or swap uses it.
//
// Evidence (2008-06 Roblox.exe):
//  * RTTI (vtable 00834bf4 Accoutrement, 00835094 Hat):
//      Accoutrement -> DescribedCreatable<Accoutrement, Instance, sAccoutrement> -> Described -> FactoryProduct
//      -> Instance; IEquipable mdisp 0x130; IRenderable mdisp 0x140; virtual ICameraSubject (vbtable at +0x150,
//      vdisp 8), virtual ILocation (vdisp 4), virtual ISelectable3d (vdisp 12).
//      Hat -> DescribedCreatable<Hat, Accoutrement, sHat> -> ... -> Accoutrement (Hat adds no fields).
//    sAccoutrement 008349f8 "Accoutrement" and sHat 00834a08 "Hat" are .rdata `const char[]` (3QBDB).
//  * Allocation sizes: Creator<Accoutrement>::create 00432520 new(0x1d8) (0043253f) and
//    Creator<Hat>::create 00432790 new(0x1d8) (004327af); both pass 1 (most-derived flag for virtual bases).
//  * Constructor 005b2230: IEquipable ctor 00628fc0 at +0x130 (vtable 00834b70); IRenderable at +0x140
//    (vtable 00834b58; index2d/index3d = -1 at +0x144/+0x148, bucket 0 at +0x14c); vbptr +0x150 (vbtable
//    00834eb4); backendAccoutrementState 0 at +0x154; G3D::CoordinateFrame at +0x158 (ctor 004782d0, 0x34);
//    three boost::signals::scoped_connection at +0x188/+0x19c/+0x1b0 (each 0x14: shared_ptr at +4, two bools);
//    vtordisp +0x1c4, ILocation +0x1c8 (vtable 00834b50), vtordisp +0x1cc, ICameraSubject +0x1d0 (vtable
//    00834b34, its own vbptr +0x1d4 -> vbtable 00846144); setName("Accoutrement"). Hat ctor 005b2d10 only
//    stores vtables and calls setName("Hat").
//  * Property descriptors (static initializers 007f4fb0..007f5190, category "Appearance"):
//      "AttachmentPoint" CoordinateFrame STREAMING (get 005b0830, set 005b2670), "AttachmentPos" Vector3 UI
//      (005b0940/005b2700), "AttachmentForward"/"AttachmentUp"/"AttachmentRight" Vector3 UI, and
//      "BackendAccoutrementState" int STREAMING (get 005b0820, set 005b24e0).
// Method and field names are analog names (donor shape); class and property strings are original.
#include "v8tree/Instance.h"
#include "v8datamodel/IEquipable.h"
#include "util/IRenderable.h"
#include "util/ICameraSubject.h"
#include "util/ISelectable3d.h"
#include <boost/signals/connection.hpp>

namespace RBX
{
	class IReferenceBinder;
	class ModelInstance;
	class PartInstance;

	extern const char sAccoutrement[];   // 008349f8 "Accoutrement"
	extern const char sHat[];            // 00834a08 "Hat"

	class Accoutrement : public DescribedCreatable<Accoutrement, Instance, sAccoutrement>,
						 public IEquipable,
						 public IRenderable,
						 public virtual ICameraSubject,
						 public virtual ISelectable3d
	{
		friend struct NativeAccoutrementLayout;  // tests/NativeAppearanceLayout.cpp
	protected:
		enum AccoutrementState
		{
			NOTHING,
			HAS_HANDLE,
			IN_WORKSPACE,
			IN_CHARACTER,
			EQUIPPED
		};

		AccoutrementState backendAccoutrementState;                      // +0x154
		G3D::CoordinateFrame attachmentPoint;                            // +0x158
		boost::signals::scoped_connection handleTouched;                 // +0x188
		boost::signals::scoped_connection characterChildAdded;           // +0x19c
		boost::signals::scoped_connection characterChildRemoved;         // +0x1b0

	protected:
		virtual bool askSetParent(const Instance* instance) const        // slot 2 (00565ff0, ICF fold)
		{
			return true;
		}
		virtual bool askAddChild(const Instance* instance) const         // slot 3 (00565ff0, ICF fold)
		{
			return true;
		}
		virtual void onAncestorChanged(const AncestorChanged&);          // 005b25f0
		virtual void readProperty(const XmlElement* propertyElement, IReferenceBinder& binder);   // 005b0840
		virtual const G3D::CoordinateFrame getLocation() const;          // 005b0b70
		virtual void render3dSelect(Adorn* adorn, SelectState selectState);                      // 005b1020
		void downFrom_InCharacter();                                     // 005b0920
		// State-machine steps called by setDesiredState 005b2510 (jump tables 005b25c8 up / 005b25d8 down; analog
		// donor names; the target's slot order is NOTHING -> 005b1d70, IN_WORKSPACE -> 005b1e50, IN_CHARACTER ->
		// 005b1830, EQUIPPED down -> 005b1fc0). Bodies are not recovered yet (placeholders func_005b1xxx).
		void onEvent_HandleTouched(boost::shared_ptr<Instance> other);   // 005b1620 bind target (donor name; body not recovered)
		PartInstance* getHandle()   // donor inline (getHandleConst const_cast)
		{
			return const_cast<PartInstance*>(getHandleConst());
		}
		void connectTouchEvent();                                        // 005b1d70 (handleTouched +0x188)
		void upTo_Equipped();                                            // 005b1830
		void upTo_InCharacter();                                         // 005b1e50
		void downFrom_Equipped();                                        // 005b1fc0 (weld +0x134)
		void upTo_InWorkspace()                                          // inlined empty into 005b2510 (HAS_HANDLE up slot)
		{
		}
		void downFrom_InWorkspace()                                      // INFERRED: empty step inlined into 005b2510; its
		{                                                                // IN_WORKSPACE slot keeps the 4-entry down jump
		}                                                                // table 005b25d8 (Tool.h declares downFrom_InWorkspace)
		void downFrom_HasHandle()                                        // inlined into 005b2510 (scoped_connection
		{                                                                // disconnect 00595230 on +0x188)
			handleTouched.disconnect();
		}
		AccoutrementState computeDesiredState(Instance* testParent);      // inlined into 005b10a0 (no out-of-line copy survives)
		AccoutrementState computeDesiredState();                          // inlined into 005b10a0 (no out-of-line copy survives)
		void updateDesiredState();                                        // 005b10a0
		void onEvent_AddedBackend(boost::shared_ptr<Instance> child);     // 005b1110 (donor name; openrbx 0x005baec0)
		void onEvent_RemovedBackend(boost::shared_ptr<Instance> child);   // 005b1190 (donor name; openrbx 0x005baf40)
		void setDesiredState(AccoutrementState desiredState, const ServiceProvider* serviceProvider);   // 005b2510
	public:
		static bool writeUnlocked;                                        // 00976cad (read by write 005b1480)
	protected:
	public:
		Accoutrement();
		virtual ~Accoutrement();                                         // 005b0da0
		virtual XmlElement* write();                                     // 005b1480
		const PartInstance* getHandleConst() const;                      // 005b08a0 (ICF name Tool)
		static void dropAllOthers(ModelInstance* model, Accoutrement* accoutrement);   // 005b15e0 (openrbx 0x005bb390)
		void setBackendAccoutrementState(int value);                     // 005b24e0
		int getBackendAccoutrementState() const                          // 005b0820 (folded getter)
		{
			return backendAccoutrementState;
		}
		const G3D::CoordinateFrame& getAttachmentPoint() const;         // 005b0830
		void setAttachmentPoint(const G3D::CoordinateFrame&);           // 005b2670
		virtual void onCameraNear(float distance);                       // 005b0fa0
		const G3D::Vector3 getAttachmentPos() const;                     // 005b0940
		const G3D::Vector3 getAttachmentForward() const;                 // 005b0970
		const G3D::Vector3 getAttachmentUp() const;                      // 005b09c0
		const G3D::Vector3 getAttachmentRight() const;                   // 005b09e0
		void setAttachmentPos(const G3D::Vector3&);                      // 005b2700
		void setAttachmentForward(const G3D::Vector3&);                  // 005b2750
		void setAttachmentUp(const G3D::Vector3&);                       // 005b28d0
		void setAttachmentRight(const G3D::Vector3&);                    // 005b2a40
	};

	class Hat : public DescribedCreatable<Hat, Accoutrement, sHat>
	{
	public:
		Hat();
	};
}
