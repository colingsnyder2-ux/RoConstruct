// from server: 82% by EspClaude
// from server: 59% by colin
// roc 2007-08 005d3420  unit: RBX::Tool  size: 392 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005d3420
//
// 005d3420  83ec4c               sub esp, 0x4c
// 005d3423  53                   push ebx
// 005d3424  56                   push esi
// 005d3425  8bf1                 mov esi, ecx
// 005d3427  8b8ea8010000         mov ecx, dword ptr [esi + 0x1a8]
// 005d342d  33db                 xor ebx, ebx
// 005d342f  85c9                 test ecx, ecx
// 005d3431  57                   push edi
// 005d3432  747b                 je 0x5d34af
// 005d3434  e817c61200           call 0x6ffa50
// 005d3439  85c0                 test eax, eax
// 005d343b  741d                 je 0x5d345a
// 005d343d  8b80bc000000         mov eax, dword ptr [eax + 0xbc]
// 005d3443  53                   push ebx
// 005d3444  68b8c68800           push 0x88c6b8
// 005d3449  684c1f8800           push 0x881f4c
// 005d344e  53                   push ebx
// 005d344f  50                   push eax
// 005d3450  e8e1d80500           call 0x630d36
// 005d3455  83c414               add esp, 0x14
// 005d3458  8bd8                 mov ebx, eax
// 005d345a  8b8ea8010000         mov ecx, dword ptr [esi + 0x1a8]
// 005d3460  6a00                 push 0
// 005d3462  e8c9e1f6ff           call 0x541630
// 005d3467  c786a801000000000000 mov dword ptr [esi + 0x1a8], 0
// 005d3471  8bbeac010000         mov edi, dword ptr [esi + 0x1ac]
// 005d3477  85ff                 test edi, edi
// 005d3479  c786ac01000000000000 mov dword ptr [esi + 0x1ac], 0
// 005d3483  742a                 je 0x5d34af
// 005d3485  8d4704               lea eax, [edi + 4]
// 005d3488  83c9ff               or ecx, 0xffffffff
// 005d348b  f00fc108             lock xadd dword ptr [eax], ecx
// 005d348f  751e                 jne 0x5d34af
// 005d3491  8b17                 mov edx, dword ptr [edi]
// 005d3493  8b4204               mov eax, dword ptr [edx + 4]
// 005d3496  8bcf                 mov ecx, edi
// 005d3498  ffd0                 call eax
// 005d349a  8d4f08               lea ecx, [edi + 8]
// 005d349d  83caff               or edx, 0xffffffff
// 005d34a0  f00fc111             lock xadd dword ptr [ecx], edx
// 005d34a4  7509                 jne 0x5d34af
// 005d34a6  8b07                 mov eax, dword ptr [edi]
// 005d34a8  8b5008               mov edx, dword ptr [eax + 8]
// 005d34ab  8bcf                 mov ecx, edi
// 005d34ad  ffd2                 call edx
// 005d34af  53                   push ebx
// 005d34b0  e8fb21fdff           call 0x5a56b0
// 005d34b5  83c404               add esp, 4
// 005d34b8  85c0                 test eax, eax
// 005d34ba  0f84db000000         je 0x5d359b
// 005d34c0  8b83ec000000         mov eax, dword ptr [ebx + 0xec]
// 005d34c6  8b4808               mov ecx, dword ptr [eax + 8]
// 005d34c9  8b9419ec000000       mov edx, dword ptr [ecx + ebx + 0xec]
// 005d34d0  8b12                 mov edx, dword ptr [edx]
// 005d34d2  8d8c19ec000000       lea ecx, [ecx + ebx + 0xec]
// 005d34d9  8d442428             lea eax, [esp + 0x28]
// 005d34dd  50                   push eax
// 005d34de  ffd2                 call edx
// 005d34e0  d944244c             fld dword ptr [esp + 0x4c]
// 005d34e4  d95c2410             fstp dword ptr [esp + 0x10]
// 005d34e8  6a02                 push 2
// 005d34ea  d9442458             fld dword ptr [esp + 0x58]
// 005d34ee  8d442420             lea eax, [esp + 0x20]
// 005d34f2  d95c241c             fstp dword ptr [esp + 0x1c]
// 005d34f6  50                   push eax
// 005d34f7  d9442458             fld dword ptr [esp + 0x58]
// 005d34fb  8d4c2430             lea ecx, [esp + 0x30]
// 005d34ff  d805fcf27900         fadd dword ptr [0x79f2fc]
// 005d3505  d95c241c             fstp dword ptr [esp + 0x1c]
// 005d3509  d905e8327a00         fld dword ptr [0x7a32e8]
// 005d350f  d95c2414             fstp dword ptr [esp + 0x14]
// 005d3513  e82861f3ff           call 0x509640
// 005d3518  d944240c             fld dword ptr [esp + 0xc]
// 005d351c  8bce                 mov ecx, esi
// 005d351e  d9c0                 fld st(0)
// 005d3520  d808                 fmul dword ptr [eax]
// 005d3522  d94004               fld dword ptr [eax + 4]
// 005d3525  d8ca                 fmul st(2)
// 005d3527  d94008               fld dword ptr [eax + 8]
// 005d352a  decb                 fmulp st(3)
// 005d352c  d905b8347a00         fld dword ptr [0x7a34b8]
// 005d3532  dcca                 fmul st(2), st(0)
// 005d3534  dcc9                 fmul st(1), st(0)
// 005d3536  decb                 fmulp st(3)
// 005d3538  d9c9                 fxch st(1)
// 005d353a  d8442410             fadd dword ptr [esp + 0x10]
// 005d353e  d95c2410             fstp dword ptr [esp + 0x10]
// 005d3542  d8442414             fadd dword ptr [esp + 0x14]
// 005d3546  d95c2414             fstp dword ptr [esp + 0x14]
// 005d354a  d8442418             fadd dword ptr [esp + 0x18]
// 005d354e  d95c2418             fstp dword ptr [esp + 0x18]
// 005d3552  e889e5ffff           call 0x5d1ae0
// 005d3557  8bf8                 mov edi, eax
// 005d3559  85ff                 test edi, edi
// 005d355b  743e                 je 0x5d359b
// 005d355d  d9442410             fld dword ptr [esp + 0x10]
// 005d3561  83ec0c               sub esp, 0xc
// 005d3564  8bc4                 mov eax, esp
// 005d3566  d918                 fstp dword ptr [eax]
// 005d3568  8bcf                 mov ecx, edi
// 005d356a  d9442420             fld dword ptr [esp + 0x20]
// 005d356e  89642418             mov dword ptr [esp + 0x18], esp
// 005d3572  d95804               fstp dword ptr [eax + 4]
// 005d3575  d9442424             fld dword ptr [esp + 0x24]
// 005d3579  d95808               fstp dword ptr [eax + 8]
// 005d357c  e8df78feff           call 0x5bae60
// 005d3581  d9e8                 fld1 
// 005d3583  8d4c2410             lea ecx, [esp + 0x10]
// 005d3587  d9542410             fst dword ptr [esp + 0x10]
// 005d358b  51                   push ecx
// 005d358c  d9542418             fst dword ptr [esp + 0x18]
// 005d3590  8bcf                 mov ecx, edi
// 005d3592  d95c241c             fstp dword ptr [esp + 0x1c]
// 005d3596  e8654afaff           call 0x578000
// 005d359b  8bce                 mov ecx, esi
// 005d359d  5f                   pop edi
// 005d359e  5e                   pop esi
// 005d359f  5b                   pop ebx
// 005d35a0  83c44c               add esp, 0x4c
// 005d35a3  e9e8faffff           jmp 0x5d3090

// roc-flags: /O2 /GS /EHsc /MD /fp:fast
#include <intrin.h>

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {}
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    Vector3 operator+(const Vector3& o) const { return Vector3(x + o.x, y + o.y, z + o.z); }
    Vector3& operator+=(const Vector3& o) { x += o.x; y += o.y; z += o.z; return *this; }
};

struct Matrix3 {
    float m[3][3];
    Vector3 getColumn(int i) const;          // 0x509640 (thiscall, hidden ret + int)
};

struct CoordinateFrame {
    Matrix3 rotation;
    Vector3 translation;                     // +0x24 (read at cf+0x24)
};

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;              // slot 1
    virtual void destroy();                  // slot 2
    long use_count_;                         // +4
    long weak_count_;                        // +8
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    void swap(shared_count& r) { sp_counted_base* tmp = r.pi_; r.pi_ = pi_; pi_ = tmp; }
};

struct Mover;

struct MoverPtr {
    Mover* px;
    shared_count pn;
    MoverPtr() : px(0) {}
    void swap(MoverPtr& o) { Mover* t = px; px = o.px; o.px = t; pn.swap(o.pn); }
    void reset() { MoverPtr().swap(*this); }
    Mover* operator->() const { return px; }
    operator bool() const { return px != 0; }
};

struct SrcBase { virtual ~SrcBase(); };

struct Holder {
    char pad[0xbc];
    SrcBase* object;                         // +0xbc
};

struct Mover {
    Holder* get();                           // 0x6ffa50 (thiscall)
    void detach(int);                        // 0x541630 (thiscall, 1 arg)
};

struct VBase1 { virtual void v(); };
struct VBase2 { virtual CoordinateFrame getCoordinateFrame() const; };   // slot 0
struct NBase : SrcBase { char pad[0xe8]; };                               // size 0xec, vbptr follows at +0xec

struct Target : NBase, virtual VBase1, virtual VBase2 {
};

struct Effect {
    void setPosition(Vector3);               // 0x5bae60 (thiscall, 12-byte by value)
    void setScale(const Vector3&);           // 0x578000 (thiscall)
};

int isValid(Target*);                       // 0x5a56b0 (cdecl)

extern float g_79f2fc;
extern float g_7a32e8;
extern float g_7a34b8;

namespace RBX {
struct Tool {
    char pad[0x1a8];
    MoverPtr mover;                          // +0x1a8 px, +0x1ac pn
    Effect* createEffect();                  // 0x5d1ae0
    void finish();                           // 0x5d3090
    void onUnequipped();
};

void Tool::onUnequipped()
{
    Target* t = 0;
    if (mover) {
        Holder* h = mover->get();
        if (h)
            t = dynamic_cast<Target*>(h->object);
        mover->detach(0);
        mover.reset();
    }
    if (isValid(t)) {
        CoordinateFrame cf = t->getCoordinateFrame();
        Vector3 p = cf.translation + Vector3(0.0f, g_79f2fc, 0.0f);
        float s = g_7a32e8;
        p += cf.rotation.getColumn(2) * s * g_7a34b8;
        Effect* e = createEffect();
        if (e) {
            e->setPosition(p);
            e->setScale(Vector3(1.0f, 1.0f, 1.0f));
        }
    }
    finish();
}
}
