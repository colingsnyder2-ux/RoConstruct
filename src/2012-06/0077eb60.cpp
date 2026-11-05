// from server: 73% by atomic.potato
extern "C" void* sub_769ad0(void*, void*);
extern "C" void sub_76a190(void*, void*);

struct EnumDesc
{
    void f(void*);
};

void EnumDesc::f(void* value)
{
    void* p = (char*)value + 4;
    void* q = sub_769ad0(this, p);
    void* v = *(void**)q;
    sub_76a190(this, &v);
}
