// from server: 5% by colin
struct RBX_ClumpStage;

struct RBX_ClumpStage
{
    char pad[0x74];
    void* field_74;
    void* field_78;
    char pad2[0x10];
    void* field_8c;
    void* field_90;
    void* field_94;
    void* field_98;
    void* field_9c;

    void func_006071f0();
};

extern "C" void __stdcall func_005375c0();
extern "C" void __stdcall func_005a93b0();
extern "C" void __stdcall func_005b3a60();
extern "C" void __stdcall func_005b3c40();
extern "C" void __stdcall func_005b3e30();
extern "C" void __stdcall func_005b3f20();
extern "C" void __stdcall func_005b4180();
extern "C" void __stdcall func_005b4830();
extern "C" void __stdcall func_005e29b0();
extern "C" void __stdcall func_00604800();
extern "C" void __stdcall func_00606c70();
extern "C" void __stdcall func_00627240();
extern "C" void __stdcall func_0062fc62();
extern "C" void __stdcall func_0062fef6();

void RBX_ClumpStage::func_006071f0()
{
    if (field_8c != 0)
    {
        do
        {
            func_005375c0();
            func_005b3a60();
            func_0062fef6();
            func_005b3f20();
            func_005e29b0();
        } while (field_8c != 0);
    }

    func_005b3e30();
    func_005a93b0();
    func_005b3a60();
    func_005b4830();
    func_005e29b0();
    func_00606c70();
    func_00627240();
    func_005b3c40();
    func_005b4180();
    func_00604800();
    func_005b3a60();
    func_0062fef6();
    func_005b3f20();
    func_005b4180();
    func_005e29b0();
    func_005b3a60();
    func_0062fc62();
}
