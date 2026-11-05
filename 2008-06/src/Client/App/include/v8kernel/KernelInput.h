#pragma once
#include "v8kernel/Constants.h"

namespace RBX
{
	class KernelInput
	{
	private:
		float lastGoal;
		float currentGoal;
		float increment;
		bool latchToZero;
	private:
		// NOTE: this is a guess
		const int steps()
		{
			return Constants::kernelStepsPerUiStep();
		}
	public:
		KernelInput() : lastGoal(0), currentGoal(0), latchToZero(false), increment(0) {}

		// NOTE: this is a guess
		void setGoal(float goal)
		{
			if (this->latchToZero)
			{
				this->latchToZero = false;
				this->currentGoal = (this->currentGoal + goal) * 0.5f;
			}

			this->currentGoal += this->increment;
		}

		// NOTE: this is a guess
		void setDelta(float value)
		{
			this->increment = value;
			if (value == 0.0f)
				this->latchToZero = true;
		}

		// NOTE: there is no evidence of this existing, but something like this is required for RotatePJoint
		template<typename Function>
		void setGoalCalc(float value, Function calculateIncrementFunc)
		{
			if (value == this->lastGoal)
			{
				this->currentGoal = value;
				this->increment = 0.0f;
			}
			else
			{
				this->lastGoal = value;
				this->increment = calculateIncrementFunc(value, this->currentGoal, steps());
			}
		}

		void get(float _lastGoal, float& _currentGoal, float& _increment)
		{
			// is the first parameter not being a reference intentional? was it used for something else?
			_lastGoal = this->lastGoal;
			_currentGoal = this->currentGoal;
			_increment = this->increment;
		}
	};
}