// from server: 62% by atomic.potato
extern "C" void __stdcall sub_411f60(const char*);

struct BoundFuncDesc
{
    double value;
    void f(double);
};

void BoundFuncDesc::f(double x)
{
    if (!(x < *(double*)((char*)this + 0x240)))
    {
        *(double*)((char*)this + 0x240) = x;
        sub_411f60("\\$ ;");
    }
}
