// from server: 100% by colin
struct ScintillaView {
    void OnCancelMode();
};

void ScintillaView::OnCancelMode()
{
    struct VTable {
        char pad[0x1a8];
        void (__thiscall *fn)(void *, int);
    };
    VTable *vt = *(VTable **)this;
    vt->fn(this, 1);
}
