// from server: 100% by EspClaude
// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_64c77a7764724be5.cpp

// Candidate translation unit (score above; library headers required).
#define map1 map1; char exePad2009[0x18]
#include "v8datamodel/BrickColor.h"
#undef map1

namespace RBX
{
	G3D::Color4 BrickColor::color4() const
	{
		return BrickMap::singleton().map2.find(number)->second;
	}
}
