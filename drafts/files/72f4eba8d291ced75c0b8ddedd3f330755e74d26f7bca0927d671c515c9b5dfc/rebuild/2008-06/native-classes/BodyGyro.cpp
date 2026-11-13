// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I/tmp/claude-0/-home-user/28a5ad2c-f9ca-5f88-a52d-b9a089ed390b/scratchpad/inc
// 2008-06 native RBX::BodyGyro rows of the original BodyMovers unit (0062e090..00633101) that read 2008 Body fields
// (inactive): BodyGyro::computeOrientation 0062e910 and BodyGyro::computeBalance 0062ec40. BodyGyro::computeForce
// 006300d0 (their only caller) is in native-classes/BodyMovers.cpp.
//
// This unit does not include native-headers/v8datamodel/BodyMovers.h: that header reaches native-headers/v8kernel/
// Connector2008.h, which includes the donor v8kernel/Body.h (root +0x4, simBody +0x20), while these bodies read the
// 2008 Body (native-headers/v8kernel/Body2008.h: root +0x10, cofm +0x28, simBody +0x2c, moment +0x68, pv +0x94), and
// the two Body declarations cannot share a unit (C2011). Following native-classes/ContactUnit2008ConnectorBody.cpp,
// Connector, BodyMover and BodyGyro are redeclared here, unit-locally, exactly as Connector2008.h and BodyMovers.h
// declare them (same bases, virtual slots, fields and offsets cited there). No constructor or vtable is emitted.
// Header proposal (Body2008.h, body/primitive owner): getBranchTorque() and getBranchIBodyV3() below, read from the
// inlined code of both functions; with them and Connector2008.h on Body2008.h this unit can include BodyMovers.h.
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include <G3D/g3dmath.h>
#include "v8kernel/KernelIndex.h"
#include "v8kernel/Body2008.h"
#include "v8tree/Instance.h"
#include "util/RunStateOwner.h"
#include "util/Math.h"

namespace RBX
{
	class World;
	class PartInstance;

	class Connector : public KernelIndex
	{
	public:
		virtual ~Connector() {}                                         // slot 0
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

	class BodyMover : public Instance, public Connector, public Listener<RunService, Stepped>
	{
	protected:
		World* world;                                  // +0x13c
		boost::weak_ptr<PartInstance> part;            // +0x140

	protected:
		BodyMover(const char* name);                   // 0062e320
	public:
		virtual ~BodyMover();                          // 0062e460
		virtual bool askSetParent(const Instance* instance) const; // 0062e190
	protected:
		virtual void onAncestorChanged(const AncestorChanged& event); // 006308f0
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 00632db0
		virtual bool preventBodySleep() const          // slot 16
		{
			return true;
		}
		virtual void onEvent(const RunService* source, Stepped event); // 0062fae0
	};

	extern char sBodyGyro[];

	class BodyGyro : public DescribedCreatable<BodyGyro, BodyMover, sBodyGyro>
	{
	private:
		float kP;                                      // +0x148
		float kD;                                      // +0x14c
		G3D::Vector3 maxTorque;                        // +0x150
		G3D::CoordinateFrame cframe;                   // +0x15c

	private:
		void computeBalance(Body* body);               // 0062ec40
		void computeOrientation(Body* body);           // 0062e910
	public:
		BodyGyro();                                    // 00632070
		virtual void computeForce(const float dt, bool throttling); // 006300d0
	};

	// 0062e910: donor tools/rbxgs Gyro.cpp BodyGyro::computeOrientation.
	void BodyGyro::computeOrientation(Body* body)
	{
		if (G3D::fuzzyEq(maxTorque.y, 0.0f))
			return;

		Body* root = body->getRoot();

		G3D::Vector3 oldTorqueWorld = root->getBranchTorque();

		G3D::Vector3 localZNegAxis = body->getCoordinateFrame().vectorToObjectSpace(cframe.lookVector());

		float desiredTorqueY = -(root->getBranchIBodyV3().y * localZNegAxis.x * kP);

		G3D::Vector3 torqueBody = body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);

		if (fabs(desiredTorqueY - torqueBody.y) < root->getBranchIBodyV3().y * maxTorque.y)
			torqueBody.y = desiredTorqueY;
		else
			torqueBody.y = torqueBody.y + desiredTorqueY;

		G3D::Vector3 angVelBody = body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
		torqueBody.y = torqueBody.y - kD * root->getBranchIBodyV3().y * angVelBody.y;

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;

		root->accumulateTorque(addedTorque);
	}

	// 0062ec40: donor tools/rbxgs Gyro.cpp BodyGyro::computeBalance.
	void BodyGyro::computeBalance(Body* body)
	{
		if (G3D::fuzzyEq(maxTorque.x, 0.0f) && G3D::fuzzyEq(maxTorque.z, 0.0f))
			return;

		Body* root = body->getRoot();
		G3D::Vector3 oldTorqueWorld = root->getBranchTorque();
		G3D::Vector3 localYAxis = body->getCoordinateFrame().vectorToObjectSpace(cframe.upVector());
		float desiredTorqueX = root->getBranchIBodyV3().x * localYAxis.z * kP;
		float desiredTorqueZ = -(root->getBranchIBodyV3().z * localYAxis.x * kP);

		G3D::Vector3 torqueBody = body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);

		if (fabs(desiredTorqueX - torqueBody.x) < root->getBranchIBodyV3().x * maxTorque.x)
			torqueBody.x = desiredTorqueX;
		else
			torqueBody.x += desiredTorqueX;

		if (fabs(desiredTorqueZ - torqueBody.z) < root->getBranchIBodyV3().z * maxTorque.z)
			torqueBody.z = desiredTorqueZ;
		else
			torqueBody.z += desiredTorqueZ;

		G3D::Vector3 angVelBody = body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
		torqueBody.x -= kD * (root->getBranchIBodyV3().x * angVelBody.x);
		torqueBody.z -= kD * (root->getBranchIBodyV3().z * angVelBody.z);

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;

		root->accumulateTorque(addedTorque);
	}
}
