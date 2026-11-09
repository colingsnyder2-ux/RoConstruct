// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void target();

void S::f()
{
    *(int *)this = 0xbb0c5c;
    *((int *)this + 1) = 0xbb0c50;
    *((int *)this + 6) = 0xbb0c44;
    *((int *)this + 7) = 0xbb0c38;
    target();
}
