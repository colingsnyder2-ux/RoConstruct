// from server: 58% by colin
struct VCApp_IObjectSafetyRobloxImpl
{
    int QueryInterfaceImpl(int* ppv, int* ppvObject, int* out);
};

extern "C" int __stdcall sub_409310(int);

int VCApp_IObjectSafetyRobloxImpl::QueryInterfaceImpl(int* ppv, int* ppvObject, int* out)
{
    int* self = this ? (int*)((char*)this - 0x14) : 0;
    if (ppv == 0 || ppvObject == 0)
        return (int)0x80004003;

    int hr = 0;
    int* punk = 0;
    int* vtbl = (int*)self[9];
    hr = ((int (__stdcall*)(int*, int*, int**))vtbl[0])(self + 9, ppv, &punk);
    if (hr < 0)
    {
        *ppv = 0;
        *ppvObject = 0;
        return hr;
    }

    int* pv = punk;
    ((void (__stdcall*)(int*))((int*)pv[0])[2])(pv);

    int result = sub_409310((int)this);
    *ppv = 1;
    if (result != 0)
    {
        *ppvObject = 0;
        return hr;
    }

    *ppvObject = *(int*)((char*)this + 4);
    return hr;
}
