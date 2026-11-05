// from server: 73% by atomic.potato
struct S
{
    void f(void*);
};

extern "C" void* sub_76bca0(void*, void*);
extern "C" void sub_76a190(void*, void*);

void S::f(void* p)
{
    void* v = sub_76bca0(this, (char*)p + 4);
    void* x = *(void**)v;
    sub_76a190(this, &x);
}
