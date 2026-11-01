// from server: 100% by colin
struct CRobloxControlColorSelector {
    void SetSomething(int value);
};

void CRobloxControlColorSelector::SetSomething(int value) {
    *(int*)((char*)this + 0x100) = value;
    if (value == 0) {
        int flags = *(int*)((char*)this + 0xd0);
        void (__thiscall *fn)(void*, int) = *(void (__thiscall **)(void*, int))(*(int*)this + 0x94);
        flags &= 0xffffffdf;
        fn(this, flags);
    }
}
