// from server: 100% by colin
struct VHint {
    void sub_5efa40(int);
    void sub_5efb50(int);
    void f(int);
};

extern "C" int __cdecl sub_630d36(int, int, int, int, int);

void VHint::f(int a)
{
    if (*(unsigned int*)((char*)this + 0x24) > 0)
    {
        int v = *(int*)((char*)this - 0x2c);
        int r = sub_630d36(v, 0, 0x881f4c, 0x88e1c8, 0);
        if (r == 0)
        {
            ((VHint*)((char*)this - 0xe8))->sub_5efa40(a);
            return;
        }
        ((VHint*)((char*)this - 0xe8))->sub_5efb50(a);
    }
}
