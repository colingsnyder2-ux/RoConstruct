#pragma once
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

		void click(PartInstance* part, float distance);

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
