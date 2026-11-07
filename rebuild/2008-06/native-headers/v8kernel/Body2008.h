#pragma once
// 2008-06 native RBX::Body and RBX::Cofm (inactive). Declared under a non-colliding name: the original path
// v8kernel/Body.h is reached through the donor v8kernel/KernelData.h <- Kernel.h <- IPipelined.h <- Edge.h by every
// engine unit, and through v8kernel/Connector2008.h / Point.h / Pair.h, so a header at that path would shadow the donor
// for nearly all recorders. A unit must not include both this header and the donor v8kernel/Body.h, Cofm.h or
// SimBody.h (or any header that reaches them: Connector2008.h, Contact2008.h, Point.h, Edge.h, Kernel.h ...).
//
// Every Body field, size and offset below is read from the 2008-06 binary:
//   size     0xdc: the world body initializer 00614b40 and Primitive() 005e8770 (005e8865) new 0xdc, then call
//            Body() 006149c0.
//   ctor     006149c0: +0x0 kernelIndex = -1, +0x4 = -1, +0x8 = 0, +0xc (byte) = false, root +0x10 = NULL, parent +0x14
//            = NULL, index +0x18 = -1, children (G3D::Array data / num / numAllocated +0x1c / +0x20 / +0x24) = 0,
//            cofm +0x28 = NULL, simBody +0x2c = NULL, canThrottle +0x30 = true, link +0x34 = NULL, meInParent +0x38
//            (CoordinateFrame() 004782d0), moment +0x68 = Matrix3::zero() (00513e20, operator= 00513220), mass +0x8c = 0,
//            stateIndex +0x90 = getNextStateIndex() (inline; its function-local static counter is 0095a898), pv +0x94 (CoordinateFrame() + Velocity()
//            00614170 at +0xc4), then root = this and simBody = new SimBody(this) (0xb4, constructor 00658ae0).
//   dtor     00614ac0: setParent(NULL) 006148b0 when parent is set, delete simBody (~SimBody, folded empty body 0047d410),
//            ~children (G3D::Array: alignedFree 00507d20, then data / num / numAllocated = 0).
//   +0x4     index into the KernelData body array at +0xc: insertBody 005faf90 / addLeafBodies 005faed0 /
//            removeBody 005faf20 test it against 0, swap-remove through it and reset it to -1.
//   +0x8     int counter of connectors on the body: Kernel insertConnector 005faff0 `inc [body + 8]`, removeConnector
//            005fb050 `dec [body + 8]`; 005faed0 adds a child to the KernelData array only when it is > 0.
//   +0xc     bool: only the constructor stores it (006149e9 `mov byte [esi + 0xc], 0`); no reader was found in the image.
//   root     calcRoot 00613ef0 walks parent +0x14; resetRoot 00614530 stores +0x10 and recurses over children.
//   cofm     getBranchMass 00613f00 (Cofm::getMass 0065ff10 or mass +0x8c), getBranchIWorldAtPoint 006145e0 (Cofm::
//            getMoment 00660170 or moment +0x68), onChildAdded 006147f0 news the 0x3c Cofm(this) 0065fef0.
//   pv       updatePV 00599360 (stateIndex +0x90, pv +0x94, meInParent +0x38 or Link::getChildInParent 00613d60);
//            setCoordinateFrame 00614400 copies pv.velocity +0xc4..+0xd8; getIWorldAtPoint 00614560 passes the
//            translation +0xb8.
//   canThrottle +0x30 (ContactConnector::canThrottle 00606250, Body::step 00614200).
//   children  Cofm::updateIfDirty 0065ff20 iterates data +0x1c / num +0x20 (getBranchMass / getBranchCofmPos /
//            getBranchIWorldAtPoint of each child).
// Cofm (0x3c: onChildAdded 006147f0 news 0x3c): Cofm(Body*) 0065fef0 stores body +0x0, dirty +0x4 = true and
// cofmInBody +0x8 = (0, 0, 0); updateIfDirty 0065ff20 tests dirty and writes mass +0x14; getCofmInBody 00660160 returns
// +0x8, getMass 0065ff10 returns +0x14 (`?getMass@Cofm@RBX@@QBE?BMXZ`, const float), getMoment 00660170 returns +0x18.
// SimBody (0xb4: Body() 006149c0 and setParent 006148b0 new 0xb4, then call SimBody(Body*) 00658ae0):
//   ctor     00658ae0: body +0x0 (argument), dt +0x4 = 0, dirty +0x8 = true, pv +0xc (CoordinateFrame() 004782d0 +
//            Velocity() 00614170 at +0x3c), qOrientation +0x54 = (0, 0, 0, 1), angMomentum +0x64 and momentRecip +0x70
//            zeroed, massRecip +0x7c not initialized, constantForceY +0x80 = 0, then force +0x84, torque +0x90 and the
//            two impulse accumulators +0x9c / +0xa8 = Vector3::zero() (function-local static 0096f044, guard 0096f050).
//   dt       +0x4: Kernel insertBody 005fb0e0 stores the kernel step time (00649310) into body->simBody +0x4, removeBody
//            005fb110 zeroes it; step() 00658fb0 takes no argument (`ret`) and multiplies force / torque by it.
//   impulse  +0x9c / +0xa8: step() 00658fb0 adds +0x9c to force * dt before scaling by massRecip +0x7c into
//            pv.velocity.linear +0x3c, and +0xa8 to torque * dt into angMomentum +0x64; resetAccumulators 00613e80 and
//            step() zero both with torque (analog names: linear / rotational impulse).
//   update   00658d20 (when dirty +0x8): pv from Body::getPV / Cofm::getCofmInBody, qOrientation, massRecip +0x7c.
//   getOwnerPV 00658ca0 (`ret 4`, PV returned by value; Body::step 00614248).
#include <G3D/Vector3.h>
#include <G3D/Matrix3.h>
#include <G3D/CoordinateFrame.h>
#include "util/IndexArray.h"
#include "util/Quaternion.h"
#include "v8kernel/Link.h"      // donor; no Body include, 2008 layout (Link() 00613d20: body +0x4; setMeInParent 00614380
                                // / setParent 006148e1 write link->body at +0x4 through setBody)
#include "util/PV.h"
#include "v8kernel/KernelIndex.h"
#include "util/Math.h"

struct NativeBodyPrimitive2008Layout;

namespace RBX
{
	class Body;
	class Link;

	class SimBody
	{
		friend struct ::NativeBodyPrimitive2008Layout;

	private:
		void update();                                    // 00658d20
		void updateIfDirty()
		{
			if (dirty)
				update();
		}

	public:
		Body* body;                                       // +0x0
		float dt;                                         // +0x4  (Kernel insertBody 005fb0e0 / removeBody 005fb110)
		bool dirty;                                       // +0x8
		PV pv;                                            // +0xc
		Quaternion qOrientation;                          // +0x54
		G3D::Vector3 angMomentum;                         // +0x64
		G3D::Vector3 momentRecip;                         // +0x70
		float massRecip;                                  // +0x7c
		float constantForceY;                             // +0x80
		G3D::Vector3 force;                               // +0x84
		G3D::Vector3 torque;                              // +0x90
		G3D::Vector3 impulse;                             // +0x9c (analog name)
		G3D::Vector3 rotImpulse;                          // +0xa8 (analog name)

		SimBody(Body* body);                              // 00658ae0
		~SimBody();                                       // folded empty body 0047d410 (Body::~Body 00614af9)

		void step();                                      // 00658fb0
		PV getOwnerPV();                                  // 00658ca0
		void makeDirty()
		{
			dirty = true;
		}
		void accumulateForce(const G3D::Vector3& _force, const G3D::Vector3& worldPos);   // 00612fb0 (out of line)
		void accumulateTorque(const G3D::Vector3& _torque)   // inline in Body::accumulateTorque 006060b0
		{
			updateIfDirty();
			torque += _torque;
		}
		void resetAccumulators()                          // out-of-line COMDAT 00613e80 (Body::step 0061421e)
		{
			updateIfDirty();
			force = G3D::Vector3(0.0f, constantForceY, 0.0f);
			torque = G3D::Vector3(0.0f, 0.0f, 0.0f);
			impulse = G3D::Vector3(0.0f, 0.0f, 0.0f);
			rotImpulse = G3D::Vector3(0.0f, 0.0f, 0.0f);
		}
	};

	class Cofm
	{
		friend struct ::NativeBodyPrimitive2008Layout;

	private:
		Body* body;                                       // +0x0
		mutable bool dirty;                               // +0x4
		mutable G3D::Vector3 cofmInBody;                  // +0x8
		mutable float mass;                               // +0x14
		mutable G3D::Matrix3 moment;                      // +0x18

		void updateIfDirty() const;                       // 0065ff20

	public:
		Cofm(Body* body);                                 // 0065fef0
		bool getIsDirty() const                           // makeCofmDirty 00613f7a reads +0x4
		{
			return dirty;
		}
		void makeDirty()                                  // makeCofmDirty 00613fa0 stores +0x4 = 1
		{
			dirty = true;
		}
		const G3D::Vector3& getCofmInBody() const;        // 00660160
		const float getMass() const;                      // 0065ff10
		const G3D::Matrix3& getMoment() const;            // 00660170
	};

	class Body : public KernelIndex
	{
		friend struct ::NativeBodyPrimitive2008Layout;

	private:
		int& getIndex()                                   // IndexArray accessor of index +0x18
		{
			return index;
		}

		int leafBodyIndex;                                // +0x4  (analog name; KernelData body array at +0xc)
		int numConnectors;                                // +0x8  (analog name; Kernel insert/removeConnector)
		bool unreadFlag;                                  // +0xc  (constructor store only)
		Body* root;                                       // +0x10
		Body* parent;                                     // +0x14
		int index;                                        // +0x18
		IndexArray<Body, &Body::getIndex> children;       // +0x1c
		Cofm* cofm;                                       // +0x28
		SimBody* simBody;                                 // +0x2c
		bool canThrottle;                                 // +0x30
		Link* link;                                       // +0x34
		G3D::CoordinateFrame meInParent;                  // +0x38
		G3D::Matrix3 moment;                              // +0x68
		float mass;                                       // +0x8c
		mutable int stateIndex;                           // +0x90
		mutable PV pv;                                    // +0x94

		static Body* worldBody;                           // 0097bec4 (initWorldBody 00614b40, getWorldBody 00614bb0)

		void updatePV() const;                            // 00599360
		void makeCofmDirty();                             // 00613f70
		void onChildAdded(Body* child);                   // 006147f0
		void onChildRemoved(Body* child);                 // 00614760
		__declspec(noinline) Body* calcRoot();            // 00613ef0 (called, not inlined, by setParent 00614958)
		void resetRoot(Body* newRoot);                    // 00614530
		static void initWorldBody();                      // 00614b40 (boost::call_once target)

	public:
		Body();                                           // 006149c0
		~Body();                                          // 00614ac0

		static Body* getWorldBody();                      // 00614bb0
		static int getNextStateIndex();                   // 00613f20 (out of line: Link() 00613d20 calls it)
		void advanceStateIndex();                         // 00613f40

		Body* getParent() const
		{
			return parent;
		}
		Body* getRoot()
		{
			return root;
		}
		float getMass() const
		{
			return mass;
		}
		float getBranchMass() const                       // inline: Cofm::updateIfDirty 0065ff20 and getBranchIWorldAtPoint
		{                                                 // 006145e0 inline it; the out-of-line COMDAT is 00613f00
			return cofm ? cofm->getMass() : mass;
		}
		int numChildren() const
		{
			return children.size();
		}
		Body* getChild(int i)
		{
			return children[i];
		}
		const bool getCanThrottle() const
		{
			return canThrottle;
		}
		const G3D::Vector3& getCofmOffset() const         // inline in SimBody::getOwnerPV 00658ca0 (00658ca7..00658ce3:
		{                                                 // Cofm::getCofmInBody 00660160 or the Vector3::zero() static)
			return cofm ? cofm->getCofmInBody() : G3D::Vector3::zero();
		}
		const PV& getPVUnsafe() const                     // no updatePV: Point::step 0064dc93 reads pv +0x94 directly
		{                                                 // (analog name)
			return pv;
		}
		const PV& getPV() const
		{
			updatePV();
			return pv;
		}
		const G3D::CoordinateFrame& getCoordinateFrame() const
		{
			updatePV();
			return pv.position;
		}
		const Velocity& getVelocity() const
		{
			updatePV();
			return pv.velocity;
		}
		const G3D::Vector3& getPos() const
		{
			updatePV();
			return pv.position.translation;
		}
		G3D::Matrix3 getIBody() const
		{
			updatePV();
			return moment;
		}
		G3D::Matrix3 getIWorld() const
		{
			return Math::momentToWorldSpace(getIBody(), pv.position.rotation);
		}
		G3D::Matrix3 getBranchIBody() const
		{
			return cofm ? cofm->getMoment() : moment;
		}
		G3D::Matrix3 getBranchIWorld() const
		{
			updatePV();
			return Math::momentToWorldSpace(getBranchIBody(), pv.position.rotation);
		}

		void setParent(Body* newParent);                  // 006148b0
		void setPv(const PV& _pv);                        // 00613fb0
		void setVelocity(const Velocity& worldVelocity);  // 00614040
		void setMass(float _mass);                        // 006140b0
		void setMoment(const G3D::Matrix3& _momentInBody);   // 00614110
		void setMeInParent(const G3D::CoordinateFrame& _meInParent);   // 006142d0
		void setMeInParent(Link* _link);                  // 00614380
		void step(bool throttling);                       // 00614200 (`ret 4`: the step time is SimBody::dt)
		void accumulateForce(const G3D::Vector3& force, const G3D::Vector3& worldPos)   // inline in Point::forceToBody
		{                                                 // 0064dc70 (SimBody::accumulateForce 00612fb0)
			SimBody* simBody = root->simBody;
			if (simBody)
				simBody->accumulateForce(force, worldPos);
		}
		void accumulateTorque(const G3D::Vector3& torque) // out-of-line COMDAT 006060b0 (Connector unit)
		{
			if (root->simBody)
				root->simBody->accumulateTorque(torque);
		}
		void setCoordinateFrame(const G3D::CoordinateFrame& worldCord);   // 00614400

		G3D::Vector3 getBranchCofmPos() const;            // 00614480
		G3D::CoordinateFrame getBranchCofmCoordinateFrame() const;        // 006144e0
		G3D::Matrix3 getIWorldAtPoint(const G3D::Vector3& point) const;   // 00614560
		G3D::Matrix3 getBranchIWorldAtPoint(const G3D::Vector3& point) const;   // 006145e0
		float kineticEnergy() const;                      // 00614670
	};
}
