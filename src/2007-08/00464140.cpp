// from server: 46% by colin
struct DxUserInput {
    char pad[0x68];
    bool flag;
    int method(int, int);
};

extern "C" int __stdcall sub_59c3f0(int, int);

int DxUserInput::method(int a, int b)
{
    if (flag) {
        int r = sub_59c3f0(a, b);
        return r;
    }
    *(int*)a = 0;
    return 0;
}
