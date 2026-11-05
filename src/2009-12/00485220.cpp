// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 100% by tester
struct GfxBinding {
    virtual void func(int);
};

void GfxBinding::func(int) {
    void (__thiscall *vtable_func)(GfxBinding*) = (void (__thiscall*)(GfxBinding*))(*(int**)this)[0];
    vtable_func(this);
}