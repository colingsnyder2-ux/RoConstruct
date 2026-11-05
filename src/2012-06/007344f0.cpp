// from server: 68% by atomic.potato
extern "C" void __cdecl G1_func_00983270(void *, unsigned int, void *, void *, void *);
extern "C" void __cdecl G1_func_009823ba(void *);

extern void *G1_data_0070c7c0;

struct Frame
{
    void *value;

    void f();
};

void Frame::f()
{
    void *p = value;
    if (p)
    {
        void *q = (char *)p - 4;
        G1_func_00983270(p, 132, *(void **)((char *)p - 4), G1_data_0070c7c0, q);
        G1_func_009823ba(q);
    }
}
