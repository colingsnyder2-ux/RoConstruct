// from server: 42% by atomic.potato
extern void G1_func_00414da0();

struct Motor
{
    float setValue(float value);
};

float Motor::setValue(float value)
{
    float *field = reinterpret_cast<float *>(*reinterpret_cast<char **>(reinterpret_cast<char *>(this) + 0xa8) + 0xa8);
    if (*field != value)
    {
        *field = value;
        G1_func_00414da0();
    }
    return value;
}
