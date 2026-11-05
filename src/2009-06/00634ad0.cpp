// from server: 100% by EspClaude
// roc 2009-06 00634ad0  unit: RBX::VScriptContext::?$FactoryProduct  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00634ad0
//
// 00634ad0  56                   push esi
// 00634ad1  8b742408             mov esi, dword ptr [esp + 8]
// 00634ad5  57                   push edi
// 00634ad6  56                   push esi
// 00634ad7  e8a4420800           call 0x6b8d80
// 00634adc  68d04a6300           push 0x634ad0
// 00634ae1  56                   push esi
// 00634ae2  e8694a0800           call 0x6b9550
// 00634ae7  68f0d8ffff           push 0xffffd8f0
// 00634aec  56                   push esi
// 00634aed  e83e4b0800           call 0x6b9630
// 00634af2  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00634af6  57                   push edi
// 00634af7  56                   push esi
// 00634af8  e8534a0800           call 0x6b9550
// 00634afd  6afe                 push -2
// 00634aff  56                   push esi
// 00634b00  e82b4b0800           call 0x6b9630
// 00634b05  6aff                 push -1
// 00634b07  56                   push esi
// 00634b08  e863440800           call 0x6b8f70
// 00634b0d  83c42c               add esp, 0x2c
// 00634b10  85c0                 test eax, eax
// 00634b12  754c                 jne 0x634b60
// 00634b14  6afe                 push -2
// 00634b16  56                   push esi
// 00634b17  e874420800           call 0x6b8d90
// 00634b1c  6a04                 push 4
// 00634b1e  56                   push esi
// 00634b1f  e8ac520800           call 0x6b9dd0
// 00634b24  83c410               add esp, 0x10
// 00634b27  85c0                 test eax, eax
// 00634b29  7402                 je 0x634b2d
// 00634b2b  8938                 mov dword ptr [eax], edi
// 00634b2d  a10c2ba200           mov eax, dword ptr [0xa22b0c]
// 00634b32  50                   push eax
// 00634b33  68f0d8ffff           push 0xffffd8f0
// 00634b38  56                   push esi
// 00634b39  e8924a0800           call 0x6b95d0
// 00634b3e  6afe                 push -2
// 00634b40  56                   push esi
// 00634b41  e81a4e0800           call 0x6b9960
// 00634b46  57                   push edi
// 00634b47  56                   push esi
// 00634b48  e8034a0800           call 0x6b9550
// 00634b4d  6afe                 push -2
// 00634b4f  56                   push esi
// 00634b50  e8eb430800           call 0x6b8f40
// 00634b55  6afc                 push -4
// 00634b57  56                   push esi
// 00634b58  e8134d0800           call 0x6b9870
// 00634b5d  83c42c               add esp, 0x2c
// 00634b60  6afe                 push -2
// 00634b62  56                   push esi
// 00634b63  e878420800           call 0x6b8de0
// 00634b68  83c408               add esp, 8
// 00634b6b  5f                   pop edi
// 00634b6c  5e                   pop esi
// 00634b6d  c3                   ret 
// copied from an identical function in another client (function ?push_object@ns_ROCX00001f@@YAXPAUlua_State@1@PAX@Z)

namespace ns_ROCX00001f {
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
}
