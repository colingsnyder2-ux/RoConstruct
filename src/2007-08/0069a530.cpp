// from server: 100% by colin
struct CPropertyGridItemBrickColor {
    void Update();
};

void CPropertyGridItemBrickColor::Update() {
    int* p = *(int**)((char*)this + 0x104);
    if (p != 0) {
        int v = *p;
        if (v != *(int*)((char*)this + 0x100)) {
            int* vtbl = *(int**)this;
            void (__thiscall *fn)(void*, int) = *(void (__thiscall **)(void*, int))(vtbl + 0xe4 / 4);
            fn(this, v);
        }
    }
}
