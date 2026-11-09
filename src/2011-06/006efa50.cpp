// from server: 76% by atomic.potato
struct BillboardGui
{
    void SetFlag(unsigned char value);
    unsigned char padding[0x111];
    unsigned char flag;
};

void BillboardGui::SetFlag(unsigned char value)
{
    if (flag != value)
    {
        flag = value;
        *(unsigned long*)0x00cd1cd4 = 0x00cd1cd4;
    }
}
