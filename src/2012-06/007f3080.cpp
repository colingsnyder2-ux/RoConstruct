// from server: 100% by atomic.potato
struct EventDesc {
    unsigned char pad[0x2e9];
    unsigned char field_2e9;
    void setFlag(unsigned char value);
};

extern "C" void __stdcall sub_414da0(const char* name);

void EventDesc::setFlag(unsigned char value)
{
    if (field_2e9 != value) {
        field_2e9 = value;
        sub_414da0((const char*)0x00e4ee50);
    }
}
