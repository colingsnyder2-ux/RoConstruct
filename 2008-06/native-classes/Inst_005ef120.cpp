// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /IC:/Users/colin/RoConstruct/2008-06/src/Client/App/include
// 005ef120 = Reflection::Value::operator=<RBX::SurfaceType>: Type::singleton<T>() (call_once 005ed620 / flag
// 0097b11c) followed by boost::any::operator=<T> storing holder<SurfaceType>'s vftable.
#include "reflection/type.h"
#include "reflection/reflection.h"
#include <boost/any.hpp>
#include "util/SurfaceType.h"

template boost::any& boost::any::operator=<RBX::SurfaceType>(const RBX::SurfaceType&);
template RBX::Reflection::Value& RBX::Reflection::Value::operator=<RBX::SurfaceType>(const RBX::SurfaceType&);
