// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 0072fd40  unit: RBX::VGameSettings::?$GlobalAdvancedSettingsItem  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0072fd40
//
// 0072fd40  8b442404             mov eax, dword ptr [esp + 4]
// 0072fd44  3981ac000000         cmp dword ptr [ecx + 0xac], eax
// 0072fd4a  7413                 je 0x72fd5f
// 0072fd4c  8981ac000000         mov dword ptr [ecx + 0xac], eax
// 0072fd52  c74424044032e300     mov dword ptr [esp + 4], 0xe33240
// 0072fd5a  e94150ceff           jmp 0x414da0
// 0072fd5f  c20400               ret 4

extern "C" void __declspec(nothrow) __stdcall GlobalAdvancedSettingsItemChanged(int);

struct GlobalAdvancedSettingsItem
{
    char padding[128];
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
