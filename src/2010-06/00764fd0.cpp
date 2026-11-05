// from server: 94% by atomic.potato
// roc 2010-06 00764fd0  unit: RBX::FilterStairs  size: 50 bytes

extern "C" int __cdecl sub_7A8BEA(int, int, int, int, int);
extern "C" int __cdecl sub_605060(int);

struct RBX_FilterStairs {
    int getCameraSubject();
};

int RBX_FilterStairs::getCameraSubject()
{
    int v = sub_7A8BEA(0, (int)&sub_7A8BEA, (int)&sub_605060, 0, (int)this);
    if (v != 0) {
        int r = sub_605060(v);
        if (r != 0) {
            return *(int*)(r + 0xd0);
        }
    }
    return 0;
}
