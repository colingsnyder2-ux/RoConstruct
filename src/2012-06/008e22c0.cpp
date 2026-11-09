// from server: 46% by atomic.potato
struct VehicleSeat
{
    char padding[0x34c];
    void* field_34c;
    bool f();
};

bool VehicleSeat::f()
{
    return field_34c != 0 && *(void**)((char*)field_34c + 4) != 0;
}
