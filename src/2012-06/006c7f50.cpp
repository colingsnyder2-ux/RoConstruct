// from server: 44% by atomic.potato
struct GlobalAdvancedSettings
{
    GlobalAdvancedSettings();
};

extern "C" void __cdecl RegisterGlobalObject(int, int, int, int);
extern "C" void __cdecl InitializeGlobalAdvancedSettings();

GlobalAdvancedSettings::GlobalAdvancedSettings()
{
    RegisterGlobalObject(0, 0x00e2e700, 0x006c7eb0, 0);
    InitializeGlobalAdvancedSettings();
}
