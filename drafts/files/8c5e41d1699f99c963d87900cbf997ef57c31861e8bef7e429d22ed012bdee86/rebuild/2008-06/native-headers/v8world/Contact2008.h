#pragma once
// 2008-06 native RBX::Contact, BallBallContact, BallBlockContact (inactive). Declared under a non-colliding name:
// the original path v8world/Contact.h is reached through the donor World.h / CollisionStage.h and the maintainer
// engine-world World.h; see the proposal in tests/record_native_world_shapes.py. The bases Edge / IPipelined come
// from the native 2008 Edge, native-headers/AppUnit658/Edge.h (index0 / index1 at +0x14 / +0x18, Edge ends at +0x20,
// constructor 00659260 / setPrimitive 00659290), over v8kernel/IPipelined2008.h; a unit that also reaches the donor
// IPipelined defines NATIVE_IPIPELINED2008_DONOR before including this header (same 2008 layout).
// Every Contact field, slot and size below is read from the 2008-06 binary:
//   RTTI     BallBallContact vtable 008436bc, BallBlockContact 008436e8, BlockBlockContact 00843714: each
//            -> Contact -> Edge -> IPipelined (all mdisp 0). Contact has no vtable of its own (no vtable store in
//            its constructor 00606c20): __declspec(novtable), like the donor Edge / IPipelined.
//   slots    10: 0 scalar deleting dtor, 1 putInKernel 0060cb10, 2 removeFromKernel 0060cb30, 3 getEdgeType
//            007286a0 (folded `mov eax, 1` = CONTACT), 4 Edge::setPrimitive 00659290, 5 deleteAllConnectors,
//            6 stepContact, 7 computeIsColliding (BallBlockContact 00607bd0 by evidence name), 8 numConnectors,
//            9 getConnector. Slots 8 / 9 have no donor declaration; their names are analog names, their
//            signatures come from the bodies (BallBall/BallBlock 0060cb60 `connector != 0` with `ret`, 0060cbc0
//            returns +0x34 with `ret 4`; BlockBlockContact 0060d580 returns +0x38, 0060d590 indexes +0x34).
//   size     Contact 0x34 (BallBallContact / BallBlockContact add one pointer at +0x34). ContactManager::
//            createContact 0060d770 news 0x38 for BallBall (ctor 0060cae0) and BallBlock (ctor 0060cb90), 0x7c for
//            BlockBlock (ctor 0060d500).
//   ctor     00606c20: Edge(prim0, prim1) 00659260, then lastContactStep (+0x20) = steppingIndex (+0x24) = -1,
//            jointK (+0x28) = elasticJointK (+0x2c) = kFriction (+0x30) = 0.
//   dtor     inline and empty down to IPipelined: BallBallContact ??_G 0060cb70 / BallBlockContact ??_G 0060cbd0
//            only restore their vtable before operator delete.
// BlockBlockContact (0x7c: two G3D::Arrays at +0x34 / +0x40, a float at +0x54 and int fields up to +0x7b) is not
// declared here: its fields beyond the two arrays are not derived yet (see the recorder's report).
#include "AppUnit658/Edge.h"

struct NativeWorldShapesLayout;
namespace G3D { class Vector3; class Vector3int16; }

namespace RBX
{
	class Ball;
	class Block;
	class Body;
	class ContactConnector;
	class Kernel;

	class __declspec(novtable) Contact : public Edge
	{
		friend struct ::NativeWorldShapesLayout;

	private:
		int lastContactStep;   // +0x20
		int steppingIndex;     // +0x24
		float jointK;          // +0x28
		float elasticJointK;   // +0x2c
		float kFriction;       // +0x30

	private:
		virtual void putInKernel(Kernel* _kernel)       // slot 1 (0060cb10)
		{
			IPipelined::putInKernel(_kernel);
			onPrimitiveContactParametersChanged();
		}
		virtual void removeFromKernel()                 // slot 2 (0060cb30)
		{
			deleteAllConnectors();
			IPipelined::removeFromKernel();
		}
		virtual Edge::EdgeType getEdgeType() const      // slot 3 (007286a0, folded)
		{
			return CONTACT;
		}

	protected:
		void deleteConnector(ContactConnector*& c);     // 00606d10
		// 00606e00 (`ret 8`, placeholder func_00606e00): new ContactConnector(jointK +0x28, elasticJointK +0x2c,
		// kFriction +0x30) 00606d40, stores the two Body arguments at connector +0x14 / +0x18, then
		// getKernel()->insertConnector 005fb160. Donor name Contact::createConnector() (the 2008 one takes the bodies);
		// called by BallBallContact 00606f80, BallBlockContact 00607150 and BlockBlockContact 00607cc0.
		ContactConnector* createConnector(Body* b0, Body* b1);   // 00606e00
		virtual void deleteAllConnectors() = 0;         // slot 5
		virtual bool stepContact() = 0;                 // slot 6

	public:
		Contact(Primitive* prim0, Primitive* prim1);    // 00606c20

		// donor v8world/Contact.h; bodies in native-classes/ContactUnit2008Contact.cpp. step: stepContact slot 6, then
		// Primitive::onNewTouch 005e7530 on the first touching step. computeIsAdjacent: computeIsColliding slot 7 with
		// +space, then -space. The hit counters are read by contactPairHitRatio / contactFeatureHitRatio
		// (DataModel::evaluate 005760a1 / 005760d5) and incremented by BlockBlockContact 00607d3b / 00607d07 /
		// 00607588 / 00607548.
		bool step(int uiStepId);                        // 00606c50
		bool computeIsAdjacent(float spaceAllowed);     // 00606ca0
		static int contactPairMatches;                  // 0097b880
		static int contactPairMisses;                   // 0097b884
		static int contactFeatureMatches;               // 0097b888
		static int contactFeatureMisses;                // 0097b88c
		static float contactPairHitRatio();             // 00606bc0
		static float contactFeatureHitRatio();          // 00606bf0

		virtual bool computeIsColliding(float overlapIgnored) = 0;   // slot 7
		virtual int numConnectors() const = 0;                       // slot 8 (analog name)
		virtual ContactConnector* getConnector(int i) = 0;           // slot 9 (analog name)

		void onPrimitiveContactParametersChanged();     // 00607ad0
	};

	class BallBallContact : public Contact
	{
		friend struct ::NativeWorldShapesLayout;

	private:
		ContactConnector* ballBallConnector;            // +0x34

	private:
		virtual void deleteAllConnectors()              // slot 5 (0060cb50)
		{
			if (ballBallConnector)
				deleteConnector(ballBallConnector);
		}
		virtual bool stepContact();                     // slot 6 (00606f80)
		virtual bool computeIsColliding(float overlapIgnored);   // slot 7 (00606e90)
		virtual int numConnectors() const               // slot 8 (0060cb60)
		{
			return ballBallConnector ? 1 : 0;
		}
		virtual ContactConnector* getConnector(int i)   // slot 9 (0060cbc0)
		{
			return ballBallConnector;
		}

	public:
		BallBallContact(Primitive* p0, Primitive* p1)   // 0060cae0
			: Contact(p0, p1),
			  ballBallConnector(NULL)
		{
		}
	};

	class BallBlockContact : public Contact
	{
		friend struct ::NativeWorldShapesLayout;

	private:
		ContactConnector* ballBlockConnector;           // +0x34
		// onBorder is int&: 00607020 passes the reference straight to Block::projectToFace 00647b90 (`int& onBorder`)
		// and stepContact 00607150 reads it back as a dword (`mov edx, [esp + 0x18]; test edx, edx`).
		bool computeIsColliding(int& onBorder, G3D::Vector3int16& clip,
			G3D::Vector3& projectionInBlock, float overlapIgnored); // 00607020

		// Donor v8world/Contact.h inline accessors (no code of their own). prim0 is the ball, prim1 the block: 00607150
		// reads the radius through +0xc -> +0x9c and the block geometry through +0x10 -> +0x9c. ball() / block() need
		// the complete Ball / Block (v8world/Ball2008.h, Block2008.h, which this header does not include), so they are
		// only declared here and defined inline by the units that use them (BallBlockContactStep.cpp).
		Primitive* ballPrim()
		{
			return getPrimitive(0);
		}
		Primitive* blockPrim()
		{
			return getPrimitive(1);
		}
		Ball* ball();
		Block* block();

	private:
		virtual void deleteAllConnectors()              // slot 5 (0060cb50, folded with BallBallContact's)
		{
			if (ballBlockConnector)
				deleteConnector(ballBlockConnector);
		}
		virtual bool stepContact();                     // slot 6 (00607150)
		virtual bool computeIsColliding(float overlapIgnored);   // slot 7 (00607bd0)
		virtual int numConnectors() const               // slot 8 (0060cb60, folded)
		{
			return ballBlockConnector ? 1 : 0;
		}
		virtual ContactConnector* getConnector(int i)   // slot 9 (0060cbc0, folded)
		{
			return ballBlockConnector;
		}

	public:
		BallBlockContact(Primitive* p0, Primitive* p1)  // 0060cb90
			: Contact(p0, p1),
			  ballBlockConnector(NULL)
		{
		}
	};
}
