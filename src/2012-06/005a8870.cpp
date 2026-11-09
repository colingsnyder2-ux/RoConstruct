// from server: 54% by atomic.potato
struct RBX_Image
{
    void sub_5a7ef0(int* out);
    void sub_8b1a70(int* out, int a, int b);
    int sub_5a8870(int arg);
};

extern "C" void __stdcall sub_5a8020(int a, int b, int* out, int zero);

int RBX_Image::sub_5a8870(int arg)
{
    int local1;
    int local2;
    sub_5a7ef0(&local1);
    int v1 = local1;
    int v2 = local2;
    int zero = 0;
    sub_5a8020(v2, v1, &local2, zero);
    sub_8b1a70(&local1, v2, v1);
    return local2;
}
