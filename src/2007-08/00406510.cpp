// from server: 42% by colin
// roc 2007-08 00406510  unit: VCWorkspace::?$CComObject  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00406510

extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" char __cdecl sub_402AC0(int);
extern "C" void* __cdecl sub_630B60();

struct CComObjectBase {
    virtual void vf0();
    virtual void vf1();
};

struct CComObject : CComObjectBase {
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
    int f5;
};

extern CComObjectBase* g_8bae44;
extern int g_8bae58;
extern int g_8bae5c;
extern int g_8bae60;
extern int g_8b5188;

int __stdcall sub_406510(int* out);

int __stdcall sub_406510(int* out)
{
    CComObject* obj;
    int result;

    if (out == 0) {
        return (int)0x80004003;
    }

    *out = 0;

    obj = (CComObject*)sub_62FEF6(0x1c);
    if (obj != 0) {
        obj->f0 = 0;
        obj->f1 = 0;
        obj->f2 = 0;
        obj->f3 = 0;
        obj->f4 = 0;
        obj->f5 = 0;
        *(int*)obj = 0x784fa8;
        g_8bae44->vf1();
    } else {
        obj = 0;
    }

    if (obj == 0) {
        return (int)0x80004005;
    }

    if ((g_8bae60 & 1) == 0) {
        g_8bae60 |= 1;
        g_8bae58 = 4;
        g_8bae5c = -1;
    }

    if (sub_402AC0(4)) {
        sub_630B60();
    }

    return 0;
}
