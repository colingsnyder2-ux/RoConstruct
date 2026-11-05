// from server: 17% by atomic.potato
struct S
{
    int f();
};

struct PartChunk
{
    int value;
    void g();
};

void PartChunk::g()
{
}

int S::f()
{
    PartChunk *p = (PartChunk *)0x00b7dc20;
    p->g();
    return 0;
}
