// roc 2012-06 008b0570  unit: RBX::GuiLayerCollector  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008b0570
//
// 008b0570  8b442404             mov eax, dword ptr [esp + 4]
// 008b0574  898134010000         mov dword ptr [ecx + 0x134], eax
// 008b057a  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_008b0570 {
    char pad0[308];
    int m_x;
    void f(int a1);
};
void S_func_008b0570::f(int a1)
{
    m_x = (int)a1;
}
