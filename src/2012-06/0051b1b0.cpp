// roc 2012-06 0051b1b0  unit: Ogre::istreamDataStream  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051b1b0
//
// 0051b1b0  8b81ec000000         mov eax, dword ptr [ecx + 0xec]
// 0051b1b6  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0051b1b0 {
    char pad0[236];
    int m_x;
    int f();
};
int S_func_0051b1b0::f()
{
    return m_x;
}
