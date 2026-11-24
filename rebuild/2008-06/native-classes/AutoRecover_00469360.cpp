// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the 256-dword table at 0x96dff0 is followed directly by the
// init flag at 0x96e3f0, so a struct is used to keep that layout.
static struct KeyMapData {
    int table[256];
    unsigned char inited;
} g_keyMap;

// INFERRED: the target takes one int key, builds the lazily initialised
// key-code translation table on first call, and returns table[key].
extern "C" int fn_00469360(int key)
{
    if (!g_keyMap.inited) {
        int* t = g_keyMap.table;
        for (int i = 0; i < 256; ++i)
            t[i] = 0;
        t[1] = 0x1b;
        t[2] = 0x31; t[3] = 0x32; t[4] = 0x33; t[5] = 0x34; t[6] = 0x35;
        t[7] = 0x36; t[8] = 0x37; t[9] = 0x38; t[10] = 0x39; t[11] = 0x30;
        t[12] = 0x2d; t[13] = 0x3d; t[14] = 8; t[15] = 9;
        t[16] = 0x71; t[17] = 0x77; t[18] = 0x65; t[19] = 0x72; t[20] = 0x74;
        t[21] = 0x79; t[22] = 0x75; t[23] = 0x69; t[24] = 0x6f; t[25] = 0x70;
        t[26] = 0x5b; t[27] = 0x5d; t[28] = 0xd; t[29] = 0x132;
        t[30] = 0x61; t[31] = 0x73; t[32] = 0x64; t[33] = 0x66; t[34] = 0x67;
        t[35] = 0x68; t[36] = 0x6a; t[37] = 0x6b; t[38] = 0x6c; t[39] = 0x3b;
        t[40] = 0x27; t[41] = 0x60; t[42] = 0x130;
        t[43] = 0x5c;
        t[86] = 0x5c;
        t[44] = 0x7a; t[45] = 0x78; t[46] = 0x63; t[47] = 0x76; t[48] = 0x62;
        t[49] = 0x6e; t[50] = 0x6d; t[51] = 0x2c; t[52] = 0x2e; t[53] = 0x2f;
        t[54] = 0x12f; t[55] = 0x10c; t[56] = 0x134; t[57] = 0x20; t[58] = 0x12d;
        t[59] = 0x11a; t[60] = 0x11b; t[61] = 0x11c; t[62] = 0x11d; t[63] = 0x11e;
        t[64] = 0x11f; t[65] = 0x120; t[66] = 0x121; t[67] = 0x122; t[68] = 0x123;
        t[69] = 0x12c; t[70] = 0x12e; t[71] = 0x107; t[72] = 0x108; t[73] = 0x109;
        t[74] = 0x10d; t[75] = 0x104; t[76] = 0x105; t[77] = 0x106; t[78] = 0x10e;
        t[79] = 0x101; t[80] = 0x102; t[81] = 0x103; t[82] = 0x100; t[83] = 0x10a;
        t[87] = 0x124; t[88] = 0x125;
        t[100] = 0x126; t[101] = 0x127; t[102] = 0x128;
        t[141] = 0x110;
        t[156] = 0x10f; t[157] = 0x131;
        t[181] = 0x10b;
        t[183] = 0x13d; t[184] = 0x133;
        t[197] = 0x13;
        t[199] = 0x116; t[200] = 0x111; t[201] = 0x118;
        t[203] = 0x114;
        t[205] = 0x113;
        t[207] = 0x117; t[208] = 0x112; t[209] = 0x119; t[210] = 0x115;
        t[211] = 0x7f;
        t[219] = 0x136; t[220] = 0x135; t[221] = 0x13f;
        int result = t[key];
        g_keyMap.inited = 1;
        return result;
    }
    return g_keyMap.table[key];
}
