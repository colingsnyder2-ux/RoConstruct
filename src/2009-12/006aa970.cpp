// from server: 68% by atomic.potato
struct S
{
    void f();
};

void call_00664370(void *);

void S::f()
{
    call_00664370((char *)this + 0x100);
    call_00664370((char *)this + 0x108);
}
