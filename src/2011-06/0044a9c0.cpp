// from server: 35% by atomic.potato
struct CXTPPropertyGridItemConstraints
{
    char pad[0xc0];
    void* m_pArray;
    CXTPPropertyGridItemConstraints* AddChildItem(CXTPPropertyGridItemConstraints* p);
};

struct CXTPPropertyGridItem
{
    char pad[0x120];
    int m_nCount;
    int m_nSome;
    CXTPPropertyGridItemConstraints* m_arr[6];

    void OnAddChildItem();
    CXTPPropertyGridItemConstraints* AddChildItem(CXTPPropertyGridItemConstraints* p);
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl func_44a6a0();

void CXTPPropertyGridItem::OnAddChildItem()
{
    if (this->m_arr[0] == 0)
    {
        func_44a6a0();
    }
}

CXTPPropertyGridItemConstraints* CXTPPropertyGridItem::AddChildItem(CXTPPropertyGridItemConstraints* p)
{
    return this->m_arr[0]->AddChildItem(p);
}

void FacesItem_ctor(CXTPPropertyGridItem* self)
{
    self->OnAddChildItem();
    int i = 0;
    CXTPPropertyGridItemConstraints** slot = self->m_arr;
    while (i < 6)
    {
        CXTPPropertyGridItemConstraints* obj = (CXTPPropertyGridItemConstraints*)operator_new(0x130);
        if (obj != 0)
        {
            obj = self->AddChildItem(obj);
        }
        else
        {
            obj = 0;
        }
        *slot = obj;
        i++;
        slot++;
    }
}
