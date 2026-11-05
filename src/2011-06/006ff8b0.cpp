// from server: 96% by atomic.potato
struct BodyForce
{
    void __thiscall get(void *unused1, void *unused2, void *unused3, void *result);
};

void __thiscall BodyForce::get(void *unused1, void *unused2, void *unused3, void *result)
{
    float *out = (float *)result;
    float *base = (float *)((char *)this + 0x150);
    out[0] = base[0];
    out[1] = base[1];
    out[2] = base[2];
}
