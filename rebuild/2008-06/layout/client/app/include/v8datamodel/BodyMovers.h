// =============================================================================
// BodyMovers.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/BodyMovers.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
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
		virtual bool preventBodySleep() const          // slot 16
		{
			return true;                               // 00565950 (ICF-shared)
		}
		virtual void onEvent(const RunService* source, Stepped event); // 0062fae0 (not recovered: needs Primitive at PartInstance+0x228)
		virtual Body* getBody(int i);                  // 0062fa10 (native-classes/BodyMovers.cpp)
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
		void computeBalance(Body* body);               // 0062ec40 (native-classes/BodyGyro.cpp; parked, 2008 Body)
		void computeOrientation(Body* body);           // 0062e910 (native-classes/BodyGyro.cpp; needs 2008 Body)
	public:
		BodyGyro();                                    // 00632070
		virtual void computeForce(const float dt, bool throttling); // 006300d0 (BodyMovers.cpp, part-embedded)
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
		virtual void computeForce(const float dt, bool throttling); // 00630140 (native-classes/RocketControl.cpp, 2008 Body; parked)
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
		virtual void computeForce(const float dt, bool throttling); // 006302d0 (native-classes/RocketControl.cpp, 2008 Body)
	};

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
		virtual void computeForce(const float dt, bool throttling); // 00630420 (native-classes/RocketControl.cpp, 2008 Body)
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
		virtual void computeForce(const float dt, bool throttling); // 00630570 (native-classes/RocketControl.cpp, 2008 Body; parked)
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
		virtual void computeForce(const float dt, bool throttling); // 00630610 (native-classes/RocketControl.cpp, 2008 Body; parked)
	};

	void registerBodyMovers();                         // 00630860
}
