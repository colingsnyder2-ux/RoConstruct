// from server: 100% by tester
struct GCamera {
    char pad[0x4c];
    int field_0x4c;
    void func_00508780(int);
    void func_00508810();
};

void GCamera::func_00508810()
{
    func_00508780(field_0x4c - 1);
}
