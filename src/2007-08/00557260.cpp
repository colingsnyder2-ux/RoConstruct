// from server: 100% by colin
// roc 2007-08 00557260  unit: ChatEnter  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00557260
//
// 00557260  51                   push ecx
// 00557261  a130688c00           mov eax, dword ptr [0x8c6830]
// 00557266  8b0d34688c00         mov ecx, dword ptr [0x8c6834]
// 0055726c  03c1                 add eax, ecx
// 0055726e  890424               mov dword ptr [esp], eax
// 00557271  7508                 jne 0x55727b
// 00557273  d9056c647900         fld dword ptr [0x79646c]
// 00557279  59                   pop ecx
// 0055727a  c3                   ret 
// 0055727b  db0530688c00         fild dword ptr [0x8c6830]
// 00557281  da3424               fidiv dword ptr [esp]
// 00557284  59                   pop ecx
// 00557285  c3                   ret 
// copied from an identical function in another client (function ?hitRatio@@YAMXZ)

// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern int g_hit, g_miss;
float hitRatio() {
    int n = g_hit + g_miss;
    if (n == 0) return -1.0f;
    return (float)g_hit / n;
}