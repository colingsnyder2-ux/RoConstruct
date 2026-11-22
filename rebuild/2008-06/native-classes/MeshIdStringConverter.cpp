// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native StringConverter<MeshId>::convertToValue/convertToString (inactive).
// MeshId inherits from ContentId, uses ContentId string conversion.

#include "util/MeshId.h"
#include "util/Utilities.h"
// Batch 41: the slingshot-load/util/ContentProvider.h include (donor ContentId) clashed with the native
// util/ContentProvider.h that util/MeshId.h includes (C2011); the native header declares ContentId::toString.

namespace RBX
{
    template<>
    bool StringConverter<MeshId>::convertToValue(const std::string& text, MeshId& value)
    {
        value = MeshId(text);
        return true;
    }

    template<>
    std::string StringConverter<MeshId>::convertToString(const MeshId& value)
    {
        return value.toString();
    }
}