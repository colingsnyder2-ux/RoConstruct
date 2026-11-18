// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/RbxGraphics/include /I{headers}/../../../tools/rbxgs/Client/Network/include /I{headers}/../../../tools/rbxgs/Client/RbxView/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/zlib /I{headers}/../../../tools/rbxgs/Client/Rendering/RenderLib/include /I{headers}/../../../tools/rbxgs/Client/Rendering/AppDraw/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}/../../../tools/rbxgs/Client/App/lua-5.1.1/src /I{headers}/../../../tools/rbxgs/Client/Rendering/SDL-1.2.6/include /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00577630 / 00577670: boost::function invokers for bound string(*)(string) and string(*)(string,string),
// instantiated by DataModel.cpp (library rbxgs v8datamodel/DataModel.cpp).
#include <string>
#include <boost/bind.hpp>
#include <boost/function.hpp>

typedef boost::_bi::bind_t<
    std::string,
    std::string (__cdecl*)(std::string),
    boost::_bi::list1<boost::_bi::value<std::string> > > RbxBindStr1;
typedef boost::_bi::bind_t<
    std::string,
    std::string (__cdecl*)(std::string, std::string),
    boost::_bi::list2<boost::_bi::value<std::string>, boost::_bi::value<std::string> > > RbxBindStr2;

template struct boost::detail::function::void_function_obj_invoker0<RbxBindStr1, void>;
template struct boost::detail::function::void_function_obj_invoker0<RbxBindStr2, void>;
