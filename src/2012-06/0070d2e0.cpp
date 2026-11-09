// from server: 73% by atomic.potato
extern "C" void* sub_70cf90(void*, const void*);
extern "C" void sub_76a190(void*, const void*);

struct S
{
    void f(const void*);
};

void S::f(const void* value)
{
    void* p = sub_70cf90(this, (const char*)value + 4);
    const void* q = *(const void**)p;
    sub_76a190(this, &q);
}
