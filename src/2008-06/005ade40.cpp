// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_loadfileinlinecontextab554d525443a024.cpp

// Candidate translation unit (score above; library headers required).
#include "util/ContentProvider.h"
struct lua_State;
struct Bridge{void require();};
extern Bridge* __stdcall security(int,const char*);
extern const char* __cdecl lua_tostring(lua_State*,int);
extern void __cdecl lua_pushlightuserdata(lua_State*,int);
extern void __cdecl lua_rawget(lua_State*,int);
extern RBX::Instance* __cdecl getInstance(lua_State*,int);
extern void __cdecl lua_settop(lua_State*,int);
extern int __cdecl luaL_loadfile(lua_State*,const char*);
extern void __cdecl lua_pushnil(lua_State*);
extern void __cdecl lua_insert(lua_State*,int);
struct Provider{std::string getFile(RBX::ContentId);};
extern Provider* __cdecl findProvider(RBX::Instance*);
inline RBX::Instance* context(lua_State* state){lua_pushlightuserdata(state,67);lua_rawget(state,-10002);RBX::Instance* instance=getInstance(state,-1);lua_settop(state,-2);return instance;}
int __cdecl loadfile(lua_State* state){
security(1,"loadfile")->require();
RBX::ContentId id(lua_tostring(state,-1));
const std::string& file=findProvider(context(state))->getFile(id);
int n;if(luaL_loadfile(state,file.c_str())==0)n=1;else{lua_pushnil(state);lua_insert(state,-2);n=2;}return n;
}
