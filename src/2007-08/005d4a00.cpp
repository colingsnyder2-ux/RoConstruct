// from server: 100% by colin
struct S {
    char pad[0x170];
    int field_0x170;
    void func_005d4950(int);
    void m();
};

void S::m()
{
    int v = field_0x170;
    int r = (v + 1) % 2;
    func_005d4950(v + r + 1);
}
