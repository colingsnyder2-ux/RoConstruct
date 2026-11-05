// from server: 38% by atomic.potato
struct OgreString {
    char pad[0x1c];
};

struct OgreVector3 {
    float x, y, z;
};

struct OgreAxisAlignedBox {
    char pad[0x18];
};

struct OgreStaticGeometry {
    char pad[0x100];
};

struct OgreSceneManager {
    char pad[0x100];
};

struct RbxStaticCluster {
    char pad0[0xd0];
    void* m_p0xd0;
    char pad1[0x18];
    float m_f0xec;
    float m_f0xf0;
    float m_f0xf4;
    char pad2[0x24];
    float m_f0x11c;
    float m_f0x120;
    float m_f0x124;
    char pad3[0x100];
    void* m_p0x118;
    char pad4[0x100];
    void* m_p0x8;
    char pad5[0x100];
    void* m_p0x34;
    char pad6[0x100];
    void* m_p0x40;
    char pad7[0x100];
    void* m_p0xf8;
    char pad8[0x100];
    void* m_p0xd4;
    char pad9[0x100];
    void* m_p0x0;
};

extern "C" {
    void* __stdcall sub_718a38(int);
    void __stdcall sub_719afb(void*);
    void* __stdcall sub_446710(void*, const char*);
    void* __stdcall sub_576580();
    void* __stdcall sub_5765b0();
    void* __stdcall sub_576740(void*, void*, float);
    void __stdcall sub_8a0b8c(void*, void*);
    void __stdcall sub_8a0b88(void*);
    void __stdcall sub_8a0b84(void*, void*);
    void __stdcall sub_8a0b80(void*, void*, float);
    void __stdcall sub_8a0b7c(void*);
    void* __stdcall sub_8a0778(void*, void*);
    void* __stdcall sub_8a0754(void*, int, void*);
    void __stdcall sub_8a0750(void*);
    void __stdcall sub_8a0eb8(void*, int, int, int, void*);
    void __stdcall sub_89e490(void*, int, int);
    void __stdcall sub_89e494(void*, void*);
    void __stdcall sub_89e498(void*);
    void __stdcall sub_89e4c4(void*);
    void __stdcall sub_89e4ec(void*);
    void __stdcall sub_89e50c(void*, void*, void*);
    void __stdcall sub_89e510(void*, const char*, void*);
    void __stdcall sub_89e448(void*, void*, void*);
    void __stdcall sub_89e464(void*, void*);
}

extern int dword_9EA1E4;
extern float flt_8BECF4;
extern float flt_8BAD4C;
extern float flt_8BD044;
extern int dword_A3C640;
extern int dword_A3C690;
extern int dword_A3C68C;
extern void* dword_A3C688;
extern void* dword_8BED14;
extern void* dword_8BECBC;
extern void* dword_8A0834;
extern void* dword_8A0B8C;
extern void* dword_8A0B88;
extern void* dword_8A0B84;
extern void* dword_8A0B80;
extern void* dword_8A0B7C;
extern void* dword_8A0778;
extern void* dword_8A0754;
extern void* dword_8A0750;
extern void* dword_8A0EB8;
extern void* dword_89E490;
extern void* dword_89E494;
extern void* dword_89E498;
extern void* dword_89E4C4;
extern void* dword_89E4EC;
extern void* dword_89E50C;
extern void* dword_89E510;
extern void* dword_89E448;
extern void* dword_89E464;
extern void* dword_894E20;

void __stdcall RbxStaticCluster_ctor(RbxStaticCluster* self, void* sceneManager, OgreString* name)
{
    void* p;
    void* q;
    void* r;
    OgreVector3 v1;
    OgreVector3 v2;
    OgreVector3 v3;
    OgreAxisAlignedBox box;
    OgreStaticGeometry* sg;
    int idx;
    int rem;
    char buf[0x100];

    sub_8a0b8c(self, sceneManager);
    self->m_p0x0 = dword_8BED14;
    self->m_p0xd0 = 0;
    p = sub_718a38(4);
    if (p != 0) {
        *(void**)p = &self->m_p0xd4;
    } else {
        p = 0;
    }
    self->m_p0xd4 = p;
    *(int*)((char*)self + 0xe0) = 0;
    *(int*)((char*)self + 0xe4) = 0;
    *(int*)((char*)self + 0xe8) = 0;
    sub_8a0b88(&self->m_p0xf8);
    sub_89e490(&box, 2, 1);
    self->m_p0x118 = 0;
    idx = dword_9EA1E4;
    dword_9EA1E4 = idx + 1;
    q = sub_446710(&box, "RbxStaticCluster");
    sub_89e4ec(q);
    sub_89e494(&box, &v1);
    sub_89e464(&v1, "Stat");
    sub_89e4c4(&v1);
    r = dword_8A0834;
    self->m_f0xec = *(float*)r;
    self->m_f0xf0 = *(float*)((char*)r + 4);
    self->m_f0xf4 = *(float*)((char*)r + 8);
    v2.x = flt_8BECF4;
    v2.y = flt_8BECF4;
    v2.z = flt_8BECF4;
    sub_8a0b84(&self->m_p0x34, &v2);
    v3.x = flt_8BAD4C;
    sub_8a0b80(&v3, &v2, flt_8BAD4C);
    sub_8a0b84(&self->m_p0x40, &v3);
    if ((dword_A3C690 & 1) == 0) {
        dword_A3C690 |= 1;
        dword_A3C68C = -1;
        dword_A3C688 = dword_8BECBC;
        sub_719afb(dword_894E20);
    }
    q = sub_8a0778(&dword_A3C688, (void*)1);
    sub_8a0b7c(q);
    p = sub_576580();
    q = sub_5765b0();
    v1.x = *(float*)p + *(float*)q;
    v1.y = *(float*)((char*)p + 4) + *(float*)((char*)q + 4);
    v1.z = *(float*)((char*)p + 8) + *(float*)((char*)q + 8);
    r = sub_576740(&v1, &v2, flt_8BD044);
    self->m_f0x11c = *(float*)r;
    self->m_f0x120 = *(float*)((char*)r + 4);
    self->m_f0x124 = *(float*)((char*)r + 8);
    idx = dword_A3C640;
    rem = idx % 10;
    dword_A3C640 = idx + 1;
    if (rem == 0) {
        sub_8a0eb8(buf, 0x20, 0, idx, 0);
        sub_89e510(&v1, "RandomColor_", &self->m_p0x8);
        sub_89e448(&v2, &v1, " total=");
        sub_89e50c(&v3, &v2, buf);
        q = sub_8a0754(&v3, 2, 0);
        sub_8a0750(q);
        sub_89e4c4(&v3);
        sub_89e4c4(&v2);
        sub_89e4c4(&v1);
        sub_89e4c4(&box);
    }
    sub_89e498(&box);
}
