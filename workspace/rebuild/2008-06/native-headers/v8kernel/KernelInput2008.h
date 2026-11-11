#pragma once
// >>> native-status (generated) -- do not edit >>>
// KernelInput2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 77719ad2 | roc native-status --write
// 2008-06 native RBX::KernelInput (inactive). Declared under a non-colliding name: the original path
// v8kernel/KernelInput.h is the donor header (reached through the donor v8kernel/Connector.h by every kernel / joint
// unit); a unit must not include both this header and the donor v8kernel/KernelInput.h (or v8kernel/Connector.h).
// Every field and inline body below is read from the 2008-06 binary (KernelInput is embedded in RotateConnector at
// +0x24, so the offsets below are given relative to the KernelInput and to the connector):
//   ctor     RotateConnector() 00606170 zeroes lastGoal +0x0 (+0x24), currentGoal +0x4 (+0x28), increment +0x8
//            (+0x2c) with fldz/fst and latchToZero +0xc (+0x30) with a byte store.
//   setGoal  RotateConnector::computeForce 006064a0: if latchToZero (006064ce), clear it and set
//            currentGoal = (currentGoal + goal) * 0.5f (006064d4..006064e3, constant 00819bac); then the current goal
//            is read (006064e6) before the increment is added (006064ea..006064f0 `fld +0x2c; fadd +0x28`), and the
//            value read is the one the connector uses (006064f9 fsubrp). The donor setGoal adds the increment
//            first and get() then returns the new value.
namespace RBX
{
	class KernelInput
	{
	private:
		float lastGoal;      // +0x0
		float currentGoal;   // +0x4
		float increment;     // +0x8
		bool latchToZero;    // +0xc

	public:
		KernelInput() : lastGoal(0), currentGoal(0), increment(0), latchToZero(false) {}

		// 006064ce..006064f0 (inlined): returns the goal of this step and advances by the increment.
		float setGoal(float goal)
		{
			if (latchToZero)
			{
				latchToZero = false;
				currentGoal = (currentGoal + goal) * 0.5f;
			}
			float answer = currentGoal;
			currentGoal = increment + currentGoal;
			return answer;
		}
	};
}
