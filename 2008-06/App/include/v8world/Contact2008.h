#pragma once
// >>> native-status (generated) -- do not edit >>>
// Contact2008 | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src e83b7ece | roc native-status --write
// 2008-06 native RBX::Contact, BallBallContact, BallBlockContact (inactive). Declared under a non-colliding name:
// the original path v8world/Contact.h is reached through the donor World.h / CollisionStage.h and the maintainer
// engine-world World.h; see the proposal in tests/record_native_world_shapes.py. The bases Edge / IPipelined come
// from the donor v8world/Edge.h (no native header yet); their layout is checked here only through the Contact
// field offsets (Edge ends at +0x20) and the Edge constructor 00659260 / setPrimitive 00659290.
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
#include "v8world/Edge.h"

struct NativeWorldShapesLayout;

namespace RBX
{
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
		virtual void deleteAllConnectors() = 0;         // slot 5
		virtual bool stepContact() = 0;                 // slot 6

	public:
		Contact(Primitive* prim0, Primitive* prim1);    // 00606c20

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
