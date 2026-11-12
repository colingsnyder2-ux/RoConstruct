// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 45% by colin
// roc 2007-08 005e0a60  unit: RBX::VMotorFeature::?$FactoryProduct  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e0a60
//
// 005e0a60  6aff                 push -1
// 005e0a62  68c8527500           push 0x7552c8
// 005e0a67  64a100000000         mov eax, dword ptr fs:[0]
// 005e0a6d  50                   push eax
// 005e0a6e  64892500000000       mov dword ptr fs:[0], esp
// 005e0a75  83ec18               sub esp, 0x18
// 005e0a78  56                   push esi
// 005e0a79  57                   push edi
// 005e0a7a  33ff                 xor edi, edi
// 005e0a7c  8bf1                 mov esi, ecx
// 005e0a7e  897c240c             mov dword ptr [esp + 0xc], edi
// 005e0a82  897c2410             mov dword ptr [esp + 0x10], edi
// 005e0a86  897c2408             mov dword ptr [esp + 8], edi
// 005e0a8a  8d442408             lea eax, [esp + 8]
// 005e0a8e  50                   push eax
// 005e0a8f  8d4e08               lea ecx, [esi + 8]
// 005e0a92  51                   push ecx
// 005e0a93  897c2430             mov dword ptr [esp + 0x30], edi
// 005e0a97  e8949afdff           call 0x5ba530
// 005e0a9c  83c408               add esp, 8
// 005e0a9f  397c240c             cmp dword ptr [esp + 0xc], edi
// 005e0aa3  7e5a                 jle 0x5e0aff
// 005e0aa5  8b5620               mov edx, dword ptr [esi + 0x20]
// 005e0aa8  8b442434             mov eax, dword ptr [esp + 0x34]
// 005e0aac  52                   push edx
// 005e0aad  50                   push eax
// 005e0aae  8d4c2410             lea ecx, [esp + 0x10]
// 005e0ab2  51                   push ecx
// 005e0ab3  8d542420             lea edx, [esp + 0x20]
// 005e0ab7  52                   push edx
// 005e0ab8  e8b30c0000           call 0x5e1770
// 005e0abd  d9442424             fld dword ptr [esp + 0x24]
// 005e0ac1  8b742440             mov esi, dword ptr [esp + 0x40]
// 005e0ac5  8b442418             mov eax, dword ptr [esp + 0x18]
// 005e0ac9  d91e                 fstp dword ptr [esi]
// 005e0acb  d9442428             fld dword ptr [esp + 0x28]
// 005e0acf  50                   push eax
// 005e0ad0  d95e04               fstp dword ptr [esi + 4]
// 005e0ad3  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 005e0adb  d9442430             fld dword ptr [esp + 0x30]
// 005e0adf  d95e08               fstp dword ptr [esi + 8]
// 005e0ae2  e829edf1ff           call 0x4ff810
// 005e0ae7  83c414               add esp, 0x14
// 005e0aea  5f                   pop edi
// 005e0aeb  8bc6                 mov eax, esi
// 005e0aed  5e                   pop esi
// 005e0aee  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005e0af2  64890d00000000       mov dword ptr fs:[0], ecx
// 005e0af9  83c424               add esp, 0x24
// 005e0afc  c20800               ret 8
// 005e0aff  b801000000           mov eax, 1
// 005e0b04  840538d18b00         test byte ptr [0x8bd138], al
// 005e0b0a  751a                 jne 0x5e0b26
// 005e0b0c  d9ee                 fldz 
// 005e0b0e  090538d18b00         or dword ptr [0x8bd138], eax
// 005e0b14  d9152cd18b00         fst dword ptr [0x8bd12c]
// 005e0b1a  d91530d18b00         fst dword ptr [0x8bd130]
// 005e0b20  d91d34d18b00         fstp dword ptr [0x8bd134]
// 005e0b26  8b742430             mov esi, dword ptr [esp + 0x30]
// 005e0b2a  d9052cd18b00         fld dword ptr [0x8bd12c]
// 005e0b30  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005e0b34  d91e                 fstp dword ptr [esi]
// 005e0b36  d90530d18b00         fld dword ptr [0x8bd130]
// 005e0b3c  51                   push ecx
// 005e0b3d  d95e04               fstp dword ptr [esi + 4]
// 005e0b40  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 005e0b48  d90534d18b00         fld dword ptr [0x8bd134]
// 005e0b4e  d95e08               fstp dword ptr [esi + 8]
// 005e0b51  e8baecf1ff           call 0x4ff810
// 005e0b56  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005e0b5a  83c404               add esp, 4

class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    static const Vector3& zero() { static Vector3 v(0.0f, 0.0f, 0.0f); return v; }
};

void __cdecl arrayFree(void* p);

template<class T> class Array {
public:
    T* data;
    int num;
    int numAllocated;
    Array() : num(0), numAllocated(0) { data = 0; }
    ~Array() { arrayFree(data); }
    int size() const { return num; }
};

struct Contact;

void gatherContacts(const void* src, Array<Contact*>& out);
Vector3 averageContacts(const Array<Contact*>& contacts, int arg, int other);

class MotorFeature {
public:
    int pad0[2];
    int contacts;
    int padC[5];
    int field20;
    Vector3 computeValue(int arg) const;
};

Vector3 MotorFeature::computeValue(int arg) const
{
    Array<Contact*> list;
    gatherContacts(&contacts, list);
    if (list.size() > 0) {
        Vector3 answer = averageContacts(list, arg, field20);
        return answer;
    }
    return Vector3::zero();
}
