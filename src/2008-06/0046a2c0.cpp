// from server: 43% by colin
struct DxUserInput
{
    unsigned short a;
    unsigned short b;
    int c;
    void* d;
    void* e;
    int f;

    void Load(int param);
};

extern "C" int __stdcall sub_7A6368(void* a, const char* b, void* c, int* d);
extern "C" void __stdcall sub_6A094A(void* p);
extern "C" void __stdcall sub_803F14(void* p);

void DxUserInput::Load(int param)
{
    int local_2c;
    int local_18;
    void* local_10;

    local_18 = 0;
    local_10 = 0;

    if (sub_7A6368(d, (const char*)0x8104EC, &e, &local_2c))
    {
        if (sub_7A6368(d, (const char*)0x81C440, &local_10, &local_2c))
        {
            if (local_2c >= 4)
            {
                void* p = local_10;
                c = local_2c >> 2;
                a = *(unsigned short*)p;
                b = *(unsigned short*)((char*)p + 2);
            }
        }
        local_18 = 1;
    }
    else
    {
        if (d != 0)
        {
            sub_6A094A(d);
            d = 0;
        }
    }

    sub_803F14(&local_10);
}
