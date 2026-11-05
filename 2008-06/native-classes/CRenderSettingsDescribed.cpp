#include "CRenderSettings.h"

namespace RBX {
template<typename Class, typename DerivedClass, const char* ClassName>
DescribedCreatable<Class, DerivedClass, ClassName>::DescribedCreatable() {}

template DescribedCreatable<CRenderSettings, GlobalSettings::Item, sRenderSettings>::DescribedCreatable();
}
