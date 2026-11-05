// from server: 78% by atomic.potato
struct PartChunk
{
    void f();
};

void PartChunk::f()
{
}

extern "C" void G1_func_0052f6f0(PartChunk*);

PartChunk* __stdcall func_0052f7c0(PartChunk* p)
{
    G1_func_0052f6f0(p);
    return p;
}
