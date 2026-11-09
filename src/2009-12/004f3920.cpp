// from server: 24% by atomic.potato
extern "C" int __stdcall sub_004f4b90(int, int, int, int);

struct GfxAttachement
{
    char pad0[4];
    int method(int);
};

int GfxAttachement::method(int a)
{
    int v = a;
    char b = 0;
    sub_004f4b90(b, (int)this + 4, (int)&v, 0);
    return 0;
}
