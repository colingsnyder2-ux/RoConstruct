// from server: 42% by atomic.potato
struct S
{
    void f();
};

extern "C" double* __cdecl sub_416030(double);
extern "C" void __cdecl sub_532f90(void*, double);

void S::f()
{
    double value = *sub_416030(*(double*)((char*)this + 4));
    sub_532f90(*(void**)((char*)this + 12), value);
}
