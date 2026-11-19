#pragma once

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
