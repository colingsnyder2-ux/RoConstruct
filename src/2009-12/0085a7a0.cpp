// from server: 100% by atomic.potato
struct CXTPStatusBarPane
{
    void* GetValue();
    char padding_00[0x50];
    int field_50;
    char padding_54[8];
    int field_5c;
    int field_60;
};

void* CXTPStatusBarPane::GetValue()
{
    if (field_50 != 0 && field_60 == 0)
        return (char*)field_50 + 0xb0;
    return &field_5c;
}
