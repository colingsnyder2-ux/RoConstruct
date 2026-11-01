// from server: 100% by atomic.potato
struct RBX_AdornG3D {
    void func_0062dba0(int, int, int);
};

extern void __cdecl sub_0062f6e0(int, int);

void RBX_AdornG3D::func_0062dba0(int a, int b, int c)
{
    (*(void (__thiscall**)(void*, int))(*(int*)this + 0x38))(this, b);
    sub_0062f6e0(a, *(int*)((char*)this + 4));
}
