// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00652310 ?_Buynode@?$_Tree@V?$_Tmap_traits@PAVTeam@RBX@@V?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@: explicit template instantiation (generic_templates.py, class form, byte-proved standalone)
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

template class std::_Tree<std::_Tmap_traits<RBX::Team *,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > >,std::less<RBX::Team *>,std::allocator<std::pair<RBX::Team * const,std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,int> > > > >,0> >;
