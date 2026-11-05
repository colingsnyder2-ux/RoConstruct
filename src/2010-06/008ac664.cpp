// from server: 45% by atomic.potato
extern "C" void __stdcall sub_008af41a(int);

extern "C" void __stdcall call_00bec120(int, int, int, int, float);

void __stdcall func_008ac664(float a, int b, int c, int d, int e)
{
    sub_008af41a(1);
    call_00bec120(b, e, d, c, a);
}
