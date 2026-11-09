// from server: 100% by sophus
struct Desc {
    void set(int);
};

struct S {
    int pad;
    Desc desc;
    void* connect(void** out, const void* src);
    void* invoke(void** out, const void* src);
};

void* S::invoke(void** out, const void* src)
{
    volatile int c = 0;
    desc.set(1);
    connect(out, src);
    return out;
}
