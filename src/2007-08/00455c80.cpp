// from server: 46% by Intel




struct S;
struct Registry {
    void remove(S* const* object);
};

struct CRobloxReportPaneView {
    unsigned long vtable;
    void func_00455c80();
};

void __cdecl sub_455ab0(CRobloxReportPaneView*);

void CRobloxReportPaneView::func_00455c80()
{
    __try {
        S* object = 0;
        if (this == 0) {
            object = reinterpret_cast<S*>(reinterpret_cast<char*>(this) + 0x318);
        }
        Registry registry;
        registry.remove(&object);
    }
    __finally {
        sub_455ab0(this);
    }
}
