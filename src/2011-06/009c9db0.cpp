// from server: 25% by atomic.potato
struct S {
    char pad[0xc];
    void *field_c;
    void invoke(int arg);
};

void S::invoke(int arg) {
    void *p = this->field_c;
    void *fn = *(void **)((char *)p + 4);
    void *obj = *(void **)p;
    ((void (__stdcall *)(int, void *))fn)(arg, obj);
}
