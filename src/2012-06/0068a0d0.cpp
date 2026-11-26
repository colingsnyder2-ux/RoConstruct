// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
//



struct WaterDirArg
{
    char a;
    char b;
    int c;
    int d;
    WaterDirArg() : a(0), b(0), c(0), d(25) {}
    WaterDirArg(const WaterDirArg& o);
    ~WaterDirArg();
};

extern int g_waterDirName;
int __stdcall makeWaterDirDesc(const char* name, WaterDirArg arg, int extra);

struct W4WaterCellDirectionEnumDesc
{
    W4WaterCellDirectionEnumDesc(int x);
    ~W4WaterCellDirectionEnumDesc();
};

const W4WaterCellDirectionEnumDesc& func_00781330()
{
    static W4WaterCellDirectionEnumDesc s(makeWaterDirDesc("Camera", WaterDirArg(), 0));
    return s;
}
