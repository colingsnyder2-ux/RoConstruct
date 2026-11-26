// from server: 100% by Xemicl
// roc 2012-06 0096eda0  unit: W4_D3DFORMAT::?$EnumDesc  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0096eda0
//
// 0096eda0  8b4104               mov eax, dword ptr [ecx + 4]
// 0096eda3  85c0                 test eax, eax
// 0096eda5  7e1a                 jle 0x96edc1
// 0096eda7  50                   push eax
// 0096eda8  8b442408             mov eax, dword ptr [esp + 8]
// 0096edac  6a00                 push 0
// 0096edae  50                   push eax
// 0096edaf  e83cf9ffff           call 0x96e6f0
// 0096edb4  33c9                 xor ecx, ecx
// 0096edb6  83f8ff               cmp eax, -1
// 0096edb9  0f95c1               setne cl
// 0096edbc  8ac1                 mov al, cl
// 0096edbe  c20400               ret 4
// 0096edc1  83c8ff               or eax, 0xffffffff
// 0096edc4  33c9                 xor ecx, ecx
// 0096edc6  3bc0                 cmp eax, eax
// 0096edc8  0f95c1               setne cl
// 0096edcb  8ac1                 mov al, cl
// 0096edcd  c20400               ret 4
// copied from an identical function in another client (function ?contains@C@@QBE_NPBD@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
int __stdcall search(const char* s, int start, int n);
class C {
public:
    int pad;
    int num;
    int find(const char* s) const {
        if (num > 0) return search(s, 0, num);
        return -1;
    }
    bool contains(const char* s) const;
};
bool C::contains(const char* s) const { return find(s) != -1; }