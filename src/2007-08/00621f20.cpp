// from server: 3% by colin
// roc 2007-08 00621f20 unit: RBX::ScoreHud size: 2634 bytes
// Reconstructed from target assembly.

extern "C" {
    int __stdcall _invalid_parameter_noinfo();
}

// Forward declarations of helper functions used by the target.
struct RBX_ScoreHud;

// Helper function declarations (addresses masked, symbolic names).
void* __cdecl sub_495730(void*);
void __cdecl sub_4E0180(void*, void*, void*);
void __cdecl sub_4F3980(void*, void*);
void __cdecl sub_50B200();
void __cdecl sub_553F80(void*, void*);
void __cdecl sub_555530();
void __cdecl sub_5555B0(void*, void*);
void __cdecl sub_586B80(void*);
void __cdecl sub_5E2FA0(void*);
void __cdecl sub_61F550(void*, void*);
void __cdecl sub_6207A0(void*, void*, void*);
void __cdecl sub_6208C0(void*, void*, void*);
void __cdecl sub_620E10(void*);
void __cdecl sub_621D70(void*);
void __cdecl sub_621E50(void*, void*);
void __cdecl sub_630D36(void*, void*, void*, void*, void*);
void __cdecl sub_736ED0();
void __cdecl sub_487C10(void*);

// std::string member functions (MSVCP80)
void __cdecl std_string_ctor_copy(void*, const void*);
void __cdecl std_string_ctor_char(void*, const char*);
void __cdecl std_string_dtor(void*);
void __cdecl std_string_assign(void*, const void*);

// Global data references
extern float flt_7C44F0;
extern float flt_7C43BC;
extern float flt_7C44F8;
extern float flt_7C44F4;
extern float flt_786F70;
extern float flt_797E9C;
extern float flt_797988;
extern float flt_7A9968;
extern float flt_7A836C;
extern const char str_79B6FC[];

// Imported function pointers (from IAT)
extern void* (__stdcall *p_77E698)(void*, const char*);
extern void* (__stdcall *p_77E6D8)();
extern void* (__stdcall *p_77E690)(void*, void*);
extern void* (__stdcall *p_77E69C)(void*, void*);
extern void* (__stdcall *p_77E6AC)(void*);

struct RBX_ScoreHud {
    char pad_000[0xF4];
    float field_F4;
    float field_F8;
    char pad_0FC[0x0C];
    void* field_108;
    char pad_10C[0x24];
    void* field_130;

    void method_621F20(void* arg1, int arg2);
};

void RBX_ScoreHud::method_621F20(void* arg1, int arg2)
{
    char local_90[0x1E8];
    char local_8C[4];

    sub_621E50(this, local_90);
    sub_620E10(local_8C);

    void* v = sub_495730(this);
    if (v == 0) {
        sub_621D70(local_8C);
        return;
    }

    sub_621D70(local_8C);
}
