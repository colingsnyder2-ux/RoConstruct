// from server: 56% by atomic.potato
extern "C" bool __stdcall sub_745190(int, float*);

struct Inner {
    virtual int f(int, float*);
};

struct S {
    char pad[0x28];
    Inner* p;
    bool method(int, float*);
};

bool S::method(int a, float* b)
{
    float v[3] = {0.0f, 0.0f, 0.0f};
    if (sub_745190(a, v)) {
        p->f(a, v);
        return true;
    }
    return false;
}
