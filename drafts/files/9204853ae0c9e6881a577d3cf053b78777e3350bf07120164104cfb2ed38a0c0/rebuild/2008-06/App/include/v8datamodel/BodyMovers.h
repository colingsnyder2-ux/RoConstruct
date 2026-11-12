#pragma once
// 2008-06 native RBX::BodyMover family (inactive): BodyGyro, BodyPosition, BodyVelocity, BodyAngularVelocity,
// BodyForce, BodyThrust; Rocket (same original unit) is in v8datamodel/Rocket.h. Shape after the donor tools/rbxgs v8datamodel/Gyro.h; every field, virtual,
// default and descriptor below is read from the 2008-06 binary (unit 0062e090..00633101, dynamic initializers
// 007f7f10..007f85a0). Verified by tests/record_native_body_movers.py.
//
//   BodyMover  RTTI vtable 00846bec .?AVBodyMover@RBX@@ (21 bases): Instance, Connector at +0x130 (vptr; its
//              KernelIndex int at +0x134, set to -1 by the constructor 0062e320), Listener<RunService, Stepped>
//              at +0x138 (vptr only: native util/Events.h Listener is novtable with no fields).
//              Constructor 0062e320 zeroes +0x13c (World* world) and +0x140/+0x144 (boost::weak_ptr<PartInstance>
//              part: destructor 0062e460 releases the count at +0x144 with weak_release, vtable slot 2; Connector
//              slot 4 0062fa10 and onAncestorChanged 006308f0 call weak_ptr<PartInstance>::lock 005cab00 on +0x140).
//              Destructor 0062e460 re-stores every vtable, so it is user-declared.
//              Primary vtable (17 slots): Instance slots 0..15 with askSetParent 0062e190 (dynamic_cast to
//              PartInstance), onAncestorChanged 006308f0, onServiceProvider 00632db0; slot 16 is the new virtual
//              preventBodySleep (00565950 return true; BodyVelocity/BodyAngularVelocity 00632370, BodyForce/BodyThrust
//              00632720). Listener vtable 00846b48 = {onEvent 0062fae0, destructor thunk}; Connector vtable 00846b54 =
//              {destructor thunk, computeForce, 00565950, 0060a2f0, 0062fa10, 005e72c0} (the 2008 Connector has six
//              slots, the donor v8kernel/Connector.h five: see the proposal in tests/record_native_body_movers.py).
//   classes    DescribedCreatable<X, BodyMover, sX>, sX a non-const char array in .data (RTTI $1?sX@2@3PADA):
//              sBodyPosition 0095c6e8, sBodyVelocity 0095c6f8, sBodyGyro 0095c708, sBodyAngularVelocity 0095c714,
//              sBodyForce 0095c728, sBodyThrust 0095c734, sRocket 0095c740 = "RocketPropulsion". Each constructor
//              passes the array itself to Instance(const char*) as the initial name.
//   sizes      Creatable<Instance>::create<X> allocations: BodyGyro 0x18c (005c1a00), BodyPosition 0x174 (005c2150),
//              BodyVelocity 0x170 (005c23c0), BodyAngularVelocity 0x170 (005c2630), BodyForce 0x154 (005c1c70),
//              BodyThrust 0x160 (005c1ee0), Rocket 0x190 (005c28a0).
#include "v8tree/Instance.h"
#include "util/RunStateOwner.h"
#include "v8kernel/Connector.h"
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>

struct NativeBodyMoverLayout;

namespace RBX
{
	class World;
	class PartInstance;

	class BodyMover : public Instance, public Connector, public Listener<RunService, Stepped>
	{
		friend struct ::NativeBodyMoverLayout; // tests/NativeBodyMoverLayout.cpp offset asserts
	protected:
		World* world;                                  // +0x13c
		boost::weak_ptr<PartInstance> part;            // +0x140

	protected:
		BodyMover(const char* name);                   // 0062e320
	public:
		virtual ~BodyMover();                          // 0062e460 (deleting 0062f980)
		virtual bool askSetParent(const Instance* instance) const; // 0062e190 (ICF-shared with Sparkles)
	protected:
		virtual void onAncestorChanged(const AncestorChanged& event); // 006308f0
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 00632db0
		// Connector slot 4: the Connector sub-vtable 00846b54 listed in the header comment above is
		// {destructor thunk, computeForce, 00565950, 0060a2f0, 0062fa10, 005e72c0}, so slot 4 is BodyMover's own
		// 0062fa10 (the donor v8kernel/Connector.h declares no such name; 'getBody(int)' is the analog name used
		// by Connector slot 4 in v8kernel/Connector2008.h). Without this override BodyMover - and every
		// DescribedCreatable<X, BodyMover, sX> - stays abstract, so Object<BodyGyro> cannot instantiate.
		// INFERRED: vtable contents (header comment above); the body at 0062fa10 is not recovered yet.
		virtual Body* getBody(int i);                                   // slot 4 (0062fa10)
		virtual bool preventBodySleep() const          // slot 16
		{
			return true;                               // 00565950 (ICF-shared)
		}
		virtual void onEvent(const RunService* source, Stepped event); // 0062fae0 (not recovered: needs Primitive at PartInstance+0x228)
	};

	extern char sBodyGyro[];

	class BodyGyro : public DescribedCreatable<BodyGyro, BodyMover, sBodyGyro>
	{
		friend struct ::NativeBodyMoverLayout;
	private:
		float kP;                                      // +0x148 (3000)
		float kD;                                      // +0x14c (500)
		G3D::Vector3 maxTorque;                        // +0x150 (400000, 0, 400000)
		G3D::CoordinateFrame cframe;                   // +0x15c
	public:
		static Reflection::BoundProp<float, 1> prop_kP;
		static Reflection::BoundProp<float, 1> prop_kD;
		static Reflection::BoundProp<G3D::Vector3, 1> prop_maxTorque;
		static Reflection::BoundProp<G3D::CoordinateFrame, 1> prop_cframe;

	private:
		void computeBalance(Body* body);               // 0062ec40 (not recovered)
		void computeOrientation(Body* body);           // 0062e910 (not recovered)
	public:
		BodyGyro();                                    // 00632070
		virtual void computeForce(const float dt, bool throttling); // 006300d0 (not recovered)
	};

	extern char sBodyPosition[];

	class BodyPosition : public DescribedCreatable<BodyPosition, BodyMover, sBodyPosition>
	{
		friend struct ::NativeBodyMoverLayout;
	private:
		float kP;                                      // +0x148 (10000)
		float kD;                                      // +0x14c (1250)
		G3D::Vector3 maxForce;                         // +0x150 (4000, 4000, 4000)
		G3D::Vector3 position;                         // +0x15c (0, 50, 0)
		G3D::Vector3 lastForce;                        // +0x168
	public:
		static Reflection::BoundProp<float, 1> prop_kP;
		static Reflection::BoundProp<float, 1> prop_kD;
		static Reflection::BoundProp<G3D::Vector3, 1> prop_maxForce;
		static Reflection::BoundProp<G3D::Vector3, 1> prop_position;

	public:
		BodyPosition();                                // 00632190
		G3D::Vector3 getLastForce();                   // 0062e090
		virtual void computeForce(const float dt, bool throttling); // 00630140 (not recovered)
	};

	extern char sBodyVelocity[];

	class BodyVelocity : public DescribedCreatable<BodyVelocity, BodyMover, sBodyVelocity>
	{
		friend struct ::NativeBodyMoverLayout;
	private:
		float kP;                                      // +0x148 (1250)
		G3D::Vector3 maxForce;                         // +0x14c (4000, 4000, 4000)
		G3D::Vector3 velocity;                         // +0x158 (0, 2, 0)
		G3D::Vector3 lastForce;                        // +0x164
	public:
		static Reflection::BoundProp<float, 1> prop_kP;
		static Reflection::BoundProp<G3D::Vector3, 1> prop_maxForce;
		static Reflection::BoundProp<G3D::Vector3, 1> prop_velocity;

	protected:
		virtual bool preventBodySleep() const;         // 00632370 (ICF-shared with BodyAngularVelocity)
	public:
		BodyVelocity();                                // 00632290
		G3D::Vector3 getLastForce();                   // 0062e0c0
		virtual void computeForce(const float dt, bool throttling); // 006302d0 (not recovered)
	};

	// Not in the donor. Same shape as BodyVelocity (constructor 00632400, size 0x170); the descriptors 007f8490..
	// 007f84f0 name +0x148 "P", +0x14c "maxTorque", +0x158 "angularvelocity". +0x164 has no descriptor: the constructor
	// zeroes it and computeForce 00630420 stores the torque clamped by maxTorque there (Connector this +0x34) before
	// adding it to the body's torque (name after BodyVelocity::lastForce).
	extern char sBodyAngularVelocity[];

	class BodyAngularVelocity : public DescribedCreatable<BodyAngularVelocity, BodyMover, sBodyAngularVelocity>
	{
		friend struct ::NativeBodyMoverLayout;
	private:
		float kP;                                      // +0x148 (1250)
		G3D::Vector3 maxTorque;                        // +0x14c (4000, 4000, 4000)
		G3D::Vector3 angularVelocity;                  // +0x158 (0, 2, 0)
		G3D::Vector3 lastTorque;                       // +0x164
	public:
		static Reflection::BoundProp<float, 1> prop_kP;
		static Reflection::BoundProp<G3D::Vector3, 1> prop_maxTorque;
		static Reflection::BoundProp<G3D::Vector3, 1> prop_angularVelocity;

	protected:
		virtual bool preventBodySleep() const;         // 00632370 (ICF-shared with BodyVelocity)
	public:
		BodyAngularVelocity();                         // 00632400
		virtual void computeForce(const float dt, bool throttling); // 00630420 (not recovered)
	};

	extern char sBodyForce[];

	class BodyForce : public DescribedCreatable<BodyForce, BodyMover, sBodyForce>
	{
		friend struct ::NativeBodyMoverLayout;
	private:
		G3D::Vector3 force;                            // +0x148 (Vector3::unitY())
	public:
		static Reflection::BoundProp<G3D::Vector3, 1> prop_Force;

	protected:
		virtual bool preventBodySleep() const;         // 00632720 (ICF-shared with BodyThrust)
	public:
		BodyForce();                                   // 006324f0
		virtual void computeForce(const float dt, bool throttling); // 00630570 (not recovered)
	};

	extern char sBodyThrust[];

	class BodyThrust : public DescribedCreatable<BodyThrust, BodyMover, sBodyThrust>
	{
		friend struct ::NativeBodyMoverLayout;
	private:
		G3D::Vector3 force;                            // +0x148 (Vector3::unitY())
		G3D::Vector3 location;                         // +0x154 (Vector3::zero())
	public:
		static Reflection::BoundProp<G3D::Vector3, 1> prop_force;
		static Reflection::BoundProp<G3D::Vector3, 1> prop_location;

	protected:
		virtual bool preventBodySleep() const;         // 00632720 (ICF-shared with BodyForce)
	public:
		BodyThrust();                                  // 006325e0
		virtual void computeForce(const float dt, bool throttling); // 00630610 (not recovered)
	};

	void registerBodyMovers();                         // 00630860
}
