// from server: 25% by Intel
struct Vector3
{
    float x, y, z;
};

extern "C" void __stdcall func_0050d320(const Vector3*, int, Vector3*);
extern "C" int __stdcall func_00634440(int, int, const float*, const float*, const float*, float*, float*, float*);

extern float g_float_00b63268;
extern int g_int_00bbc29c;
extern float g_float_00e2877c;
extern float g_float_00e28780;

struct BallBallContact
{
    char pad[16];
    float field_10;
    float field_14;
    float field_18;
    bool __thiscall CheckContact(int a2, int a3, int a4, Vector3* a5);
};

bool BallBallContact::CheckContact(int a2, int a3, int a4, Vector3* a5)
{
    float v10 = field_10;
    float v14 = field_14;
    float v18 = field_18;

    int cmp1_ge = (0.0f >= v10) ? 1 : 0;
    int cmp1_gt = (v10 > 0.0f) ? 1 : 0;

    int cmp2_ge = (0.0f >= v14) ? 1 : 0;
    int cmp2_gt = (v14 > 0.0f) ? 1 : 0;

    int cmp3_ge = (0.0f >= v18) ? 1 : 0;
    int cmp3_gt = (v18 > 0.0f) ? 1 : 0;

    int var_14 = 1;
    if (cmp3_gt == 0)
        var_14 = 0;

    float val = static_cast<float>(g_int_00bbc29c) * g_float_00b63268;
    val += g_float_00e28780;
    val = val * val;

    int var_1c = 1;
    int var_10 = a2;
    int var_50 = a3;
    int var_54 = a4;
    int var_18 = cmp3_gt ? -1 : 0;

    for (int edi = var_10; edi <= var_50; ++edi)
    {
        for (int ebp = cmp1_ge; ebp <= cmp1_gt; ++ebp)
        {
            for (int ebx = var_18; ebx <= var_14; ++ebx)
            {
                int abs_ebp = (ebp ^ (ebp >> 31)) - (ebp >> 31);
                int abs_edi = (edi ^ (edi >> 31)) - (edi >> 31);
                int abs_ebx = (ebx ^ (ebx >> 31)) - (ebx >> 31);

                int sum = abs_ebp + abs_edi + abs_ebx;
                if (sum != var_1c)
                    continue;

                Vector3 pt;
                pt.x = a5->x + edi;
                pt.y = a5->y + ebp;
                pt.z = a5->z + ebx;

                Vector3 out;
                func_0050d320(&pt, 0, &out);

                float f68 = out.x;
                float f6c = out.y;
                float f70 = out.z;

                int edi_val = a2 + 4;
                int arg1 = (int)&g_float_00e28780;
                int arg2 = (int)&g_float_00e2877c;
                int arg3 = (int)&f68;
                int arg4 = (int)&f6c;
                int arg5 = (int)&f70;
                int arg6 = edi_val;
                int arg7 = 0;
                int arg8 = 0;
                int arg9 = 0;

                int result = func_00634440(arg1, arg2, (const float*)arg3, (const float*)arg4, (const float*)arg5, (float*)arg6, (float*)arg7, (float*)arg8);

                if (result)
                {
                    float diff_x = f68 - *(float*)(edi_val + 8);
                    float diff_y = f6c - *(float*)(edi_val + 4);
                    float diff_z = f70 - *(float*)edi_val;

                    float dist_sq = diff_x * diff_x + diff_y * diff_y + diff_z * diff_z;

                    if (val > dist_sq)
                    {
                        a5->x += edi;
                        a5->y += ebp;
                        a5->z += ebx;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
