// from server: 62% by atomic.potato
struct RBX_DecalTool {
    int* vtable;
    int field_1C;

    void func_78CB60();
};

extern "C" void __cdecl sub_611D00(int, int);

void RBX_DecalTool::func_78CB60() {
    int* vtable = this->vtable;
    int (*func)(RBX_DecalTool*) = reinterpret_cast<int(*)(RBX_DecalTool*)>(vtable[12]);
    func(this);

    vtable = this->vtable;
    int (*func2)(RBX_DecalTool*) = reinterpret_cast<int(*)(RBX_DecalTool*)>(vtable[0]);
    int result = func2(this);

    int* ptr = reinterpret_cast<int*>(result + 4);
    if (ptr[6] < 0x10) {
        sub_611D00(reinterpret_cast<int>(ptr), this->field_1C);
    } else {
        sub_611D00(ptr[1], this->field_1C);
    }
}
