// from server: 62% by atomic.potato
extern float flt_009AEA18;
extern float flt_009AB804;

int sub_71F7F0(const float* a1)
{
    if (a1[0] == flt_009AEA18) return 0;
    if (a1[1] == flt_009AEA18) return 1;
    if (a1[2] == flt_009AEA18) return 2;
    if (a1[0] == flt_009AB804) return 3;
    if (a1[1] == flt_009AB804) return 4;
    if (a1[2] == flt_009AB804) return 5;
    return 6;
}
