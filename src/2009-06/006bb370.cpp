// from server: 100% by why2
// roc 2009-06 006bb370  unit: RBX::Lua::LuaArguments  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006bb370
//
// 006bb370  8b4110               mov eax, dword ptr [ecx + 0x10]
// 006bb373  50                   push eax
// 006bb374  e807daffff           call 0x6b8d80
// 006bb379  83c404               add esp, 4
// 006bb37c  48                   dec eax
// 006bb37d  c3                   ret

extern "C" int __cdecl sub_6b8d80(int);

struct LuaArguments {
    char pad[0x10];
    int field_0x10;
    int f();
};

int LuaArguments::f() {
    return sub_6b8d80(field_0x10) - 1;
}
