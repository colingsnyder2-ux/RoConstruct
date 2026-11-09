// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 80% by colin
// from server: 73% by king_originala
// roc 2008-06 004dbf00  unit: RBX::ViewNew::ViewG3D  size: 306 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dbf00
//
// 004dbf00  6aff                 push -1
// 004dbf02  6838957d00           push 0x7d9538
// 004dbf07  64a100000000         mov eax, dword ptr fs:[0]
// 004dbf0d  50                   push eax
// 004dbf0e  64892500000000       mov dword ptr fs:[0], esp
// 004dbf15  51                   push ecx
// 004dbf16  53                   push ebx
// 004dbf17  56                   push esi
// 004dbf18  57                   push edi
// 004dbf19  8bf9                 mov edi, ecx
// 004dbf1b  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 004dbf1e  85c9                 test ecx, ecx
// 004dbf20  7409                 je 0x4dbf2b
// 004dbf22  e84979fdff           call 0x4b3870
// 004dbf27  8bf0                 mov esi, eax
// 004dbf29  eb02                 jmp 0x4dbf2d
// 004dbf2b  33f6                 xor esi, esi
// 004dbf2d  d98634020000         fld dword ptr [esi + 0x234]
// 004dbf33  8b5f08               mov ebx, dword ptr [edi + 8]
// 004dbf36  83ec0c               sub esp, 0xc
// 004dbf39  8bc4                 mov eax, esp
// 004dbf3b  d918                 fstp dword ptr [eax]
// 004dbf3d  89642418             mov dword ptr [esp + 0x18], esp
// 004dbf41  d98638020000         fld dword ptr [esi + 0x238]
// 004dbf47  83ec0c               sub esp, 0xc
// 004dbf4a  d95804               fstp dword ptr [eax + 4]
// 004dbf4d  89642424             mov dword ptr [esp + 0x24], esp
// 004dbf51  d9863c020000         fld dword ptr [esi + 0x23c]
// 004dbf57  d95808               fstp dword ptr [eax + 8]
// 004dbf5a  8bc4                 mov eax, esp
// 004dbf5c  d98628020000         fld dword ptr [esi + 0x228]
// 004dbf62  81ecf8000000         sub esp, 0xf8
// 004dbf68  d918                 fstp dword ptr [eax]
// 004dbf6a  8bcc                 mov ecx, esp
// 004dbf6c  d9862c020000         fld dword ptr [esi + 0x22c]
// 004dbf72  89a4241c010000       mov dword ptr [esp + 0x11c], esp
// 004dbf79  d95804               fstp dword ptr [eax + 4]
// 004dbf7c  d98630020000         fld dword ptr [esi + 0x230]
// 004dbf82  d95808               fstp dword ptr [eax + 8]
// 004dbf85  8d8630010000         lea eax, [esi + 0x130]
// 004dbf8b  50                   push eax
// 004dbf8c  e88fb0ffff           call 0x4d7020
// 004dbf91  51                   push ecx
// 004dbf92  8bc4                 mov eax, esp
// 004dbf94  c70000000000         mov dword ptr [eax], 0
// 004dbf9a  8b03                 mov eax, dword ptr [ebx]
// 004dbf9c  8b5004               mov edx, dword ptr [eax + 4]
// 004dbf9f  c784242c01000000000000 mov dword ptr [esp + 0x12c], 0
// 004dbfaa  8bcb                 mov ecx, ebx
// 004dbfac  89a42420010000       mov dword ptr [esp + 0x120], esp
// 004dbfb3  c784242c010000ffffffff mov dword ptr [esp + 0x12c], 0xffffffff
// 004dbfbe  ffd2                 call edx
// 004dbfc0  8b4748               mov eax, dword ptr [edi + 0x48]
// 004dbfc3  85c0                 test eax, eax
// 004dbfc5  742c                 je 0x4dbff3
// 004dbfc7  83c004               add eax, 4
// 004dbfca  50                   push eax
// 004dbfcb  ff15ac218000         call dword ptr [0x8021ac]
// 004dbfd1  85c0                 test eax, eax
// 004dbfd3  7517                 jne 0x4dbfec
// 004dbfd5  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 004dbfd8  e8b3edf7ff           call 0x45ad90
// 004dbfdd  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 004dbfe0  85c9                 test ecx, ecx
// 004dbfe2  7408                 je 0x4dbfec
// 004dbfe4  8b01                 mov eax, dword ptr [ecx]
// 004dbfe6  8b10                 mov edx, dword ptr [eax]
// 004dbfe8  6a01                 push 1
// 004dbfea  ffd2                 call edx
// 004dbfec  c7474800000000       mov dword ptr [edi + 0x48], 0
// 004dbff3  d98644020000         fld dword ptr [esi + 0x244]
// 004dbff9  8b7f08               mov edi, dword ptr [edi + 8]
// 004dbffc  d98648020000         fld dword ptr [esi + 0x248]
// 004dc002  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004dc006  d9864c020000         fld dword ptr [esi + 0x24c]
// 004dc00c  83c714               add edi, 0x14
// 004dc00f  d98650020000         fld dword ptr [esi + 0x250]
// 004dc015  d9cb                 fxch st(3)
// 004dc017  d91f                 fstp dword ptr [edi]
// 004dc019  d9c9                 fxch st(1)
// 004dc01b  d95f04               fstp dword ptr [edi + 4]
// 004dc01e  d95f08               fstp dword ptr [edi + 8]
// 004dc021  d95f0c               fstp dword ptr [edi + 0xc]
// 004dc024  5f                   pop edi
// 004dc025  5e                   pop esi
// 004dc026  64890d00000000       mov dword ptr fs:[0], ecx
// 004dc02d  5b                   pop ebx
// 004dc02e  83c410               add esp, 0x10
// 004dc031  c3                   ret 

extern "C" {
    extern long (__stdcall *InterlockedDecrement)(volatile long *);
}

struct Vector3 {
    float x, y, z;
    Vector3(const Vector3 &);
};

inline Vector3::Vector3(const Vector3 &v)
    : x(v.x), y(v.y), z(v.z) {}

struct Color4 {
    float r, g, b, a;
    Color4(const Color4& v):r(v.r),g(v.g),b(v.b),a(v.a) {}
    Color4 &operator=(const Color4 &);
};

inline Color4 &Color4::operator=(const Color4 &v)
{
    r = v.r;
    g = v.g;
    b = v.b;
    a = v.a;
    return *this;
}

struct StateBlock {
    char data[248];
    StateBlock(const StateBlock &);
    ~StateBlock();
};

struct Handle {
    void *pointer;
    Handle(void* p=0):pointer(p) { if(p) retain(); }
    void retain();
    ~Handle();
    __declspec(dllimport) Handle(const Handle &);
};

struct Renderer {
    virtual void reserved() = 0;
    virtual void configure(Handle, StateBlock, Vector3, Vector3) = 0;
    char padding[16];
    Color4 color;
};

struct Image {
    virtual ~Image();
    volatile long references;
    void release();
};

struct Scene {
    char padding[0x130];
    StateBlock state;
    Vector3 first;
    Vector3 second;
    char gap[4];
    Color4 color;
};

struct Provider {
    Scene *getScene();
};

struct S {
    char padding0[8];
    Renderer *renderer;
    char padding1[8];
    Provider *provider;
    char padding2[0x30];
    Image *image;
    void f();
};

void S::f()
{
    Scene *scene = provider ? provider->getScene() : 0;
    Renderer *target = renderer;

    target->configure(Handle(), scene->state, scene->first, scene->second);

    if (image) {
        if (InterlockedDecrement(&image->references) == 0) {
            image->release();
            if (image)
                delete image;
        }
        image = 0;
    }

    Color4 color = scene->color;
    renderer->color = color;
}
