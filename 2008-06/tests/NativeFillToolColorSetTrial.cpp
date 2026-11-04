#include "v8datamodel/ToolsPart.h"
namespace RBX {
// Body from tests/NativePropGridWorkerTrial.cpp; FillToolColor is a Notifier<FillToolColor, BrickColor>.
void FillToolColor::set(const BrickColor& value)
{
    if (color != value)
    {
        color = value;
        raise(value);
    }
}
}
