// from server: 100% by tester
struct CPatchedControlComboBox {
    char pad[0x1cc];
    int field_1cc;
    int getValue();
};

struct Inner {
    virtual int method1f8();
};

extern "C" Inner* __fastcall sub_637300(CPatchedControlComboBox* self);

int CPatchedControlComboBox::getValue()
{
    Inner* p = sub_637300(this);
    if (p != 0)
        return (*(int (__thiscall**)(Inner*))((*(int*)p) + 0x1f8))(p);
    return this->field_1cc;
}
