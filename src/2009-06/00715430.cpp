// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
int getColourBits(int format)
{
    switch (format) {
    case 20: return 8;
    case 21: return 8;
    case 22: return 8;
    case 23: return 5;
    case 24: return 5;
    case 25: return 5;
    case 26: return 4;
    case 27: return 2;
    case 28: return 0;
    case 29: return 2;
    case 30: return 4;
    case 31: return 10;
    case 32: return 8;
    case 33: return 0;
    case 34: return 0;
    case 35: return 10;
    case 36: return 16;
    }
    return 0;
}
