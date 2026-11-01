// from server: 100% by colin
// from server: 94% by king_originala
// roc 2008-06 00645060  unit: RBX::HUMAN::Climbing  size: 350 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00645060
//
// 00645060  83ec68               sub esp, 0x68
// 00645063  56                   push esi
// 00645064  8bf1                 mov esi, ecx
// 00645066  807e1000             cmp byte ptr [esi + 0x10], 0
// 0064506a  0f8447010000         je 0x6451b7
// 00645070  8b4608               mov eax, dword ptr [esi + 8]
// 00645073  6a01                 push 1
// 00645075  50                   push eax
// 00645076  e8350ee5ff           call 0x495eb0
// 0064507b  83c408               add esp, 8
// 0064507e  84c0                 test al, al
// 00645080  0f8431010000         je 0x6451b7
// 00645086  57                   push edi
// 00645087  8b7c2474             mov edi, dword ptr [esp + 0x74]
// 0064508b  57                   push edi
// 0064508c  8bce                 mov ecx, esi
// 0064508e  e8edfbffff           call 0x644c80
// 00645093  837e2400             cmp dword ptr [esi + 0x24], 0
// 00645097  0f8482000000         je 0x64511f
// 0064509d  e8bef9ecff           call 0x514a60
// 006450a2  d900                 fld dword ptr [eax]
// 006450a4  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 006450a7  d95c2410             fstp dword ptr [esp + 0x10]
// 006450ab  d94004               fld dword ptr [eax + 4]
// 006450ae  8d542410             lea edx, [esp + 0x10]
// 006450b2  d95c2414             fstp dword ptr [esp + 0x14]
// 006450b6  52                   push edx
// 006450b7  d94008               fld dword ptr [eax + 8]
// 006450ba  57                   push edi
// 006450bb  d95c2420             fstp dword ptr [esp + 0x20]
// 006450bf  d9e8                 fld1 
// 006450c1  d95c2424             fstp dword ptr [esp + 0x24]
// 006450c5  e8c659f5ff           call 0x59aa90
// 006450ca  50                   push eax
// 006450cb  e8301d0300           call 0x676e00
// 006450d0  83c40c               add esp, 0xc
// 006450d3  e848edecff           call 0x513e20
// 006450d8  50                   push eax
// 006450d9  8d4c2444             lea ecx, [esp + 0x44]
// 006450dd  e83ee1ecff           call 0x513220
// 006450e2  d9462c               fld dword ptr [esi + 0x2c]
// 006450e5  d95c2464             fstp dword ptr [esp + 0x64]
// 006450e9  d94630               fld dword ptr [esi + 0x30]
// 006450ec  d95c2468             fstp dword ptr [esp + 0x68]
// 006450f0  d94634               fld dword ptr [esi + 0x34]
// 006450f3  d95c246c             fstp dword ptr [esp + 0x6c]
// 006450f7  e864f9ecff           call 0x514a60
// 006450fc  d9e8                 fld1 
// 006450fe  50                   push eax
// 006450ff  83ec08               sub esp, 8
// 00645102  d95c2404             fstp dword ptr [esp + 4]
// 00645106  d905f8498200         fld dword ptr [0x8249f8]
// 0064510c  8d44244c             lea eax, [esp + 0x4c]
// 00645110  d91c24               fstp dword ptr [esp]
// 00645113  6a01                 push 1
// 00645115  50                   push eax
// 00645116  57                   push edi
// 00645117  e8d4220300           call 0x6773f0
// 0064511c  83c418               add esp, 0x18
// 0064511f  8b4e08               mov ecx, dword ptr [esi + 8]
// 00645122  e8e938f9ff           call 0x5d8a10
// 00645127  85c0                 test eax, eax
// 00645129  0f8487000000         je 0x6451b6
// 0064512f  e8bcf8ecff           call 0x5149f0
// 00645134  d900                 fld dword ptr [eax]
// 00645136  d95c2420             fstp dword ptr [esp + 0x20]
// 0064513a  d94004               fld dword ptr [eax + 4]
// 0064513d  d95c2424             fstp dword ptr [esp + 0x24]
// 00645141  d94008               fld dword ptr [eax + 8]
// 00645144  d95c2428             fstp dword ptr [esp + 0x28]
// 00645148  d9e8                 fld1 
// 0064514a  d95c242c             fstp dword ptr [esp + 0x2c]
// 0064514e  e80df9ecff           call 0x514a60
// 00645153  d900                 fld dword ptr [eax]
// 00645155  8b16                 mov edx, dword ptr [esi]
// 00645157  d95c2430             fstp dword ptr [esp + 0x30]
// 0064515b  d94004               fld dword ptr [eax + 4]
// 0064515e  8bce                 mov ecx, esi
// 00645160  d95c2434             fstp dword ptr [esp + 0x34]
// 00645164  d94008               fld dword ptr [eax + 8]
// 00645167  8b02                 mov eax, dword ptr [edx]
// 00645169  d95c2438             fstp dword ptr [esp + 0x38]
// 0064516d  d9e8                 fld1 
// 0064516f  d95c243c             fstp dword ptr [esp + 0x3c]
// 00645173  d905a4638100         fld dword ptr [0x8163a4]
// 00645179  d9542408             fst dword ptr [esp + 8]
// 0064517d  d95c240c             fstp dword ptr [esp + 0xc]
// 00645181  ffd0                 call eax
// 00645183  dd0528ad8400         fld qword ptr [0x84ad28]
// 00645189  8b17                 mov edx, dword ptr [edi]
// 0064518b  8b5234               mov edx, dword ptr [edx + 0x34]
// 0064518e  6a00                 push 0
// 00645190  6a03                 push 3
// 00645192  6a01                 push 1
// 00645194  8d4c242c             lea ecx, [esp + 0x2c]
// 00645198  51                   push ecx
// 00645199  8d4c2440             lea ecx, [esp + 0x40]
// 0064519d  51                   push ecx
// 0064519e  83ec08               sub esp, 8
// 006451a1  dd1c24               fstp qword ptr [esp]
// 006451a4  8d4c2424             lea ecx, [esp + 0x24]
// 006451a8  51                   push ecx
// 006451a9  83c004               add eax, 4
// 006451ac  50                   push eax
// 006451ad  8d442434             lea eax, [esp + 0x34]
// 006451b1  50                   push eax
// 006451b2  8bcf                 mov ecx, edi
// 006451b4  ffd2                 call edx
// 006451b6  5f                   pop edi
// 006451b7  5e                   pop esi
// 006451b8  83c468               add esp, 0x68
// 006451bb  c20400               ret 4

struct Vector2
{
    float x, y;
};

struct Vector3
{
    float x, y, z;
};

struct Color4
{
    float x, y, z, w;
    Color4(const Vector3&);
};

inline Color4::Color4(const Vector3& v)
    : x(v.x), y(v.y), z(v.z), w(1.0f)
{
}

struct Matrix3
{
    float m[9];
};

struct Frame
{
    Matrix3 rotation;
    Vector3 position;
    Frame(const Matrix3&);
};

struct Part
{
    void* updatePV();
};

struct Human
{
    void* getPart();
};

struct Render
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void draw(Vector3*, const void*, const Vector2*, double,
                      const Color4*, const Color4*, int, int, int);
};

extern "C" bool __cdecl checkHuman(Human*, int);
extern "C" const Vector3& __cdecl getZero();
extern "C" const Vector3& __cdecl getOne();
extern "C" const Matrix3& __cdecl getIdentity();
extern "C" void __cdecl drawPart(void*, Render*, const Color4*);
extern "C" void __cdecl drawFrame(Render*, const Frame*, int, float,
                                float, const Vector3*);

extern const float scaleValue;
extern const float drawValue;
extern const double lineValue;

struct S
{
    virtual const unsigned char* getGeometry();
    unsigned char pad04[4];
    Human* human;
    unsigned char pad0c[4];
    bool enabled;
    unsigned char pad11[19];
    Part* part;
    unsigned char pad28[4];
    Vector3 position;

    void prepare(Render*);
    void f(Render*);
};

void S::f(Render* render)
{
    if (enabled && checkHuman(human, 1))
    {
        prepare(render);
        if (part)
        {
            Color4 color(getOne());
            Part* p = part;
            drawPart(p->updatePV(), render, &color);

            Frame frame(getIdentity());
            frame.position.x = position.x;
            frame.position.y = position.y;
            frame.position.z = position.z;
            drawFrame(render, &frame, 1, scaleValue, 1.0f, &getOne());
        }

        if (human->getPart())
        {
            Color4 color1(getZero());
            Color4 color2(getOne());
            Vector2 width;
            width.x = drawValue;
            width.y = drawValue;
            Vector3 result;
            const unsigned char* geometry = getGeometry();
            render->draw(&result, geometry + 4, &width, lineValue,
                         &color2, &color1, 1, 3, 0);
        }
    }
}
