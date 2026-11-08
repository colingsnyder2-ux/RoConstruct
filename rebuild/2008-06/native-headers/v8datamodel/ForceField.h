#pragma once
// 2008-06 native RBX::ForceField (inactive). No donor header: every base, field and virtual below is read from the
// 2008-06 binary:
//   RTTI       vtable 0084682c .?AVForceField@RBX@@ -> DescribedCreatable<ForceField, Instance, sForceField> (name
//              mangled $1?sForceField@2@3PADA, a non-const char array in .data at 0095c3a8 holding "ForceField":
//              doDeclare 005bf9c0, classDescriptor 005c0400) and IRenderable (mdisp 0x130, vtable 00846798).
//   size       0x148: Creatable<Instance>::create<ForceField> 005c1520 mallocs 0x148 and calls the constructor 0062d6b0.
//   ctor       0062d6b0: DescribedCreatable<..>() 0062d5f0, IRenderable fields +0x134/+0x138 = -1, +0x13c = 0,
//              rendered (+0x140, byte) = false, sparkleCycle (+0x144) = 0, then setName("ForceField") (literal 0084686c).
//   dtor       0062d820: ~IRenderable (folded empty body 0047d410) on +0x130, then ~FactoryProduct 0062d0c0
//              (deleting 0062d8d0).
//   vtable     Instance part: only slot 3 askSetParent 0062d090 (true unless the parent is a Workspace).
//              IRenderable part 00846798: shouldRender3dAdorn returns true (folded 00565950), render3dAdorn 0062d570.
//   render     0062d570 skips the first call (rendered), then unless the parent is a Workspace advances sparkleCycle
//              modulo 30 and draws every PartInstance of the parent and its descendants (renderPart 0062d200 through
//              Instance::visitDescendents 0062d400).
//   protected  isProtected 0062d3d0 (name provisional; called by 005dbf40 and the Explosion unit 00629d60): true when
//              the instance or an ancestor below the Workspace has a ForceField child (0062d310 / 0062d380).
#include "v8tree/Instance.h"
#include "util/IRenderable.h"

struct NativeDebrisForceFieldLayout;

namespace RBX
{
	extern char sForceField[];

	class ForceField : public DescribedCreatable<ForceField, Instance, sForceField>,
					   public IRenderable
	{
		friend struct ::NativeDebrisForceFieldLayout; // tests/NativeDebrisForceFieldLayout.cpp offset asserts

	private:
		bool rendered;                                 // +0x140: set after the first render3dAdorn
		int sparkleCycle;                              // +0x144: 0..29, advanced per rendered frame

	public:
		ForceField();                                  // 0062d6b0
		~ForceField()                                  // 0062d820 (deleting 0062d8d0): user-declared, the original
		{                                              // re-stores the ForceField vtables before ~IRenderable
		}

		static bool isProtected(Instance* instance);   // 0062d3d0 (name provisional)

	private:
		static bool hasForceField(Instance* instance);        // 0062d310 (a ForceField child)
		static bool isProtectedRecursive(Instance* instance); // 0062d380 (cdecl: the 0062d3d0 wrapper is a jmp)

	protected:
		virtual bool askSetParent(const Instance* instance) const; // 0062d090

		virtual bool shouldRender3dAdorn() const       // folded 00565950
		{
			return true;
		}

		virtual void render3dAdorn(Adorn* adorn);      // 0062d570
	};
}
