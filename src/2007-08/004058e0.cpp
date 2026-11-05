// from server: 52% by colin
struct VCWorkspace_CComObject
{
    int method(int* p1, int* p2, int* p3, int* p4);
};

extern "C" int __stdcall sub_4046c0(int);

int VCWorkspace_CComObject::method(int* p1, int* p2, int* p3, int* p4)
{
    int* self = (int*)this;
    int* obj;
    if (self != 0)
        obj = (int*)((char*)self - 0x18);
    else
        obj = 0;

    if (p1 != 0 || p2 == 0)
        return (int)0x80004003;

    int* vtable = (int*)*obj;
    int* local;
    int (__stdcall *fn)(int*, int*, int**) = (int (__stdcall *)(int*, int*, int**))vtable[0];
    int hr = fn(obj, p2, &local);
    if (hr < 0)
    {
        *p1 = 0;
        *p2 = 0;
        return hr;
    }

    int* localVtable = (int*)*local;
    void (__stdcall *release)(int*) = (void (__stdcall *)(int*))localVtable[2];
    release(local);

    int result = sub_4046c0((int)self);
    *p1 = 1;
    if (result != 0)
    {
        *p2 = 0;
        return hr;
    }

    *p2 = self[1];
    return hr;
}
