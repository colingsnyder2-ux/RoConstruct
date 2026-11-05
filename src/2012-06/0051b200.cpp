// roc 2012-06 0051b200  unit: Ogre::istreamDataStream  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051b200
//
// 0051b200  8b8170010000         mov eax, dword ptr [ecx + 0x170]
// 0051b206  c3                   ret 
// auto-matched from its assembly shape

struct S_func_0051b200 {
    char pad0[368];
    int m_x;
    int f();
};
int S_func_0051b200::f()
{
    return m_x;
}
