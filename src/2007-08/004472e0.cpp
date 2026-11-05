// from server: 100% by colin
struct CRenderSettings {
    char pad[0x118];
    int field_0x118;
    void setSomething(int value);
};

void CRenderSettings::setSomething(int value) {
    if (value != this->field_0x118) {
        this->field_0x118 = value;
        extern void __stdcall someFunction(int);
        someFunction(0x8bbc34);
    }
}
