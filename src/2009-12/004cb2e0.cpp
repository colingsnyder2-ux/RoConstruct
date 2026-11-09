// from server: 72% by atomic.potato
extern "C" void __stdcall glLineWidth(float width);

struct VARArea {
    char pad[0x70];
    int refCount70;
    char pad2[0x78 - 0x74];
    int refCount78;
    char pad3[0x498 - 0x7c];
    double value498;
    void setLineWidth(double w);
};

void VARArea::setLineWidth(double w) {
    double old = value498;
    refCount78++;
    if (w != old) {
        glLineWidth((float)w);
        refCount70++;
        value498 = w;
    }
}
