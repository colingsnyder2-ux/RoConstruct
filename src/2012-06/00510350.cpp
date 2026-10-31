// from server: 85% by Intel
struct IUnknown
{
    virtual void QueryInterface() = 0;
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

struct ISpatialHashNode : IUnknown
{
    virtual void Method1(void*) = 0;
    virtual void Method2(void*) = 0;
    virtual void Method3(void*) = 0;
};

struct OgreRbxSpatialHashedSceneNode
{
    char pad[0x60];
    ISpatialHashNode* m_pNode;

    void __thiscall Function510350(void* a1);
};

void __thiscall OgreRbxSpatialHashedSceneNode::Function510350(void* a1)
{
    if (*(int*)a1)
    {
        if (m_pNode)
        {
            m_pNode->Method1(*(void**)((char*)a1 + 4));
            m_pNode->Method2(*(void**)((char*)a1 + 8));
            m_pNode->Method3(*(void**)a1);
        }
        *(int*)a1 = 0;
        *(int*)((char*)a1 + 4) = 0;
        *(int*)((char*)a1 + 8) = 0;
        *(int*)((char*)a1 + 0xC) = 0;
        *(int*)((char*)a1 + 0x10) = 0;
    }
}
