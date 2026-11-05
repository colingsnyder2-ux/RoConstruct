// from server: 23% by atomic.potato
struct S {
    char pad[0xc];
    void *field_c;
    void invoke(void *arg);
};

void S::invoke(void *arg) {
    void *p = (char *)this + 0xc;
    void *a = &arg;
    char flag = 0;
    void *fn = *(void **)((char *)p + 4);
    void *obj = *(void **)p;
    ((void (__stdcall *)(void *, void *))fn)(obj, a);
}
