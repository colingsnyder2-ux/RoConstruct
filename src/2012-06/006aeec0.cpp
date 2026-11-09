// from server: 31% by atomic.potato
extern "C" void __cdecl sub_562210(void*);

struct S
{
    void* f();
};

void* S::f()
{
    void* result = this;
    sub_562210(result);
    return result;
}
