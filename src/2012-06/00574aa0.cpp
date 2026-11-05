// from server: 100% by tester
extern "C" {
    int __cdecl sub_972290(unsigned char, const char*);
    int __cdecl sub_4015a0(const char*, const char*);
    int __cdecl sub_67f480();
    int __cdecl sub_570430();
}

extern unsigned char g_e580b3;
extern int g_e246b8;
extern int g_e5809c;
extern int g_bc5b10;

extern const char g_b42f20[];
extern const char g_b42f90[];
extern const char g_b42fa8[];
extern const char g_e24714[];
extern const char g_571ed0[];

struct AsyncResult {
    void construct();
};

void AsyncResult::construct()
{
    if (g_e580b3 != 0) {
        if (g_e246b8 != 0x29a) {
            int f = g_e5809c;
            if (f != 0) {
                if (((char (__cdecl*)(const char*, const char*, int))f)(g_b42f90, g_b42fa8, 0xcf) != 0) {
                    goto after;
                }
            }
            sub_972290(g_e580b3, g_b42f20);
        }
    }
after:
    if (g_bc5b10 == 0) {
        sub_67f480();
        return;
    }
    sub_4015a0(g_e24714, g_571ed0);
    sub_570430();
}
