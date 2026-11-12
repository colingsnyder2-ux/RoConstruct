// from server: 100% by EspClaude
// from server: 56% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_b1c058dac790ab4b.cpp

// Candidate translation unit (score above; library headers required).
#define _MT 1
#define _DLL 1
#include "RenderLib/Profiler.h"
#include "v8datamodel/DebugSettings.h"

namespace RBX
{
	std::string DebugSettings::gfxcard() const
	{
		return Render::SpecData().gfxcard;
	}
}
