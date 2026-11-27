// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
int f(int fmt) {
    switch (fmt) {
    case 70: case 80: return 0x20;
    case 71: case 82: return 0x18;
    case 73: return 0x10;
    case 75: case 77: case 79: case 83: return 0xf;
    }
    return 0;
}
