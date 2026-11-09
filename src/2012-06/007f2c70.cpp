// from server: 100% by atomic.potato
struct EventDesc {
    unsigned char pad[0x1bc];
    int value;
    void setValue(int value);
};

extern "C" void __stdcall sub_414da0(const char* value);

void EventDesc::setValue(int value)
{
    if (value < 0)
        value = 0;
    else if (value > 1)
        value = 1;

    if (this->value != value) {
        this->value = value;
        sub_414da0((const char*)0x00e4eda0);
    }
}
