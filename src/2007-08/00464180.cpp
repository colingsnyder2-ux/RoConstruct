// from server: 98% by EspClaude
// from server: 52% by colin
// roc 2007-08 00464180  unit: DxUserInput  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00464180
//
// 00464180  83ec20               sub esp, 0x20
// 00464183  56                   push esi
// 00464184  8bf1                 mov esi, ecx
// 00464186  8d4634               lea eax, [esi + 0x34]
// 00464189  57                   push edi
// 0046418a  8d4c2408             lea ecx, [esp + 8]
// 0046418e  89442408             mov dword ptr [esp + 8], eax
// 00464192  c644240c00           mov byte ptr [esp + 0xc], 0
// 00464197  e8d496fbff           call 0x41d870
// 0046419c  d94658               fld dword ptr [esi + 0x58]
// 0046419f  807c240c00           cmp byte ptr [esp + 0xc], 0
// 004641a4  d95c2418             fstp dword ptr [esp + 0x18]
// 004641a8  d9465c               fld dword ptr [esi + 0x5c]
// 004641ab  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004641af  d95c241c             fstp dword ptr [esp + 0x1c]
// 004641b3  d94660               fld dword ptr [esi + 0x60]
// 004641b6  d95c2420             fstp dword ptr [esp + 0x20]
// 004641ba  d94664               fld dword ptr [esi + 0x64]
// 004641bd  d95c2424             fstp dword ptr [esp + 0x24]
// 004641c1  d9442420             fld dword ptr [esp + 0x20]
// 004641c5  d8442418             fadd dword ptr [esp + 0x18]
// 004641c9  d95c2410             fstp dword ptr [esp + 0x10]
// 004641cd  d9442424             fld dword ptr [esp + 0x24]
// 004641d1  d844241c             fadd dword ptr [esp + 0x1c]
// 004641d5  d95c2414             fstp dword ptr [esp + 0x14]
// 004641d9  d9442410             fld dword ptr [esp + 0x10]
// 004641dd  dd05485b7900         fld qword ptr [0x795b48]
// 004641e3  dcc9                 fmul st(1), st(0)
// 004641e5  d9c9                 fxch st(1)
// 004641e7  d95c2418             fstp dword ptr [esp + 0x18]
// 004641eb  d84c2414             fmul dword ptr [esp + 0x14]
// 004641ef  d95c241c             fstp dword ptr [esp + 0x1c]
// 004641f3  d9442418             fld dword ptr [esp + 0x18]
// 004641f7  d84670               fadd dword ptr [esi + 0x70]
// 004641fa  d91f                 fstp dword ptr [edi]
// 004641fc  d94674               fld dword ptr [esi + 0x74]
// 004641ff  d844241c             fadd dword ptr [esp + 0x1c]
// 00464203  d95f04               fstp dword ptr [edi + 4]
// 00464206  740b                 je 0x464213
// 00464208  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0046420c  51                   push ecx
// 0046420d  ff15f8d27700         call dword ptr [0x77d2f8]
// 00464213  8bc7                 mov eax, edi
// 00464215  5f                   pop edi
// 00464216  5e                   pop esi
// 00464217  83c420               add esp, 0x20
// 0046421a  c20400               ret 4

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *);

struct Vector2 {
    float x, y;
    Vector2() {}
    Vector2(float a, float b) : x(a), y(b) {}
    Vector2(const Vector2 &v) : x(v.x), y(v.y) {}
    Vector2 operator+(const Vector2 &o) const { return Vector2(x + o.x, y + o.y); }
};

struct Rect2D {
    Vector2 lo, hi;
    Vector2 center() const { Vector2 s = hi + lo; return Vector2(s.x * 0.5, s.y * 0.5); }
};

struct ScopedLock {
    void *cs;
    bool locked;
    ScopedLock(void *m) : cs(m), locked(false) { lock(); }
    void lock();
    ~ScopedLock() { if (locked) LeaveCriticalSection(cs); }
};

struct S_func_00464180 {
    char pad0[0x34];
    char m_lock[0x24];
    Rect2D m_rect;
    char pad68[0x8];
    Vector2 m_offset;
    Rect2D getRect() const { return m_rect; }
    Vector2 f();
};

Vector2 S_func_00464180::f()
{
    ScopedLock lock(m_lock);
    Rect2D r = getRect();
    Vector2 c = r.center();
    return Vector2(c.x + m_offset.x, m_offset.y + c.y);
}
