// from server: 100% by tester
struct CPropertyGridItemBrickColor {
    void Update();
};

void CPropertyGridItemBrickColor::Update() {
    int* p = *(int**)((char*)this + 0x110);
    if (p != 0) {
        int v = *p;
        if (v != *(int*)((char*)this + 0x10c)) {
            int* vtbl = *(int**)this;
            void (__thiscall *fn)(void*, int) = *(void (__thiscall **)(void*, int))(vtbl + 0xe4 / 4);
            fn(this, v);
        }
    }
}
