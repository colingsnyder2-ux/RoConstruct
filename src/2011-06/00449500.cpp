// from server: 92% by atomic.potato
struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, void*);
    virtual void f3(void*, void*);
};

struct Mid {
    char pad[0x1c];
    Inner* inner;
};

struct Vector3ComponentItem {
    char pad[0x124];
    Mid* mid;
    int idx;
    void method(void* a, void* b);
};

void Vector3ComponentItem::method(void* a, void* b)
{
    float tmp[3];
    void* p = a ? (char*)a + 0x1c : 0;
    mid->inner->f2(p, tmp);
    float v = *(float*)((char*)b + idx * 4);
    tmp[idx] = v;
    void* q = a ? (char*)a + 0x1c : 0;
    mid->inner->f3(q, tmp);
}
