// from server: 45% by atomic.potato
struct S_func_004cc450 {
    char pad0[2120];
    int m_x;
    int f();
};

int S_func_004cc450::f()
{
    return m_x;
}

struct Ogre_RbxSpatialHashedSceneNode {
    char pad0[0x60];
    void* m_scene;
    void f(void*, void*);
};

extern void sub_005cf450(void*, Ogre_RbxSpatialHashedSceneNode*, void*, void*);

void Ogre_RbxSpatialHashedSceneNode::f(void* a, void* b)
{
    S_func_004cc450* p = (S_func_004cc450*)m_scene;
    if (p->f())
        sub_005cf450((void*)p->f(), this, a, b);
}
