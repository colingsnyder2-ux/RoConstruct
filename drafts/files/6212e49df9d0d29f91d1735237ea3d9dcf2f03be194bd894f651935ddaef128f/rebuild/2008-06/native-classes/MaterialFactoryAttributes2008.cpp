// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Material-cache key ordering; identity inferred from 2008 call sites and donor.
#include "ViewNew/MaterialFactory2008.h"

bool RBX::ViewNew::MaterialFactory::Attributes::operator<(const Attributes& other) const
{
    if (color < other.color) return true;
    if (color > other.color) return false;
    if (transparency < other.transparency) return true;
    if (transparency > other.transparency) return false;
    return reflectance < other.reflectance;
}
