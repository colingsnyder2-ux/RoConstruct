// from server: 100% by atomic.potato
extern "C" void __cdecl lua_pushnumber(void* L, double n);

struct VScriptContext {
    char pad0[0x1c];
    void* field1c;
};

int __cdecl method(void* a) {
    VScriptContext* p;
    if (a) {
        p = (VScriptContext*)((char*)a - 0x28);
    } else {
        p = 0;
    }
    void* q = p->field1c;
    double d = *(double*)(*(char**)((char*)q + 0x100) + 0xb0);
    lua_pushnumber(a, d);
    return 1;
}
