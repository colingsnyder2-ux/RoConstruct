// from server: 68% by atomic.potato
struct CRobloxControlMaterialSelector
{
    void SetMaterial(void* material);
};

void CRobloxControlMaterialSelector::SetMaterial(void* material)
{
    if (material == 0)
        *(int*)((char*)this + 0x17c) = -1;
}
