// from server: 100% by tester
struct ScintillaView {
    void method();
};

void ScintillaView::method()
{
    typedef void (__thiscall *Fn)(void*, int);
    Fn fn = *(Fn*)(*(int*)this + 0x1b0);
    fn(this, 0);
}
