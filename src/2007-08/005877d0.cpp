// from server: 100% by colin
struct RBX_Reflection_EnumDescriptor {
    void func_005877d0();
};

extern "C" void __stdcall func_0062fbde(int, float, float, float);

void RBX_Reflection_EnumDescriptor::func_005877d0()
{
    int v = *(int*)((char*)this + 0xec);
    if (v) {
        float f3 = *(float*)((char*)this + 0x108);
        float f2 = *(float*)((char*)this + 0x104);
        float f1 = *(float*)((char*)this + 0x100);
        func_0062fbde(v, f1, f2, f3);
    }
}
