// from server: 100% by EspClaude
// from server: 59% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_099374df11dda606.cpp

// Candidate translation unit (score above; library headers required).
#define _MT 1
#define _DLL 1
#include "v8datamodel/Feature.h"

namespace RBX
{
	void MotorFeature::join(Instance* i0, Instance* i1)
	{
		if (canJoin(i0, i1))
		{
			Instance* first = dynamic_cast<Hole*>(i0) ? i0 : i1;
			Instance* second = (first == i0) ? i1 : i0;

			boost::shared_ptr<VelocityMotor> velocityMotor = Creatable<Instance>::create<VelocityMotor>();
			velocityMotor->setParent(first);
			velocityMotor->setHole(static_cast<Hole*>(second));
		}
	}
}
