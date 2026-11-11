#pragma once
// >>> native-status (generated) -- do not edit >>>
// Connector2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src cae16136 | roc native-status --write
// 2008-06 native RBX::Connector, ContactConnector, PointToPointBreakConnector, NormalBreakConnector, RotateConnector
// (inactive). Declared under a non-colliding name: the original path v8kernel/Connector.h is reached through the donor
// v8kernel/KernelData.h <- Kernel.h <- IPipelined.h by every engine unit (Edge, Joint, Contact, Primitive, World ...),
// so a header at that path would shadow the donor for nearly all recorders (see the proposal in
// tests/record_native_world_joints.py). A unit must not include both this header and v8kernel/Connector.h (or
// v8kernel/Kernel.h, v8world/Edge.h, which include it).
// The bases come from the donor headers: KernelIndex (kernelIndex = -1 at +0x4: RotateConnector() 00606170 and
// ContactConnector() 00606d40 store -1 at +4 after the vptr), Point (body +0xc, worldPos +0x1c: getBody 00606150,
// potentialEnergy 006061f0), GeoPair (0x24 bytes, body0 +0xc / body1 +0x10: ContactConnector::getBody 00606230 reads
// +0x14 / +0x18 of the connector), KernelInput (+0x24 of RotateConnector: lastGoal / currentGoal / increment /
// latchToZero, read by RotatePJoint::stepWorld 00645cb0 and RotateVJoint::stepWorld 00645d00).
// Every Connector slot, field and size below is read from the 2008-06 binary:
//   RTTI     Connector 0083d1f4 -> KernelIndex (mdisp 4: the public non-polymorphic base after the vptr);
//            ContactConnector 00842834, RotateConnector 00842804, PointToPointBreakConnector 0084ada8 -> Connector;
//            NormalBreakConnector 0084ae5c -> PointToPointBreakConnector -> Connector.
//   slots    6: 0 scalar deleting dtor (006062c0, shared by every connector: all destructors are empty and only the
//            Connector vtable store survives), 1 computeForce (`ret 8`: RotateConnector 006064a0, P2P 006065d0,
//            NormalBreak 00606670, Contact 00606780; _purecall in Connector), 2 canThrottle (Connector 00565950
//            `mov al, 1`; ContactConnector 00606250), 3 getBroken (Connector 0060a2f0 false; P2P 00645a60 reads +0x18),
//            4 `Body* (int)` (`ret 4`; _purecall in Connector; P2P 00606150, RotateConnector 006061d0, Contact
//            00606230) -- no donor declaration, getBody is an analog name --, 5 potentialEnergy (Connector 005e72c0
//            `fldz`; P2P 006061f0).
//   sizes    PointToPointBreakConnector 0x1c (RotateJoint::putInKernel 00646550 news 0x1c), RotateConnector 0x34 (same
//            function news 0x34), NormalBreakConnector 0x20 (GlueJoint::putInKernel 00647190 news 0x20),
//            ContactConnector 0x50 (constructor 00606d40 writes up to frictionOffset.z +0x4c).
#include <G3D/Vector3.h>
#include "v8kernel/KernelIndex.h"
#include "v8kernel/KernelInput.h"
#include "v8kernel/Body.h"
#include "v8kernel/Pair.h"
#include "v8kernel/Point.h"
#include "util/Math.h"

struct NativeWorldJointsConnectorLayout;

namespace RBX
{
	class Connector : public KernelIndex
	{
	public:
		Connector() {}
		// KernelData indexes Connector through the proven KernelIndex +0x4
		// field.  Inline only: no object layout or vtable effect.
		int& getKernelIndex() { return kernelIndex; }
		virtual ~Connector() {}                                         // slot 0 (??_G 006062c0)
		virtual void computeForce(const float dt, bool throttling) = 0; // slot 1
		virtual bool canThrottle() const                                // slot 2 (00565950)
		{
			return true;
		}
		virtual bool getBroken()                                        // slot 3 (0060a2f0)
		{
			return false;
		}
		virtual Body* getBody(int i) = 0;                               // slot 4 (analog name)
		virtual float potentialEnergy()                                 // slot 5 (005e72c0)
		{
			return 0;
		}
	};

	// ContactConnector(k, kNeg, kFriction) 00606d40: GeoPair() 00613060 at +0x8, frictionOffset +0x44 = 0 then
	// Vector3::zero(), k +0x2c, kNeg +0x34, kFriction +0x30, firstApproach +0x38, threshold +0x3c, forceMagLast +0x40.
	class ContactConnector : public Connector
	{
		friend struct ::NativeWorldJointsConnectorLayout;

	protected:
		GeoPair geoPair;                  // +0x8
		float k;                          // +0x2c
		float kFriction;                  // +0x30
		float kNeg;                       // +0x34
		float firstApproach;              // +0x38
		float threshold;                  // +0x3c
		float forceMagLast;               // +0x40
		G3D::Vector3 frictionOffset;      // +0x44

	public:
		ContactConnector(float _k, float _kNeg, float _kFriction)       // 00606d40
			: geoPair()
		{
			k = _k;
			kNeg = _kNeg;
			kFriction = _kFriction;
			frictionOffset = G3D::Vector3::zero();
			firstApproach = 0;
			threshold = 0;
			forceMagLast = 0;
		}

		virtual void computeForce(const float dt, bool throttling);    // slot 1 (00606780)
		virtual bool canThrottle() const;                               // slot 2 (00606250; reads Body +0x30)
		virtual Body* getBody(int i)                                    // slot 4 (00606230)
		{
			return geoPair.getBody(i);
		}
	};

	// PointToPointBreakConnector: point0 +0x8, point1 +0xc, k +0x10 (potentialEnergy 006061f0), breakForce +0x14,
	// broken +0x18 (getBroken 00645a60).
	class PointToPointBreakConnector : public Connector
	{
		friend struct ::NativeWorldJointsConnectorLayout;

	protected:
		Point* point0;                    // +0x8
		Point* point1;                    // +0xc
		float k;                          // +0x10
		float breakForce;                 // +0x14
		bool broken;                      // +0x18

	public:
		PointToPointBreakConnector(Point* _point0, Point* _point1, float _k, float _breakForce)
			: point0(_point0),
			  point1(_point1),
			  k(_k),
			  breakForce(_breakForce),
			  broken(false)
		{
		}

		virtual void computeForce(const float dt, bool throttling);    // slot 1 (006065d0)
		virtual bool getBroken()                                        // slot 3 (00645a60)
		{
			return broken;
		}
		virtual Body* getBody(int i);                                   // slot 4 (00606150)
		virtual float potentialEnergy();                                // slot 5 (006061f0)
	};

	class NormalBreakConnector : public PointToPointBreakConnector
	{
		friend struct ::NativeWorldJointsConnectorLayout;

	private:
		NormalId normalIdBody0;           // +0x1c

	public:
		NormalBreakConnector(Point* _point0, Point* _point1, float _k, float _breakForce, NormalId _normalIdBody0)
			: PointToPointBreakConnector(_point0, _point1, _k, _breakForce),
			  normalIdBody0(_normalIdBody0)
		{
		}

		virtual void computeForce(const float dt, bool throttling);    // slot 1 (00606670)
	};

	// RotateConnector(base0, ray0, ref0, ref1, kValue, armLength) 00606170: k +0x8 = kValue * armLength * armLength,
	// base0 +0xc, ray0 +0x10, ref0 +0x14, ref1 +0x18, lastRotation +0x1c = 0, windings +0x20 = 0, kernelInput +0x24.
	class RotateConnector : public Connector
	{
		friend struct ::NativeWorldJointsConnectorLayout;

	private:
		float k;                          // +0x8
		Point* base0;                     // +0xc
		Point* ray0;                      // +0x10
		Point* ref0;                      // +0x14
		Point* ref1;                      // +0x18
		float lastRotation;               // +0x1c
		int windings;                     // +0x20
		KernelInput kernelInput;          // +0x24

	public:
		RotateConnector(Point* base0, Point* ray0, Point* ref0, Point* ref1, float kValue, float armLength);   // 00606170
		KernelInput* getKernelInput()
		{
			return &kernelInput;
		}
		virtual void computeForce(const float dt, bool throttling);    // slot 1 (006064a0)
		virtual Body* getBody(int i);                                   // slot 4 (006061d0)
	};
}
