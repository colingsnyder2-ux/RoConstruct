// from server: 100% by EspClaude
// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_ff998e1af6293bae.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include "v8kernel/Pair.h"
namespace RBX
{
	// 2009-06 Body layout from the target: root at +0x2c, simBody at +0x34.
	class Body2008
	{
		char prefix[0x2c];
		Body2008* root;
		char gap[0x4];
		SimBody* simBody;
	public:
		void accumulateForce(const G3D::Vector3& force, const G3D::Vector3& worldPos)
		{
			SimBody* simBody = root->simBody;
			if (simBody)
				simBody->accumulateForce(force, worldPos);
		}
	};

	void GeoPair::forceToBodies(const G3D::Vector3& _force, const G3D::Vector3& _position)
	{
		((Body2008*)this->body0)->accumulateForce(-_force, _position);
		((Body2008*)this->body1)->accumulateForce(_force, _position);
	}
}

