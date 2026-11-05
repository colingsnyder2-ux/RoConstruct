// from server: 42% by atomic.potato
struct X_00669bd0 {
    char pad_0[8];
    int (__stdcall *f_8)(int, void*);
    int f_c;
    int run(int a, int b);
};

struct S_str {
    char pad_0[0x1c];
    int f_1c;
};

extern "C" {
    void __stdcall sub_9ea40c(void*, void*);
    void __stdcall sub_9ea400(void*);
    void __stdcall str_copy(void*, void*);
    void __stdcall str_dtor(void*);
}

int X_00669bd0::run(int a, int b) {
    char buf[0x24];
    *(int*)buf = 0;
    int* p = (int*)(a ? a - 0x1c : 0);
    int r;
    r = f_8(f_c + (int)p, buf);
    S_str* src = (S_str*)r;
    S_str* dst = (S_str*)b;
    str_copy(dst, src);
    dst->f_1c = src->f_1c;
    str_dtor(buf);
    return (int)dst;
}
