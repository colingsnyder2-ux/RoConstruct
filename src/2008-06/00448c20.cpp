// from server: 100% by king_originala
struct Setter
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* instance, const int& value);
};

struct EnumInfo
{
    bool accepts(int value);
};

struct Descriptor
{
    char gap[0x1c];
    Setter* setter;
    EnumInfo* info;

    bool setValue(void* instance, int value);
};

bool Descriptor::setValue(void* instance, int value)
{
    if (info->accepts(value)) {
        int converted = value;
        setter->set(instance, converted);
        return true;
    }
    return false;
}
