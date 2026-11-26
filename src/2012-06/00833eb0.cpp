// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00833f00  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00833f00
//
// 00833f00  56                   push esi
// 00833f01  57                   push edi
// 00833f02  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00833f06  6a0c                 push 0xc
// 00833f08  57                   push edi
// 00833f09  e832ecffff           call 0x832b40
// 00833f0e  8bf0                 mov esi, eax
// 00833f10  83c408               add esp, 8
// 00833f13  85f6                 test esi, esi
// 00833f15  7414                 je 0x833f2b
// 00833f17  8b442410             mov eax, dword ptr [esp + 0x10]
// 00833f1b  8906                 mov dword ptr [esi], eax
// 00833f1d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00833f21  894e04               mov dword ptr [esi + 4], ecx
// 00833f24  8b542418             mov edx, dword ptr [esp + 0x18]
// 00833f28  895608               mov dword ptr [esi + 8], edx
// 00833f2b  a1c013de00           mov eax, dword ptr [0xde13c0]
// 00833f30  50                   push eax
// 00833f31  68f0d8ffff           push 0xffffd8f0
// 00833f36  57                   push edi
// 00833f37  e804e4ffff           call 0x832340
// 00833f3c  6afe                 push -2
// 00833f3e  57                   push edi
// 00833f3f  e88ce7ffff           call 0x8326d0
// 00833f44  83c414               add esp, 0x14
// 00833f47  5f                   pop edi
// 00833f48  8bc6                 mov eax, esi
// 00833f4a  5e                   pop esi
// 00833f4b  c3                   ret 

struct lua_State;
struct V { int a; int b; int c; };

void* lua_newuserdata(lua_State* L, unsigned size);
void lua_getfield(lua_State* L, int idx, const char* k);
int lua_setmetatable(lua_State* L, int idx);

extern const char* className;

V* pushNew(lua_State* L, V v)
{
    V* r = (V*)lua_newuserdata(L, sizeof(V));
    if (r)
    {
        r->a = v.a;
        r->b = v.b;
        r->c = v.c;
    }
    lua_getfield(L, -10000, className);
    lua_setmetatable(L, -2);
    return r;
}
