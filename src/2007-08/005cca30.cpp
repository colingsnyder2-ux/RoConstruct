// from server: 100% by colin
extern "C" int __stdcall sub_72d3d0(int, int);

struct seg_005c0000
{
    int method(int);
};

int seg_005c0000::method(int a)
{
    int v = *(int*)this;
    return sub_72d3d0(v, a);
}
