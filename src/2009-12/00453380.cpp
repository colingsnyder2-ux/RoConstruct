// from server: 66% by atomic.potato
struct CRobloxControlMaterialSelector
{
    void SetMaterial(void* material);
};

void CRobloxControlMaterialSelector::SetMaterial(void* material)
{
    *(void**)((char*)this + 0x188) = material;
}
