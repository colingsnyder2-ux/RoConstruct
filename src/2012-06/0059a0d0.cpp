// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Marker {
    char pad[0x14];
    unsigned int field_14;
    int pad18;
    int field_1c;
};
int __stdcall func(Marker* edx) {
    int ecx = edx->field_1c;
    int eax = 0x18;
    if (ecx == 2 || ecx == 4 || ecx == 3 || ecx == 6 || ecx == 7) {
        eax = 0x30;
    }
    if (ecx == 1 || ecx == 4) {
        eax += 0x18;
    }
    if (ecx == 1 || ecx == 4 || ecx == 3 || ecx == 7) {
        eax += 0x20;
    }
    if (edx->field_14 > 0) {
        eax += 0x50;
    }
    return eax;
}
