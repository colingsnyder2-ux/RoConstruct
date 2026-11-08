#pragma once
// >>> native-status (generated) -- do not edit >>>
// Sparkles | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 0d4164d1 | roc native-status --write
// 2008-06 native RBX::Sparkles and its base RBX::Effect (inactive). No donor source: every field, virtual and
// descriptor below is read from the 2008-06 binary.
//   RTTI       vtable 0084a234 .?AVSparkles@RBX@@ -> DescribedCreatable<Sparkles, Instance, sSparkles> (23 bases;
//              name mangled $1?sSparkles@2@3PADA, a char array in .data at 0096181c), IRenderable at +0x130,
//              Effect at +0x140.
//   Effect     RTTI .?AVEffect@RBX@@, vtable 0084cb84 with one slot (deleting destructor 00665690); out-of-line
//              constructor 00665670 and destructor 00665680 only store that vtable, so Effect is a bare vptr.
//   size       0x148: Creatable<Instance>::create<Sparkles> 005c32f0 allocates 0x148. Constructor 0063da90 stores
//              IRenderable defaults (+0x134/+0x138 = -1, +0x13c = 0), calls Effect() on +0x140, stores
//              bool enabled +0x144 = 1, then setName("Sparkles") (literal 0084a274).
//   vtable     Instance slot 2 askAddChild -> 00565ff0 (return true), slot 3 askSetParent -> 0062e190
//              (dynamic_cast to PartInstance, ICF-shared); IRenderable vtable 0084a1a0 = {0060a2f0 shouldRender2d false, 00565950 shouldRender3dAdorn true,
//              render2d default, 0063d710 render3dAdorn, 00458e90 render3dSelect}.
//   descriptor prop_Enabled 0097d58c (BoundProp<bool,1> "Enabled"/"Data", member +0x144, dynamic initializer
//              007f8be0, constructor 0063d8e0).
#include "v8tree/Instance.h"
#include "util/IRenderable.h"

namespace RBX
{
	class Effect
	{
	public:
		Effect();                      // 00665670
		virtual ~Effect();             // 00665680 (deleting 00665690)
	};

	extern const char sSparkles[];

	class Sparkles : public DescribedCreatable<Sparkles, Instance, sSparkles>,
					 public IRenderable,
					 public Effect
	{
	private:
		bool enabled;                  // +0x144

	public:
		static Reflection::BoundProp<bool, 1> prop_Enabled;

	public:
		Sparkles();                    // 0063da90
		virtual ~Sparkles();           // 0063dc20 (deleting 0063dce0; resets the vtables, so user-declared)

		virtual bool askAddChild(const Instance* instance) const
		{
			return true;               // 00565ff0 (ICF-shared)
		}
		virtual bool askSetParent(const Instance* instance) const; // 0062e190 (ICF-shared)

		virtual bool shouldRender3dAdorn() const
		{
			return true;               // 00565950 (ICF-shared)
		}
		virtual void render3dAdorn(Adorn* adorn); // 0063d710
	};
}
