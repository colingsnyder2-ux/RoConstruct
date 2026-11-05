// from server: 100% by why2
// roc 2009-06 006c2ae0  unit: lua_exception  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c2ae0

extern "C" int __cdecl sub_6b9180(int, int, int);

struct lua_exception {
    int f();
};

int lua_exception::f() {
    return sub_6b9180(*(int*)((char*)this + 0xc), -1, 0);
}
