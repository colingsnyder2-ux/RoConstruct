// from server: 64% by atomic.potato
extern "C" void G1_func_007ec080(void *, void *);

struct Climbing
{
    Climbing(void *, void *);
};

Climbing::Climbing(void *a, void *b)
{
    G1_func_007ec080(this, b);
    *(unsigned int *)this = 0x00abca90;
    *((unsigned int *)this + 1) = 0x00abca84;
}
