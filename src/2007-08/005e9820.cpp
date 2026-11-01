// from server: 100% by colin
struct VExplosionSignalDesc {
    int get(int* out);
};

int VExplosionSignalDesc::get(int* out)
{
    *out = *(int*)((char*)this + 0x294);
    return (int)out;
}
