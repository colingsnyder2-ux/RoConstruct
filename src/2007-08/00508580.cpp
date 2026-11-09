// from server: 100% by colin
struct GCamera {
    char pad0[0x18];
    double f18;
    double f20;
    int i28;
    int i2c;
    double f30;
    double f38;
    double f40;
    double f48;
    void init();
    GCamera();
};

extern double g_cameraDefault;

GCamera::GCamera()
{
    f18 = g_cameraDefault;
    *(char*)this = 0;
    f20 = 0.0;
    i28 = 0;
    f30 = 0.0;
    i2c = 0;
    f38 = 0.0;
    f40 = 0.0;
    f48 = 0.0;
    init();
}
