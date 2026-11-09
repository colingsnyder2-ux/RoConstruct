// from server: 81% by atomic.potato
struct Ogre_RbxMeshPartAdapter
{
    int* m_object;
    void f(int value);
};

void Ogre_RbxMeshPartAdapter::f(int value)
{
    int* old = m_object;
    m_object = (int*)value;
    if (old != 0)
        ((void (__thiscall *)(int*, int))(*(int**)old + 0x3c))(old, 1);
}
