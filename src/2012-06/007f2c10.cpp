// from server: 100% by atomic.potato
struct EventDesc {
    unsigned char pad[0xb0];
    unsigned char field_b0;
    void setValue(unsigned char value);
};

extern "C" void __stdcall sub_414da0(const char* value);

void EventDesc::setValue(unsigned char value)
{
    if (field_b0 != value) {
        field_b0 = value;
        sub_414da0((const char*)0x00e4ee24);
    }
}
