// from server: 31% by atomic.potato
struct S {
    char pad[4];
    void f(const void* src);
};

extern "C" {
    void __stdcall sub_9ea40c(void*, const void*);
    void __stdcall sub_9ea468(void*, void*);
    void __stdcall sub_9ea400(void*);
}

void S::f(const void* src)
{
    char buf[28];
    sub_9ea40c(buf, src);
    sub_9ea468(this, buf);
    sub_9ea400(buf);
}
