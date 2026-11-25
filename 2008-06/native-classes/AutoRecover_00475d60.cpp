// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>
#include <stdlib.h>
#include <string>

extern "C" void fn_0050a940(void);
extern "C" void fn_0050a9b0(void);

struct Local_475d60_Img {
    virtual ~Local_475d60_Img() {}
    volatile long references;
};

extern "C" void __fastcall fn_0045ad90(Local_475d60_Img* self);

extern unsigned long g_0096efd0;
extern int g_0096efcc;
extern bool g_0096efe1;
extern bool (__cdecl *g_0094278c)(const char*, const std::string&, const char*, int, bool*, bool);
extern void (__stdcall *g_0096f8e8)(int, unsigned long*);

struct Local_475d60_Ref {
    Local_475d60_Img* p;
    __forceinline ~Local_475d60_Ref() {
        if (p) {
            if (InterlockedDecrement(&p->references) == 0) {
                fn_0045ad90(p);
                if (p)
                    delete p;
            }
            p = 0;
        }
    }
};

struct Local_475d60_Base {
    __forceinline virtual ~Local_475d60_Base() {}
};

struct Local_475d60 : Local_475d60_Base {
    unsigned long padding0[2];
    Local_475d60_Ref image;
    unsigned long padding1[6];
    unsigned long size;
    unsigned long texture;
    void* memory;
    __forceinline virtual ~Local_475d60() {
        g_0096efd0 -= size;
        if (size) {
            switch (g_0096efcc) {
            case 1:
                g_0096f8e8(1, &texture);
                texture = 0;
                break;
            case 2:
                free(memory);
                memory = 0;
                break;
            default:
                if (!g_0096efe1) {
                    fn_0050a940();
                    if (g_0094278c &&
                        g_0094278c("false", "Fell through switch.",
                                   ".\\glg3dcpp\\VARArea.cpp", 136, &g_0096efe1, true))
                        exit(-1);
                    fn_0050a9b0();
                }
                break;
            }
            size = 0;
        }
    }
};

extern "C" void __fastcall fn_00475d60(Local_475d60* self, int unusedEdx)
{
    self->Local_475d60::~Local_475d60();
}
