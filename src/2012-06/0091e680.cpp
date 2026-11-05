// from server: 38% by atomic.potato
struct Motor6DJoint
{
    char padding[0x9c];
    float field_9c;
    float field_a0;
    int field_a4;

    void set(float a, float b, float c);
};

void Motor6DJoint::set(float a, float b, float c)
{
    field_9c = a * b;
    field_a0 = c;
    field_a4 = 0x20;
}
