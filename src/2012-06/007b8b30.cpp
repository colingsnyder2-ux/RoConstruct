// from server: 49% by Intel
extern "C" int __stdcall G1_func_0068acd0();
extern "C" int __stdcall G1_func_006c8100(int);
extern "C" int __stdcall G1_func_007b8310(int);
extern "C" void __stdcall G1_func_00972290(int, int);

extern int G1_global_00e5809c;
extern char G1_global_00e580b3;

struct ForceField
{
    char pad_0[56];
    int field_38;
    bool func_007b8b30(int a1);
};

bool ForceField::func_007b8b30(int a1)
{
    if (G1_global_00e580b3)
    {
        if (!a1)
        {
            if (G1_global_00e5809c)
            {
                if (G1_func_0068acd0())
                {
                    return false;
                }
            }
            G1_func_00972290(G1_global_00e580b3, 0xbb9e90);
        }
    }

    if (!G1_func_007b8310(a1))
    {
        int v = field_38;
        if (v)
        {
            int* esi = reinterpret_cast<int*>(v + 0x1c);
            if (esi)
            {
                int ebx = esi[3];
                int eax = G1_func_0068acd0();
                if (G1_func_006c8100(ebx))
                {
                    return false;
                }
                int* check = reinterpret_cast<int*>(esi - 7);
                if (check)
                {
                    return false;
                }
            }
        }
        return false;
    }
    return true;
}
