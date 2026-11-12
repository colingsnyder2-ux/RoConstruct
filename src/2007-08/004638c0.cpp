// from server: 100% by EspClaude
// from server: 47% by colin
// roc 2007-08 004638c0  unit: RBX::VRunService::?$Listener  size: 318 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004638c0
//
// 004638c0  6aff                 push -1
// 004638c2  68582e7400           push 0x742e58
// 004638c7  64a100000000         mov eax, dword ptr fs:[0]
// 004638cd  50                   push eax
// 004638ce  83ec20               sub esp, 0x20
// 004638d1  56                   push esi
// 004638d2  a188518b00           mov eax, dword ptr [0x8b5188]
// 004638d7  33c4                 xor eax, esp
// 004638d9  50                   push eax
// 004638da  8d442428             lea eax, [esp + 0x28]
// 004638de  64a300000000         mov dword ptr fs:[0], eax
// 004638e4  8bf1                 mov esi, ecx
// 004638e6  8d4634               lea eax, [esi + 0x34]
// 004638e9  8d4c2408             lea ecx, [esp + 8]
// 004638ed  89442408             mov dword ptr [esp + 8], eax
// 004638f1  c644240c00           mov byte ptr [esp + 0xc], 0
// 004638f6  e8759ffbff           call 0x41d870
// 004638fb  807e6800             cmp byte ptr [esi + 0x68], 0
// 004638ff  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00463907  7420                 je 0x463929
// 00463909  8b868c010000         mov eax, dword ptr [esi + 0x18c]
// 0046390f  8b08                 mov ecx, dword ptr [eax]
// 00463911  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 00463914  50                   push eax
// 00463915  ffd2                 call edx
// 00463917  85c0                 test eax, eax
// 00463919  7d04                 jge 0x46391f
// 0046391b  c6466800             mov byte ptr [esi + 0x68], 0
// 0046391f  807e6800             cmp byte ptr [esi + 0x68], 0
// 00463923  0f85b0000000         jne 0x4639d9
// 00463929  8b8e80010000         mov ecx, dword ptr [esi + 0x180]
// 0046392f  e8c6d01c00           call 0x6309fa
// 00463934  85c0                 test eax, eax
// 00463936  0f849d000000         je 0x4639d9
// 0046393c  8b868c010000         mov eax, dword ptr [esi + 0x18c]
// 00463942  8b08                 mov ecx, dword ptr [eax]
// 00463944  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00463947  50                   push eax
// 00463948  ffd2                 call edx
// 0046394a  8b868c010000         mov eax, dword ptr [esi + 0x18c]
// 00463950  8b08                 mov ecx, dword ptr [eax]
// 00463952  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 00463955  50                   push eax
// 00463956  ffd2                 call edx
// 00463958  85c0                 test eax, eax
// 0046395a  0f9dc0               setge al
// 0046395d  84c0                 test al, al
// 0046395f  884668               mov byte ptr [esi + 0x68], al
// 00463962  7475                 je 0x4639d9
// 00463964  d94658               fld dword ptr [esi + 0x58]
// 00463967  8b442438             mov eax, dword ptr [esp + 0x38]
// 0046396b  d95c2418             fstp dword ptr [esp + 0x18]
// 0046396f  d9465c               fld dword ptr [esi + 0x5c]
// 00463972  d95c241c             fstp dword ptr [esp + 0x1c]
// 00463976  d94660               fld dword ptr [esi + 0x60]
// 00463979  d95c2420             fstp dword ptr [esp + 0x20]
// 0046397d  d94664               fld dword ptr [esi + 0x64]
// 00463980  d95c2424             fstp dword ptr [esp + 0x24]
// 00463984  d9442420             fld dword ptr [esp + 0x20]
// 00463988  d8442418             fadd dword ptr [esp + 0x18]
// 0046398c  d95c2410             fstp dword ptr [esp + 0x10]
// 00463990  d9442424             fld dword ptr [esp + 0x24]
// 00463994  d844241c             fadd dword ptr [esp + 0x1c]
// 00463998  d95c2414             fstp dword ptr [esp + 0x14]
// 0046399c  d9442410             fld dword ptr [esp + 0x10]
// 004639a0  dd05485b7900         fld qword ptr [0x795b48]
// 004639a6  dcc9                 fmul st(1), st(0)
// 004639a8  d9c9                 fxch st(1)
// 004639aa  d95c2418             fstp dword ptr [esp + 0x18]
// 004639ae  d84c2414             fmul dword ptr [esp + 0x14]
// 004639b2  d95c241c             fstp dword ptr [esp + 0x1c]
// 004639b6  d900                 fld dword ptr [eax]
// 004639b8  d8642418             fsub dword ptr [esp + 0x18]
// 004639bc  d95c2410             fstp dword ptr [esp + 0x10]
// 004639c0  d94004               fld dword ptr [eax + 4]
// 004639c3  d864241c             fsub dword ptr [esp + 0x1c]
// 004639c7  d95c2414             fstp dword ptr [esp + 0x14]
// 004639cb  d9442410             fld dword ptr [esp + 0x10]
// 004639cf  d95e70               fstp dword ptr [esi + 0x70]
// 004639d2  d9442414             fld dword ptr [esp + 0x14]
// 004639d6  d95e74               fstp dword ptr [esi + 0x74]
// 004639d9  807c240c00           cmp byte ptr [esp + 0xc], 0
// 004639de  740b                 je 0x4639eb
// 004639e0  8b442408             mov eax, dword ptr [esp + 8]
// 004639e4  50                   push eax
// 004639e5  ff15f8d27700         call dword ptr [0x77d2f8]
// 004639eb  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004639ef  64890d00000000       mov dword ptr fs:[0], ecx
// 004639f6  59                   pop ecx
// 004639f7  5e                   pop esi
// 004639f8  83c42c               add esp, 0x2c
// 004639fb  c20400               ret 4

struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);

struct ScopedLock
{
    _RTL_CRITICAL_SECTION* m;
    bool locked;

    ScopedLock(_RTL_CRITICAL_SECTION* mutex) : m(mutex), locked(false) { lock(); }
    ~ScopedLock() { if (locked) LeaveCriticalSection(m); }
    void lock();
};

struct Vector2
{
    float x, y;
    Vector2() {}
    Vector2(float _x, float _y) : x(_x), y(_y) {}
    Vector2(const Vector2& o) : x(o.x), y(o.y) {}
    Vector2& operator=(const Vector2& o) { x = o.x; y = o.y; return *this; }
    Vector2 operator+(const Vector2& o) const { return Vector2(x + o.x, y + o.y); }
    Vector2 operator-(const Vector2& o) const { return Vector2(x - o.x, y - o.y); }
};

struct Rect2D
{
    Vector2 min, max;
    Vector2 center() const
    {
        Vector2 s = max + min;
        return Vector2(s.x * 0.5, s.y * 0.5);
    }
};

struct IDevice
{
    virtual long __stdcall f0() = 0;
    virtual long __stdcall f1() = 0;
    virtual long __stdcall f2() = 0;
    virtual long __stdcall f3() = 0;
    virtual long __stdcall f4() = 0;
    virtual long __stdcall f5() = 0;
    virtual long __stdcall f6() = 0;
    virtual long __stdcall Acquire() = 0;
    virtual long __stdcall Unacquire() = 0;
};

struct Window
{
    int isActive();
};

struct Listener
{
    char pad0[0x34];
    _RTL_CRITICAL_SECTION* mutexAt34() { return (_RTL_CRITICAL_SECTION*)((char*)this + 0x34); }
    char pad34[0x24];
    Rect2D rect;
    bool acquired;
    char pad69[7];
    Vector2 position;
    char pad78[0x108];
    Window* window;
    char pad184[8];
    IDevice* device;

    void update(const Vector2& mouse);
};

void Listener::update(const Vector2& mouse)
{
    ScopedLock lock(mutexAt34());
    if (acquired) {
        if (device->Acquire() < 0)
            acquired = false;
        if (acquired)
            return;
    }
    if (window->isActive()) {
        device->Unacquire();
        acquired = device->Acquire() >= 0;
        if (acquired) {
            Rect2D r = rect;
            position = mouse - r.center();
        }
    }
}
