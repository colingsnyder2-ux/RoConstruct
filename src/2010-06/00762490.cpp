// from server: 64% by atomic.potato
struct S
{
    int field0;
    int field1;
    int field2;
    int f(int);
};

void func_00762180(int, int);
void func_00750ac0(int, int);

int S::f(int p)
{
    func_00762180(field2, p);
    func_00750ac0(p, (int)this);
    return 0;
}
