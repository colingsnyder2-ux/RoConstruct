// from server: 100% by atomic.potato
extern "C" void __stdcall sub_414da0(const char* name);

struct EventDesc {
    unsigned char pad[0x2e8];
    unsigned char field_2e8;
    void setValue(unsigned char value);
};

void EventDesc::setValue(unsigned char value)
{
    if (field_2e8 != value) {
        field_2e8 = value;
        sub_414da0((const char*)0x00e4ed48);
    }
}
