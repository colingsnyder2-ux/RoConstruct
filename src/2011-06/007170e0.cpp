// from server: 32% by atomic.potato
struct VehicleSeat
{
    void f(float value);
    float field[213];
};

extern "C" void __stdcall dispatch(float);

void VehicleSeat::f(float value)
{
    if (field[212] != value)
    {
        field[212] = value;
        dispatch(value);
    }
}
