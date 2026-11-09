// roc 2012-06 00686470  unit: RBX::VInstance::?$EventDesc  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00686470
//
// 00686470  803900               cmp byte ptr [ecx], 0
// 00686473  753f                 jne 0x6864b4
// 00686475  80790100             cmp byte ptr [ecx + 1], 0
// 00686479  7539                 jne 0x6864b4
// 0068647b  80790200             cmp byte ptr [ecx + 2], 0
// 0068647f  7533                 jne 0x6864b4
// 00686481  80790300             cmp byte ptr [ecx + 3], 0
// 00686485  752d                 jne 0x6864b4
// 00686487  80790400             cmp byte ptr [ecx + 4], 0
// 0068648b  7527                 jne 0x6864b4
// 0068648d  80790500             cmp byte ptr [ecx + 5], 0
// 00686491  7521                 jne 0x6864b4
// 00686493  80790600             cmp byte ptr [ecx + 6], 0
// 00686497  751b                 jne 0x6864b4
// 00686499  80790700             cmp byte ptr [ecx + 7], 0
// 0068649d  7515                 jne 0x6864b4
// 0068649f  80790800             cmp byte ptr [ecx + 8], 0
// 006864a3  750f                 jne 0x6864b4
// 006864a5  80790900             cmp byte ptr [ecx + 9], 0
// 006864a9  7509                 jne 0x6864b4
// 006864ab  80790a00             cmp byte ptr [ecx + 0xa], 0
// 006864af  7503                 jne 0x6864b4
// 006864b1  33c0                 xor eax, eax
// 006864b3  c3                   ret 
// 006864b4  b801000000           mov eax, 1
// 006864b9  c3                   ret 
// copied from an identical function in another client (function ?isIdle@ArrowToolBase@@QBEHXZ)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct ArrowToolBase {
    char f0;
    char f1;
    char f2;
    char f3;
    char f4;
    char f5;
    char f6;
    char f7;
    char f8;
    char f9;
    char f10;
    int isIdle() const;
};

int ArrowToolBase::isIdle() const {
    if (f0 || f1 || f2 || f3 || f4 || f5 || f6 || f7 || f8 || f9 || f10)
        return 1;
    return 0;
}