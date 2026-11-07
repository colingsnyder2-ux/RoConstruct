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
//            stateIndex +0x90 = getNextStateIndex() (inline, static 0095a898), pv +0x94 (CoordinateFrame() + Velocity()
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
// SimBody (0xb4, constructor 00658ae0) is declared here only by its out-of-line destructor (folded at 0047d410): its
// fields are not derived, so it must not be used for new, sizeof or member access.
#include <G3D/Vector3.h>
#include <G3D/Matrix3.h>
#include <G3D/CoordinateFrame.h>
#include "util/IndexArray.h"
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
	public:
		~SimBody();                                       // folded empty body 0047d410 (Body::~Body 00614af9)
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
		static int nextStateIndex;                        // 0095a898

		void updatePV() const;                            // 00599360
		Body* calcRoot();                                 // 00613ef0
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
		void setCoordinateFrame(const G3D::CoordinateFrame& worldCord);   // 00614400

		G3D::Vector3 getBranchCofmPos() const;            // 00614480
		G3D::CoordinateFrame getBranchCofmCoordinateFrame() const;        // 006144e0
		G3D::Matrix3 getIWorldAtPoint(const G3D::Vector3& point) const;   // 00614560
		G3D::Matrix3 getBranchIWorldAtPoint(const G3D::Vector3& point) const;   // 006145e0
		float kineticEnergy() const;                      // 00614670
	};
}
