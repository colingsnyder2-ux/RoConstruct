// from server: 41% by atomic.potato
struct SceneUpdater {
    void* vfptr;
    unsigned int flags;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    float f24;
    int f28;
    int f2c;
    float f30;
    float f34;
    char pad38[4];
    void init(int, int, int, int, int, int, int, int, int, int, float, int, int, float, float, int);
};

extern "C" void __stdcall sub_971af0(int);

void SceneUpdater::init(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, float a11, int a12, int a13, float a14, float a15, int a16)
{
    this->flags = a1 | 0x200;
    this->f08 = a2;
    this->f0c = a3;
    this->f10 = a4;
    this->f14 = a5;
    this->f18 = a6;
    this->f1c = a7;
    this->f20 = a8;
    this->f24 = a11;
    this->f28 = a9;
    this->f2c = a10;
    this->f30 = a14;
    this->f34 = a15;
    this->vfptr = (void*)0xaf88e0;
    sub_971af0(a16);
}
