#pragma once
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
