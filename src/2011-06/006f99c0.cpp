// from server: 100% by atomic.potato
struct Motor
{
    float get() const;
    char reserved[0xb4];
    void* field_b4;
};

float Motor::get() const
{
    return *(float*)((char*)field_b4 + 0xa8);
}
