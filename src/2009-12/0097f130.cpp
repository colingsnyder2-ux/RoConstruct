// from server: 37% by atomic.potato
struct PartChunk
{
    void f();
};

void PartChunk::f()
{
}

extern "C" void sub_005ccc20(PartChunk *);

void function_0097f130()
{
    PartChunk *p = (PartChunk *)0x00b7dc90;
    sub_005ccc20(p);
}
