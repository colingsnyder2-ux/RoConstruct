// from server: 98% by atomic.potato
struct Job {
    int field0;
    void sub_4EC9E0(int, int, int*);
    void sub_4F04F0(int*);
    void __cdecl f(int*);
};

void Job::f(int* p) {
    *p = 0;
    sub_4EC9E0(2, 1, p);
    int v = *p;
    if (v < 1 || v > 3) {
        sub_4F04F0(p);
    }
}
