// from server: 92% by king_originala
extern int keyMap[323];
extern bool keyMapInitialized;

int __cdecl translateKey(int key)
{
    if (!keyMapInitialized)
    {
        keyMap[267] = 0x6f;
        keyMap[307] = 0xa5;
        keyMap[278] = 0x24;
        keyMap[273] = 0x26;
        keyMap[280] = 0x21;
        keyMap[276] = 0x25;
        keyMap[275] = 0x27;
        keyMap[279] = 0x23;
        keyMap[274] = 0x28;
        keyMap[281] = 0x22;
        keyMap[277] = 0x2d;
        keyMap[127] = 0x2e;
        keyMap[310] = 0x5b;
        keyMap[309] = 0x5c;
        keyMap[319] = 0x5d;

        int result = keyMap[key];
        keyMapInitialized = true;
        return result;
    }

    return keyMap[key];
}
