// from server: 100% by tajop
struct Holder { void set(const int& v); };
struct Var { void* type; Holder h; };
extern int g_onceFlag;
extern void initOnce();
extern void callOnce(int* flag, void (*fn)());
extern void* getEnumType();
struct S {
    char pad0[0x2c];
    unsigned count;
    char pad1[0x90 - 0x30];
    int* values;
    bool f(unsigned index, Var* out);
};
bool S::f(unsigned index, Var* out)
{
    bool ok;
    int v;
    if (index < count) {
        v = values[index];
        ok = true;
    } else {
        ok = false;
    }
    callOnce(&g_onceFlag, &initOnce);
    out->type = getEnumType();
    out->h.set(v);
    return ok;
}
