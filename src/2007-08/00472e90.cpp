// from server: 100% by atomic.potato
// roc 2007-08 00472e90  unit: G3D::VARArea  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00472e90

struct VARArea {
    void cleanup();
    virtual void release(int);
    void removeAll(int, int);
};

extern int g_varAreaCount;
extern VARArea** g_varAreas;

void VARArea::cleanup()
{
    int i = 0;
    if (g_varAreaCount > 0) {
        do {
            g_varAreas[i]->cleanup();
            g_varAreas[i]->release(0);
            ++i;
        } while (i < g_varAreaCount);
    }
    ((VARArea*)0x8bd0b8)->removeAll(0, 1);
}
