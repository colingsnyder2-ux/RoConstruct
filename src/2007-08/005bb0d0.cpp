// from server: 100% by colin
struct T_func_005bb0d0 {
    char pad[0x12d];
    void m();
};

void func_005bb0d0();

void T_func_005bb0d0::m()
{
    *(char*)((char*)this + 0x12c) = 1;
    *(char*)((char*)this + 0xf9) = 1;
    *(char*)((char*)this + 0x111) = 1;
    func_005bb0d0();
}
