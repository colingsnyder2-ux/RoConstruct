// from server: 79% by atomic.potato
struct Feature
{
    int a0;
    int a4;
    int a18;
    int a1c;
    int a80;
    void init();
};

extern "C" void __cdecl feature_finish();

void Feature::init()
{
    a0 = 0x00bdbb8c;
    a4 = 0x00bdbb80;
    a18 = 0x00bdbb74;
    a1c = 0x00bdbb68;
    a80 = 0x00bdbb3c;
    feature_finish();
}
