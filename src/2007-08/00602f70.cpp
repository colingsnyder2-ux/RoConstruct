// from server: 40% by colin
struct IStage {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

struct Primitive;
struct Joint;

struct JointStage {
    char pad0[8];
    void* field8;
    char padC[4];
    char field10[12];
    char field1C[12];

    void onPrimitiveAdded(Primitive* p);
};

extern "C" void* __stdcall sub_5B4D10(void* p);
extern "C" void __stdcall sub_5B4710(void* p);
extern "C" void __stdcall sub_5E29B0(void* a, void* b, void* c);
extern "C" void __stdcall sub_602F00(void* a, void* b, void* c);
extern "C" void __stdcall sub_608490(void* a, void* b);
extern "C" void __stdcall sub_609120(void* a, void* b);

void JointStage::onPrimitiveAdded(Primitive* p)
{
    void* esi;
    void* edi;
    void* local10;
    void* local14;
    void* local18;
    void* local1C;
    void* local20;
    void* local24;
    void* local28;
    void* local2C;
    void* local30;
    void* local34;
    void* local38;
    void* local3C;
    void* local40;
    void* local44;
    void* local48;
    void* local4C;
    void* local50;
    void* local54;
    void* local58;
    void* local5C;
    void* local60;
    void* local64;

    local4C = 0;
    local50 = 0;
    local54 = 0;
    local64 = 0;

    edi = p;
    esi = sub_5B4D10(edi);
    while (esi != 0) {
        void* ecx = field8;
        void* eax = *(void**)ecx;
        void* edx = *(void**)((char*)eax + 0x14);
        ((void (__stdcall*)(void*))edx)(esi);

        sub_5B4710(esi);

        local10 = esi;
        sub_5E29B0(&local28, &local10, field10);

        if (edi != 0) {
            local14 = edi;
            local18 = esi;
            sub_602F00(&local34, &local14, field1C);
        }

        void* eax2 = *(void**)((char*)esi + 8);
        if (edi == eax2) {
            eax2 = *(void**)((char*)esi + 0xC);
        }
        if (eax2 != 0) {
            local1C = eax2;
            local20 = esi;
            sub_602F00(&local40, &local1C, field1C);
        }

        esi = sub_5B4D10(edi);
    }

    sub_608490(field8, edi);
    sub_609120(edi, this);
}
