// from server: 100% by atomic.potato
struct EventDesc {
    unsigned char pad[0xb1];
    unsigned char field_b1;
    void setValue(unsigned char value);
};

extern "C" void __stdcall sub_414da0(const char* value);

void EventDesc::setValue(unsigned char value)
{
    if (field_b1 != value) {
        field_b1 = value;
        sub_414da0((const char*)0x00e4f148);
    }
}
