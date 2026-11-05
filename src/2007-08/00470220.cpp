// from server: 65% by colin
// roc 2007-08 00470220  size: 243 bytes
// glg3dcpp/Texture.cpp

extern "C" {
    int __stdcall glGetError(void);
    void __stdcall glGenTextures(int n, unsigned int* textures);
}

extern "C" unsigned long __stdcall GetTickCount(void);

struct std_string {
    char buf[28];
    std_string(const char* s);
    ~std_string();
};

extern void* g_8980fc;
extern unsigned char g_8bd07d;

extern "C" int __cdecl sub_502880(void);
extern "C" int __cdecl sub_5028f0(void);

extern "C" void __stdcall RaiseException_77e938(unsigned long, unsigned long, unsigned long, const void*);

int __cdecl sub_470220(void)
{
    unsigned int textures;
    unsigned long t;
    unsigned long t2;

    textures = 0;
    t = GetTickCount();
    glGenTextures(1, &textures);

    if (g_8bd07d == 0) {
        t2 = GetTickCount();
        if (t2 == 0x502) {
            sub_502880();
            if (g_8980fc != 0) {
                std_string msg("GL_INVALID_OPERATION: Probably caused by invoking glGenTextures between glBegin and glEnd.");
                bool reported = false;
                if (((int (__cdecl*)(const char*, int, const char*, const char*, ...))g_8980fc)(
                        "glGetError() != GL_INVALID_OPERATION", 0x4d8, ".\\glg3dcpp\\Texture.cpp", "L$4d", 1)) {
                    reported = true;
                }
                if (reported) {
                    RaiseException_77e938(0xffffffff, 0, 0, 0);
                }
                sub_5028f0();
            }
        }
    }

    return (int)textures;
}
