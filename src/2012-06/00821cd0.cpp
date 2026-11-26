// from server: 100% by Xemicl
// from server: 100% by atomic.potato

extern "C" void __declspec(nothrow) __stdcall GlobalAdvancedSettingsItemChanged(int);

struct GlobalAdvancedSettingsItem
{
    char padding[144];
    int value;
    void set(int);
};

void GlobalAdvancedSettingsItem::set(int value)
{
    if (this->value != value)
    {
        this->value = value;
        GlobalAdvancedSettingsItemChanged(0xe33240);
    }
}
