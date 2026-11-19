// native-flags: /O2 /Oy /GS- /EHsc /Zc:wchar_t- /MD
#include <stdlib.h>
#include <memory>
#include "v8tree/Instance.h"
#include "v8datamodel/Stats.h"
#include "G3D/Stopwatch.h"
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

// 005a4af0
template boost::shared_ptr<RBX::Stats::TypedStatsItem<int> >
RBX::Creatable<RBX::Instance>::create<RBX::Stats::TypedStatsItem<int>, boost::function0<int, std::allocator<boost::function_base> > >(boost::function0<int, std::allocator<boost::function_base> >);

// 005a4bd0
template boost::shared_ptr<RBX::Stats::TypedStatsItem<unsigned int> >
RBX::Creatable<RBX::Instance>::create<RBX::Stats::TypedStatsItem<unsigned int>, boost::function0<unsigned int, std::allocator<boost::function_base> > >(boost::function0<unsigned int, std::allocator<boost::function_base> >);

// 005a4cb0
template boost::shared_ptr<RBX::Stats::TypedStatsItem<G3D::Stopwatch> >
RBX::Creatable<RBX::Instance>::create<RBX::Stats::TypedStatsItem<G3D::Stopwatch>, boost::function0<G3D::Stopwatch, std::allocator<boost::function_base> > >(boost::function0<G3D::Stopwatch, std::allocator<boost::function_base> >);
