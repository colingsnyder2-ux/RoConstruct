// from server: 81% by atomic.potato
struct FlatTool
{
    void f(void*);
};

extern "C" void sub_751480(void*);
extern "C" void sub_822d00(void*);
extern "C" void sub_7514b0(void*);

void FlatTool::f(void* arg)
{
    void* p = *(void**)arg;
    sub_751480(p);
    sub_822d00(arg);
    p = *(void**)arg;
    sub_7514b0(p);
}
