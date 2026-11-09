// from server: 48% by atomic.potato
struct S
{
    char pad10[16];
    int* field10;
    char pad20[12];
    int* field20;
    char pad30[12];
    int* field30;
    char pad50[28];
    int field50;
    void f();
};

void S::f()
{
    *field10 = field50;
    *field20 = field50;
    *field30 = field50 - field50;
}
