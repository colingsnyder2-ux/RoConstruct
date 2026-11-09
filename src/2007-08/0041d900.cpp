// from server: 54% by colin
struct CNameItem {
    int f(int);
};

extern "C" int __stdcall sub_652220(int);
extern "C" int __stdcall sub_62fef6(int);
extern "C" int __stdcall sub_65e750(int, int, int, int, int, int, int);
extern "C" int __stdcall sub_655f00(int, int);
extern "C" int __stdcall sub_65e930(int, int);
extern "C" int __stdcall sub_6607c0(int, int);

int CNameItem::f(int a) {
    int r = sub_652220(a);
    if (r == -1) {
        return 0;
    }
    int* p = (int*)this;
    int (*fn)(void*) = (int (*)(void*))((*(int**)p)[0x18c / 4]);
    int obj = fn(this);
    int* q = (int*)(obj + 0x200);
    *(int*)(*q + 0x88) = 1;
    *(int*)(*q + 0x7c) = 0;
    sub_6607c0(*q, 1);
    int mem = sub_62fef6(0xb4);
    int tmp;
    if (mem != 0) {
        tmp = sub_65e750(mem, 0, 0x787ed4, 0x12c, 1, -1, 1);
    } else {
        tmp = 0;
    }
    int res = sub_655f00(obj, tmp);
    sub_65e930(res, 1);
    *(int*)(res + 0xac) = 0;
    return 0;
}
