// from server: 56% by Intel
struct W4_D3DFORMAT_EnumDesc {
    int GetValue(int format);
};

int W4_D3DFORMAT_EnumDesc::GetValue(int format) {
    int index = format - 70;
    if (index > 13)
        return 0;

    static const unsigned char jumpTable[14] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
    };
    index = jumpTable[index];

    switch (index) {
        case 0: return 1;
        case 1: return 4;
        case 2: return 8;
        default: return 0;
    }
}
