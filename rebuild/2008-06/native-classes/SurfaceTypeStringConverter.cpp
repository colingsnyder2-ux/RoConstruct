// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native StringConverter<SurfaceType>::convertToValue/convertToString (inactive).
// Uses EnumDesc<SurfaceType>::singleton() for string<->enum conversion.

#include "util/SurfaceType.h"
#include "util/Utilities.h"
#include "reflection/enumconverter.h"

namespace RBX
{
    template<>
    bool StringConverter<SurfaceType>::convertToValue(const std::string& text, SurfaceType& value)
    {
        return Reflection::EnumDesc<SurfaceType>::singleton().convertToValue(text, value);
    }

    template<>
    std::string StringConverter<SurfaceType>::convertToString(const SurfaceType& value)
    {
        return Reflection::EnumDesc<SurfaceType>::singleton().convertToString(value);
    }
}