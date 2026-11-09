// roc 2012-06 008f5190  unit: RBX::HandlesBase  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008f5190
//
// 008f5190  8a8180000000         mov al, byte ptr [ecx + 0x80]
// 008f5196  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008f5190 {
    char pad0[128];
    char m_x;
    char f();
};
char S_func_008f5190::f()
{
    return m_x;
}
