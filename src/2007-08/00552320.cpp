// from server: 35% by colin
struct S_00552320 {
    char pad[0x40];
    int field_40;
    char pad2[0x8];
    int field_4c;
    void sub_54dc00(int);
    void sub_54e820(int*, int);
    void func(int);
};

void S_00552320::func(int arg)
{
    sub_54dc00(arg);
    int tmp = field_4c;
    int local = tmp;
    sub_54e820(&local, arg);
}
