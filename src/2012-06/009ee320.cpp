// from server: 67% by atomic.potato
extern "C" void __stdcall imported_call(void *, int, int);

struct CXTAuxData
{
    int f(int);
};

int CXTAuxData::f(int value)
{
    imported_call((char *)this + 0xb4, 0, value);
    return value;
}
