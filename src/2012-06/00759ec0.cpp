// from server: 62% by atomic.potato
extern "C" void __stdcall sub_759de0(void*, double, const char*);

struct EventDesc
{
    void f(int*);
};

void EventDesc::f(int* value)
{
    sub_759de0(this, static_cast<double>(*value), "Content-Length");
}
