// from server: 23% by atomic.potato
struct Ball
{
    void get(float* out);
};

void Ball::get(float* out)
{
    float value = *(float*)((char*)this + 0x10);
    out[0] = value;
    out[1] = value;
    out[2] = value;
}
