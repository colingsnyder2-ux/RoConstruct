// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0058b1c0 is boost::any::holder<RBX::Reflection::Tuple>::clone, not holder<std::vector<Value>> as the identity
// registry names it: its vtable 0083193c holds type() 0058b1b0, which returns the type descriptor 00946340
// .?AUTuple@Reflection@RBX@@ (the holder<vector<Value>> twin 005acd10 sits in vtable 008345c8 whose type() 005acd00
// returns 0092bf60 .?AV?$vector@VValue@...). Its holder constructor 0058b160 copies the Tuple through the
// vector<Value> copy constructor 0055fed0. Explicit instantiation of the Tuple holder.
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
#include "reflection/type.h"
#include "reflection/reflection.h"
#include "util/Object.h"

template class boost::any::holder<RBX::Reflection::Tuple>;
