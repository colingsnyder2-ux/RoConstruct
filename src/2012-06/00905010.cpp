// from server: 19% by Intel
extern "C" void __cdecl func_007be4f0(float*, float*, float*);
extern "C" float __cdecl func_00904b20(float*, float*, float*);

float func_00905010(float a1, float a2, float a3)
{
    float v4[3];
    v4[0] = a1;
    v4[1] = a2;
    v4[2] = a3;

    float v8[3];
    func_007be4f0(v4, v8, v4);

    const float* c1 = (const float*)0x00b4c440;
    float c1_val = *c1;

    float v12 = v8[0];
    float v13 = v8[1];
    float v14 = v8[2];

    if (v12 > c1_val) v12 = c1_val;
    if (v13 > c1_val) v13 = c1_val;
    if (v14 > c1_val) v14 = c1_val;

    float* p_min1 = &v12;
    if (v13 < v12) p_min1 = &v13;
    float* p_min2 = &v14;
    if (*p_min1 > v14) p_min2 = p_min1;

    float* p_max1 = &v12;
    if (v13 > v12) p_max1 = &v13;
    float* p_max2 = &v14;
    if (*p_max1 < v14) p_max2 = p_max1;

    float min_val = *p_min2;
    float max_val = *p_max2;

    float args[3];
    args[0] = min_val;
    args[1] = max_val;
    args[2] = v4[0];

    float result = func_00904b20(&args[0], &args[1], &args[2]);

    if (c1_val > result)
    {
        result *= v4[0];
    }

    const float* c2 = (const float*)0x00bf2b40;
    return result * (*c2);
}
