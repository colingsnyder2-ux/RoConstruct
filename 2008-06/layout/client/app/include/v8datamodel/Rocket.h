#pragma once
#include "v8datamodel/BodyMovers.h"

namespace RBX
{
	extern char sRocket[];

	class Rocket : public DescribedCreatable<Rocket, BodyMover, sRocket>
	{
		friend struct ::NativeBodyMoverLayout;
	private:
		bool active;                                   // +0x148 (fire 0062e1c0 / abort 0062e290)
		boost::shared_ptr<PartInstance> target;        // +0x14c (setTarget 00632fd0)
		G3D::Vector3 targetOffset;                     // +0x154
		float targetRadius;                            // +0x160 (4)
		bool firedEvent;                               // +0x164 (onGoalChanged 0062e0f0)
		float maxThrust;                               // +0x168 (4000)
		float kThrustP;                                // +0x16c (5)
		float kThrustD;                                // +0x170 (0.001)
		float maxSpeed;                                // +0x174 (30)
		float kTurnP;                                  // +0x178 (3000)
		float kTurnD;                                  // +0x17c (500)
		G3D::Vector3 maxTorque;                        // +0x180 (400000, 400000, 0)
		float cartoonFactor;                           // +0x18c (0.7)
	public:
		static Reflection::RefPropDescriptor<Rocket, PartInstance> prop_Target;
		static Reflection::BoundProp<G3D::Vector3, 1> prop_targetOffset;
		static Reflection::BoundProp<float, 1> prop_targetRadius;
		static Reflection::BoundProp<float, 1> prop_MaxThrust;
		static Reflection::BoundProp<float, 1> prop_ThrustP;
		static Reflection::BoundProp<float, 1> prop_ThrustD;
		static Reflection::BoundProp<float, 1> prop_MaxSpeed;
		static Reflection::BoundProp<G3D::Vector3, 1> prop_MaxTorque;
		static Reflection::BoundProp<float, 1> prop_TurnP;
		static Reflection::BoundProp<float, 1> prop_TurnD;
		static Reflection::BoundProp<float, 1> prop_CartoonFactor;
		static Reflection::BoundFuncDesc<Rocket, void(void), 0> func_Fire;
		static Reflection::BoundFuncDesc<Rocket, void(void), 0> func_Abort;
		static Reflection::SignalDesc<Rocket, void(void)> event_ReachedTarget;

	public:
		Rocket();                                      // 00632b50
		void fire();                                   // 0062e1c0
		void abort();                                  // 0062e290
		virtual void computeForce(const float dt, bool throttling); // 0062fc00 (not recovered)
	protected:
		virtual void onEvent(const RunService* source, Stepped event); // 00632e10 (not recovered)
	private:
		G3D::Vector3 turn(Body* body, const G3D::Vector3& targetDir); // 0062e530 (not recovered)
		PartInstance* getTarget() const
		{
			return target.get();                       // 00609a50 (ICF-shared)
		}
		void setTarget(PartInstance* value);           // 00632fd0
		void onGoalChanged(const Reflection::PropertyDescriptor&)
		{
			firedEvent = false;                        // 0062e0f0
		}
	};

}
