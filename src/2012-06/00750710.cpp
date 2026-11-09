// roc 2012-06 00750710  unit: RBX::ContentProvider::UCachedContent::?$AsyncHttpCache  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00750710
//
// 00750710  8a81b0010000         mov al, byte ptr [ecx + 0x1b0]
// 00750716  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00750710 {
    char pad0[432];
    char m_x;
    char f();
};
char S_func_00750710::f()
{
    return m_x;
}
