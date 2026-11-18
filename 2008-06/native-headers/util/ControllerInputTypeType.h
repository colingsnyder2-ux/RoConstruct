#pragma once
// 2008-06: the reflection Type of RBX::Controller::InputType uses the EnumDesc singleton (inactive).
// Evidence: EnumDesc<Controller::InputType> is used for string<->enum conversion in genericConvert.

#include "reflection/type.h"
#include "util/Controller.h"
#include "reflection/enumconverter.h"

namespace RBX
{
    namespace Reflection
    {
        template<>
        inline const Type& Type::singleton<Controller::InputType>()
        {
            return EnumDesc<Controller::InputType>::singleton();
        }
    }
}