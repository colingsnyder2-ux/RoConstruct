// from server: 100% by colin
// roc 2007-08 006e61e0  unit: seg_006e0000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006e61e0

extern "C" int __stdcall sub_6e54b0(int);
extern "C" int (__stdcall *SetPixel)(int, int, int, int);

struct CXTPDockingPanePaintManager
{
    int sub_6e61e0(int, int, int, int);
};

int CXTPDockingPanePaintManager::sub_6e61e0(int a, int b, int c, int d)
{
    int v = sub_6e54b0(d);
    return SetPixel(*(int *)(a + 4), b, c, v);
}
