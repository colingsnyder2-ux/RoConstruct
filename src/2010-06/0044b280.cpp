// from server: 100% by colin
extern "C" void __stdcall helper(unsigned char);

struct TypedPropertyDescriptor {
    char pad[0xf8];
    unsigned char field_f8;
    void setFlag(unsigned char value);
};

void TypedPropertyDescriptor::setFlag(unsigned char value) {
    if (value != field_f8) {
        field_f8 = value;
        helper(0xc01800);
    }
}
