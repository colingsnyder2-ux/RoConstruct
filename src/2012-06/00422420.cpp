// from server: 82% by atomic.potato
struct S_func_00422420 {
    int f(int* p);
};

int S_func_00422420::f(int* p)
{
    int* q = *(int**)((char*)p - 8);
    int* vtable = *(int**)q;
    int (__stdcall* fn)(int*) = *(int (__stdcall**)(int*))vtable;
    return fn(q);
}
