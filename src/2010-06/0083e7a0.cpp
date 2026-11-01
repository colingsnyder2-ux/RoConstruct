// from server: 100% by tester
struct CXTPCustomizeSheet_CCustomizeEdit {
    void SetStyle(unsigned int flags);
};

void CXTPCustomizeSheet_CCustomizeEdit::SetStyle(unsigned int flags) {
    if (flags & 0x10) {
        unsigned int v = *(unsigned int*)((char*)this + 0xd0);
        void (__thiscall *fn)(void*, unsigned int) = *(void (__thiscall **)(void*, unsigned int))((*(char**)this) + 0x94);
        v |= 4;
        fn(this, v);
    } else {
        unsigned int v = *(unsigned int*)((char*)this + 0xd0);
        void (__thiscall *fn)(void*, unsigned int) = *(void (__thiscall **)(void*, unsigned int))((*(char**)this) + 0x94);
        v &= ~4u;
        fn(this, v);
    }
}
