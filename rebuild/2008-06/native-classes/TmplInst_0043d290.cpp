// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0043d290 ?_Buynode@?$_Tree@V?$_Tmap_traits@PBVClassDescriptor@Reflection@RBX@@V?$vector@V?$shared_ptr@VInstance@RBX@@@b: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/any.hpp>
#include "reflection/Metadata.h"
#include "v8tree/Instance.h"
#include "util/Object.h"

template class std::_Tree<std::_Tmap_traits<RBX::Reflection::ClassDescriptor const *,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >,std::less<RBX::Reflection::ClassDescriptor const *>,std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > >,0> >;
