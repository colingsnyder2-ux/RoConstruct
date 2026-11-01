// from server: 100% by colin
struct VCContent_CComAggObject
{
    void* QueryInterface(void* p);
    void* AddRef();
};

void* __stdcall sub_004125C0(void* p);
void* __stdcall sub_00412880(void* p);

void* VCContent_CComAggObject::QueryInterface(void* p)
{
    if (p == 0)
    {
        return sub_004125C0(p);
    }
    return sub_00412880(p);
}
