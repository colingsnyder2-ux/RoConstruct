#pragma once
// >>> native-status (generated) -- do not edit >>>
// Filters2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src d016a379 | roc native-status --write
// 2008-06 native hit-test filters (inactive): RBX::Unlocked, RBX::PartByLocalCharacter,
// RBX::UnlockedPartByLocalCharacter, RBX::FilterStairs and RBX::FilterCharacterOcclusion. Shape after the donor
// tools/rbxgs v8datamodel/Filters.h (which this file must not shadow: the donor path stays visible to every other
// unit); FilterStairs and FilterCharacterOcclusion are not in the donor. Every base, field and virtual below is
// read from the 2008-06 binary (verified by tests/record_native_hit_filters.py):
//   HitTestFilter   donor util/HitTestFilter.h (vtable only): vtable 00843a40 has one slot (filterResult, pure);
//                   Result values from the bodies: STOP_TEST 0, IGNORE_PRIM 1, INCLUDE_PRIM 2.
//   Unlocked        RTTI .?AVUnlocked@RBX@@, vtable 00843a48 (one slot: filterResult 00615b60, emitted where the
//                   object is built, MouseCommand 00616080); no fields (size 4). unlocked() 006601f0 is out of line
//                   in the filter unit and returns !PartInstance::fromPrimitiveConst(p)->getPartLocked().
//   PartByLocalCharacter
//                   RTTI .?AVPartByLocalCharacter@RBX@@, vtable 0084c464 (filterResult 00660260). Constructor
//                   00660380 stores the vtable and zeroes +0x04/+0x08 and +0x0c/+0x10 (two boost::shared_ptr), then
//                   assigns +0x04 from shared_from(Network::Players::findLocalCharacter(root)) (0049aca0) and +0x0c
//                   from shared_from(Humanoid::getHeadFromCharacter(character)) (005d75a0); both through the
//                   shared_from body 00618a40 (ICF-folded with shared_from<Instance>). The implicit destructor
//                   00615b80 (MouseCommand unit) releases +0x0c/+0x10 then +0x04/+0x08 and stores no vtable.
//                   Size 0x14 (the constructor's last field write is +0x10).
//   UnlockedPartByLocalCharacter
//                   RTTI .?AVUnlockedPartByLocalCharacter@RBX@@, vtable 00843a50 (filterResult 006602b0, which
//                   inlines PartByLocalCharacter::filterResult and Unlocked::unlocked). Its constructor is inline:
//                   MouseCommand 00616000 calls PartByLocalCharacter(Instance*) 00660380 and then stores 00843a50.
//                   No own fields.
//   FilterStairs    RTTI .?AVFilterStairs@RBX@@, vtable 0084c46c (filterResult 00660320). Constructor 006604a0 takes
//                   an Instance*, zeroes the shared_ptr at +0x04/+0x08 and assigns it from shared_from(model)
//                   (00618a40). Size 0x0c (last field write +0x08).
//   FilterCharacterOcclusion
//                   RTTI .?AVFilterCharacterOcclusion@RBX@@, vtable 0084c45c (filterResult 00660220). Constructor
//                   00660210 only stores the vtable and pops one unused 4-byte argument (ret 4; the only caller
//                   00641605 passes 0): its type is not recoverable from the bytes, `int` is provisional. No fields.
#include "util/HitTestFilter.h"
#include <boost/shared_ptr.hpp>

struct NativeHitTestFilterLayout;

namespace RBX
{
	class Instance;
	class ModelInstance;
	class PartInstance;
	class Primitive;

	class Unlocked : public HitTestFilter
	{
	public:
		virtual HitTestFilter::Result filterResult(const Primitive* testMe) const   // 00615b60
		{
			return unlocked(testMe) ? HitTestFilter::INCLUDE_PRIM : HitTestFilter::STOP_TEST;
		}

		static bool unlocked(const Primitive* testMe);   // 006601f0
	};

	class PartByLocalCharacter : public HitTestFilter
	{
		friend struct ::NativeHitTestFilterLayout;   // tests/NativeHitTestFilterLayout.cpp offset asserts

	protected:
		boost::shared_ptr<ModelInstance> character;   // +0x04 (px), +0x08 (pn)
		boost::shared_ptr<PartInstance> head;         // +0x0c (px), +0x10 (pn)

	public:
		PartByLocalCharacter(Instance* root);                                         // 00660380
		virtual HitTestFilter::Result filterResult(const Primitive* testMe) const;    // 00660260
	};

	class UnlockedPartByLocalCharacter : public PartByLocalCharacter
	{
	public:
		UnlockedPartByLocalCharacter(Instance* root)   // inline (MouseCommand 00616000)
			: PartByLocalCharacter(root)
		{
		}
		virtual HitTestFilter::Result filterResult(const Primitive* testMe) const;    // 006602b0
	};

	class FilterStairs : public HitTestFilter
	{
		friend struct ::NativeHitTestFilterLayout;

	private:
		boost::shared_ptr<Instance> model;   // +0x04 (px), +0x08 (pn)

	public:
		FilterStairs(Instance* model);                                                 // 006604a0
		virtual HitTestFilter::Result filterResult(const Primitive* testMe) const;    // 00660320
	};

	class FilterCharacterOcclusion : public HitTestFilter
	{
	public:
		FilterCharacterOcclusion(int);                                                 // 00660210 (argument unused)
		virtual HitTestFilter::Result filterResult(const Primitive* testMe) const;    // 00660220
	};
}
