// from server: 79% by atomic.potato
struct S
{
    void f(void*);
};

extern "C" void* sub_76ca30(void*);
extern "C" void sub_76a190(void*, void*);

void S::f(void* p)
{
    void* v = sub_76ca30((char*)p + 4);
    void* x = *(void**)v;
    sub_76a190(this, &x);
}
