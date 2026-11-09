// from server: 100% by colin
struct RBX_ImageButton_StaticData
{
    static float* get();
};

float* RBX_ImageButton_StaticData::get()
{
    static unsigned int initFlag = 0;
    static float value0;
    static float value1;
    static float value2;

    if ((initFlag & 1) == 0)
    {
        initFlag |= 1;
        value0 = 1.0f;
        value1 = *(float*)0x7c42b0;
        value2 = *(float*)0x7c42ac;
    }

    return &value0;
}
