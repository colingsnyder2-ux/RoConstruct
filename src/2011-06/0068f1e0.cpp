// from server: 44% by atomic.potato
struct S
{
    float value;
    void set(float);
};

void S::set(float value)
{
    if (this->value != value)
    {
        this->value = value;
        extern void G1_func_00411f60(float);
        G1_func_00411f60(0x00ccf424);
    }
}
