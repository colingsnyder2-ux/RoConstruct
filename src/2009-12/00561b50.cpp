// from server: 100% by atomic.potato
extern "C" void __cdecl sub_007f385a(int);

struct Job_00561b50
{
    int padding_00;
    int padding_04;
    int field_08;
    int field_0c;
    void f();
};

void Job_00561b50::f()
{
    if (field_08 != 0)
        sub_007f385a(field_0c);
}
