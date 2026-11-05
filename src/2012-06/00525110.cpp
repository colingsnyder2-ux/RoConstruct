// from server: 79% by atomic.potato
extern "C" void* sub_523530(void*);
extern "C" void sub_76a190(void*, void*);

struct S
{
    void f(void*);
};

void S::f(void* p)
{
    void* value = sub_523530((char*)p + 4);
    void* local = *(void**)value;
    sub_76a190(this, &local);
}
