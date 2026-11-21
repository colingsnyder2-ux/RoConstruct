#pragma once

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
