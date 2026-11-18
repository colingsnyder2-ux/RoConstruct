// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native StringConverter<Controller::InputType>::convertToValue/convertToString (inactive).
// Uses EnumDesc<Controller::InputType>::singleton() for string<->enum conversion.

#include "util/Controller.h"
#include "util/Utilities.h"
#include "reflection/enumconverter.h"

namespace RBX
{
    template<>
    bool StringConverter<Controller::InputType>::convertToValue(const std::string& text, Controller::InputType& value)
    {
        return Reflection::EnumDesc<Controller::InputType>::singleton().convertToValue(text, value);
    }

    template<>
    std::string StringConverter<Controller::InputType>::convertToString(const Controller::InputType& value)
    {
        return Reflection::EnumDesc<Controller::InputType>::singleton().convertToString(value);
    }
}