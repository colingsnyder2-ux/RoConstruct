// from server: 100% by why2
struct ScintillaView {
    void method();
};

void ScintillaView::method()
{
    void (__thiscall *fn)(void*, int);
    fn = *(void (__thiscall **)(void*, int))(*(int*)this + 0x1b0);
    fn(this, 1);
}
