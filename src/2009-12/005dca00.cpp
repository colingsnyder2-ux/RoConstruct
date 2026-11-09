// from server: 54% by atomic.potato
extern "C" void __cdecl func_00910ac0(float, float, float, float);

struct AdornG3D_005dca00 {
    char pad[8];
    int value;
    void f(float a, float b, float c);
};

void AdornG3D_005dca00::f(float a, float b, float c)
{
    func_00910ac0((float)value, a, b, c);
}
