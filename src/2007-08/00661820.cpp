// from server: 100% by colin
struct S_00661820 {
    void f(int);
    int sub_00663c50();
    int sub_00661700(int);
};

void S_00661820::f(int a)
{
    int i = a;
    if (i < sub_00663c50()) {
        do {
            int* p = (int*)sub_00661700(i);
            p[0x13] = i;
            i++;
        } while (i < sub_00663c50());
    }
}
