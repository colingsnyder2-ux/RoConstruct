// from server: 68% by Intel
struct GuiObject
{
    int field_20;
    int field_34;
    void setField34(int value);
};

void GuiObject::setField34(int value)
{
    if (value != field_34)
    {
        field_34 = value;
        if (value == 0)
        {
            extern const float flt_BA8508;
            field_20 = *reinterpret_cast<const int*>(&flt_BA8508);
        }
    }
}
