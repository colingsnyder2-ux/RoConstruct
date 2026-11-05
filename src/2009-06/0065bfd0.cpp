// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00599250  unit: RBX::VPartInstance::?$FactoryProduct  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00599250
//
// 00599250  83ec20               sub esp, 0x20
// 00599253  d9ee                 fldz 
// 00599255  8b01                 mov eax, dword ptr [ecx]
// 00599257  d91424               fst dword ptr [esp]
// 0059925a  d9542404             fst dword ptr [esp + 4]
// 0059925e  d9542408             fst dword ptr [esp + 8]
// 00599262  d9542410             fst dword ptr [esp + 0x10]
// 00599266  d9542414             fst dword ptr [esp + 0x14]
// 0059926a  d95c2418             fstp dword ptr [esp + 0x18]
// 0059926e  83f806               cmp eax, 6
// 00599271  7752                 ja 0x5992c5
// 00599273  ff2485e4925900       jmp dword ptr [eax*4 + 0x5992e4]
// 0059927a  8d0424               lea eax, [esp]
// 0059927d  50                   push eax
// 0059927e  e8dda20700           call 0x613560
// 00599283  eb40                 jmp 0x5992c5
// 00599285  8d1424               lea edx, [esp]
// 00599288  52                   push edx
// 00599289  e812a40700           call 0x6136a0
// 0059928e  eb35                 jmp 0x5992c5
// 00599290  8d0424               lea eax, [esp]
// 00599293  50                   push eax
// 00599294  e8f79f0700           call 0x613290
// 00599299  eb2a                 jmp 0x5992c5
// 0059929b  8d1424               lea edx, [esp]
// 0059929e  52                   push edx
// 0059929f  e89ca10700           call 0x613440
// 005992a4  eb1f                 jmp 0x5992c5
// 005992a6  8d0424               lea eax, [esp]
// 005992a9  50                   push eax
// 005992aa  e8319f0700           call 0x6131e0
// 005992af  eb14                 jmp 0x5992c5
// 005992b1  8d1424               lea edx, [esp]
// 005992b4  52                   push edx
// 005992b5  e866a00700           call 0x613320
// 005992ba  eb09                 jmp 0x5992c5
// 005992bc  8d0424               lea eax, [esp]
// 005992bf  50                   push eax
// 005992c0  e8fba60700           call 0x6139c0
// 005992c5  8b442424             mov eax, dword ptr [esp + 0x24]
// 005992c9  d9442410             fld dword ptr [esp + 0x10]
// 005992cd  d918                 fstp dword ptr [eax]
// 005992cf  d9442414             fld dword ptr [esp + 0x14]
// 005992d3  d95804               fstp dword ptr [eax + 4]
// 005992d6  d9442418             fld dword ptr [esp + 0x18]
// 005992da  d95808               fstp dword ptr [eax + 8]
// 005992dd  83c420               add esp, 0x20
// 005992e0  c20400               ret 4
// 005992e3  90                   nop 
// 005992e4  90                   nop 
// 005992e5  92                   xchg edx, eax
// 005992e6  59                   pop ecx
// 005992e7  00a6925900b1         add byte ptr [esi - 0x4effa66e], ah
// 005992ed  92                   xchg edx, eax
// 005992ee  59                   pop ecx
// 005992ef  009b9259007a         add byte ptr [ebx + 0x7a005992], bl
// 005992f5  92                   xchg edx, eax
// 005992f6  59                   pop ecx
// 005992f7  0085925900bc         add byte ptr [ebp - 0x43ffa66e], al
// 005992fd  92                   xchg edx, eax
// 005992fe  59                   pop ecx

struct VPartInstance {
    int type;
    void getPos0(float* out);
    void getPos1(float* out);
    void getPos2(float* out);
    void getPos3(float* out);
    void getPos4(float* out);
    void getPos5(float* out);
    void getPos6(float* out);
    void compute(float* out);
};

void VPartInstance::compute(float* out)
{
    float v[8];
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    v[4] = 0.0f;
    v[5] = 0.0f;
    v[6] = 0.0f;

    switch (type) {
    case 0: getPos0(v); break;
    case 1: getPos1(v); break;
    case 2: getPos2(v); break;
    case 3: getPos3(v); break;
    case 4: getPos4(v); break;
    case 5: getPos5(v); break;
    case 6: getPos6(v); break;
    }

    out[0] = v[4];
    out[1] = v[5];
    out[2] = v[6];
}
