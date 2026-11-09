// from server: 100% by atomic.potato
struct VehicleSeat
{
    unsigned char padding[0x35c];
    unsigned char value;
    void changed(unsigned long);
    void setValue(unsigned char);
};

void VehicleSeat::setValue(unsigned char v)
{
    if (value == v)
        return;
    value = v;
    changed(0xcd38dc);
}
