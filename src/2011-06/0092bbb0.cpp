// from server: 100% by tester
struct GfxBinding {
    virtual void func(int);
};

void GfxBinding::func(int) {
    void (__thiscall *vtable_func)(GfxBinding*) = (void (__thiscall*)(GfxBinding*))(*(int**)this)[0];
    vtable_func(this);
}
