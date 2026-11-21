#pragma once
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
		// INFERRED: 00575890 case '=' calls this with the ModelInstance* returned by
		static void dropAll(ModelInstance*);
	};
}
