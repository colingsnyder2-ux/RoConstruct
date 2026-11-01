// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060a5e0  unit: RBX::MotorFeature  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060a5e0
//
// 0060a5e0  83ec30               sub esp, 0x30
// 0060a5e3  56                   push esi
// 0060a5e4  8bf1                 mov esi, ecx
// 0060a5e6  8d4c2404             lea ecx, [esp + 4]
// 0060a5ea  e8e1dce6ff           call 0x4782d0
// 0060a5ef  8d442404             lea eax, [esp + 4]
// 0060a5f3  50                   push eax
// 0060a5f4  8d8ed0feffff         lea ecx, [esi - 0x8c]
// 0060a5fa  e891feffff           call 0x60a490
// 0060a5ff  5e                   pop esi
// 0060a600  84c0                 test al, al
// 0060a602  742c                 je 0x60a630
// 0060a604  e877a3f0ff           call 0x514980
// 0060a609  d9051c718200         fld dword ptr [0x82711c]
// 0060a60f  8b542434             mov edx, dword ptr [esp + 0x34]
// 0060a613  50                   push eax
// 0060a614  83ec08               sub esp, 8
// 0060a617  d95c2404             fstp dword ptr [esp + 4]
// 0060a61b  8d4c240c             lea ecx, [esp + 0xc]
// 0060a61f  d9e8                 fld1 
// 0060a621  d91c24               fstp dword ptr [esp]
// 0060a624  6a02                 push 2
// 0060a626  51                   push ecx
// 0060a627  52                   push edx
// 0060a628  e8c3cd0600           call 0x6773f0
// 0060a62d  83c418               add esp, 0x18
// 0060a630  83c430               add esp, 0x30
// 0060a633  c20400               ret 4

struct Matrix {
    float m[9];
};

struct Vector3 {
    float x, y, z;
};

struct Frame {
    Matrix rotation;
    Vector3 translation;
    Frame();
};

struct Owner {
    bool query(Frame& frame);
};

extern const Vector3& getVector();
extern float scale;
extern void draw(void* context, const Frame* frame, int mode,
                 float weight, float scaleValue, const Vector3& vector, int extra);

struct S {
    void f(void* context);
};

void S::f(void* context)
{
    Frame frame;
    if (reinterpret_cast<Owner*>(reinterpret_cast<char*>(this) - 0x8c)->query(frame))
        draw(context, &frame, 2, 1.0f, scale, getVector(), 1);
}
