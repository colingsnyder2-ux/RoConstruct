// from server: 100% by atomic.potato
struct Motor
{
    float get();
    char pad[180];
};

float Motor::get()
{
    float* value = *(float**)((char*)this + 180);
    return *(value + 43);
}
