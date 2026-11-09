// from server: 43% by colin
struct std_string {
    std_string();
    std_string(const std_string&);
    std_string(const char*);
    ~std_string();
};

extern "C" {
    int __cdecl func_0046d4d0();
    void __cdecl func_00472f80();
    float __cdecl func_004f3110();
    int __cdecl func_004f35c0();
    bool __cdecl func_005085b0(const std_string*, std_string*);
    void __cdecl func_00630a1e();
}

extern float g_79f738;
extern float g_79b500;
extern float g_78fef0;
extern float g_797988;
extern const char g_797f4c[];
extern const char g_79f730[];
extern const char g_79f728[];
extern const char g_79f720[];

extern "C" {
    void* __stdcall imp_77e69c(const char*);
    void __stdcall imp_77e698(std_string*, const char*);
    void __stdcall imp_77e6ac(std_string*);
}

struct S_func_004f3770 {
    void func(float* a, float* b, char* c);
};

void S_func_004f3770::func(float* a, float* b, char* c)
{
    *a = g_79f738;
    *b = g_79b500;
    *c = 0;

    std_string s1;
    imp_77e69c(g_797f4c);
    imp_77e698(&s1, g_797f4c);

    std_string s2;
    bool found = false;

    imp_77e698(&s2, g_79f730);
    if (func_005085b0(&s2, &s1)) {
        found = true;
    }
    imp_77e6ac(&s2);

    if (!found) {
        imp_77e698(&s2, g_79f728);
        if (func_005085b0(&s2, &s1)) {
            found = true;
        }
        imp_77e6ac(&s2);
    }

    if (!found) {
        imp_77e698(&s2, g_79f720);
        if (func_005085b0(&s2, &s1)) {
            found = true;
        }
        imp_77e6ac(&s2);
    }

    float f = func_004f3110();
    func_00472f80();
    int v = func_004f35c0();

    if (v >= 0x708) {
        if (!(g_797988 > f)) {
            if (v > 0x80) {
                *b = g_78fef0;
                *a = g_78fef0;
            }
        }
    }

    imp_77e6ac(&s1);
}
