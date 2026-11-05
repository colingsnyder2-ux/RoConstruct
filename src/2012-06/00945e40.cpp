// from server: 84% by atomic.potato
extern "C" int __cdecl sub_983448(int, int, int, int, int);

struct RBX_AnchorTool {
    char pad[0x30];
    int field_30;
    void sub_945E40(int);
};

void RBX_AnchorTool::sub_945E40(int a)
{
    int v = field_30;
    if (v != 0) {
        int r = sub_983448(v, 0, 0xd601e8, 0xd8866c, 0);
        if (r != 0) {
            int* p = (int*)r;
            int (*fn)(void*, int) = (int (*)(void*, int))p[8];
            fn((void*)r, a);
        }
    }
}
