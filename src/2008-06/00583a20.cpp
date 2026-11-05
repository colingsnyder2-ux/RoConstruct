// from server: 100% by tester
struct RBX_ModelInstance {
    char pad[524];
    bool field_1ac;
    char pad2[0x1e0 - 0x1ad];
    bool field_1e0;
    char pad3[0x210 - 0x1e1];
    bool field_210;
    void tail();
};

extern "C" void __fastcall func_005bb0f0(void*);

void RBX_ModelInstance::tail()
{
    bool one = true;
    field_1e0 = one;
    field_210 = one;
    field_1ac = one;
    func_005bb0f0(this);
}
