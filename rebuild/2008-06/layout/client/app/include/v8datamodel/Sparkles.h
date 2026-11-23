// =============================================================================
// Sparkles.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Sparkles.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
