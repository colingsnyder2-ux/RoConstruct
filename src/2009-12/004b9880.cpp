// from server: 69% by atomic.potato
extern "C" int __stdcall Call4598(void *, int, float);

struct S
{
    int f(int);
};

int S::f(int a)
{
    float v = *(float *)((char *)this + 0x290);
    int x = *(int *)((char *)this + 0x1e4);
    int y = *(int *)((char *)this + 0x294);
    return Call4598((char *)x + 0x4598, y, v);
}
