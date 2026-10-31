// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005a9260  unit: RBX::VScriptContext::?$FactoryProduct  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a9260
//
// 005a9260  83ec08               sub esp, 8
// 005a9263  56                   push esi
// 005a9264  8b742410             mov esi, dword ptr [esp + 0x10]
// 005a9268  57                   push edi
// 005a9269  6a01                 push 1
// 005a926b  56                   push esi
// 005a926c  e8ef8c0600           call 0x611f60
// 005a9271  dd5c2410             fstp qword ptr [esp + 0x10]
// 005a9275  6a43                 push 0x43
// 005a9277  56                   push esi
// 005a9278  e893910600           call 0x612410
// 005a927d  68eed8ffff           push 0xffffd8ee
// 005a9282  56                   push esi
// 005a9283  e8d8910600           call 0x612460
// 005a9288  6aff                 push -1
// 005a928a  56                   push esi
// 005a928b  e8908e0600           call 0x612120
// 005a9290  6afe                 push -2
// 005a9292  56                   push esi
// 005a9293  8bf8                 mov edi, eax
// 005a9295  e886890600           call 0x611c20
// 005a929a  dd442430             fld qword ptr [esp + 0x30]
// 005a929e  8b8fa8010000         mov ecx, dword ptr [edi + 0x1a8]
// 005a92a4  dd5c2420             fstp qword ptr [esp + 0x20]
// 005a92a8  83c420               add esp, 0x20
// 005a92ab  56                   push esi
// 005a92ac  e82f820700           call 0x6214e0
// 005a92b1  6a00                 push 0
// 005a92b3  56                   push esi
// 005a92b4  e8078c0700           call 0x621ec0
// 005a92b9  83c408               add esp, 8
// 005a92bc  5f                   pop edi
// 005a92bd  5e                   pop esi
// 005a92be  83c408               add esp, 8
// 005a92c1  c3                   ret 

struct lua_State;

struct Scheduler {
    void wait(lua_State*, double);
};

struct Context {
    char padding[0x1A8];
    Scheduler* scheduler;
};

extern "C" double __cdecl lua_tonumber(lua_State*, int);
extern "C" void __cdecl lua_pushlightuserdata(lua_State*, void*);
extern "C" void __cdecl lua_rawget(lua_State*, int);
extern "C" void* __cdecl lua_touserdata(lua_State*, int);
extern "C" void __cdecl lua_settop(lua_State*, int);
extern "C" int __cdecl lua_yield(lua_State*, int);

int __cdecl wait_callback(lua_State* state)
{
    double duration = lua_tonumber(state, 1);
    lua_pushlightuserdata(state, reinterpret_cast<void*>(0x43));
    lua_rawget(state, -10002);
    Context* context = static_cast<Context*>(lua_touserdata(state, -1));
    lua_settop(state, -2);
    context->scheduler->wait(state, duration);
    return lua_yield(state, 0);
}
