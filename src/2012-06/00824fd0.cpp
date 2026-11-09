// from server: 75% by Intel
struct VPlayerRefPropDescriptor {
    int getValue();
};

int VPlayerRefPropDescriptor::getValue() {
    int* vtable = *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x2C);
    int (__thiscall *func)(int*) = reinterpret_cast<int (__thiscall *)(int*)>(vtable[0]);
    return func(vtable);
}
