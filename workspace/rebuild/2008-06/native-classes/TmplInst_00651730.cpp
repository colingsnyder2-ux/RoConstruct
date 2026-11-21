// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00651730 ?_Buynode@?$_Tree@V?$_Tmap_traits@PAVTeam@RBX@@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
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
#include "v8datamodel/Team.h"
#include "util/Object.h"

template class std::_Tree<std::_Tmap_traits<RBX::Team *,std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::less<RBX::Team *>,std::allocator<std::pair<RBX::Team * const,std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > > >,0> >;
