// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_656e438fa0359e17.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include "v8kernel/Connector.h"
#include "v8kernel/Point.h"
namespace RBX
{
	// 2008-06 layouts from the target: SimBody dirty at +8, torque at +0x90;
	// Body root at +0x10, simBody at +0x2c.
	class SimBody2008
	{
		char prefix[8];
		bool dirty;
		char gap[0x90 - 9];
		G3D::Vector3 torque;
		void update();
	public:
		void accumulateTorque(const G3D::Vector3& _torque)
		{
			if (dirty)
				update();
			torque += _torque;
		}
	};

	class Body2008
	{
		char prefix[0x10];
		Body2008* root;
		char gap[0x18];
		SimBody2008* simBody;
	public:
		void accumulateTorque(const G3D::Vector3& torque)
		{
			SimBody2008* simBody = root->simBody;
			if (simBody)
				simBody->accumulateTorque(torque);
		}
	};

	class KernelInput2008
	{
		float lastGoal;
		float currentGoal;
		float increment;
		bool latchToZero;
	public:
		float step(float goal)
		{
			if (latchToZero)
			{
				latchToZero = false;
				currentGoal = (currentGoal + goal) * 0.5f;
			}
			float result = currentGoal;
			currentGoal += increment;
			return result;
		}
	};

	void RotateConnector::computeForce(const float dt, bool throttling)
	{
		G3D::Vector3 normal;
		float rotation;
		float rotVel;
		this->computeParams(normal, rotation, rotVel);

		float currentGoal = ((KernelInput2008*)this->getKernelInput())->step(rotation);

		float v1 = (currentGoal - rotation) * this->k;
		G3D::Vector3 v2 = normal * v1;

		((Body2008*)this->ref0->getBody())->accumulateTorque(-v2);
		((Body2008*)this->ref1->getBody())->accumulateTorque(v2);
	}
}
