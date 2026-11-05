// from server: 19% by atomic.potato
struct S_func_007a2e60
{
    void f(void*, void*, float, float);
};

struct S_func_006d3040
{
    char pad[28];
    float a;
    float b;
    float f(void*);
};

void S_func_007a2e60::f(void*, void*, float, float)
{
}

float S_func_006d3040::f(void* p)
{
    S_func_007a2e60* q = (S_func_007a2e60*)((char*)this - 4);
    q->f(p, (char*)p + 12, *(float*)((char*)p + 24), *(float*)((char*)p + 28));
    return 0.0f;
}
