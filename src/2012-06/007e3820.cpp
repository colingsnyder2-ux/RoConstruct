// roc 2012-06 007e3820  unit: RBX::LuaWebService::UCachedRawLuaWebServiceInfo::?$AsyncHttpCache  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e3820
//
// 007e3820  8b4940               mov ecx, dword ptr [ecx + 0x40]
// 007e3823  e9189d1300           jmp 0x91d540
// auto-matched from its assembly shape

struct P_func_007e3820 { void g(); };
struct S_func_007e3820 {
    char pad[64];
    P_func_007e3820* m_p;
    void f();
};
void S_func_007e3820::f()
{
    m_p->g();
}
