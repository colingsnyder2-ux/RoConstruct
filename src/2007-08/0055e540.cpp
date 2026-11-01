// from server: 56% by colin
struct RotateSelectionVerb {
    char pad0[0xe8];
    struct VTableHolder {
        void* pad0;
        void* fn;
    };
    VTableHolder* m_holder;
    void invoke();
};

void RotateSelectionVerb::invoke()
{
    VTableHolder* h = m_holder;
    void (*fn)() = (void (*)())h->fn;
    fn();
}
