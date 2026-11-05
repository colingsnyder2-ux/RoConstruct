// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 67% by colin
// roc 2008-06 0059eca0  unit: RBX::PartInstance  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059eca0
//
// 0059eca0  8b8104010000         mov eax, dword ptr [ecx + 0x104]
// 0059eca6  85c0                 test eax, eax
// 0059eca8  742e                 je 0x59ecd8
// 0059ecaa  6a00                 push 0
// 0059ecac  6850dd9200           push 0x92dd50
// 0059ecb1  687c909200           push 0x92907c
// 0059ecb6  6a00                 push 0
// 0059ecb8  50                   push eax
// 0059ecb9  e8082b1000           call 0x6a17c6
// 0059ecbe  83c414               add esp, 0x14
// 0059ecc1  85c0                 test eax, eax
// 0059ecc3  7413                 je 0x59ecd8
// 0059ecc5  d9e8                 fld1 
// 0059ecc7  d9c0                 fld st(0)
// 0059ecc9  d8a0e8010000         fsub dword ptr [eax + 0x1e8]
// 0059eccf  d88828030000         fmul dword ptr [eax + 0x328]
// 0059ecd5  dee9                 fsubp st(1)
// 0059ecd7  c3                   ret 
// 0059ecd8  d9ee                 fldz 
// 0059ecda  c3                   ret 

struct Instance {
    char pad[0x104];
    void* field_104;
    float getSomething();
};

float Instance::getSomething()
{
    void* p = field_104;
    if (p) {
        void* r = __RTDynamicCast(p, 0, (void*)0x92907c, (void*)0x92dd50, 0);
        if (r) {
            float a = *(float*)((char*)r + 0x1e8);
            float b = *(float*)((char*)r + 0x328);
            return 1.0f - (1.0f - a) * b;
        }
    }
    return 0.0f;
}
