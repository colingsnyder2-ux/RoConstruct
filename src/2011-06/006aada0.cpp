// from server: 64% by atomic.potato
extern "C" int helper_006aa460(int, void*);

struct S
{
    int f(void*, void*);
};

int S::f(void* a, void* b)
{
    void* p = *(void**)((char*)this + 0x1c);
    int* q = *(int**)p + 3;
    int v = helper_006aa460(*(int*)((char*)b + 0), (char*)&v);
    return ((int (__thiscall *)(void*, void*, int))q[0])(p, b, v);
}
