// from server: 74% by atomic.potato
struct EventDesc
{
};

void __cdecl fire(void *p, float a, float b)
{
    struct Data
    {
        int pad0;
        int pad1;
        void (*vtable)(Data *, float, float);
        int enabled;
    };

    Data *q = (Data *)p;
    if (*(int *)((char *)q + 16) != 0)
        q->vtable((Data *)((char *)q + 8), a, b);
}
