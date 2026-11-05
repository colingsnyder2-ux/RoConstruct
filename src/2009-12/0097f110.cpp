// from server: 31% by atomic.potato
struct S
{
    void f();
};

typedef void (__thiscall *PartChunkFunction)(void *);

void S::f()
{
    ((PartChunkFunction)0x5ccc20)((void *)0xb7dcb0);
}
