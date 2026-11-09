// from server: 44% by tester
extern "C" int __stdcall sub_4022A0(int, int, int, int);
extern "C" int __stdcall sub_404400(int, int, int, int, int);
extern "C" int __stdcall sub_406120(int, int);

struct S {
    int f(int, int);
};

int S::f(int a, int b) {
    int result = -2147467261;
    int sp18 = 0;
    int sp14 = 0;
    int sp2c = 0;
    int sp24 = 0;
    int sp30 = 0;
    int flag = 0;
    int* p = (int*)a;
    if (p == 0) {
        return result;
    }
    *p = 0;
    result = sub_406120((int)&sp18, (int)p);
    if (result < 0) {
        return result;
    }
    int* obj = (int*)b;
    if ((*(unsigned char*)((char*)obj + 0x14) & 2) != 0) {
        int* vtbl = (int*)*obj;
        int (*fn)(int) = (int (*)(int))vtbl[1];
        sp30 = b;
        fn(b);
        sp24 = 0;
        flag = 1;
        sp2c = (int)&sp30;
        sp14 = flag;
    } else {
        sp2c = (int)((char*)obj + 4);
    }
    int v1 = *(int*)sp2c;
    int v2 = *(int*)((char*)obj + 8);
    int v3 = sp18;
    int v4 = *(int*)((char*)obj + 0xc);
    result = sub_404400(v3, v2, v4, v1, 0);
    int ret = result;
    sp24 = -1;
    if ((flag & 1) != 0) {
        int* q = (int*)sp30;
        if (q != 0) {
            int* vtbl2 = (int*)*q;
            int (*fn2)(int) = (int (*)(int))vtbl2[2];
            fn2((int)q);
        }
    }
    if (ret < 0) {
        if (v3 != 0) {
            int* vtbl3 = (int*)*(int*)v3;
            int (*fn3)(int, int) = (int (*)(int, int))vtbl3[7];
            fn3(v3, 1);
        }
        return ret;
    }
    int v5 = sp30;
    int v6 = *(int*)((char*)obj + 0x10);
    *(int*)(v3 + 0x10) = v6;
    ret = sub_4022A0(v3, 0x784e28, 0x784e40, v5);
    if (ret < 0) {
        if (v3 != 0) {
            int* vtbl4 = (int*)*(int*)v3;
            int (*fn4)(int, int) = (int (*)(int, int))vtbl4[7];
            fn4(v3, 1);
        }
    }
    return ret;
}
