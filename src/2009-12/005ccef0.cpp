// from server: 66% by atomic.potato
extern "C" void __cdecl sub_007f49a4(void *, int, int, void *);

struct PartChunk
{
    void f();
    void g();
};

void PartChunk::f()
{
    sub_007f49a4(this, 4, 4, (void *)0x004e4d20);
}

void PartChunk::g()
{
    sub_007f49a4(this, 4, 1, (void *)0x004e4d20);
}
