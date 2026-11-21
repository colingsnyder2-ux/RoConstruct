#pragma once
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
