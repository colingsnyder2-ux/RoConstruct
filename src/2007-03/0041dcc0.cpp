// from server: 100% by colin
// roc 2007-03 0041dcc0  unit: seg_00410000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0041dcc0
//
// 0041dcc0  8bc1                 mov eax, ecx
// 0041dcc2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041dcc6  85c9                 test ecx, ecx
// 0041dcc8  740f                 je 0x41dcd9
// 0041dcca  50                   push eax
// 0041dccb  e8a0ffffff           call 0x41dc70
// 0041dcd0  84c0                 test al, al
// 0041dcd2  7505                 jne 0x41dcd9
// 0041dcd4  33c0                 xor eax, eax
// 0041dcd6  c20400               ret 4
// 0041dcd9  b801000000           mov eax, 1
// 0041dcde  c20400               ret 4
// copied from an identical function in another client (function ?g@S@@QAEHPAU1@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    bool f(S*);
    int g(S*);
};

int S::g(S* other)
{
    if (other && !other->f(this))
        return 0;
    return 1;
}