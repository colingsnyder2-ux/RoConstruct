// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005a9a90  unit: RBX::VScriptContext::?$FactoryProduct  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a9a90
//
// 005a9a90  56                   push esi
// 005a9a91  8b742408             mov esi, dword ptr [esp + 8]
// 005a9a95  57                   push edi
// 005a9a96  56                   push esi
// 005a9a97  e874810600           call 0x611c10
// 005a9a9c  68909a5a00           push 0x5a9a90
// 005a9aa1  56                   push esi
// 005a9aa2  e869890600           call 0x612410
// 005a9aa7  68f0d8ffff           push 0xffffd8f0
// 005a9aac  56                   push esi
// 005a9aad  e83e8a0600           call 0x6124f0
// 005a9ab2  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005a9ab6  57                   push edi
// 005a9ab7  56                   push esi
// 005a9ab8  e853890600           call 0x612410
// 005a9abd  6afe                 push -2
// 005a9abf  56                   push esi
// 005a9ac0  e82b8a0600           call 0x6124f0
// 005a9ac5  6aff                 push -1
// 005a9ac7  56                   push esi
// 005a9ac8  e833830600           call 0x611e00
// 005a9acd  83c42c               add esp, 0x2c
// 005a9ad0  85c0                 test eax, eax
// 005a9ad2  754c                 jne 0x5a9b20
// 005a9ad4  6afe                 push -2
// 005a9ad6  56                   push esi
// 005a9ad7  e844810600           call 0x611c20
// 005a9adc  6a04                 push 4
// 005a9ade  56                   push esi
// 005a9adf  e85c910600           call 0x612c40
// 005a9ae4  83c410               add esp, 0x10
// 005a9ae7  85c0                 test eax, eax
// 005a9ae9  7402                 je 0x5a9aed
// 005a9aeb  8938                 mov dword ptr [eax], edi
// 005a9aed  a1d4b19500           mov eax, dword ptr [0x95b1d4]
// 005a9af2  50                   push eax
// 005a9af3  68f0d8ffff           push 0xffffd8f0
// 005a9af8  56                   push esi
// 005a9af9  e892890600           call 0x612490
// 005a9afe  6afe                 push -2
// 005a9b00  56                   push esi
// 005a9b01  e8ea8c0600           call 0x6127f0
// 005a9b06  57                   push edi
// 005a9b07  56                   push esi
// 005a9b08  e803890600           call 0x612410
// 005a9b0d  6afe                 push -2
// 005a9b0f  56                   push esi
// 005a9b10  e8bb820600           call 0x611dd0
// 005a9b15  6afc                 push -4
// 005a9b17  56                   push esi
// 005a9b18  e8f38b0600           call 0x612710
// 005a9b1d  83c42c               add esp, 0x2c
// 005a9b20  6afe                 push -2
// 005a9b22  56                   push esi
// 005a9b23  e848810600           call 0x611c70
// 005a9b28  83c408               add esp, 8
// 005a9b2b  5f                   pop edi
// 005a9b2c  5e                   pop esi
// 005a9b2d  c3                   ret 

struct lua_State;

extern "C" {
int __cdecl lua_gettop(lua_State*);
void __cdecl lua_settop(lua_State*, int);
void __cdecl lua_remove(lua_State*, int);
void __cdecl lua_pushvalue(lua_State*, int);
int __cdecl lua_type(lua_State*, int);
void __cdecl lua_pushlightuserdata(lua_State*, void*);
void __cdecl lua_getfield(lua_State*, int, const char*);
void __cdecl lua_rawget(lua_State*, int);
void __cdecl lua_rawset(lua_State*, int);
int __cdecl lua_setmetatable(lua_State*, int);
void* __cdecl lua_newuserdata(lua_State*, unsigned int);
}

extern const char* metatableName;

void __cdecl push_object(lua_State* state, void* object)
{
    lua_gettop(state);
    lua_pushlightuserdata(state, reinterpret_cast<void*>(&push_object));
    lua_rawget(state, -10000);
    lua_pushlightuserdata(state, object);
    lua_rawget(state, -2);

    if (lua_type(state, -1) == 0) {
        lua_settop(state, -2);
        void** storage = static_cast<void**>(lua_newuserdata(state, 4));
        if (storage)
            *storage = object;

        lua_getfield(state, -10000, metatableName);
        lua_setmetatable(state, -2);
        lua_pushlightuserdata(state, object);
        lua_pushvalue(state, -2);
        lua_rawset(state, -4);
    }

    lua_remove(state, -2);
}
