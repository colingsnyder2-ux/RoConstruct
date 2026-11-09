// from server: 39% by atomic.potato
struct Inner {
    virtual void* f(int, int*);
};

struct Outer {
    char pad[0x28];
    Inner* inner;
    void func(int, int*);
};

void Outer::func(int a, int* b) {
    Inner* p = inner;
    int* v = 0;
    void* r = p->f(a, (int*)&v);
    *v = (int)r;
    v = v + 1;
    (*(void(__stdcall**)(int*))0x575c50)(v);
}
