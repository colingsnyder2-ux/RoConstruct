// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 004fa340  unit: G3D::Lighting  size: 437 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004fa340
//
// 004fa340  6aff                 push -1
// 004fa342  6873e37400           push 0x74e373
// 004fa347  64a100000000         mov eax, dword ptr fs:[0]
// 004fa34d  50                   push eax
// 004fa34e  83ec08               sub esp, 8
// 004fa351  53                   push ebx
// 004fa352  55                   push ebp
// 004fa353  56                   push esi
// 004fa354  57                   push edi
// 004fa355  a188518b00           mov eax, dword ptr [0x8b5188]
// 004fa35a  33c4                 xor eax, esp
// 004fa35c  50                   push eax
// 004fa35d  8d44241c             lea eax, [esp + 0x1c]
// 004fa361  64a300000000         mov dword ptr fs:[0], eax
// 004fa367  8bf1                 mov esi, ecx
// 004fa369  89742418             mov dword ptr [esp + 0x18], esi
// 004fa36d  33db                 xor ebx, ebx
// 004fa36f  895e04               mov dword ptr [esi + 4], ebx
// 004fa372  895e08               mov dword ptr [esi + 8], ebx
// 004fa375  891e                 mov dword ptr [esi], ebx
// 004fa377  895c2424             mov dword ptr [esp + 0x24], ebx
// 004fa37b  895e10               mov dword ptr [esi + 0x10], ebx
// 004fa37e  895e14               mov dword ptr [esi + 0x14], ebx
// 004fa381  895e0c               mov dword ptr [esi + 0xc], ebx
// 004fa384  895e1c               mov dword ptr [esi + 0x1c], ebx
// 004fa387  895e20               mov dword ptr [esi + 0x20], ebx
// 004fa38a  895e18               mov dword ptr [esi + 0x18], ebx
// 004fa38d  895e28               mov dword ptr [esi + 0x28], ebx
// 004fa390  895e2c               mov dword ptr [esi + 0x2c], ebx
// 004fa393  895e24               mov dword ptr [esi + 0x24], ebx
// 004fa396  895e34               mov dword ptr [esi + 0x34], ebx
// 004fa399  895e38               mov dword ptr [esi + 0x38], ebx
// 004fa39c  895e30               mov dword ptr [esi + 0x30], ebx
// 004fa39f  895e40               mov dword ptr [esi + 0x40], ebx
// 004fa3a2  895e44               mov dword ptr [esi + 0x44], ebx
// 004fa3a5  895e3c               mov dword ptr [esi + 0x3c], ebx
// 004fa3a8  8d4e48               lea ecx, [esi + 0x48]
// 004fa3ab  c644242405           mov byte ptr [esp + 0x24], 5
// 004fa3b0  e8abc0f8ff           call 0x486460
// 004fa3b5  895e68               mov dword ptr [esi + 0x68], ebx
// 004fa3b8  8dae80000000         lea ebp, [esi + 0x80]
// 004fa3be  895d00               mov dword ptr [ebp], ebx
// 004fa3c1  8dbe84000000         lea edi, [esi + 0x84]
// 004fa3c7  891f                 mov dword ptr [edi], ebx
// 004fa3c9  d9056c647900         fld dword ptr [0x79646c]
// 004fa3cf  d99688000000         fst dword ptr [esi + 0x88]
// 004fa3d5  889e90000000         mov byte ptr [esi + 0x90], bl
// 004fa3db  d99e8c000000         fstp dword ptr [esi + 0x8c]
// 004fa3e1  f60508d18b0001       test byte ptr [0x8bd108], 1
// 004fa3e8  7514                 jne 0x4fa3fe
// 004fa3ea  a164e57700           mov eax, dword ptr [0x77e564]
// 004fa3ef  830d08d18b0001       or dword ptr [0x8bd108], 1
// 004fa3f6  dd00                 fld qword ptr [eax]
// 004fa3f8  dd1d00d18b00         fstp qword ptr [0x8bd100]
// 004fa3fe  dd0500d18b00         fld qword ptr [0x8bd100]
// 004fa404  d99e94000000         fstp dword ptr [esi + 0x94]
// 004fa40a  899e9c000000         mov dword ptr [esi + 0x9c], ebx
// 004fa410  899ea0000000         mov dword ptr [esi + 0xa0], ebx
// 004fa416  899e98000000         mov dword ptr [esi + 0x98], ebx
// 004fa41c  899ea8000000         mov dword ptr [esi + 0xa8], ebx
// 004fa422  899eac000000         mov dword ptr [esi + 0xac], ebx
// 004fa428  899ea4000000         mov dword ptr [esi + 0xa4], ebx
// 004fa42e  8d8eb0000000         lea ecx, [esi + 0xb0]
// 004fa434  c64424240b           mov byte ptr [esp + 0x24], 0xb
// 004fa439  e882d0ffff           call 0x4f74c0
// 004fa43e  889ee8020000         mov byte ptr [esi + 0x2e8], bl
// 004fa444  899eec020000         mov dword ptr [esi + 0x2ec], ebx
// 004fa44a  d9059c7e7900         fld dword ptr [0x797e9c]
// 004fa450  d996f0020000         fst dword ptr [esi + 0x2f0]
// 004fa456  8d8e00030000         lea ecx, [esi + 0x300]
// 004fa45c  d99ef4020000         fstp dword ptr [esi + 0x2f4]
// 004fa462  c64424240c           mov byte ptr [esp + 0x24], 0xc
// 004fa467  d9e8                 fld1 
// 004fa469  d996f8020000         fst dword ptr [esi + 0x2f8]
// 004fa46f  d99efc020000         fstp dword ptr [esi + 0x2fc]
// 004fa475  e8f6bb2300           call 0x736070
// 004fa47a  8d8ef8030000         lea ecx, [esi + 0x3f8]
// 004fa480  e8ebbb2300           call 0x736070
// 004fa485  8d4c2414             lea ecx, [esp + 0x14]
// 004fa489  51                   push ecx
// 004fa48a  e811ebffff           call 0x4f8fa0
// 004fa48f  83c404               add esp, 4
// 004fa492  8b10                 mov edx, dword ptr [eax]
// 004fa494  52                   push edx
// 004fa495  8bcf                 mov ecx, edi
// 004fa497  c64424280d           mov byte ptr [esp + 0x28], 0xd
// 004fa49c  e8cfaaf7ff           call 0x474f70
// 004fa4a1  8b07                 mov eax, dword ptr [edi]
// 004fa4a3  50                   push eax
// 004fa4a4  8bcd                 mov ecx, ebp
// 004fa4a6  e8c5aaf7ff           call 0x474f70
// 004fa4ab  8b442414             mov eax, dword ptr [esp + 0x14]
// 004fa4af  3bc3                 cmp eax, ebx
// 004fa4b1  c64424240c           mov byte ptr [esp + 0x24], 0xc
// 004fa4b6  7427                 je 0x4fa4df
// 004fa4b8  83c004               add eax, 4
// 004fa4bb  50                   push eax
// 004fa4bc  ff15e8d27700         call dword ptr [0x77d2e8]
// 004fa4c2  85c0                 test eax, eax
// 004fa4c4  7519                 jne 0x4fa4df
// 004fa4c6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004fa4ca  e801d9f5ff           call 0x457dd0
// 004fa4cf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004fa4d3  3bcb                 cmp ecx, ebx
// 004fa4d5  7408                 je 0x4fa4df
// 004fa4d7  8b11                 mov edx, dword ptr [ecx]
// 004fa4d9  8b02                 mov eax, dword ptr [edx]
// 004fa4db  6a01                 push 1
// 004fa4dd  ffd0                 call eax
// 004fa4df  8bc6                 mov eax, esi
// 004fa4e1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004fa4e5  64890d00000000       mov dword ptr fs:[0], ecx
// 004fa4ec  59                   pop ecx
// 004fa4ed  5f                   pop edi
// 004fa4ee  5e                   pop esi
// 004fa4ef  5d                   pop ebp
// 004fa4f0  5b                   pop ebx
// 004fa4f1  83c414               add esp, 0x14
// 004fa4f4  c3                   ret 

#include <limits>

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile *);

namespace G3D {

inline double inf() {
    static const double i = std::numeric_limits<double>::infinity();
    return i;
}

class ReferenceCountedObject {
public:
    long ReferenceCountedObject_refCount;
    void ReferenceCountedObject_zeroWeakPointers();
    virtual ~ReferenceCountedObject();
};

template <class T>
class ReferenceCountedPointer {
public:
    T *m_pointer;
    ReferenceCountedPointer() : m_pointer(0) {}
    void setPointer(T *x);
    ReferenceCountedPointer &operator=(const ReferenceCountedPointer &r) { setPointer(r.m_pointer); return *this; }
    void zeroPointer() {
        if (m_pointer != 0) {
            if (InterlockedDecrement(&m_pointer->ReferenceCountedObject_refCount) == 0) {
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }
            m_pointer = 0;
        }
    }
    ~ReferenceCountedPointer() { zeroPointer(); }
};

typedef ReferenceCountedPointer<ReferenceCountedObject> Ref;

void freeBlock(void *p);

template <class T>
class Buffer {
public:
    T *first;
    T *last;
    T *end;
    Buffer() { last = 0; end = 0; first = 0; }
    ~Buffer() { freeBlock(first); first = 0; last = 0; end = 0; }
};

class A12 { public: int a, b, c; A12() { b = 0; c = 0; a = 0; } ~A12(); };
class B12 { public: int a, b, c; B12() { b = 0; c = 0; a = 0; } ~B12(); };

class S48 { public: Ref p; int rest[7]; S48(); };
class SB0 { public: int d[142]; SB0(); };
class S300 { public: int d[62]; S300(); };

Ref makeRef();

class Lighting {
public:
    A12 m0;
    Buffer<int> mc;
    Buffer<int> m18;
    Buffer<int> m24;
    A12 m30;
    B12 m3c;
    S48 m48;
    Ref m68;
    int pad6c[5];
    Ref m80;
    Ref m84;
    float f88;
    float f8c;
    bool b90;
    float f94;
    B12 m98;
    Buffer<int> ma4;
    SB0 mb0;
    bool b2e8;
    Ref m2ec;
    float f2f0;
    float f2f4;
    float f2f8;
    float f2fc;
    S300 m300;
    S300 m3f8;
    Lighting();
};

Lighting::Lighting() :
    f88(-1.0f), f8c(-1.0f), b90(false), f94((float)inf()),
    b2e8(false), f2f0(0.5f), f2f4(0.5f), f2f8(1.0f), f2fc(1.0f)
{
    m80 = m84 = makeRef();
}

}
