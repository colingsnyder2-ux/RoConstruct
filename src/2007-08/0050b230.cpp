// from server: 100% by colin
// roc 2007-08 0050b230  unit: seg_00500000  size: 334 bytes

extern "C" int __cdecl sub_0050bc70(int, int);

float g_8981a0;
float g_8981a4;
float g_8981a8;
float g_8981ac;
float g_8981b0;
float g_8981b4;
float g_8981b8;
float g_8981bc;
float g_8981c0;
float g_8981c4;
float g_8981c8;
float g_8981cc;
float g_8981d0;
float g_8981d4;
float g_8981d8;
float g_8981dc;
float g_8981e0;
float g_8981e4;
float g_8981e8;
float g_8981ec;
float g_8981f0;
float g_8981f4;
float g_8981f8;
float g_8981fc;

float g_8c0b60[24];
unsigned int g_8c0bc0;

float* sub_0050b230()
{
    if ((g_8c0bc0 & 1) == 0)
    {
        g_8c0bc0 |= 1;
        g_8c0b60[0] = g_8981b8;
        g_8c0b60[1] = g_8981bc;
        g_8c0b60[2] = g_8981c0;
        g_8c0b60[3] = g_8981a0;
        g_8c0b60[4] = g_8981a4;
        g_8c0b60[5] = g_8981a8;
        g_8c0b60[6] = g_8981ac;
        g_8c0b60[7] = g_8981b0;
        g_8c0b60[8] = g_8981b4;
        g_8c0b60[9] = g_8981f4;
        g_8c0b60[10] = g_8981f8;
        g_8c0b60[11] = g_8981fc;
        g_8c0b60[12] = g_8981dc;
        g_8c0b60[13] = g_8981e0;
        g_8c0b60[14] = g_8981e4;
        g_8c0b60[15] = g_8981d0;
        g_8c0b60[16] = g_8981d4;
        g_8c0b60[17] = g_8981d8;
        g_8c0b60[18] = g_8981c4;
        g_8c0b60[19] = g_8981c8;
        g_8c0b60[20] = g_8981cc;
        g_8c0b60[21] = g_8981e8;
        g_8c0b60[22] = g_8981ec;
        g_8c0b60[23] = g_8981f0;
    }
    int idx = sub_0050bc70(0, 7);
    return &g_8c0b60[idx * 3];
}
