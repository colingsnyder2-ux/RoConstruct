#include "v8datamodel/Stats.h"
namespace RBX {
template<class D, const char* N> const Name& NonFactoryProduct<D,N>::className() { return Name::declare<N>(); }
template<> const Name& NonFactoryProduct<Instance,Stats::sStatsItem>::getClassName() const { return className(); }
}
