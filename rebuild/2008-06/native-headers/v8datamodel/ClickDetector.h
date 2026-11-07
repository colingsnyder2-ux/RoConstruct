#pragma once
// >>> native-status (generated) -- do not edit >>>
// ClickDetector | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 2765df58 | roc native-status --write
// 2008-06 native RBX::ClickDetector (inactive). No donor source (tools/rbxgs has no ClickDetector): every base, field,
// virtual and descriptor below is read from the 2008-06 binary:
//   RTTI       vtable 00845afc .?AVClickDetector@RBX@@ -> DescribedCreatable<ClickDetector, Instance, sClickDetector>
//              (22 bases; name mangled $1?sClickDetector@2@3PADA, a char array in .data at 0095b3c8 holding
//              "ClickDetector"), IRenderable at +0x130 (vtable 00845a68).
//   size       0x14c: Creatable<Instance>::create<ClickDetector> 005c0b60 allocates 0x14c and calls 006297e0.
//   fields     constructor 006297e0: IRenderable defaults (+0x134/+0x138 = -1, +0x13c = 0), float +0x144 = 32.0f
//              (00833eac), int +0x140 = 0, then setName("ClickDetector") (literal 00845b3c). +0x148 (bool, read by
//              the getter 0068e8c0 and toggled by click 00629ac0) is not initialized by the constructor.
//              The destructor 006299a0 resets the vtables, runs ~IRenderable (shared ret 0047d410) and the
//              FactoryProduct destructor 00629340.
//              +0x140 has no reader or writer in the binary besides the constructor (no instruction of the unit or
//              of its callers touches it); its type is known only as a 4-byte integer store of 0, so it is declared
//              as an int and named after that fact (see the receipt).
//   vtable     Instance slot 2 askAddChild -> 00565ff0 (return true, ICF-shared), slot 3 askSetParent -> 006298d0
//              (dynamic_cast to PartInstance or ModelInstance); IRenderable vtable 00845a68 = {0060a2f0 shouldRender2d
//              false, 00565950 shouldRender3dAdorn true, render2d / render3dAdorn default 0070bdf0, 00458e90}.
//   descriptors (dynamic initializers 007f7d20, 007f7d50, 007f7d90 in this order; atexit 00800330..00800370):
//              event_MouseClick 0097bf80 (SignalDesc<ClickDetector, void()> "MouseClick" 00845b4c),
//              desc_FrontendMouseClick 0097bf64 (PropDescriptor<ClickDetector, bool> "FrontendMouseClick" 00845b58,
//              category "Behavior" 0082d944, getter 0068e8c0, setter 00629a70, Functionality 4 = STREAMING),
//              prop_MaxActivationDistance 0097bfb4 (BoundProp<float,1> "MaxActivationDistance" 00845b6c, "Data"
//              00822490, member +0x144, STANDARD).
//   statics    isClickable 00629b20 (called by NewNullTool::onMouseIdle/onMouseHover/onMouseDown 00617ee4/00617f74/
//              0061802b with the part under the mouse, a distance and a raise flag) walks the part and its ancestors up
//              to the Workspace (type descriptor 009481b8) looking for a ClickDetector child
//              (Instance::findFirstChildOfType<ClickDetector> 006294a0) whose +0x144 exceeds the distance.
#include "v8tree/Instance.h"
#include "util/IRenderable.h"

struct NativeClickDetectorLayout;

namespace RBX
{
	class PartInstance;

	extern char sClickDetector[];

	class ClickDetector : public DescribedCreatable<ClickDetector, Instance, sClickDetector>,
						  public IRenderable
	{
		friend struct ::NativeClickDetectorLayout; // tests/NativeClickDetectorLayout.cpp offset asserts

	private:
		int zeroInitialized;          // +0x140 (constructor stores 0; no other access in the binary)
		float maxActivationDistance;  // +0x144
		bool frontendMouseClick;      // +0x148 (toggled per click; not initialized by the constructor)

	public:
		static Reflection::SignalDesc<ClickDetector, void(void)> event_MouseClick;
		static Reflection::BoundProp<float, 1> prop_MaxActivationDistance;

	public:
		ClickDetector();              // 006297e0
		virtual ~ClickDetector();     // 006299a0 (deleting 00629a50; resets the vtables, so user-declared)

		bool getFrontendMouseClick() const   // 0068e8c0 (ICF-shared)
		{
			return frontendMouseClick;
		}
		void setFrontendMouseClick(bool value);  // 00629a70 (the value is not used)

		// 00629ac0: toggles frontendMouseClick when distance < maxActivationDistance. The first argument is the part
		// isClickable was called with; the body does not use it.
		void click(PartInstance* part, float distance);

		// 00629b20
		static bool isClickable(PartInstance* part, float distance, bool raiseClickedEvent);

	protected:
		virtual bool askAddChild(const Instance* instance) const
		{
			return true;              // 00565ff0 (ICF-shared)
		}
		virtual bool askSetParent(const Instance* instance) const; // 006298d0

		virtual bool shouldRender3dAdorn() const
		{
			return true;              // 00565950 (ICF-shared)
		}
	};
}
