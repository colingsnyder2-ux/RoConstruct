// from server: 31% by atomic.potato
extern "C" void __stdcall sub_91d250(float);
extern "C" void __stdcall sub_91fe20();

struct seg_00920000
{
    void f();
};

void seg_00920000::f()
{
    sub_91d250(0.0f);
    sub_91fe20();
}
