// from server: 29% by Intel
// from server: 29% by Intel
struct String {
    char _buf[28];
    String() {}
    ~String() {}
    String& operator=(const String&) { return *this; }
};

struct MaterialPtr {
    char _buf[4];
    MaterialPtr() {}
    MaterialPtr& operator=(const void*) { return *this; }
};

struct Material {
    virtual ~Material() {}
    virtual unsigned char getNumSupportedTechniques() const = 0;
    virtual unsigned char getNumTechniques() const = 0;
};

struct MaterialManager {
    static MaterialManager& getSingleton();
    virtual Material* getByName(const String&, const String&) = 0;
};

struct ResourceGroupManager {
    static const String AUTODETECT_RESOURCE_GROUP_NAME;
};

extern "C" void __stdcall G1_00b22f04(void*);
extern "C" void __stdcall G1_00b23104(void*, void*);
extern "C" void* __stdcall G1_00b22eb8();
extern "C" void __stdcall G1_00b226c4(int, void*, void*);
extern "C" void __stdcall G1_00b2263c(void*);
extern "C" void __stdcall G1_00b2396c(void*);
extern "C" unsigned short __stdcall G1_00b23970(void*);

extern int G1_00aa6833;
extern int G1_00b23050;
extern int G1_00b6447c;
extern int G1_00b66d18;

struct OgreGfxClustererPart {
    void __cdecl func_004cd430(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

void OgreGfxClustererPart::func_004cd430(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    int v_ebp_10;
    int v_ebp_30[12];
    int v_ebp_48[14];
    int v_ebp_80[32];
    int v_ebp_100[132];

    G1_00b22f04(v_ebp_30);

    int ebx = a7 ? a7 : a6;
    int eax = ebx - 1;

    if (eax == 0) {
        goto L_004cd69d;
    }
    eax--;
    if (eax == 0) {
        goto L_004cd552;
    }
    eax--;
    if (eax != 0) {
        goto L_004cd73a;
    }

    void* esi = G1_00b22eb8();
    G1_00b226c4(G1_00b66d18, v_ebp_48, v_ebp_80);

    int ecx = G1_00b23050;
    int edx = *(int*)esi;
    void (*func)(int, int, int) = (void(*)(int,int,int))*(int*)(edx + 0x50);
    func(ecx, (int)v_ebp_48, a1 + 0x10);

    MaterialPtr* matPtr = (MaterialPtr*)a1;
    *matPtr = 0;
    char state = 3;
    G1_00b23104(v_ebp_30, matPtr);
    state = 2;

    int v18 = *(int*)(a1 + 0x18);
    *(int*)(a1 + 0x10) = G1_00b6447c;
    if (v18) {
        (*(int*)v18)--;
        if (*(int*)v18 == 0) {
            void (*dtor)(int*) = (void(*)(int*))*(int*)(G1_00b6447c + 4);
            dtor((int*)(a1 + 0x10));
        }
    }

    state = 1;
    G1_00b2263c(v_ebp_80);

    if (*(int*)(a1 + 0x34)) {
        int ecx2 = *(int*)(a1 + 0x34);
        int edx2 = *(int*)ecx2;
        void (*func2)(int, int) = (void(*)(int,int))*(int*)(edx2 + 0x3c);
        state = 4;
        func2(ecx2, 0);

        void* esi2 = (void*)ecx2;
        G1_00b2396c(esi2);
        unsigned short di = G1_00b23970(esi2);
        unsigned short ax = G1_00b23970(esi2);
        if (di == ax) {
            state = 1;
            goto L_004cd77e;
        }
        state = 1;
    }

L_004cd552:
L_004cd69d:
L_004cd73a:
L_004cd77e:
    ;
}
