// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_00469360 (placeholder name for 00469360 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"

int sub_00469360(int key)
{
    static bool initialized = false;
    static int table[256];
    if (!initialized)
    {
        for (int i = 0; i < 256; ++i)
            table[i] = 0;
        table[1] = 0x1b;
        table[2] = '1'; table[3] = '2'; table[4] = '3'; table[5] = '4'; table[6] = '5';
        table[7] = '6'; table[8] = '7'; table[9] = '8'; table[10] = '9'; table[11] = '0';
        table[12] = '-'; table[13] = '='; table[14] = 8; table[15] = 9;
        table[16] = 'q'; table[17] = 'w'; table[18] = 'e'; table[19] = 'r'; table[20] = 't';
        table[21] = 'y'; table[22] = 'u'; table[23] = 'i'; table[24] = 'o'; table[25] = 'p';
        table[26] = '['; table[27] = ']'; table[28] = 0xd; table[29] = 0x132;
        table[30] = 'a'; table[31] = 's'; table[32] = 'd'; table[33] = 'f'; table[34] = 'g';
        table[35] = 'h'; table[36] = 'j'; table[37] = 'k'; table[38] = 'l';
        table[39] = ';'; table[40] = '\''; table[41] = '`'; table[42] = 0x130;
        table[43] = '\\'; table[86] = '\\';
        table[44] = 'z'; table[45] = 'x'; table[46] = 'c'; table[47] = 'v'; table[48] = 'b';
        table[49] = 'n'; table[50] = 'm'; table[51] = ','; table[52] = '.'; table[53] = '/';
        table[54] = 0x12f; table[55] = 0x10c; table[56] = 0x134; table[57] = ' '; table[58] = 0x12d;
        table[59] = 0x11a; table[60] = 0x11b; table[61] = 0x11c; table[62] = 0x11d; table[63] = 0x11e;
        table[64] = 0x11f; table[65] = 0x120; table[66] = 0x121; table[67] = 0x122; table[68] = 0x123;
        table[69] = 0x12c; table[70] = 0x12e;
        table[71] = 0x107; table[72] = 0x108; table[73] = 0x109; table[74] = 0x10d;
        table[75] = 0x104; table[76] = 0x105; table[77] = 0x106; table[78] = 0x10e;
        table[79] = 0x101; table[80] = 0x102; table[81] = 0x103; table[82] = 0x100; table[83] = 0x10a;
        table[87] = 0x124; table[88] = 0x125;
        table[100] = 0x126; table[101] = 0x127; table[102] = 0x128;
        table[141] = 0x110; table[156] = 0x10f; table[157] = 0x131;
        table[181] = 0x10b; table[183] = 0x13d; table[184] = 0x133;
        table[197] = 0x13; table[199] = 0x116; table[200] = 0x111; table[201] = 0x118;
        table[203] = 0x114; table[205] = 0x113; table[207] = 0x117; table[208] = 0x112;
        table[209] = 0x119; table[210] = 0x115; table[211] = 0x7f;
        table[219] = 0x136; table[220] = 0x135; table[221] = 0x13f;
        initialized = true;
    }
    return table[key];
}
