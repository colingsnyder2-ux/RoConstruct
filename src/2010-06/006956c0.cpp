// from server: 100% by atomic.potato
struct Motor
{
    float getValue();
    char padding[0xb4];
    void* field_b4;
};

float Motor::getValue()
{
    return *(float*)((char*)field_b4 + 0xb0);
}
