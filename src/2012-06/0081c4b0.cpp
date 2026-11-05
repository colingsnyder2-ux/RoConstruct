// roc 2012-06 0081c4b0  unit: RBX::Reflection::UTuple::$$A6A?AV?$shared_ptr::V?$function::?$sp_counted_impl_p  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0081c4b0
//
// 0081c4b0  8b89ac000000         mov ecx, dword ptr [ecx + 0xac]
// 0081c4b6  e9555b1000           jmp 0x922010
// auto-matched from its assembly shape

struct P_func_0081c4b0 { void g(); };
struct S_func_0081c4b0 {
    char pad[172];
    P_func_0081c4b0* m_p;
    void f();
};
void S_func_0081c4b0::f()
{
    m_p->g();
}
