// from server: 91% by atomic.potato
extern "C" void __stdcall sub_411F60(void*, void*);

struct RBX_VBasicPartInstance_ActionStation
{
    char pad_000[0x170];
    int field_170;
    void SetValue(int);
};

void RBX_VBasicPartInstance_ActionStation::SetValue(int value)
{
    if (value != this->field_170)
    {
        this->field_170 = value;
        sub_411F60((void*)0xCCE318, (void*)this);
        sub_411F60((void*)0xCCE0A8, (void*)this);
    }
}
