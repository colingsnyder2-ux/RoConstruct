// from server: 5% by atomic.potato
// roc 2012-06 004ffbf0  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen
// Minimal declarations for the observed imports and helpers.

struct OgreSubMesh;
struct OgreMesh;

struct OgreHardwareIndexBufferSharedPtr {
    void* p;
};

struct OgreHardwareBufferManager {
    static OgreHardwareBufferManager& getSingleton();
};

struct OgreNedPoolingImpl {
    static void* allocBytes(unsigned int, const char*, int, const char*);
};

struct OgreMesh {
    OgreSubMesh* createSubMesh();
};

extern "C" {
    void __stdcall Ogre_HardwareIndexBufferSharedPtr_dtor(OgreHardwareIndexBufferSharedPtr*);
    OgreHardwareIndexBufferSharedPtr* __stdcall Ogre_HardwareIndexBufferSharedPtr_assign(OgreHardwareIndexBufferSharedPtr*, const OgreHardwareIndexBufferSharedPtr*);
}

// Helper functions observed in the target.
void __cdecl sub_4f7d50(void*);
void __cdecl sub_4f96f0(void);
void __cdecl sub_4fe9e0(void);
void __cdecl sub_5ca000(void*, void*, void*, void*, void*);

// Globals referenced.
extern char byte_E31AB8;
extern float flt_B6A1FC;
extern float flt_B6B278;
extern float flt_B62770;
extern char str_B6B27C[];

// The class being reconstructed.
struct UTVertexPositionNormalStudsTex_SpecializedMeshGen {
    char pad0[8];
    void* field8;
    void* fieldC;
    char pad10[0x20];
    char field30[0x30];
    void* method(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h);
};

void* UTVertexPositionNormalStudsTex_SpecializedMeshGen::method(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h)
{
    void* result;
    void* local10;
    float local14;
    float local18;
    float local1C;
    float local20;
    void* local24;
    void* local28;
    void* local2C;
    void* local30;
    void* local34;
    void* local38;
    void* local3C;
    void* local40;
    void* local44;
    void* local48;
    void* local4C;
    void* local50;
    void* local54;
    void* local58;
    void* local5C;

    result = 0;
    local10 = 0;
    local14 = 0.0f;
    local18 = 0.0f;
    local1C = 0.0f;
    local20 = 0.0f;
    local24 = 0;
    local28 = 0;
    local2C = 0;
    local30 = 0;
    local34 = 0;
    local38 = 0;
    local3C = 0;
    local40 = 0;
    local44 = 0;
    local48 = 0;
    local4C = 0;
    local50 = 0;
    local54 = 0;
    local58 = 0;
    local5C = 0;

    if (a != 0) {
        Ogre_HardwareIndexBufferSharedPtr_assign((OgreHardwareIndexBufferSharedPtr*)&local10, (const OgreHardwareIndexBufferSharedPtr*)a);
    } else {
        void* mem = OgreNedPoolingImpl::allocBytes(0xCC, 0, 0, 0);
        local10 = mem;
        local38 = 0;
        if (mem != 0) {
            sub_4f7d50(mem);
        } else {
            mem = 0;
        }
        local38 = (void*)0xFFFFFFFF;
        *(void**)((char*)mem + 0x40) = 0;
    }

    void* p54 = local54;
    void* p48 = local48;
    void* ebp = local10;

    if (byte_E31AB8 != 0) {
        sub_5ca000((void*)(unsigned char)byte_E31AB8, str_B6B27C, local40, p48, p54);
    }

    void* p44 = local44;
    sub_4f96f0();
    *(void**)((char*)ebp + 8) = result;
    *(char*)ebp = 0;

    void* edi = p54;
    edi = (void*)((unsigned int)edi * 3);

    OgreHardwareBufferManager::getSingleton();
    void* edx = *(void**)result;
    edx = *(void**)((char*)edx + 0x24);
    int ecx = 0;
    if (local4C == 0) ecx = 1;
    void* tmp = &local20;
    ((void (__stdcall*)(void*, int, void*, int, int, void*))edx)(result, ecx, edi, 5, 0, tmp);

    void* eax2 = local4C;
    local38 = (void*)1;
    void* edx2 = eax2;
    if (eax2 == 0) edx2 = local50;

    void* ecx2 = local24;
    void* eax3 = *(void**)((char*)ecx2 + 4);
    void* ebx2 = *(void**)ecx2;
    void* eax4 = *(void**)((char*)ebx2 + 0x18);
    ((void (__stdcall*)(int, void*, void*, int))eax4)(0, eax3, edx2, 1);

    void* ecx3 = &local20;
    Ogre_HardwareIndexBufferSharedPtr_assign((OgreHardwareIndexBufferSharedPtr*)&local20, (const OgreHardwareIndexBufferSharedPtr*)&local20);

    void* edx3 = *(void**)((char*)ebp + 0xC);
    float xmm0 = flt_B6A1FC;
    *(void**)((char*)edx3 + 0x14) = edi;
    void* eax5 = *(void**)((char*)ebp + 0xC);
    local14 = xmm0;
    float xmm7 = xmm0;
    float xmm6 = xmm0;
    xmm0 = flt_B6B278;
    int edx4 = 0;
    *(void**)((char*)eax5 + 0x10) = 0;
    float xmm1 = xmm0;
    float xmm2 = xmm0;

    if ((int)p48 >= 4) {
        void* eax6 = local44;
        int ecx4 = (int)p48 - 4;
        ecx4 >>= 2;
        eax6 = (char*)eax6 + 8;
        ecx4++;
        edx4 = ecx4 * 4;
        do {
            float xmm5 = *(float*)((char*)eax6 - 8);
            float xmm3 = local14;
            if (xmm3 > xmm5) local14 = xmm5;
            float xmm4 = *(float*)((char*)eax6 - 4);
            if (xmm7 > xmm4) xmm7 = xmm4;
            xmm3 = *(float*)eax6;
            if (xmm6 > xmm3) xmm6 = xmm3;
            if (xmm5 > xmm0) xmm0 = xmm5;
            if (xmm4 > xmm1) xmm1 = xmm4;
            if (xmm3 > xmm2) xmm2 = xmm3;

            xmm5 = *(float*)((char*)eax6 + 0x28);
            xmm3 = local14;
            if (xmm3 > xmm5) local14 = xmm5;
            xmm4 = *(float*)((char*)eax6 + 0x2C);
            if (xmm7 > xmm4) xmm7 = xmm4;
            xmm3 = *(float*)((char*)eax6 + 0x30);
            if (xmm6 > xmm3) xmm6 = xmm3;
            if (xmm5 > xmm0) xmm0 = xmm5;
            if (xmm4 > xmm1) xmm1 = xmm4;
            if (xmm3 > xmm2) xmm2 = xmm3;

            xmm5 = *(float*)((char*)eax6 + 0x58);
            xmm3 = local14;
            if (xmm3 > xmm5) local14 = xmm5;
            xmm4 = *(float*)((char*)eax6 + 0x5C);
            if (xmm7 > xmm4) xmm7 = xmm4;
            xmm3 = *(float*)((char*)eax6 + 0x60);
            if (xmm6 > xmm3) xmm6 = xmm3;
            if (xmm5 > xmm0) xmm0 = xmm5;
            if (xmm4 > xmm1) xmm1 = xmm4;
            if (xmm3 > xmm2) xmm2 = xmm3;

            xmm5 = *(float*)((char*)eax6 + 0x88);
            xmm3 = local14;
            if (xmm3 > xmm5) local14 = xmm5;
            xmm4 = *(float*)((char*)eax6 + 0x8C);
            if (xmm7 > xmm4) xmm7 = xmm4;
            xmm3 = *(float*)((char*)eax6 + 0x90);
            if (xmm6 > xmm3) xmm6 = xmm3;
            if (xmm5 > xmm0) xmm0 = xmm5;
            if (xmm4 > xmm1) xmm1 = xmm4;
            if (xmm3 > xmm2) xmm2 = xmm3;

            eax6 = (char*)eax6 + 0xC0;
            ecx4--;
        } while (ecx4 != 0);
    }

    if ((unsigned int)edx4 < (unsigned int)p48) {
        void* eax7 = local44;
        int ecx5 = edx4 + edx4 * 2;
        ecx5 <<= 4;
        eax7 = (char*)eax7 + ecx5 + 8;
        int esi2 = (int)p48 - edx4;
        do {
            float xmm5 = *(float*)((char*)eax7 - 8);
            float xmm3 = local14;
            if (xmm3 > xmm5) local14 = xmm5;
            float xmm4 = *(float*)((char*)eax7 - 4);
            if (xmm7 > xmm4) xmm7 = xmm4;
            xmm3 = *(float*)eax7;
            if (xmm6 > xmm3) xmm6 = xmm3;
            if (xmm5 > xmm0) xmm0 = xmm5;
            if (xmm4 > xmm1) xmm1 = xmm4;
            if (xmm3 > xmm2) xmm2 = xmm3;
            eax7 = (char*)eax7 + 0x30;
            esi2--;
        } while (esi2 != 0);
    }

    void* eax8 = local58;
    float xmm3b = local14;
    *(float*)eax8 = xmm3b;
    *(float*)((char*)eax8 + 4) = xmm7;
    *(float*)((char*)eax8 + 8) = xmm6;
    void* eax9 = local5C;
    *(float*)eax9 = xmm0;
    *(float*)((char*)eax9 + 4) = xmm1;
    *(float*)((char*)eax9 + 8) = xmm2;

    xmm0 = xmm0 + xmm3b;
    xmm3b = flt_B62770;
    void* ecx6 = &local14;
    xmm1 = xmm1 + xmm7;
    xmm2 = xmm2 + xmm6;
    xmm0 = xmm0 * xmm3b;
    xmm1 = xmm1 * xmm3b;
    xmm2 = xmm2 * xmm3b;
    void* ecx7 = (char*)ebp + 0x30;
    local18 = xmm0;
    local1C = xmm1;
    local20 = xmm2;
    sub_4fe9e0();

    void* ecx8 = &local20;
    local38 = (void*)0xFFFFFFFF;
    Ogre_HardwareIndexBufferSharedPtr_dtor((OgreHardwareIndexBufferSharedPtr*)&local20);

    void* ecx9 = local30;
    return ebp;
}
