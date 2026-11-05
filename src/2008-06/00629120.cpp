// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_soundtype_enum_family_c7559d52160566d0.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/type.h"
#include "util/SoundWorld.h"

#include <map>
#include <string>
#include <vector>

namespace RBX {
namespace Reflection {

class EnumDescriptor : public Type
{
protected:
    class Item;

    EnumDescriptor(const char* name, const std::type_info& type);
    virtual ~EnumDescriptor();

    std::vector<const Item*> allItems;
    size_t enumCount;
    size_t enumCountMSB;
};

template <class Enum>
class EnumDesc : public EnumDescriptor
{
private:
    EnumDesc();
    virtual ~EnumDesc();

    void addPair(Enum value, const char* name);

    std::map<const Name*, Enum> nameToEnum;
    std::map<const Name*, Enum> nameToEnumLegacy;
    std::vector<const Name*> enumToName;
    std::vector<std::string> stringNames;
    std::vector<Enum> stringValues;
    std::vector<Enum> indexToEnum;
    std::vector<size_t> enumToIndex;
};

template <>
EnumDesc<SoundType>::EnumDesc()
    : EnumDescriptor("SoundType", typeid(SoundType))
{
    addPair(NO_SOUND, "NoSound");
    addPair(BOING_SOUND, "Boing");
    addPair(BOMB_SOUND, "Bomb");
    addPair(BREAK_SOUND, "Break");
    addPair(CLICK_SOUND, "Click");
    addPair(CLOCK_SOUND, "Clock");
    addPair(RUBBERBAND_SOUND, "Slingshot");
    addPair(PAGE_SOUND, "Page");
    addPair(PING_SOUND, "Ping");
    addPair(SNAP_SOUND, "Snap");
    addPair(SPLAT_SOUND, "Splat");
    addPair(STEP_SOUND, "Step");
    addPair(STEP_ON_SOUND, "StepOn");
    addPair(SWOOSH_SOUND, "Swoosh");
    addPair(VICTORY_SOUND, "Victory");
}

} // namespace Reflection
} // namespace RBX
