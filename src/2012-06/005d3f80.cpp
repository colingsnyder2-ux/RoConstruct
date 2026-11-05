// from server: 41% by Intel
struct FactoryProduct {
    void* Creator();
};

extern "C" void* __stdcall sub_5CF230(void*);
extern "C" void __stdcall sub_6CAB60(void*);
extern "C" void __stdcall sub_9831F5(void*);

unsigned char byte_E277D4;
void* dword_BB2504;
void* dword_E275F0;
void* dword_B14B30;

void* FactoryProduct::Creator()
{
    if (byte_E277D4 & 1)
        return dword_E275F0;

    byte_E277D4 |= 1;

    struct {
        char pad0[2];
        int pad2;
        int value;
    } local;
    local.pad0[0] = 0;
    local.pad0[1] = 0;
    local.pad2 = 0;
    local.value = 0x1B;

    void* result = sub_5CF230(dword_BB2504);
    sub_6CAB60(dword_E275F0);
    sub_9831F5(dword_B14B30);

    return dword_E275F0;
}
