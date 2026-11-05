// from server: 100% by intel
extern "C" void __declspec(nothrow) __stdcall GlobalAdvancedSettingsItemChanged(int);

struct GlobalAdvancedSettingsItem
{
    char padding[176];
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
