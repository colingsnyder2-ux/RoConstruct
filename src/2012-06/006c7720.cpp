// from server: 29% by Intel
extern "C" void __stdcall func_006c7670(void*);
extern "C" void __stdcall func_00b2263c();

struct RBX_Settings {
    void func_006c7720(int, int, int, int, int, int, int);
};

void RBX_Settings::func_006c7720(int, int, int, int, int, int, int)
{
    char vtable_gap[0x14];
    int* vtable_ptr = reinterpret_cast<int*>(&vtable_gap);
    func_006c7670(vtable_ptr);
    *reinterpret_cast<int*>(this) = 0xb96d5c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4) = 0xb96d54;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18) = 0xb96d48;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x1c) = 0xb96d3c;
    func_00b2263c();
}
