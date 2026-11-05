// from server: 49% by atomic.potato
struct S_func_0050c180 {
    void f();
};

void S_func_0050c180::f()
{
    int* p = (int*)((char*)this + 4);
    while (p) {
        int* q = (int*)((char*)p - 4);
        if (*p == (int)q) {
            break;
        }
        int* r = (int*)*p;
        *p = *(int*)((char*)r + 4);
        *(int*)((char*)r + 4) = (int)r;
        int* vt = (int*)*r;
        void (*fn)(int) = (void (*)(int))*(int*)vt;
        fn(1);
    }
    if (this) {
        int* vt = (int*)*(int*)this;
        void (*fn)(int) = (void (*)(int))*(int*)vt;
        fn(1);
    }
}
