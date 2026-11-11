// from server: 100% by EspClaude
// from server: 80% by Intel
// roc 2007-08 00775e30  unit: seg_00770000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00775e30
//
// 00775e30  dd05685b7900         fld qword ptr [0x795b68]
// 00775e36  6a01                 push 1
// 00775e38  83ec08               sub esp, 8
// 00775e3b  dd1c24               fstp qword ptr [esp]
// 00775e3e  68381e7c00           push 0x7c1e38
// 00775e43  68301e7c00           push 0x7c1e30
// 00775e48  33c9                 xor ecx, ecx
// 00775e4a  68281e7c00           push 0x7c1e28
// 00775e4f  51                   push ecx
// 00775e50  b820975f00           mov eax, 0x5f9720
// 00775e55  50                   push eax
// 00775e56  b9487f8c00           mov ecx, 0x8c7f48
// 00775e5b  e8b03ce8ff           call 0x5f9b10
// 00775e60  6850c87700           push 0x77c850
// 00775e65  e8b9aeebff           call 0x630d23
// 00775e6a  59                   pop ecx
// 00775e6b  c3                   ret 

struct MIBase1_00775e30 { int a; };
struct MIBase2_00775e30 { int b; };
struct Owner_00775e30 : MIBase1_00775e30, MIBase2_00775e30 {
    void func_005f9720();
};
extern const char str_007c1e28[];
extern const char str_007c1e30[];
extern const char str_007c1e38[];
extern const double g_double_00795b68;

struct Desc_008c7f48 {
    Desc_008c7f48(void (Owner_00775e30::*fn)(), const char *a, const char *b, const char *c, double d, int e);
    ~Desc_008c7f48();
};

static Desc_008c7f48 g_desc_008c7f48(&Owner_00775e30::func_005f9720, str_007c1e28, str_007c1e30, str_007c1e38, g_double_00795b68, 1);
