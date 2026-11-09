// from server: 100% by EspClaude
// roc 2009-06 006b1550  unit: RBX::BallBallContact  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b1550
//
// 006b1550  6aff                 push -1
// 006b1552  68b3038700           push 0x8703b3
// 006b1557  64a100000000         mov eax, dword ptr fs:[0]
// 006b155d  50                   push eax
// 006b155e  64892500000000       mov dword ptr fs:[0], esp
// 006b1565  51                   push ecx
// 006b1566  8b442418             mov eax, dword ptr [esp + 0x18]
// 006b156a  56                   push esi
// 006b156b  8bf1                 mov esi, ecx
// 006b156d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006b1571  50                   push eax
// 006b1572  51                   push ecx
// 006b1573  8bce                 mov ecx, esi
// 006b1575  e846d9ffff           call 0x6aeec0
// 006b157a  33c0                 xor eax, eax
// 006b157c  c70634ab8e00         mov dword ptr [esi], 0x8eab34
// 006b1582  894638               mov dword ptr [esi + 0x38], eax
// 006b1585  89463c               mov dword ptr [esi + 0x3c], eax
// 006b1588  894634               mov dword ptr [esi + 0x34], eax
// 006b158b  d90530f28b00         fld dword ptr [0x8bf230]
// 006b1591  894644               mov dword ptr [esi + 0x44], eax
// 006b1594  894648               mov dword ptr [esi + 0x48], eax
// 006b1597  894640               mov dword ptr [esi + 0x40], eax
// 006b159a  d95e54               fstp dword ptr [esi + 0x54]
// 006b159d  83c9ff               or ecx, 0xffffffff
// 006b15a0  894e64               mov dword ptr [esi + 0x64], ecx
// 006b15a3  894e68               mov dword ptr [esi + 0x68], ecx
// 006b15a6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006b15aa  894658               mov dword ptr [esi + 0x58], eax
// 006b15ad  894660               mov dword ptr [esi + 0x60], eax
// 006b15b0  89464c               mov dword ptr [esi + 0x4c], eax
// 006b15b3  894650               mov dword ptr [esi + 0x50], eax
// 006b15b6  8bc6                 mov eax, esi
// 006b15b8  5e                   pop esi
// 006b15b9  64890d00000000       mov dword ptr fs:[0], ecx
// 006b15c0  83c410               add esp, 0x10
// 006b15c3  c20800               ret 8
// copied from an identical function in another client (function ??0BlockBlockContact@RBX@@QAE@PAVPrimitive@1@0@Z)

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
namespace G3D {
template <class T>
class Array {
private:
    T* data;
    int num;
    int numAllocated;
    void resize(int n);
    void init(int n, int a) {
        this->num = 0;
        this->numAllocated = 0;
        data = 0;
        if (a > 0) {
            resize(n);
        } else {
            data = 0;
        }
    }
public:
    Array() { init(0, 0); }
    ~Array();
};
}
namespace RBX {
class Primitive;
class ContactConnector;
class Contact
{
public:
    Contact(Primitive* p0, Primitive* p1);
    virtual ~Contact();
    char pad[0x34 - 4];
};
class BlockBlockContact : public Contact
{
public:
    BlockBlockContact(Primitive* p0, Primitive* p1);
    virtual ~BlockBlockContact();
private:
    G3D::Array<ContactConnector*> connectors; // 0x34
    G3D::Array<ContactConnector*> matched;    // 0x40
    int unk4c;                                // 0x4c
    int unk50;                                // 0x50
    float overlap;                            // 0x54
    int separatingAxisId;                     // 0x58
    int separatingBodyId;                     // 0x5c
    int bodyId;                               // 0x60
    int feature[2];                           // 0x64
};
BlockBlockContact::BlockBlockContact(Primitive* p0, Primitive* p1)
    : Contact(p0, p1), overlap(1e9f), separatingAxisId(0), bodyId(0)
{
    feature[0] = -1;
    feature[1] = -1;
    unk4c = 0;
    unk50 = 0;
}
}