// from server: 72% by atomic.potato
extern "C" void __stdcall sub_414da0(const char* value);

struct EventDesc
{
    char pad[0x1e0];
    float field_1e0;

    void setValue(float value);
};

void EventDesc::setValue(float value)
{
    if (value != field_1e0) {
        field_1e0 = value;
        sub_414da0((const char*)0x00e4ec04);
    }
}
