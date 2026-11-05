// from server: 83% by atomic.potato
extern "C" void __cdecl ProbeD3DDeviceSettingsForWindowed();

struct PrismPoly
{
    float f[36];

    float method();
};

float PrismPoly::method()
{
    if (f[36] == *(float*)0xA6EC30)
        ProbeD3DDeviceSettingsForWindowed();
    return f[36];
}
