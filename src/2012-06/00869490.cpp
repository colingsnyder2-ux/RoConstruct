// from server: 59% by atomic.potato
struct Kernel {
    char pad0[0x10];
    char m_flag10;
    char pad1[3];
    void* m_field14;
    void step(int a);
};

extern "C" void __stdcall sub_972290(unsigned char a, const char* b);
extern "C" float __stdcall sub_904910();

extern unsigned char g_flag_e580b3;
extern void* g_ptr_e5809c;
extern float g_const_b4c440;
extern float g_const_b7a314;

extern char g_str_ba3894[];
extern char g_str_bd5718[];
extern char g_str_bd6424[];
extern char g_str_bd6390[];
extern char g_str_bd6460[];

void Kernel::step(int a)
{
    if (g_flag_e580b3 != 0) {
        if (m_flag10 != 0) {
            void* p = g_ptr_e5809c;
            if (p != 0) {
                typedef unsigned char (__stdcall *Fn)(int, const char*, const char*);
                if (((Fn)p)(0x59, g_str_bd5718, g_str_ba3894) != 0) {
                    goto skip1;
                }
            }
            sub_972290(g_flag_e580b3, g_str_bd6460);
        }
    skip1:
        if (g_flag_e580b3 != 0) {
            float dt = ((float (__thiscall*)(int))0x867ec0)(a);
            float inf = sub_904910();
            if (!(dt == inf)) {
                float d = dt - inf;
                if (d < 0) d = -d;
                float lim = (d + g_const_b4c440) * g_const_b7a314;
                if (!(lim < inf)) {
                    goto skip2;
                }
                void* p = g_ptr_e5809c;
                if (p != 0) {
                    typedef unsigned char (__stdcall *Fn)(int, const char*, const char*);
                    if (((Fn)p)(0x5a, g_str_bd5718, g_str_bd6424) != 0) {
                        goto skip2;
                    }
                }
                sub_972290(g_flag_e580b3, g_str_bd6390);
            }
        }
    }
skip2:
    ((void (__thiscall*)(void*, int))0x869370)(m_field14, a);
    ((void (__thiscall*)(int, float))0x867e10)(a, 0.0f);
}
