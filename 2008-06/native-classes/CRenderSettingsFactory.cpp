#include "CRenderSettings.h"

namespace RBX {
template<typename Class, typename DerivedClass, const char* ClassName>
FactoryProduct<Class, DerivedClass, ClassName>::FactoryProduct() {}

template FactoryProduct<CRenderSettings, GlobalSettings::Item, sRenderSettings>::FactoryProduct();
}
