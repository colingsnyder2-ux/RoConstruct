// roc 2012-06 0055a190  unit: RBX::VNetworkSettings::?$GlobalAdvancedSettingsItem  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0055a190
//
// 0055a190  c6416100             mov byte ptr [ecx + 0x61], 0
// 0055a194  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0055a190 {
    char pad0[97];
    char m_x;
    void f();
};
void S_func_0055a190::f()
{
    m_x = (char)0;
}
