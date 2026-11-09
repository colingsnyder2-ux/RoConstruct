// from server: 69% by atomic.potato
extern "C" void updateValue(void *, int);

struct CRenderSettingsItem
{
    char padding[216];
    int value;
    void setValue(int);
};

void CRenderSettingsItem::setValue(int v)
{
    if (value != v)
    {
        value = v;
        updateValue((char *)this + 0x144, 0xe19b8c);
    }
}
