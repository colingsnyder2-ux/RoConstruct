// from server: 43% by atomic.potato
struct VGuiTextButton {
    char pad[0x2ec];
    int state;
    void* method4(void*);
};

extern float g_f1;
extern float g_f2;
extern void* g_ptr1;
extern unsigned char g_byte1;
extern void* g_ptr2;

extern "C" void* __stdcall sub_7e6170(void*);
extern "C" void* __stdcall sub_7e8370(void*, void*);
extern "C" void __stdcall sub_972290(unsigned char, const char*);

void* VGuiTextButton::method4(void* arg) {
    if (state != 0) {
        unsigned int v = (unsigned int)(state - 1);
        if (v <= 1) {
            float a = g_f1;
            float b = g_f2;
            void* r = sub_7e6170(&a);
            return sub_7e8370(r, arg);
        }
        if (g_byte1 != 0) {
            void* fn = g_ptr1;
            if (fn != 0) {
                if (((unsigned char (__stdcall*)(int, const char*, const char*))fn)(0x555, (const char*)0xbc25f8, (const char*)0xb460cc) != 0) {
                    goto skip;
                }
            }
            sub_972290(g_byte1, (const char*)0xbc2738);
        }
    }
skip:
    return sub_7e6170(arg);
}
