// roc 2012-06 0051b180  unit: Ogre::istreamDataStream  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051b180
//
// 0051b180  8b8148010000         mov eax, dword ptr [ecx + 0x148]
// 0051b186  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0051b180 {
    char pad0[328];
    int m_x;
    int f();
};
int S_func_0051b180::f()
{
    return m_x;
}
