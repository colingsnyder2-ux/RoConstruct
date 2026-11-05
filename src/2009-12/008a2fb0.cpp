// from server: 81% by atomic.potato
struct S_func_008a2fb0
{
    int* p0;
    int* p1;
    int* p2;
    int* p3;
    int* p4;
    int* p5;
    int* p6;
    int f(void*);
};

extern "C" void __stdcall func_0086ac70(int*, int*, void*);

int S_func_008a2fb0::f(void* p)
{
    int* v = p6;
    func_0086ac70((int*)((char*)this + 0x20), v, p);
    return (int)v;
}
