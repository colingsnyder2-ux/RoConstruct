// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Native LuaArguments/type/ThreadRef/Boost any declarations plus the complete target switch.
#include <string>
#include <vector>
#include <typeinfo>
#include <stddef.h>
struct lua_State;
extern "C" {
 int __cdecl lua_gettop(lua_State*);int __cdecl lua_type(lua_State*,int);double __cdecl lua_tonumber(lua_State*,int);int __cdecl lua_toboolean(lua_State*,int);
 const char*__cdecl lua_tolstring(lua_State*,int,unsigned*);unsigned __cdecl lua_objlen(lua_State*,int);
 void __cdecl lua_rawgeti(lua_State*,int,int);void __cdecl lua_settop(lua_State*,int);
}
namespace boost {
struct any {
 struct placeholder {virtual ~placeholder(){}virtual const std::type_info&type()const=0;virtual placeholder*clone()const=0;};
 placeholder*content;~any(){delete content;}
};
}
namespace RBX {
namespace Lua {
struct ThreadRef {virtual void removeRef();char unused[28];};
struct FunctionRef:ThreadRef {int functionId;~FunctionRef();};
FunctionRef __cdecl lua_tofunction(lua_State*,int);
}
namespace Reflection {
struct Type;
struct Value {
 const Type*_type;boost::any value;
 Value();Value(const Value&);Value&operator=(const Value&);
 template<class T>Value&operator=(const T&);
};
typedef std::vector<Value>ValueCollection;
ValueCollection&__cdecl collectionFromAny(boost::any&);
}
namespace Lua {
struct CoordinateFrameBridge {static bool getValue(lua_State*,int,Reflection::Value&);};
struct Vector3Bridge {static bool getValue(lua_State*,int,Reflection::Value&);};
struct Color3Bridge {static bool getValue(lua_State*,int,Reflection::Value&);};
struct BrickColorBridge {static bool getValue(lua_State*,int,Reflection::Value&);};
struct ObjectBridge {static bool getPtr(lua_State*,int,Reflection::Value&);};
struct LuaArguments {static bool get(lua_State*,int,Reflection::Value&,bool);};
bool LuaArguments::get(lua_State*L,int luaIndex,Reflection::Value&value,bool nilIsMissing){
 if(luaIndex>lua_gettop(L))return false;
 switch(lua_type(L,luaIndex)){
 case 3:{double rhs=lua_tonumber(L,luaIndex);value=rhs;break;}
 case 1:{bool rhs=lua_toboolean(L,luaIndex)!=0;value=rhs;break;}
 case 4:{value=std::string(lua_tolstring(L,luaIndex,0));break;}
 case 5:{
  const int n=(int)lua_objlen(L,luaIndex);
  value=Reflection::ValueCollection(n);
  int i=1;
  Reflection::ValueCollection&values=Reflection::collectionFromAny(value.value);
  if(n>=1){
   do{
    Reflection::Value&ival=values[i-1];
    lua_rawgeti(L,luaIndex,i);get(L,-1,ival,false);lua_settop(L,-2);++i;
   }while(i<=n);
  }
  return true;
 }
 case 0:if(nilIsMissing)return false;value=Reflection::Value();break;
 case 6:value=lua_tofunction(L,luaIndex);break;
 default:value=Reflection::Value();break;
 case 7:
  if(CoordinateFrameBridge::getValue(L,luaIndex,value)||Vector3Bridge::getValue(L,luaIndex,value)||Color3Bridge::getValue(L,luaIndex,value)||BrickColorBridge::getValue(L,luaIndex,value)||ObjectBridge::getPtr(L,luaIndex,value))break;
  value=Reflection::Value();break;
 }
 return true;
}
}}
typedef char value_size[sizeof(RBX::Reflection::Value)==8?1:-1];
typedef char function_size[sizeof(RBX::Lua::FunctionRef)==36?1:-1];
typedef char collection_size[sizeof(RBX::Reflection::ValueCollection)==24?1:-1];
