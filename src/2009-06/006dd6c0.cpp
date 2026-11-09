// from server: 35% by atomic.potato
struct Vec3 { int x, y, z; };

struct TreeStage {
    char pad0[0x30];
    int f30, f34, f38, f3c, f40, f44;
    char pad48[0x4];
    void* f48;
    int method(int, int, int, int, int, int, int, int);
};

extern "C" int __stdcall sub_6dc3f0(void*, int, int*, int*);
extern "C" int __stdcall sub_482630(int*, int*, int*);
extern "C" int __fastcall sub_6dd490(TreeStage*, int, int*, int*, int);
extern "C" int __fastcall sub_6dc970(TreeStage*, int);

int TreeStage::method(int a, int b, int c, int d, int e, int f, int g, int h)
{
    int v0 = 0, v1 = 0, v2 = 0;
    int v3 = 0, v4 = 0, v5 = 0;
    int out0, out1, out2, out3, out4, out5;

    sub_6dc3f0(f48, a, &v0, &v3);

    if (v0 == f30 && v1 == f34 && v2 == f38 &&
        v3 == f3c && v4 == f40 && v5 == f44)
        return 0;

    int o30 = f30, o34 = f34, o38 = f38, o3c = f3c, o40 = f40, o44 = f44;
    int n30 = v0, n34 = v1, n38 = v2, n3c = v3, n40 = v4, n44 = v5;

    f30 = v0; f34 = v1; f38 = v2; f3c = v3; f40 = v4; f44 = v5;

    if (o30 <= n3c && o34 <= n40 && o38 <= n44 &&
        o3c >= n30 && o40 >= n34 && o44 >= n38)
    {
        sub_482630(&n30, &o30, &out0);
        sub_6dd490(this, 0, &n30, &out0, 0);
    }
    else
    {
        sub_6dd490(this, 0, &n30, &n30, 0);
        sub_6dd490(this, 0, &o30, 0, 0);
    }
    sub_6dc970(this, 0);
    return 0;
}
