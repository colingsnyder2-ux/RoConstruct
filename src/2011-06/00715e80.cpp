// from server: 52% by atomic.potato
struct VehicleSeat
{
    int f();
    char reserved[0x370];
    int value;
};

int VehicleSeat::f()
{
    return value;
}
