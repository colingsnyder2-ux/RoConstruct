// from server: 55% by colin
struct Descriptor {
    char pad[0x28];
    int offset28;
    int offset2c;
};

struct FuncDesc {
    char pad[0x2c];
    int offset2c;
    int offset28;
};

struct Holder {
    int field0;
    int field4;
    int field8;
};

extern "C" int __stdcall sub_630d36(int a, int b, int c, int d, int e);
extern "C" int __stdcall sub_630b9e(int a, int b);
extern "C" int __stdcall sub_56d7d0();
extern "C" int __stdcall sub_62fef6(int a);
extern "C" void* __stdcall sub_77e710(int a);

struct VServerBoundFuncDesc {
    int method(int a, Holder* h);
};

int VServerBoundFuncDesc::method(int a, Holder* h)
{
    int r = sub_630d36(a, 0, 0x8904bc, 0x88209c, 0);
    if (r == 0) {
        void* p = sub_77e710(0x786e04);
        sub_630b9e((int)p, 0x841e0c);
    }
    int ecx = *(int*)((char*)this + 0x2c);
    int edx = *(int*)((char*)this + 0x28);
    int arg = *(int*)((char*)h + 0x1c);
    ecx += r;
    int (*fn)(int, int) = (int (*)(int, int))edx;
    int res = fn(ecx, arg);
    int v = sub_56d7d0();
    h->field4 = v;
    int* obj = (int*)sub_62fef6(8);
    if (obj != 0) {
        obj[0] = 0x787198;
        obj[1] = res;
    } else {
        obj = 0;
    }
    int old = h->field8;
    h->field8 = (int)obj;
    if (old != 0) {
        int* vt = *(int**)old;
        int (*f)(int, int) = (int (*)(int, int))vt[0];
        f(old, 1);
    }
    return 0;
}
