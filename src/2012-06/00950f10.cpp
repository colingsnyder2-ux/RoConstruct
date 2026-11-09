// from server: 39% by atomic.potato
extern "C" int __cdecl sub_94FFE0(int, int, int, int, int, int);
extern "C" int __cdecl sub_8A8F80(int, int, int, int);

struct RBX_AdvRotateTool {
    char pad0[8];
    int field8;
    int method(int, int, int);
};

int RBX_AdvRotateTool::method(int a, int b, int c) {
    int* out = (int*)a;
    int v1 = b;
    int v2 = c;
    *out = v1;
    if (v1 != v2) {
        int old = field8;
        char flag = 0;
        int r = sub_94FFE0(old, v2, v1, c, b, *(int*)&flag);
        sub_8A8F80(r, old, (int)this, c);
        field8 = r;
    }
    return (int)out;
}
