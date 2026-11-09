// roc 2012-06 00573e40  unit: AsyncResult  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00573e40
//
// 00573e40  8b81c81a0000         mov eax, dword ptr [ecx + 0x1ac8]
// 00573e46  c3                   ret 
// auto-matched from its assembly shape

struct S_func_00573e40 {
    char pad0[6856];
    int m_x;
    int f();
};
int S_func_00573e40::f()
{
    return m_x;
}
