// from server: 78% by atomic.potato
struct AdornG3D {
    void sub_5dc9c0(float a, float b, float c, int d, int e);
};

extern "C" void __cdecl sub_7e0b60(int, float, float, int, int);

void AdornG3D::sub_5dc9c0(float a, float b, float c, int d, int e)
{
    (*(void (__thiscall **)(AdornG3D *, int))(*(int *)this + 0x40))(this, e);
    sub_7e0b60(*(int *)((char *)this + 8), a, b, d, c);
}
