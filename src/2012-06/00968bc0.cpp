// from server: 70% by Intel
struct LuaDragTool
{
    int func_00968bc0(int);
};

extern "C" int __stdcall sub_00867850(int, int, int);
extern "C" int __stdcall sub_008ee650(int);
extern "C" int __stdcall sub_00972290(int, int);

extern int dword_00C025D0;
extern int dword_00C07DD8;
extern int dword_00C07E28;
extern int dword_00E5809C;
extern char byte_00E580B3;

int LuaDragTool::func_00968bc0(int arg0)
{
    if (byte_00E580B3)
    {
        if (!*(char*)((int)this + 0x1C))
        {
            int v1 = dword_00E5809C;
            if (v1)
            {
                if (sub_00867850(0x3C, dword_00C07DD8, dword_00C025D0))
                {
                    goto LABEL_6;
                }
            }
            sub_00972290(dword_00C07E28, byte_00E580B3);
        }
    }
LABEL_6:
    int v2 = *(int*)((int)this + 0x20);
    int v3;
    if (v2)
    {
        v3 = v2 + 0x150;
    }
    else
    {
        v3 = 0;
    }
    int v4 = sub_00867850(v3, arg0, (int)&v3);
    sub_008ee650(*(int*)((int)this + 0x34));
    return v4;
}
