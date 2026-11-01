// from server: 100% by EspClaude
// from server: 83% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_43bca4cad0e1009c.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
#include "util/PV.h"
namespace RBX {
	class Body;
	class Cofm
	{
		Body* body;
		mutable bool dirty;
		mutable G3D::Vector3 cofmInBody;
		void updateIfDirty() const;
	public:
		const G3D::Vector3& getCofmInBody() const { updateIfDirty(); return cofmInBody; }
	};
	class Body
	{
		char exeBodyPad[0x30];
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

