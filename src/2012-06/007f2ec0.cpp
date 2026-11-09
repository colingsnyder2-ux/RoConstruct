// from server: 100% by atomic.potato
struct EventDesc {
    char pad[0x2ea];
    unsigned char field_2ea;
    void setFlag(unsigned char value);
};

extern "C" void __stdcall sub_414da0(const char* name);

void EventDesc::setFlag(unsigned char value)
{
    if (field_2ea != value) {
        field_2ea = value;
        sub_414da0((const char*)0x00e4f028);
    }
}
