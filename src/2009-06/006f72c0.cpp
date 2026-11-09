// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// from server: 78% by EspClaude
// roc 2009-06 006f72c0  unit: RBX::GroupDropTool  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f72c0
//
// 006f72c0  6aff                 push -1
// 006f72c2  6802278700           push 0x872702
// 006f72c7  64a100000000         mov eax, dword ptr fs:[0]
// 006f72cd  50                   push eax
// 006f72ce  64892500000000       mov dword ptr fs:[0], esp
// 006f72d5  83ec64               sub esp, 0x64
// 006f72d8  c7042400000000       mov dword ptr [esp], 0
// 006f72df  d9ee                 fldz 
// 006f72e1  55                   push ebp
// 006f72e2  d9542408             fst dword ptr [esp + 8]
// 006f72e6  8b6c2478             mov ebp, dword ptr [esp + 0x78]
// 006f72ea  d954240c             fst dword ptr [esp + 0xc]
// 006f72ee  56                   push esi
// 006f72ef  d95c2414             fstp dword ptr [esp + 0x14]
// 006f72f3  8bf1                 mov esi, ecx
// 006f72f5  8a4614               mov al, byte ptr [esi + 0x14]
// 006f72f8  84c0                 test al, al
// 006f72fa  7475                 je 0x6f7371
// 006f72fc  807e2800             cmp byte ptr [esi + 0x28], 0
// 006f7300  746f                 je 0x6f7371
// 006f7302  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 006f7305  e8c6aefbff           call 0x6b21d0
// 006f730a  84c0                 test al, al
// 006f730c  7463                 je 0x6f7371
// 006f730e  57                   push edi
// 006f730f  e89cb2d8ff           call 0x4825b0
// 006f7314  50                   push eax
// 006f7315  e846e7e6ff           call 0x565a60
// 006f731a  50                   push eax
// 006f731b  8d4c243c             lea ecx, [esp + 0x3c]
// 006f731f  e81c29e9ff           call 0x589c40
// 006f7324  8bf8                 mov edi, eax
// 006f7326  55                   push ebp
// 006f7327  8d442458             lea eax, [esp + 0x58]
// 006f732b  50                   push eax
// 006f732c  8bce                 mov ecx, esi
// 006f732e  c784248000000000000000 mov dword ptr [esp + 0x80], 0
// 006f7339  c744241401000000     mov dword ptr [esp + 0x14], 1
// 006f7341  e8baedfbff           call 0x6b6100
// 006f7346  8d4c2410             lea ecx, [esp + 0x10]
// 006f734a  51                   push ecx
// 006f734b  57                   push edi
// 006f734c  50                   push eax
// 006f734d  c784248400000001000000 mov dword ptr [esp + 0x84], 1
// 006f7358  c744241803000000     mov dword ptr [esp + 0x18], 3
// 006f7360  e83b70f7ff           call 0x66e3a0
// 006f7365  83c40c               add esp, 0xc
// 006f7368  5f                   pop edi
// 006f7369  84c0                 test al, al
// 006f736b  7404                 je 0x6f7371
// 006f736d  b001                 mov al, 1
// 006f736f  eb02                 jmp 0x6f7373
// 006f7371  32c0                 xor al, al
// 006f7373  c7442474ffffffff     mov dword ptr [esp + 0x74], 0xffffffff
// 006f737b  84c0                 test al, al
// 006f737d  0f84ea000000         je 0x6f746d
// 006f7383  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 006f7386  55                   push ebp
// 006f7387  8d542434             lea edx, [esp + 0x34]
// 006f738b  52                   push edx
// 006f738c  e88fb0fbff           call 0x6b2420
// 006f7391  d900                 fld dword ptr [eax]
// 006f7393  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 006f7396  d95c240c             fstp dword ptr [esp + 0xc]
// 006f739a  d94004               fld dword ptr [eax + 4]
// 006f739d  d95c2410             fstp dword ptr [esp + 0x10]
// 006f73a1  d94008               fld dword ptr [eax + 8]
// 006f73a4  d95c2414             fstp dword ptr [esp + 0x14]
// 006f73a8  e8c3acfbff           call 0x6b2070
// 006f73ad  8d44240c             lea eax, [esp + 0xc]
// 006f73b1  50                   push eax
// 006f73b2  8d4c241c             lea ecx, [esp + 0x1c]
// 006f73b6  51                   push ecx
// 006f73b7  e894d0fbff           call 0x6b4450
// 006f73bc  d9442420             fld dword ptr [esp + 0x20]
// 006f73c0  d8662c               fsub dword ptr [esi + 0x2c]
// 006f73c3  8d542438             lea edx, [esp + 0x38]
// 006f73c7  52                   push edx
// 006f73c8  8d442430             lea eax, [esp + 0x30]
// 006f73cc  d95c243c             fstp dword ptr [esp + 0x3c]
// 006f73d0  50                   push eax
// 006f73d1  d944242c             fld dword ptr [esp + 0x2c]
// 006f73d5  d86630               fsub dword ptr [esi + 0x30]
// 006f73d8  d95c2444             fstp dword ptr [esp + 0x44]
// 006f73dc  d9442430             fld dword ptr [esp + 0x30]
// 006f73e0  d86634               fsub dword ptr [esi + 0x34]
// 006f73e3  d95c2448             fstp dword ptr [esp + 0x48]
// 006f73e7  e864d0fbff           call 0x6b4450
// 006f73ec  d9442428             fld dword ptr [esp + 0x28]
// 006f73f0  83c410               add esp, 0x10
// 006f73f3  d95e2c               fstp dword ptr [esi + 0x2c]
// 006f73f6  d944241c             fld dword ptr [esp + 0x1c]
// 006f73fa  d95e30               fstp dword ptr [esi + 0x30]
// 006f73fd  d9442420             fld dword ptr [esp + 0x20]
// 006f7401  d95e34               fstp dword ptr [esi + 0x34]
// 006f7404  f605f8c6a30001       test byte ptr [0xa3c6f8], 1
// 006f740b  751b                 jne 0x6f7428
// 006f740d  d9ee                 fldz 
// 006f740f  830df8c6a30001       or dword ptr [0xa3c6f8], 1
// 006f7416  d915ecc6a300         fst dword ptr [0xa3c6ec]
// 006f741c  d915f0c6a300         fst dword ptr [0xa3c6f0]
// 006f7422  d91df4c6a300         fstp dword ptr [0xa3c6f4]
// 006f7428  d905ecc6a300         fld dword ptr [0xa3c6ec]
// 006f742e  d85c2424             fcomp dword ptr [esp + 0x24]
// 006f7432  dfe0                 fnstsw ax
// 006f7434  f6c444               test ah, 0x44
// 006f7437  7a22                 jp 0x6f745b
// 006f7439  d905f0c6a300         fld dword ptr [0xa3c6f0]
// 006f743f  d85c2428             fcomp dword ptr [esp + 0x28]
// 006f7443  dfe0                 fnstsw ax
// 006f7445  f6c444               test ah, 0x44
// 006f7448  7a11                 jp 0x6f745b
// 006f744a  d905f4c6a300         fld dword ptr [0xa3c6f4]
// 006f7450  d85c242c             fcomp dword ptr [esp + 0x2c]
// 006f7454  dfe0                 fnstsw ax
// 006f7456  f6c444               test ah, 0x44
// 006f7459  7b12                 jnp 0x6f746d
// 006f745b  8d4c2424             lea ecx, [esp + 0x24]
// 006f745f  51                   push ecx
// 006f7460  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 006f7463  8d542448             lea edx, [esp + 0x48]
// 006f7467  52                   push edx
// 006f7468  e873b0fbff           call 0x6b24e0
// 006f746d  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 006f7471  5e                   pop esi
// 006f7472  5d                   pop ebp
// 006f7473  64890d00000000       mov dword ptr fs:[0], ecx
// 006f747a  83c470               add esp, 0x70
// 006f747d  c20400               ret 4

// from server: 100% by colin
// roc 2008-06 0066a7c0  unit: RBX::GroupDragTool  size: 360 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066a7c0
//
// 0066a7c0  6aff                 push -1
// 0066a7c2  6802c57d00           push 0x7dc502
// 0066a7c7  64a100000000         mov eax, dword ptr fs:[0]
// 0066a7cd  50                   push eax
// 0066a7ce  64892500000000       mov dword ptr fs:[0], esp
// 0066a7d5  83ec64               sub esp, 0x64
// 0066a7d8  c7042400000000       mov dword ptr [esp], 0
// 0066a7df  d9ee                 fldz 
// 0066a7e1  55                   push ebp
// 0066a7e2  d9542408             fst dword ptr [esp + 8]
// 0066a7e6  8b6c2478             mov ebp, dword ptr [esp + 0x78]
// 0066a7ea  d954240c             fst dword ptr [esp + 0xc]
// 0066a7ee  56                   push esi
// 0066a7ef  d95c2414             fstp dword ptr [esp + 0x14]
// 0066a7f3  8bf1                 mov esi, ecx
// 0066a7f5  807e1400             cmp byte ptr [esi + 0x14], 0
// 0066a7f9  7475                 je 0x66a870
// 0066a7fb  807e2800             cmp byte ptr [esi + 0x28], 0
// 0066a7ff  746f                 je 0x66a870
// 0066a801  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0066a804  e8d735faff           call 0x60dde0
// 0066a809  84c0                 test al, al
// 0066a80b  7463                 je 0x66a870
// 0066a80d  57                   push edi
// 0066a80e  e88ddae0ff           call 0x4782a0
// 0066a813  50                   push eax
// 0066a814  e8b778e9ff           call 0x5020d0
// 0066a819  50                   push eax
// 0066a81a  8d4c2430             lea ecx, [esp + 0x30]
// 0066a81e  e8bdb1ebff           call 0x5259e0
// 0066a823  8bf8                 mov edi, eax
// 0066a825  55                   push ebp
// 0066a826  8d442458             lea eax, [esp + 0x58]
// 0066a82a  50                   push eax
// 0066a82b  8bce                 mov ecx, esi
// 0066a82d  c784248000000000000000 mov dword ptr [esp + 0x80], 0
// 0066a838  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0066a840  e8fbb4faff           call 0x615d40
// 0066a845  8d4c2410             lea ecx, [esp + 0x10]
// 0066a849  51                   push ecx
// 0066a84a  57                   push edi
// 0066a84b  50                   push eax
// 0066a84c  c784248400000001000000 mov dword ptr [esp + 0x84], 1
// 0066a857  c744241803000000     mov dword ptr [esp + 0x18], 3
// 0066a85f  e81c4bf7ff           call 0x5df380
// 0066a864  83c40c               add esp, 0xc
// 0066a867  5f                   pop edi
// 0066a868  84c0                 test al, al
// 0066a86a  7404                 je 0x66a870
// 0066a86c  b001                 mov al, 1
// 0066a86e  eb02                 jmp 0x66a872
// 0066a870  32c0                 xor al, al
// 0066a872  c7442474ffffffff     mov dword ptr [esp + 0x74], 0xffffffff
// 0066a87a  84c0                 test al, al
// 0066a87c  0f8493000000         je 0x66a915
// 0066a882  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0066a885  55                   push ebp
// 0066a886  8d542428             lea edx, [esp + 0x28]
// 0066a88a  52                   push edx
// 0066a88b  e83036faff           call 0x60dec0
// 0066a890  d900                 fld dword ptr [eax]
// 0066a892  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0066a895  d95c240c             fstp dword ptr [esp + 0xc]
// 0066a899  d94004               fld dword ptr [eax + 4]
// 0066a89c  d95c2410             fstp dword ptr [esp + 0x10]
// 0066a8a0  d94008               fld dword ptr [eax + 8]
// 0066a8a3  d95c2414             fstp dword ptr [esp + 0x14]
// 0066a8a7  e8b434faff           call 0x60dd60
// 0066a8ac  8d44240c             lea eax, [esp + 0xc]
// 0066a8b0  50                   push eax
// 0066a8b1  8d4c241c             lea ecx, [esp + 0x1c]
// 0066a8b5  51                   push ecx
// 0066a8b6  e8e555faff           call 0x60fea0
// 0066a8bb  d9442420             fld dword ptr [esp + 0x20]
// 0066a8bf  d8662c               fsub dword ptr [esi + 0x2c]
// 0066a8c2  8d54242c             lea edx, [esp + 0x2c]
// 0066a8c6  52                   push edx
// 0066a8c7  8d442444             lea eax, [esp + 0x44]
// 0066a8cb  d95c2430             fstp dword ptr [esp + 0x30]
// 0066a8cf  50                   push eax
// 0066a8d0  d944242c             fld dword ptr [esp + 0x2c]
// 0066a8d4  d86630               fsub dword ptr [esi + 0x30]
// 0066a8d7  d95c2438             fstp dword ptr [esp + 0x38]
// 0066a8db  d9442430             fld dword ptr [esp + 0x30]
// 0066a8df  d86634               fsub dword ptr [esi + 0x34]
// 0066a8e2  d95c243c             fstp dword ptr [esp + 0x3c]
// 0066a8e6  e8b555faff           call 0x60fea0
// 0066a8eb  d9442428             fld dword ptr [esp + 0x28]
// 0066a8ef  83c410               add esp, 0x10
// 0066a8f2  d95e2c               fstp dword ptr [esi + 0x2c]
// 0066a8f5  8d4c2438             lea ecx, [esp + 0x38]
// 0066a8f9  d944241c             fld dword ptr [esp + 0x1c]
// 0066a8fd  51                   push ecx
// 0066a8fe  d95e30               fstp dword ptr [esi + 0x30]
// 0066a901  8d542448             lea edx, [esp + 0x48]
// 0066a905  d9442424             fld dword ptr [esp + 0x24]
// 0066a909  52                   push edx
// 0066a90a  d95e34               fstp dword ptr [esi + 0x34]
// 0066a90d  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0066a910  e8eb37faff           call 0x60e100
// 0066a915  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0066a919  5e                   pop esi
// 0066a91a  5d                   pop ebp
// 0066a91b  64890d00000000       mov dword ptr fs:[0], ecx
// 0066a922  83c470               add esp, 0x70
// 0066a925  c20400               ret 4

struct Vector3 {
    float x, y, z;

    Vector3(float, float, float);
    Vector3(const Vector3&);
    Vector3& operator=(const Vector3&);
    bool operator!=(const Vector3& o) const { return x != o.x || y != o.y || z != o.z; }
    static const Vector3& zero() { static Vector3 v(0.0f, 0.0f, 0.0f); return v; }
};

inline Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c) {}

inline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z) {}

inline Vector3& Vector3::operator=(const Vector3& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

extern const Vector3& __cdecl zeroVector();
extern const Vector3& __cdecl unitVector();

struct Plane {
    float data[4];

    Plane(const Vector3&, const Vector3&);
    Plane(const Plane&);
    virtual ~Plane();
};

struct Ray {
    float data[6];

    Ray(const Ray&);
    virtual ~Ray();
};

inline Plane::~Plane() {}
inline Ray::~Ray() {}

extern bool __cdecl intersect(const Ray&, const Plane&, Vector3&);
extern Vector3 __cdecl transformVector(const Vector3&);

struct DragState {
    bool ready();
    Vector3 position(int);
    void generateDataForMovingAssemblyStage();
    Vector3 move(const Vector3&);
};

struct GroupDragTool {
    char padding0[20];
    bool enabled;
    char padding1[7];
    DragState* state;
    char padding2[8];
    bool active;
    char padding3[3];
    Vector3 previous;

    bool isEnabled() const { return enabled; }
    Ray ray(int);
    void update(int);
};

void GroupDragTool::update(int argument)
{
    Vector3 point(0.0f, 0.0f, 0.0f);

    bool hit = isEnabled() && active && state->ready() &&
        intersect(ray(argument), Plane(unitVector(), zeroVector()), point);

    if (hit)
    {
        point = state->position(argument);
        state->generateDataForMovingAssemblyStage();

        Vector3 current = transformVector(point);
        Vector3 displacement = transformVector(
            Vector3(current.x - previous.x,
                    current.y - previous.y,
                    current.z - previous.z));

        previous = current;

        if (displacement != Vector3::zero())
            state->move(displacement);
    }
}
