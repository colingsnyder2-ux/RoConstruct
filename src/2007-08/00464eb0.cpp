// from server: 73% by colin
struct DxUserInput
{
    char pad[0x28];
    void func_00463a00(int, int, int);
    void func_00464eb0(int, int, int);
};

void DxUserInput::func_00464eb0(int a, int b, int c)
{
    ((DxUserInput*)((char*)this - 0x28))->func_00463a00(a, b, c);
}
