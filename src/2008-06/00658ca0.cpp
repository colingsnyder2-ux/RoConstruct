// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_1099a329ff82780b.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
#include "util/PV.h"
#include "v8kernel/Cofm.h"
namespace RBX {
	class Body
	{
		char exeBodyPad[0x28];
		Cofm* cofm;
	public:
		const G3D::Vector3& getCofmOffset() const
		{
			if (cofm)
			{
				return cofm->getCofmInBody();
			}
			else
			{
				return G3D::Vector3::zero();
			}
		}
	};
	class SimBody
	{
	public:
		Body* body;
		bool dirty;
		int exeSimPad;
		PV pv;
		PV getOwnerPV();
	};
PV SimBody::getOwnerPV()
{
	G3D::Vector3 cofmOffset = body->getCofmOffset();
	return pv.pvAtLocalOffset(G3D::Vector3(-cofmOffset.x, -cofmOffset.y, -cofmOffset.z));
}
}
