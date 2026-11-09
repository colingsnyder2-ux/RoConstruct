// from server: 100% by EspClaude
// roc 2009-06 004579a0  unit: InsertModelFromRobloxVerb  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004579a0
//
// 004579a0  56                   push esi
// 004579a1  8bf1                 mov esi, ecx
// 004579a3  e8a8401100           call 0x56ba50
// 004579a8  dd4618               fld qword ptr [esi + 0x18]
// 004579ab  dc05809a8b00         fadd qword ptr [0x8b9a80]
// 004579b1  ded9                 fcompp 
// 004579b3  dfe0                 fnstsw ax
// 004579b5  f6c441               test ah, 0x41
// 004579b8  7504                 jne 0x4579be
// 004579ba  32c0                 xor al, al
// 004579bc  5e                   pop esi
// 004579bd  c3                   ret 
// 004579be  8b4610               mov eax, dword ptr [esi + 0x10]
// 004579c1  6a01                 push 1
// 004579c3  50                   push eax
// 004579c4  e867c50600           call 0x4c3f30
// 004579c9  83c408               add esp, 8
// 004579cc  33c9                 xor ecx, ecx
// 004579ce  84c0                 test al, al
// 004579d0  0f94c1               sete cl
// 004579d3  8ac1                 mov al, cl
// 004579d5  5e                   pop esi
// 004579d6  c3                   ret 
// copied from an identical function in another client (function ?f@InsertModelFromRobloxVerb@ns_ROCX000016@@QAE_NXZ)

namespace ns_ROCX000016 {
extern "C" bool __cdecl G1_func_00495e60(void*, int);
extern "C" double __cdecl G2_func_005083d0();

extern double g_8190b8;

struct InsertModelFromRobloxVerb
{
    char pad[0x10];
    void* field10;
    char pad2[0x4];
    double field18;

    bool f();
};

bool InsertModelFromRobloxVerb::f()
{
    double now = G2_func_005083d0();
    if (this->field18 + g_8190b8 > now)
        return false;

    return !G1_func_00495e60(this->field10, 1);
}
}
