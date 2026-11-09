// roc 2012-06 0074e450  unit: RBX::ContentProvider::UCachedContent::?$AsyncHttpCache  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0074e450
//
// 0074e450  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 0074e456  e955fcffff           jmp 0x74e0b0
// auto-matched from its assembly shape

struct P_func_0074e450 { void g(); };
struct S_func_0074e450 {
    char pad[156];
    P_func_0074e450* m_p;
    void f();
};
void S_func_0074e450::f()
{
    m_p->g();
}
