// from server: 100% by tajop
struct WaterDirArg
{
    char a;
    char b;
    int c;
    int d;
    WaterDirArg() : a(0), b(0), c(0), d(27) {}
    WaterDirArg(const WaterDirArg& o);
    ~WaterDirArg();
};

extern int g_waterDirName;
int __stdcall makeWaterDirDesc(int name, WaterDirArg arg, int extra);

struct W4WaterCellDirectionEnumDesc
{
    W4WaterCellDirectionEnumDesc(int x);
    ~W4WaterCellDirectionEnumDesc();
};

const W4WaterCellDirectionEnumDesc& func_00781330()
{
    static W4WaterCellDirectionEnumDesc s(makeWaterDirDesc(g_waterDirName, WaterDirArg(), 0));
    return s;
}
