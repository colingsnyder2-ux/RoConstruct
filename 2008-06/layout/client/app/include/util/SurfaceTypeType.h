#pragma once

#include "reflection/type.h"
#include "util/SurfaceType.h"
#include "reflection/enumconverter.h"

namespace RBX
{
    namespace Reflection
    {
        template<>
        inline const Type& Type::singleton<SurfaceType>()
        {
            return EnumDesc<SurfaceType>::singleton();
        }
    }
}
