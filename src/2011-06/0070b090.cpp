// from server: 95% by atomic.potato
extern "C" void __cdecl sub_411f60(const char*);

struct Vector3 {
    char padding[0x194];
    int field_194;
    void __thiscall method_70b090(int arg);
};

void Vector3::method_70b090(int arg) {
    if (field_194 != arg) {
        field_194 = arg;
        sub_411f60((const char*)0xCD3290);
    }
}
