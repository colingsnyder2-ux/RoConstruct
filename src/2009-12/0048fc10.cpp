// from server: 91% by atomic.potato
struct RenderOperation
{
};

struct SubMesh
{
    void __thiscall getRenderOperation(RenderOperation& operation, unsigned short lod);
};

struct RbxSubEntity_0048fc10
{
    char pad0[100];
    SubMesh* m_subMesh;
    char pad1[252];
    int m_index;

    void f(RenderOperation& operation);
};

void RbxSubEntity_0048fc10::f(RenderOperation& operation)
{
    if (m_index == 0)
        m_subMesh->getRenderOperation(operation, 0);
    else
        ((SubMesh**)((char*)this + 0x15c))[m_index]->getRenderOperation(operation, 0);
}
