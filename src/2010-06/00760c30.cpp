// from server: 55% by atomic.potato
extern "C" void __cdecl function_0078c3d0(void *);
extern "C" void function_00750ab0(void *, int);

struct SleepStage
{
    void f(int);
};

void SleepStage::f(int a1)
{
    function_0078c3d0(this);
    function_00750ab0((void *)a1, (int)this);
}
