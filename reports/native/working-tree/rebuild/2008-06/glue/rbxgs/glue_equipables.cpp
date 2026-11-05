// Rebuild glue: Accoutrement and Tool members rbxgs declares but never defines. The state walk mirrors
// rbxgs Accoutrement::setDesiredState; the frame setters mirror setAttachmentForward/setGripForward.
// Behavioural reconstruction, not byte-verified.
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/Tool.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/PartInstance.h"
#include "Network/Players.h"

namespace RBX
{
	namespace
	{
		// keep `forward` (column 2) and rebuild the other two axes around a new up or right vector
		G3D::CoordinateFrame withUp(G3D::CoordinateFrame c, const G3D::Vector3& v)
		{
			G3D::Vector3 oldZ = c.rotation.getColumn(2);
			G3D::Vector3 y = v.direction();
			G3D::Vector3 x = y.cross(oldZ);
			x.unitize();
			G3D::Vector3 z = x.cross(y);
			z.unitize();
			c.rotation.setColumn(0, x);
			c.rotation.setColumn(1, y);
			c.rotation.setColumn(2, z);
			return c;
		}

		G3D::CoordinateFrame withRight(G3D::CoordinateFrame c, const G3D::Vector3& v)
		{
			G3D::Vector3 oldY = c.rotation.getColumn(1);
			G3D::Vector3 x = v.direction();
			G3D::Vector3 z = x.cross(oldY);
			z.unitize();
			G3D::Vector3 y = z.cross(x);
			y.unitize();
			c.rotation.setColumn(0, x);
			c.rotation.setColumn(1, y);
			c.rotation.setColumn(2, z);
			return c;
		}

		void dropWeld(boost::shared_ptr<Weld>& weld)
		{
			if (weld)
			{
				weld->setParent(NULL);
				weld.reset();
			}
		}
	}

	bool Accoutrement::writeUnlocked = false;

	void Accoutrement::setAttachmentUp(const G3D::Vector3& v) { setAttachmentPoint(withUp(attachmentPoint, v)); }
	void Accoutrement::setAttachmentRight(const G3D::Vector3& v) { setAttachmentPoint(withRight(attachmentPoint, v)); }

	// undo upTo_Equipped: drop the head weld, listen for pickups again
	void Accoutrement::downFrom_Equipped()
	{
		dropWeld(weld);
		connectTouchEvent();
	}

	void Accoutrement::onAncestorChanged(const AncestorChanged& event)
	{
		Instance::onAncestorChanged(event);
		if (const ServiceProvider* provider = ServiceProvider::findServiceProvider(this))
			if (Network::Players::backendProcessing(provider, false))
				setDesiredState(computeDesiredState(), provider);
	}

	void Tool::setGripUp(const G3D::Vector3& v) { setGrip(withUp(grip, v)); }
	void Tool::setGripRight(const G3D::Vector3& v) { setGrip(withRight(grip, v)); }

	void Tool::upTo_HasHandle() { connectTouchEvent(); }
	void Tool::downFrom_HasHandle() { handleTouched.disconnect(); }
	void Tool::upTo_InWorkspace() {}
	void Tool::downFrom_InWorkspace() {}
	void Tool::upTo_Activated() {}
	void Tool::downFrom_Activated() {}

	// undo upTo_Equipped: drop the right-grip weld, listen for pickups again
	void Tool::downFrom_Equipped()
	{
		dropWeld(weld);
		connectTouchEvent();
	}

	// walk one state at a time toward the desired state, as Accoutrement::setDesiredState
	void Tool::setDesiredState(ToolState desiredState, const ServiceProvider* serviceProvider)
	{
		while (desiredState != backendToolState)
		{
			if (backendToolState < desiredState)
			{
				switch (backendToolState)
				{
				case NOTHING: upTo_HasHandle(); break;
				case HAS_HANDLE: upTo_InWorkspace(); break;
				case IN_WORKSPACE: upTo_InCharacter(); break;
				case IN_CHARACTER: upTo_HasTorso(); break;
				case HAS_TORSO: upTo_Equipped(); break;
				case EQUIPPED: upTo_Activated(); break;
				default: break;
				}
				setBackendToolStateNoReplicate(backendToolState + 1);
			}
			else
			{
				switch (backendToolState)
				{
				case ACTIVATED: downFrom_Activated(); break;
				case EQUIPPED: downFrom_Equipped(); break;
				case HAS_TORSO: downFrom_HasTorso(); break;
				case IN_CHARACTER: downFrom_InCharacter(); break;
				case IN_WORKSPACE: downFrom_InWorkspace(); break;
				case HAS_HANDLE: downFrom_HasHandle(); break;
				default: break;
				}
				setBackendToolStateNoReplicate(backendToolState - 1);
			}
		}
	}

	void Tool::onAncestorChanged(const AncestorChanged& event)
	{
		Instance::onAncestorChanged(event);
		if (const ServiceProvider* provider = ServiceProvider::findServiceProvider(this))
			if (Network::Players::backendProcessing(provider, false))
				setDesiredState(computeDesiredState(), provider);
	}
}
