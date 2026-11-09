// from server: 100% by tester
struct ScintillaView {
    void OnCancelMode();
};

void ScintillaView::OnCancelMode()
{
    struct VTable {
        char pad[0x1b0];
        void (__thiscall *fn)(void *, int);
    };
    VTable *vt = *(VTable **)this;
    vt->fn(this, 1);
}