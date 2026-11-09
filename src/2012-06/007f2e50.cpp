// from server: 100% by colin
struct VGuiObject {
    char pad[0x194];
    int field_194;
    char pad2[0x1dd - 0x198];
    unsigned char field_1dd;
    void setFlag(unsigned char value);
};

extern "C" void __stdcall sub_414da0(const char* name);

void VGuiObject::setFlag(unsigned char value)
{
    if (field_1dd != value) {
        field_1dd = value;
        sub_414da0((const char*)0x00e4ed74);
        if (field_1dd == 0) {
            field_194 = 0;
        }
    }
}
