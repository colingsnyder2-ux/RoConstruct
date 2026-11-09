// from server: 22% by atomic.potato
struct S {
    void f(int*, int*, int*);
};

extern "C" void __stdcall sub_5eb040(int*, int*, int*);

void S::f(int* a, int* b, int* c) {
    int* first = a;
    int* last = b;
    int n = (int)(last - first);
    if (n > 0x28) {
        int m = (n + 1) / 8;
        int* p = first + m * 8;
        int* q = first + m * 4;
        int* tmp[3];
        tmp[0] = c;
        tmp[1] = a;
        tmp[2] = b;
        sub_5eb040(first, q, p);
        tmp[0] = c;
        tmp[1] = a;
        tmp[2] = b;
        sub_5eb040(q, first, p);
        tmp[0] = c;
        tmp[1] = a;
        tmp[2] = b;
        sub_5eb040(p, q, first);
        tmp[0] = c;
        tmp[1] = a;
        tmp[2] = b;
        sub_5eb040(first, q, p);
    } else {
        int* tmp[3];
        tmp[0] = c;
        tmp[1] = a;
        tmp[2] = b;
        sub_5eb040(first, last, c);
    }
}
