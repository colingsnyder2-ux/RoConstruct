// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: table of 0x143 ints at 0x96e908 followed by init flag at 0x96ee14; lazy-init key map.
static int g_table[0x143];
static bool g_inited;

extern "C" int fn_00469c60(int idx)
{
    if (!g_inited) {
        for (int i = 0; i < 0x143; i++) g_table[i] = 0;
        g_table[13] = 0xd;
        g_table[271] = 0xd;
        g_table[316] = 0x2a;
        g_table[317] = 0x2c;
        g_table[27] = 0x1b;
        g_table[8] = 8;
        g_table[9] = 9;
        g_table[306] = 0xa2;
        g_table[304] = 0xa0;
        g_table[92] = 0xe2;
        g_table[303] = 0xa1;
        g_table[268] = 0x6a;
        g_table[308] = 0xa4;
        g_table[32] = 0x20;
        g_table[301] = 0x14;
        g_table[282] = 0x70;
        g_table[283] = 0x71;
        g_table[284] = 0x72;
        g_table[285] = 0x73;
        g_table[286] = 0x74;
        g_table[287] = 0x75;
        g_table[288] = 0x76;
        g_table[289] = 0x77;
        g_table[290] = 0x78;
        g_table[291] = 0x79;
        g_table[300] = 0x90;
        g_table[302] = 0x91;
        g_table[263] = 0x67;
        g_table[264] = 0x68;
        g_table[265] = 0x69;
        g_table[269] = 0x6d;
        g_table[260] = 0x64;
        g_table[261] = 0x65;
        g_table[262] = 0x66;
        g_table[270] = 0x6b;
        g_table[257] = 0x61;
        g_table[258] = 0x62;
        g_table[259] = 0x63;
        g_table[256] = 0x60;
        g_table[266] = 0x6e;
        g_table[292] = 0x7a;
        g_table[293] = 0x7b;
        g_table[294] = 0x7c;
        g_table[295] = 0x7d;
        g_table[296] = 0x7e;
        g_table[305] = 0xa3;
        g_table[267] = 0x6f;
        g_table[307] = 0xa5;
        g_table[278] = 0x24;
        g_table[273] = 0x26;
        g_table[280] = 0x21;
        g_table[276] = 0x25;
        g_table[275] = 0x27;
        g_table[279] = 0x23;
        g_table[274] = 0x28;
        g_table[281] = 0x22;
        g_table[277] = 0x2d;
        g_table[127] = 0x2e;
        g_table[310] = 0x5b;
        g_table[309] = 0x5c;
        g_table[319] = 0x5d;
        int r = g_table[idx];
        g_inited = true;
        return r;
    }
    return g_table[idx];
}
