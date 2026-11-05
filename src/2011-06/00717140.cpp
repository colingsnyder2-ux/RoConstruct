// from server: 31% by atomic.potato
struct VehicleSeat
{
    float value;
    void setValue(float);
};

void VehicleSeat::setValue(float v)
{
    if (!(value > v) && !(value < v))
        return;
    value = v;
    *((int*)0xcd393c) = 0xcd393c;
}
