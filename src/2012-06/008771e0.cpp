// roc 2012-06 008771e0  unit: DummyJob  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008771e0
//
// 008771e0  8a8186000000         mov al, byte ptr [ecx + 0x86]
// 008771e6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008771e0 {
    char pad0[134];
    char m_x;
    char f();
};
char S_func_008771e0::f()
{
    return m_x;
}
