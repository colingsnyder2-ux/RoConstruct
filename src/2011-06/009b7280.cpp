// from server: 52% by atomic.potato
struct CornerWedgeBuilder
{
    CornerWedgeBuilder& initialize(void*);
    float field28;
    float field2c;
};

extern float g_value;

CornerWedgeBuilder& CornerWedgeBuilder::initialize(void* value)
{
    initialize(value);
    field28 = 0.0f;
    field2c = *(float*)((char*)value + 0x10) * g_value;
    return *this;
}
