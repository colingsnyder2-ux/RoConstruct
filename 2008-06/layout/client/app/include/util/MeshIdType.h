#pragma once
// 2008-06: the reflection Type of RBX::MeshId is the ContentId type (inactive).
// Evidence: MeshId inherits from ContentId; same pattern as TextureId (AppUnit594_2008/TextureIdType2008.h).

#include "reflection/type.h"
#include "util/MeshId.h"

namespace RBX
{
    namespace Reflection
    {
        template<>
        inline const Type& Type::singleton<MeshId>()
        {
            return Type::singleton<ContentId>();
        }
    }
}