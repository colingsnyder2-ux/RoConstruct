// from server: 39% by colin
struct S {
    int f(int, int);
};

extern "C" int __stdcall sub_401150(int);
extern "C" int __stdcall sub_403e40(int, int, int, int);
extern "C" int __stdcall sub_630a1e(int, int);

int S::f(int a, int b) {
    int result = -2147024882;
    int* p = (int*)0x8baf48;
    if (*p != 0) {
        int* src = (int*)0;
        int* dst = (int*)0;
        while (*src != -1) {
            if (*src == -2) {
                src = (int*)src[1];
                int (*fn)(int) = (int (*)(int))src;
                src = (int*)fn(0);
                dst = (int*)0;
            } else {
                *dst = *src + b;
                dst++;
                src++;
            }
        }
    }
    int r = sub_403e40(0, 0, b, 3);
    if (r < 0) {
        sub_401150(0);
        return r;
    }
    int r2 = sub_630a1e(0, 0);
    if (r2 < 0) {
        sub_401150(0);
    }
    return r2;
}
