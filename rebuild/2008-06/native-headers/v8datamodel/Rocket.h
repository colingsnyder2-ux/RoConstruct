#pragma once
// 2008-06 native RBX::Rocket (inactive): a BodyMover subclass (RTTI .?AVRocket@RBX@@ lists BodyMover as its base,
// DescribedCreatable<Rocket, BodyMover, sRocket>). The original compiles it in the BodyMover unit (0062e090..
// 00633101); evidence for the shared base is in v8datamodel/BodyMovers.h. Verified by
// tests/record_native_body_movers.py.
//   size       0x190: Creatable<Instance>::create<Rocket> 005c28a0 allocates 0x190; constructor 00632b50 stores every
//              field below (defaults in the comments).
//   descriptors dynamic initializers 007f7f10..007f8190: prop_Target 0097cae8 (RefPropDescriptor, getter 00609a50,
//              setter 00632fd0), prop_targetOffset 0097c774 / prop_targetRadius 0097c758 (BoundProp with the
//              onGoalChanged 0062e0f0 callback), MaxSpeed 0097c8cc, MaxThrust 0097c73c, ThrustP 0097c944, ThrustD
//              0097c928, TurnP 0097ca50, TurnD 0097c7ac, MaxTorque 0097c850, CartoonFactor 0097c694 (functionality 5),
//              func_Fire 0097c870 / func_Abort 0097ca70 (security 0), event_ReachedTarget 0097c81c.
#include "v8datamodel/BodyMovers.h"

namespace RBX
{
	// RTTI vtable 0084816c .?AVRocket@RBX@@: DescribedCreatable<Rocket, BodyMover, sRocket>; class name
	// "RocketPropulsion". No user-declared destructor: 00632d10 releases target and calls ~FactoryProduct without
	// re-storing the vtables.
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
