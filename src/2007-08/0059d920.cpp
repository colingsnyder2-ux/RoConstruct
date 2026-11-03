// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_dd161f8825eec2ae.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/enumconverter.h"

namespace RBX {
class HopperBin
{
public:
	enum BinType
	{
		SCRIPT_BIN,
		GAME_TOOL,
		GRAB_TOOL,
		CLONE_TOOL,
		HAMMER_TOOL,
		SLINGSHOT_TOOL,
		ROCKET_TOOL,
		LASER_TOOL
	};
};

namespace Reflection {

template <>
EnumDesc<HopperBin::BinType>::EnumDesc() : EnumDescriptor("BinType", typeid(HopperBin::BinType))
{
	addPair(HopperBin::SCRIPT_BIN, "Script");
	addPair(HopperBin::GAME_TOOL, "GameTool");
	addPair(HopperBin::GRAB_TOOL, "Grab");
	addPair(HopperBin::CLONE_TOOL, "Clone");
	addPair(HopperBin::HAMMER_TOOL, "Hammer");
	addPair(HopperBin::SLINGSHOT_TOOL, "Slingshot");
	addPair(HopperBin::ROCKET_TOOL, "Rocket");
	addPair(HopperBin::LASER_TOOL, "Laser");
}

} // namespace Reflection
} // namespace RBX
