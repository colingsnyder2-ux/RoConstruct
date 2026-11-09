// from server: 53% by atomic.potato
struct VArrowTool {
    void* vtable;
    void* vtable2;
    char pad8[0x14];
    char f1c;
    char pad1d[3];
    int f20;
    int f24;
    char f28;
    char pad29[7];
    float f30;
    float f34;
    float f38;
    unsigned short f3c;
    unsigned short f3e;
    int f40;
    int f44;
    VArrowTool* construct(int arg);
};

extern "C" void __stdcall sub_785a00(void* self, int arg);

VArrowTool* VArrowTool::construct(int arg) {
    sub_785a00(this, arg);
    this->f1c = 0;
    this->vtable = (void*)0x9d8324;
    this->vtable2 = (void*)0x9d8308;
    this->f20 = 0;
    this->f24 = 0;
    this->f28 = 0;
    this->f30 = 0.0f;
    this->f34 = 0.0f;
    this->f38 = 0.0f;
    this->f3c = 0;
    this->f3e = 0;
    this->f40 = 0;
    this->f44 = 0;
    return this;
}
