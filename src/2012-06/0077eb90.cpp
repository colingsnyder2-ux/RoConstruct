// from server: 65% by atomic.potato
struct S
{
    void* f(void*);
    void g(void*);
};

extern "C" void* call_7a0cf0(void*, void*);
extern "C" void call_76a190(void*, void*);

void S::g(void* p)
{
    void* v = call_7a0cf0(this, (char*)p + 4);
    call_76a190(this, &v);
}
