// from server: 100% by colin
struct VCApp_CComObject
{
    void sub_40A2B0(void*);
    void sub_40A560(void*);
    void Release(void* p);
};

void VCApp_CComObject::Release(void* p)
{
    if (p == 0)
    {
        sub_40A2B0(p);
    }
    else
    {
        sub_40A560(p);
    }
}
