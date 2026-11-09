// from server: 94% by atomic.potato
struct VBlockMeshFactoryProduct
{
    void setValue(int value);
};

extern "C" void __stdcall G1_func_00414da0(int);

void VBlockMeshFactoryProduct::setValue(int value)
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xA8) != value)
    {
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xA8) = value;
        G1_func_00414da0(0xE4E95C);
    }
}
