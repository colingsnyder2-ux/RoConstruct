// from server: 29% by atomic.potato
extern "C" void* __cdecl sub_98211a(unsigned int size);

struct Inner {
    void init();
};

struct VWorkspace {
    void func(void* arg);
};

void Inner::init()
{
    sub_98211a(0);
}

void VWorkspace::func(void* arg)
{
    void* p = sub_98211a(0xa8);
    void* q = 0;
    if (p) {
        ((Inner*)p)->init();
        q = p;
    }
    ((VWorkspace*)this)->func(arg);
}
