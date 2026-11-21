// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 004a2030 ??$getset@P8Instance@RBX@@BE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ@?$PropDescripto: explicit template instantiation (generic_templates.py, member form, byte-proved standalone)
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
#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "reflection/property.h"
#include "util/Object.h"

template std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >::GetSet> RBX::Reflection::PropDescriptor<RBX::Instance,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >::getset<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > (__thiscall RBX::Instance::*)(void)const >(std::basic_string<char,std::char_traits<char>,std::allocator<char> > (__thiscall RBX::Instance::*)(void)const ,int);
