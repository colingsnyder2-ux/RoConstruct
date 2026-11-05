// from server: 100% by colin
extern "C" __int64 __stdcall func_006311b0(int, int, int, int);

struct CRenderSettings
{
    char pad[0x210];
    int field_210;
    int field_214;
    double getFullscreenSize();
};

double CRenderSettings::getFullscreenSize()
{
    int a = field_210;
    int b = field_214;
    __int64 v = func_006311b0(a, b, 0x3e8, 0);
    return (double)v * *(double*)0x7b5a08;
}
