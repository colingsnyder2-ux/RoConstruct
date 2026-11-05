#pragma once
// 2008-06 RBX::BlockBlockContact (inactive native recovery). Non-colliding name: the original path v8world/Contact.h
// is the donor header reached through World.h / Primitive.h; the bases come from the committed
// native-headers/v8world/Contact2008.h (Contact 0x34, novtable, 10 slots), which is included, never edited.
//   RTTI     vtable 00843714 .?AVBlockBlockContact@RBX@@ -> Contact -> Edge -> IPipelined (all mdisp 0); 10 slots:
//            0 ??_G 0060d610, 1 Contact::putInKernel 0060cb10, 2 Contact::removeFromKernel 0060cb30,
//            3 Contact::getEdgeType 007286a0, 4 Edge::setPrimitive 00659290, 5 deleteAllConnectors 00607c60,
//            6 stepContact 00608830, 7 computeIsColliding 00607c20, 8 numConnectors 0060d580, 9 getConnector 0060d590.
//   size     0x7c: ContactManager::createContact 0060d770 pushes 0x7c before calling the constructor 0060d500.
//   ctor     0060d500: Contact(p0, p1) 00606c20; G3D::Array() at +0x34 (data / num / numAllocated = 0) and +0x40;
//            +0x54 = float 0082d030 (1e9); +0x64 / +0x68 = -1; +0x4c, +0x50, +0x58, +0x60 = 0. +0x5c and
//            +0x6c..+0x7b are not written.
//   dtor     0060d5a0: ~Array at +0x40 then +0x34 (System::alignedFree 00507d20, then data / num / numAllocated = 0),
//            so +0x34 is declared before +0x40; ??_G 0060d610 calls it out of line. It stores no vtable: the
//            destructor is implicit (a user-declared empty one stores 00843714 first under the same profile).
// Field types, from the bodies:
//   +0x34    G3D::Array<ContactConnector*>: numConnectors 0060d580 returns +0x38 (num), getConnector 0060d590 reads
//            data[i] (4-byte elements); deleteAllConnectors 00607c60 deletes each element through vtable slot 0.
//   +0x40    G3D::Array<bool>: 006087a0 resizes it to connectors.size() (Array<bool>::resize 0047ff20, a different
//            instantiation from 006078f0) and stores `mov byte ptr [data + i], 0`.
//   +0x4c / +0x50  32-bit, zeroed by the constructor (0060d560 / 0060d563); no reader in the BlockBlockContact unit
//            (00607c20..00608945, 0060d500..0060d62b). Declared int (the zero store does not separate int from a
//            pointer; it does separate them from float, which compiles to fldz / fstp here). Donor names
//            (separatingAxisId / separatingBodyId are the first two int fields of the donor class).
//   +0x54    float: 1e9 in the constructor; stepContact 00608830 stores -1.0 (0081c3b8) when colliding, else 1e9, and
//            006087a0 deletes all connectors while it is > 0.
//   +0x58    int: 00607280 loops it over the two bodies (`i % 2`, Edge primitive +0xc + 4 * i) and caches the result.
//   +0x5c    bool: 00607280 stores byte 1 / 0; 006087a0 chooses the plane-contact path (00608580) when it is set.
//   +0x60    int: 00607280 loops it over three axes (`j .. j + 3`) and caches the result.
//   +0x64    int[2]: indexed `[this + 4 * i + 0x64]` (00607280 at 006074f0), -1 in the constructor and 006087a0;
//            006087a0 passes feature[k] - 6 to 00607ea0.
//   +0x6c / +0x70  int 0 / 1 pairs (00608580 at 00608595 / 006085a4), used as body indexes (`[this + 4 * i + 0xc]`).
//   +0x74 / +0x78  32-bit, written from feature[] (00608580 at 006085b1) and read as face ids by 00608160.
#include "v8world/Contact2008.h"
#include "v8kernel/Connector.h"
#include "util/NormalId.h"
#include <G3D/Array.h>

struct NativeLeaves2008Layout;

namespace RBX
{
	class BlockBlockContact : public Contact
	{
		friend struct ::NativeLeaves2008Layout;

	private:
		G3D::Array<ContactConnector*> connectors;   // +0x34
		G3D::Array<bool> matched;                   // +0x40
		int separatingAxisId;                       // +0x4c (no reader found)
		int separatingBodyId;                       // +0x50 (no reader found)
		float separation;                           // +0x54
		int cachedBody;                             // +0x58
		bool planeContact;                          // +0x5c
		int cachedAxis;                             // +0x60
		int feature[2];                             // +0x64
		int bPlane;                                 // +0x6c
		int bOther;                                 // +0x70
		NormalId planeID;                           // +0x74
		NormalId otherPlaneID;                      // +0x78

		void deleteUnmatchedConnectors();                        // 00607e00 (`ret`; donor name, body not here)
		void loadGeoPairEdgeEdge(int b0, int b1, int edge0, int edge1);   // 00607ea0 (`ret 0x10`; donor name)
		int computePlaneContact();                               // 00608580 (`ret`; donor name, result unused)
		void updateConnectors();                                 // 006087a0 (analog name; called by stepContact)

		virtual bool computeIsColliding(float overlapIgnored);   // slot 7 (00607c20)
		virtual void deleteAllConnectors();                      // slot 5 (00607c60)
		virtual bool stepContact();                              // slot 6 (00608830)
		virtual int numConnectors() const;                       // slot 8 (0060d580)
		virtual ContactConnector* getConnector(int i);           // slot 9 (0060d590)

	public:
		BlockBlockContact(Primitive* p0, Primitive* p1);         // 0060d500
		// implicit virtual destructor 0060d5a0 (??_G 0060d610), see above
	};
}
