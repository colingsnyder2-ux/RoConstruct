// from server: 34% by atomic.potato
struct VehicleSeat
{
    char padding[860];
    float value;
    void setValue(float);
};

extern "C" void __stdcall UpdateValue(float*);

void VehicleSeat::setValue(float v)
{
    if (value != v)
    {
        value = v;
        UpdateValue(&value);
    }
}
