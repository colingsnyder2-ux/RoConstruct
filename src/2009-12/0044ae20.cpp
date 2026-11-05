// from server: 85% by atomic.potato
struct VCRenderSettingsItem;

extern "C" void sub_44ab90(VCRenderSettingsItem *, int);
extern "C" void sub_40c080(VCRenderSettingsItem *, const char *);

struct VCRenderSettingsItem
{
    int value;
    int pad[55];
    int current;
    int selected;
    void f(int);
};

void VCRenderSettingsItem::f(int value)
{
    if (value != current)
    {
        selected = value;
        sub_44ab90(this, 0);
        sub_40c080(this, "(SVW");
    }
}
