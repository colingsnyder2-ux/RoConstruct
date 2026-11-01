// from server: 100% by colin
struct Tool {
    char pad[0x174];
    int sub_509640(int, int);
    int func_005d1ca0(int);
};

int Tool::func_005d1ca0(int a)
{
    char* p = (char*)this + 0x174;
    ((Tool*)p)->sub_509640(a, 0);
    return a;
}
