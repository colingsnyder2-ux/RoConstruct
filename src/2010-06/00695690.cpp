// from server: 100% by atomic.potato
struct RotatePJoint
{
    float GetValue();
};

float RotatePJoint::GetValue()
{
    struct Data
    {
        char padding[0xd0];
        float value;
    };

    Data* data = *(Data**)((char*)this + 0xb4);
    return data->value;
}
