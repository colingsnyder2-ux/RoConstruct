// from server: 54% by Intel
struct S {
    int f(int, int*, int*);
};

extern "C" int __stdcall sub_783b90();
extern "C" void __stdcall sub_67bc80(int*, int*);

int S::f(int arg0, int* arg4, int* arg8) {
    int v;
    if (arg0 < *(int*)((char*)this + 0x2C)) {
        int* arr = *(int**)((char*)this + 0x90);
        v = arr[arg0];
        *arg4 = v;
    } else {
        v = 0;
    }
    int eax = sub_783b90();
    *arg8 = eax;
    sub_67bc80(arg4, arg4 + 1);
    return v != 0;
}
