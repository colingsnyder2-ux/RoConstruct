// from server: 51% by Intel
typedef int DWORD;
typedef float REAL;

struct CPropGrid {
    char pad0[0x224];
    char flag;
    char pad1[3];
    DWORD value;
    void UpdateItemsJob(REAL* out);
};

extern REAL g_global_float;

void CPropGrid::UpdateItemsJob(REAL* out)
{
    DWORD val = value;
    if (val != 0)
    {
        if (out != 0)
        {
            *out = 0.0f;
        }
        return;
    }
    val -= 1;
    if (val == 0)
    {
        if (out != 0)
        {
            *out = 0.0f;
        }
        return;
    }
    if (flag == 0)
    {
        if (out != 0)
        {
            *out = 0.0f;
        }
        return;
    }
    if (out != 0)
    {
        *out = g_global_float;
    }
    return;
}
