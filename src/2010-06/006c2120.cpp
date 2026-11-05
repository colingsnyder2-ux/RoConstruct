// from server: 100% by atomic.potato
struct Motor
{
    float get();
};

float Motor::get()
{
    return *(float *)(*(int *)((char *)this + 0xb4) + 0x9c);
}
