// from server: 78% by atomic.potato
extern "C" int __stdcall InvalidateRect(void*, const void*, int);
extern "C" int Next(int);

struct S
{
    int f();
    int m00[8];
    void* m20;
    int m24[16];
    int m64;
};

int S::f()
{
    InvalidateRect(m20, 0, 0);
    return Next(m64);
}
