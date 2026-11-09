// from server: 82% by atomic.potato
struct RbxParticleEmitter
{
};

extern void G1_func_007f8e90(void *, void *);

void __cdecl f(void **begin, void **end, void *value)
{
    while (begin != end)
    {
        G1_func_007f8e90(*begin, value);
        ++begin;
    }
}
