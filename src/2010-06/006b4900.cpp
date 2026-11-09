// from server: 96% by atomic.potato
struct BodyForce
{
    void get(void*, void*, void*, void*);
};

void BodyForce::get(void*, void*, void*, void* result)
{
    float* p = (float*)result;
    float* base = (float*)((char*)this + 0x158);
    p[0] = base[0];
    p[1] = base[1];
    p[2] = base[2];
}
