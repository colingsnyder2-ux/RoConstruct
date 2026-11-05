// from server: 100% by colin
struct CXTPPropertyGridItem
{
    char pad_0000[0xb4];
    void* field_0xb4;
    char pad_00b8[0xf0 - 0xb8];
    void* field_0xf0;
    void SetValue(void* value);
};

extern void __fastcall sub_0069d700(void*);

void CXTPPropertyGridItem::SetValue(void* value)
{
    if (value != this->field_0xf0)
    {
        this->field_0xf0 = value;
        sub_0069d700(this->field_0xb4);
    }
}
