// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_c2c942bca420252e.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/enumconverter.h", "../roc_enum_native_owner_header_b9f24b80cd6bff22.cpp")
#undef _RELEASEASSERT
#include "util/Name.h"
#include "util/Debug.h"
#define Descriptor Descriptor_unused_
#include "reflection/descriptor.h"
#undef Descriptor
namespace RBX { namespace Reflection {
extern bool exeFlag2009;
void exeHook2009();
const Name& exeDeclare2009(const char*);
class Descriptor : public boost::noncopyable
{
public:
	const Name& name;
	Descriptor(const Name&);
	Descriptor(const char* name) : name(exeDeclare2009(name)) { if (exeFlag2009) exeHook2009(); }
	virtual ~Descriptor() {}
};
} }
#include "reflection/type.h"
namespace RBX { namespace Reflection { struct ExePad2009 { int exePad2009; }; } }
#define Type Type, public ExePad2009
#include "reflection/enumconverter.h"
#undef Type
#include "util/Sound.h"
namespace RBX { namespace Reflection {
using namespace Soundscape;
template<>
EnumDesc<Soundscape::ReverbType>::EnumDesc()
	:EnumDescriptor("ReverbType", typeid(Soundscape::ReverbType))
{
	addPair(NoReverb, "NoReverb");
	addPair(GenericReverb, "GenericReverb");
	addPair(PaddedCell, "PaddedCell");
	addPair(Room, "Room");
	addPair(Bathroom, "Bathroom");
	addPair(LivingRoom, "LivingRoom");
	addPair(StoneRoom, "StoneRoom");
	addPair(Auditorium, "Auditorium");
	addPair(ConcertHall, "ConcertHall");
	addPair(Cave, "Cave");
	addPair(Arena, "Arena");
	addPair(Hangar, "Hangar");
	addPair(CarpettedHallway, "CarpettedHallway");
	addPair(Hallway, "Hallway");
	addPair(StoneCorridor, "StoneCorridor");
	addPair(Alley, "Alley");
	addPair(Forest, "Forest");
	addPair(City, "City");
	addPair(Mountains, "Mountains");
	addPair(Quarry, "Quarry");
	addPair(Plain, "Plain");
	addPair(ParkingLot, "ParkingLot");
	addPair(SewerPipe, "SewerPipe");
	addPair(UnderWater, "UnderWater");
}
} }

