// from server: 100% by atomic.potato
struct Motor
{
    char padding[0xb4];
    void* field_b4;
    float get_value();
};

float Motor::get_value()
{
    return *((float*)((char*)field_b4 + 0xac));
}
