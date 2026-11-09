// from server: 96% by atomic.potato
struct BodyForce
{
    void GetValue(float* result, int, int, int, int);
};

void BodyForce::GetValue(float* result, int, int, int, int)
{
    result[0] = *(float*)((char*)this + 0x158);
    result[1] = *(float*)((char*)this + 0x15c);
    result[2] = *(float*)((char*)this + 0x160);
}
