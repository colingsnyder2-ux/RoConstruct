// from server: 100% by colin
struct S {
    char pad[0x58];
    char flag;
    void sub_54b960();
    void f();
};

void S::f()
{
    if (flag != 0) {
        sub_54b960();
        flag = 0;
    }
}
