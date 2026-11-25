// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	extern Reflection::PropDescriptor<Accoutrement, G3D::CoordinateFrame> prop_AttachmentPoint;

	void Accoutrement::setAttachmentPoint(const G3D::CoordinateFrame& value)
	{
		if (value != attachmentPoint)
		{
			attachmentPoint = value;

			if (Workspace* workspace = ServiceProvider::find<Workspace>(this))
				workspace->raiseDrawChanged();

			raisePropertyChanged(prop_AttachmentPoint);

			// INFERRED: weld member at +0x134 is an AutoJoint*
			if (weld)
				weld->setC1(attachmentPoint);
		}
	}
}
