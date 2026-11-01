// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct R_00517e10 { R_00517e10(const R_00517e10&); ~R_00517e10(); int x; };
struct C_00517e10 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual R_00517e10 get(int m, int z);
    R_00517e10 f();
    char pad[0x88];
    int m;
};
R_00517e10 C_00517e10::f()
{
    return get(m, 0);
}
