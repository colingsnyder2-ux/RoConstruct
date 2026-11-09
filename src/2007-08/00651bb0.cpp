// from server: 28% by colin
struct CComVariant {
    int vt;
    int pad[7];
    CComVariant() : vt(0) {}
    ~CComVariant();
};

struct CComSafeArray {
    int pad[4];
    CComSafeArray() { pad[0]=0; pad[1]=0; pad[2]=0; pad[3]=0; }
    ~CComSafeArray();
};

struct CComGITPtr {
    void* p;
    CComGITPtr() : p(0) {}
    ~CComGITPtr();
};

struct CComCritSecLock {
    int pad[4];
    CComCritSecLock() { pad[0]=0; pad[1]=0; pad[2]=0; pad[3]=0; }
    ~CComCritSecLock();
};

struct CComObject {
    void* vtable;
    int pad[13];
    int field_38;
};

extern "C" void* __stdcall sub_62FC6E();
extern "C" void* __stdcall sub_63052C();
extern "C" void __stdcall sub_738424();
extern "C" void __stdcall sub_738436();

struct CXTPToolBar {
    void* CreateObject(int a, int b, int c, int d, int e, int f, int g);
};

void* CXTPToolBar::CreateObject(int a, int b, int c, int d, int e, int f, int g)
{
    CComVariant var1;
    CComSafeArray sa;
    CComGITPtr git;
    CComCritSecLock lock;
    CComObject* obj;
    void* result;
    int* p;

    if (g == 0)
        g = a;

    if (e == 0)
    {
        var1.vt = 0;
        var1.pad[0] = 0;
        var1.pad[1] = 0;
        var1.pad[2] = 0;
        var1.pad[3] = 0;
        var1.pad[4] = 0;
        var1.pad[5] = 0;
        var1.pad[6] = 0;
        var1.pad[7] = 0;
        var1.vt = c;
        var1.pad[0] = b;
        if (b != 0)
            var1.pad[1] = *(int*)(b + 0x28);
        p = &var1.vt;
    }
    else
    {
        p = (int*)e;
    }

    sub_738436();
    obj = (CComObject*)sub_63052C();
    if (obj == 0)
        sub_62FC6E();

    sub_738424();

    result = 0;
    if (obj->vtable != 0)
    {
        typedef int (__stdcall *PFN)(void*, int, int, int, int*, int, int, int);
        PFN fn = *(PFN*)((char*)obj->vtable + 0x5c);
        int hr = fn(obj, 0, 0, d, p, f, g, 0);
        if (hr != 0)
        {
            if (g != 0)
                obj->field_38 = *(int*)(g + 0x20);
            result = obj;
        }
    }

    return result;
}
