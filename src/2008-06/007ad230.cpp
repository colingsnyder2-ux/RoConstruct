// from server: 100% by colin
// from server: 97% by king_originala
// roc 2008-06 007ad230  unit: RBX::RenderNew::Material::Level  size: 218 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007ad230
//
// 007ad230  6aff                 push -1
// 007ad232  68f6d77e00           push 0x7ed7f6
// 007ad237  64a100000000         mov eax, dword ptr fs:[0]
// 007ad23d  50                   push eax
// 007ad23e  64892500000000       mov dword ptr fs:[0], esp
// 007ad245  51                   push ecx
// 007ad246  56                   push esi
// 007ad247  8bf1                 mov esi, ecx
// 007ad249  89742404             mov dword ptr [esp + 4], esi
// 007ad24d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ad255  c706e44a8700         mov dword ptr [esi], 0x874ae4
// 007ad25b  c6460400             mov byte ptr [esi + 4], 0
// 007ad25f  c7460800000000       mov dword ptr [esi + 8], 0
// 007ad266  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ad26a  8d4e0c               lea ecx, [esi + 0xc]
// 007ad26d  50                   push eax
// 007ad26e  c644241402           mov byte ptr [esp + 0x14], 2
// 007ad273  c70100000000         mov dword ptr [ecx], 0
// 007ad279  e822bddeff           call 0x598fa0
// 007ad27e  d944241c             fld dword ptr [esp + 0x1c]
// 007ad282  d95e10               fstp dword ptr [esi + 0x10]
// 007ad285  6a00                 push 0
// 007ad287  d9442424             fld dword ptr [esp + 0x24]
// 007ad28b  8d4e2c               lea ecx, [esi + 0x2c]
// 007ad28e  d95e14               fstp dword ptr [esi + 0x14]
// 007ad291  c644241403           mov byte ptr [esp + 0x14], 3
// 007ad296  d9442428             fld dword ptr [esp + 0x28]
// 007ad29a  d95e18               fstp dword ptr [esi + 0x18]
// 007ad29d  d944242c             fld dword ptr [esp + 0x2c]
// 007ad2a1  d95e1c               fstp dword ptr [esi + 0x1c]
// 007ad2a4  d9442430             fld dword ptr [esp + 0x30]
// 007ad2a8  d95e20               fstp dword ptr [esi + 0x20]
// 007ad2ab  d9442434             fld dword ptr [esp + 0x34]
// 007ad2af  d95e24               fstp dword ptr [esi + 0x24]
// 007ad2b2  d9442438             fld dword ptr [esp + 0x38]
// 007ad2b6  d95e28               fstp dword ptr [esi + 0x28]
// 007ad2b9  ff15bc438000         call dword ptr [0x8043bc]
// 007ad2bf  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ad2c3  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 007ad2cb  85c0                 test eax, eax
// 007ad2cd  7427                 je 0x7ad2f6
// 007ad2cf  83c004               add eax, 4
// 007ad2d2  50                   push eax
// 007ad2d3  ff15ac218000         call dword ptr [0x8021ac]
// 007ad2d9  85c0                 test eax, eax
// 007ad2db  7519                 jne 0x7ad2f6
// 007ad2dd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007ad2e1  e8aadacaff           call 0x45ad90
// 007ad2e6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007ad2ea  85c9                 test ecx, ecx
// 007ad2ec  7408                 je 0x7ad2f6
// 007ad2ee  8b11                 mov edx, dword ptr [ecx]
// 007ad2f0  8b02                 mov eax, dword ptr [edx]
// 007ad2f2  6a01                 push 1
// 007ad2f4  ffd0                 call eax
// 007ad2f6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007ad2fa  8bc6                 mov eax, esi
// 007ad2fc  5e                   pop esi
// 007ad2fd  64890d00000000       mov dword ptr fs:[0], ecx
// 007ad304  83c410               add esp, 0x10
// 007ad307  c22000               ret 0x20

struct RefObject {
    virtual ~RefObject();
    long references;
    void release();
};

extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);

struct RefPtr {
    RefObject *pointer;

    RefPtr() : pointer(0) {}
    RefPtr(const RefPtr &other) : pointer(0) {
        assign(other.pointer);
    }

    ~RefPtr() {
        if (pointer && InterlockedDecrement(&pointer->references) == 0) {
            pointer->release();
            if (pointer)
                delete pointer;
        }
    }

    void assign(RefObject *);
};

struct MaterialPtr;
typedef void (__thiscall *MaterialConstructor)(MaterialPtr *, void *);
extern MaterialConstructor constructMaterial;

struct MaterialPtr {
    __declspec(dllimport) MaterialPtr(void *material);
    ~MaterialPtr();
    unsigned long storage;
};

struct Base {
    virtual ~Base();
};

struct Level : Base {
    bool enabled;
    RefPtr first;
    RefPtr second;
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
    float g;
    MaterialPtr material;

    Level(RefPtr, float, float, float, float, float, float, float);
    virtual ~Level();
};

Level::Level(RefPtr value, float av, float bv, float cv,
             float dv, float ev, float fv, float gv)
    : enabled(false),
      first(),
      second(value),
      a(av),
      b(bv),
      c(cv),
      d(dv),
      e(ev),
      f(fv),
      g(gv),
      material(0)
{
}
