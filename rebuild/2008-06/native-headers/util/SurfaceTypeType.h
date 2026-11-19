#pragma once
// 2008-06: the reflection Type of RBX::SurfaceType uses the EnumDesc singleton (inactive).
// Evidence: EnumDesc<SurfaceType> is used for string<->enum conversion in genericConvert.

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