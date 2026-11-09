// from server: 65% by atomic.potato
struct CRenderSettingsItem
{
    int value;
    void SetValue(int);
};

void CRenderSettingsItem::SetValue(int value)
{
    if (value != *(int *)((char *)this + 0xac))
    {
        *(int *)((char *)this + 0xac) = value;
        *(int *)((char *)this + 0xe199b4) = value;
    }
}
