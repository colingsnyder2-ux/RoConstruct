// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005a92d0  unit: RBX::VScriptContext::?$FactoryProduct  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a92d0
//
// 005a92d0  56                   push esi
// 005a92d1  8b742408             mov esi, dword ptr [esp + 8]
// 005a92d5  57                   push edi
// 005a92d6  6a43                 push 0x43
// 005a92d8  56                   push esi
// 005a92d9  e832910600           call 0x612410
// 005a92de  68eed8ffff           push 0xffffd8ee
// 005a92e3  56                   push esi
// 005a92e4  e877910600           call 0x612460
// 005a92e9  6aff                 push -1
// 005a92eb  56                   push esi
// 005a92ec  e82f8e0600           call 0x612120
// 005a92f1  6afe                 push -2
// 005a92f3  56                   push esi
// 005a92f4  8bf8                 mov edi, eax
// 005a92f6  e825890600           call 0x611c20
// 005a92fb  8b87a0010000         mov eax, dword ptr [edi + 0x1a0]
// 005a9301  dd80b8010000         fld qword ptr [eax + 0x1b8]
// 005a9307  83c418               add esp, 0x18
// 005a930a  dd1c24               fstp qword ptr [esp]
// 005a930d  56                   push esi
// 005a930e  e8ed8e0600           call 0x612200
// 005a9313  83c40c               add esp, 0xc
// 005a9316  5f                   pop edi
// 005a9317  b801000000           mov eax, 1
// 005a931c  5e                   pop esi
// 005a931d  c3                   ret 

struct lua_State;

extern "C" void __cdecl lua_pushlightuserdata(lua_State *, void *);
extern "C" void __cdecl lua_rawget(lua_State *, int);
extern "C" void * __cdecl lua_touserdata(lua_State *, int);
extern "C" void __cdecl lua_settop(lua_State *, int);
extern "C" void __cdecl lua_pushnumber(lua_State *, double);

int __cdecl f(lua_State *L)
{
    lua_pushlightuserdata(L, (void *)0x43);
    lua_rawget(L, -10002);
    void *context = lua_touserdata(L, -1);
    lua_settop(L, -2);
    void *object = *(void **)((char *)context + 0xf0);
    lua_pushnumber(L, *(double *)((char *)object + 0xa0));
    return 1;
}
