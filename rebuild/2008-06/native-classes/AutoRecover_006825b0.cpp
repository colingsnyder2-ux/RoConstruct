// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Ogre headers exist under native-headers, so the Ogre types are local stand-ins.
// INFERRED: RenderSystem vtable slots are called by byte offset, via fastcall pointers with a dummy edx.
// INFERRED: the layout of LayerBlendModeEx and the target object comes from the disassembly only.
// This has not been compiled or diffed.

struct Mat4 { float m[16]; };

struct BlendEx {            // INFERRED: 0x3c bytes, ctor is an rgmain import
    int a, b, c;
    char pad[0x3c - 12];
};

struct SizeSource {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned getWidth();
    virtual unsigned getHeight(float a, float b, int c, void* d);
};

struct ViewTarget {
    char pad[0xa];
    bool flag;
    char pad2;
    SizeSource* src;
};

extern "C" void* __stdcall fn_rootGetSingleton();
extern Mat4 g_identity;          // INFERRED: Ogre::Matrix4::IDENTITY
extern const float g_pi;         // INFERRED: Ogre::Math::PI
extern const float g_white[4];   // INFERRED: Ogre::ColourValue::White
extern const float kHalf;        // 0x819bac
extern const float kC8282dc;     // 0x8282dc
extern const float kTwo32;       // 0x819778

typedef void (__fastcall *Fn)(void* o, int edx, ...);

static inline Fn slot(void* o, int off)
{
    return (Fn)*(void**)(*(char**)o + off);
}

extern "C" void* __fastcall fn_rootGetRenderSystem(void* root, int unusedEdx);

static inline float u2f(unsigned v)
{
    return (float)(int)v + ((int)v < 0 ? kTwo32 : 0.0f);
}

extern "C" void __fastcall fn_006825b0(ViewTarget* self, int unusedEdx)
{
    BlendEx blendA;
    BlendEx blendB;
    blendA.a = 0; blendA.b = 0; blendA.c = 1;
    blendB.a = 1; blendB.b = 0; blendB.c = 1;
    int arr[3] = { 2, 2, 2 };

    void* root = fn_rootGetSingleton();
    void* rs = fn_rootGetRenderSystem(root, 0);

    slot(rs, 0x60)(rs, 0, &g_identity);

    Mat4 m = g_identity;
    float fovy;
    float aspect;
    if (self->flag) {
        m.m[5] = kC8282dc;
        m.m[10] = kC8282dc;
        m.m[11] = 0.0f;
        m.m[0] = kHalf;
        m.m[3] = kHalf;
        m.m[12] = 0.0f;
        slot(rs, 0x68)(rs, 0, &m);
        fovy = g_pi * kHalf;
        float w = u2f(self->src->getWidth());
        float h = u2f(self->src->getHeight(1.0f, 0.0f, 0, &blendB));
        aspect = w / h;
    } else {
        float w = u2f(self->src->getHeight(0.0f, 0.0f, 0, 0));
        fovy = w * kHalf;
        self->src->getHeight(0.0f, 0.0f, 0, 0);
        m = g_identity;
        m.m[2] = u2f(self->src->getWidth()) * kC8282dc;
        m.m[3] = u2f(self->src->getHeight(0.0f, 0.0f, 0, 0)) * kC8282dc;
        slot(rs, 0x68)(rs, 0, &m);
        float h = u2f(self->src->getWidth());
        aspect = u2f(self->src->getHeight(h, 0.0f, 0, &blendB));
    }
    slot(rs, 0x11c)(rs, 0, &fovy, aspect);

    slot(rs, 0x6c)(rs, 0, &blendB);
    slot(rs, 0xb8)(rs, 0, 0, &g_identity);
    slot(rs, 0x94)(rs, 0, 0, 0);
    slot(rs, 0x98)(rs, 0, 0, 0, 0);
    slot(rs, 0xa4)(rs, 0, 0, 2, 2, 2);
    slot(rs, 0x9c)(rs, 0, 0, &blendA);
    slot(rs, 0x9c)(rs, 0, 0, &blendB);
    slot(rs, 0xac)(rs, 0, 0, arr);
    slot(rs, 0x78)(rs, 0, 1);
    slot(rs, 0x30)(rs, 0, 0);
    slot(rs, 0xf4)(rs, 0, 0, g_white, 0.0f, 0.0f, 1.0f);
    slot(rs, 0xd4)(rs, 0, 1);
    slot(rs, 0xdc)(rs, 0, 0, 0, 3);
    slot(rs, 0xec)(rs, 0, 1, 1, 1, 0);
    slot(rs, 0x2c)(rs, 0, 1);
    slot(rs, 0x124)(rs, 0, 3);
    slot(rs, 0x14c)(rs, 0, 1);
    slot(rs, 0x14c)(rs, 0, 0);
    slot(rs, 0xbc)(rs, 0, 7, 9);
    slot(rs, 0xc0)(rs, 0, 1, 0);
}
