// from server: 96% by atomic.potato
struct S
{
    int f(float* out);
};

int S::f(float* out)
{
    out[0] = *(float*)((char*)this + 0x20);
    out[1] = *(float*)((char*)this + 0x24);
    out[2] = *(float*)((char*)this + 0x28);
    return 0;
}
