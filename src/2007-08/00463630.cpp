// from server: 100% by Yeetserama
struct VRunServiceListener {
    char pad[0x184];
    int field184;
    int field188;
    int field18c;
    void func();
};

extern "C" __declspec(noreturn) void __stdcall sub_401000(int hr);

void VRunServiceListener::func()
{
    int hr;
    int local[5];

    hr = (*(int (__stdcall **)(int, int, int, int))(*(int*)field188 + 0xc))(field188, 0x7e51b4, (int)&field18c, 0);
    if (hr < 0)
        sub_401000(hr);

    hr = (*(int (__stdcall **)(int, int))(*(int*)field18c + 0x2c))(field18c, 0x7e53b4);
    if (hr < 0)
        sub_401000(hr);

    hr = (*(int (__stdcall **)(int, int, int))(*(int*)field18c + 0x34))(field18c, field184, 5);
    if (hr < 0)
        sub_401000(hr);

    local[0] = 0x14;
    local[1] = 0x10;
    local[2] = 0;
    local[3] = 0;
    local[4] = 0x800;

    hr = (*(int (__stdcall **)(int, int, int*))(*(int*)field18c + 0x18))(field18c, 1, local);
    if (hr < 0)
        sub_401000(hr);
}
