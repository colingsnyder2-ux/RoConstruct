// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 0043e7e0  unit: Vector3ComponentItem  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043e7e0
// 0043e7e0  6aff                 push -1
// 0043e7e2  68a2ec7300           push 0x73eca2
// 0043e7e7  64a100000000         mov eax, dword ptr fs:[0]
// 0043e7ed  50                   push eax
// 0043e7ee  83ec2c               sub esp, 0x2c
// 0043e7f1  53                   push ebx
// 0043e7f2  56                   push esi
// 0043e7f3  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043e7f8  33c4                 xor eax, esp
// 0043e7fa  50                   push eax
// 0043e7fb  8d442438             lea eax, [esp + 0x38]
// 0043e7ff  64a300000000         mov dword ptr fs:[0], eax
// 0043e805  8bf1                 mov esi, ecx
// 0043e807  d98620010000         fld dword ptr [esi + 0x120]
// 0043e80d  8d44240c             lea eax, [esp + 0xc]
// 0043e811  d95c2410             fstp dword ptr [esp + 0x10]
// 0043e815  50                   push eax
// 0043e816  d98624010000         fld dword ptr [esi + 0x124]
// 0043e81c  d95c2418             fstp dword ptr [esp + 0x18]
// 0043e820  d98628010000         fld dword ptr [esi + 0x128]
// 0043e826  d95c241c             fstp dword ptr [esp + 0x1c]
// 0043e82a  e821a6ffff           call 0x438e50
// 0043e82f  8bc8                 mov ecx, eax
// 0043e831  c744244000000000     mov dword ptr [esp + 0x40], 0
// 0043e839  ff1598dd7700         call dword ptr [0x77dd98]
// 0043e83f  50                   push eax
// 0043e840  8d4c2420             lea ecx, [esp + 0x20]
// 0043e844  ff1598e67700         call dword ptr [0x77e698]
// 0043e84a  8b861c010000         mov eax, dword ptr [esi + 0x11c]
// 0043e850  8d448410             lea eax, [esp + eax*4 + 0x10]
// 0043e854  50                   push eax
// 0043e855  8d4c2420             lea ecx, [esp + 0x20]
// 0043e859  51                   push ecx
// 0043e85a  c644244801           mov byte ptr [esp + 0x48], 1
// 0043e85f  e80c251400           call 0x580d70
// 0043e864  83c408               add esp, 8
// 0043e867  8d4c241c             lea ecx, [esp + 0x1c]
// 0043e86b  8ad8                 mov bl, al
// 0043e86d  c644244000           mov byte ptr [esp + 0x40], 0
// 0043e872  ff15ace67700         call dword ptr [0x77e6ac]
// 0043e878  8d4c240c             lea ecx, [esp + 0xc]
// 0043e87c  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0043e882  84db                 test bl, bl
// 0043e884  8b442448             mov eax, dword ptr [esp + 0x48]
// 0043e888  7413                 je 0x43e89d
// 0043e88a  d9442410             fld dword ptr [esp + 0x10]
// 0043e88e  d918                 fstp dword ptr [eax]
// 0043e890  d9442414             fld dword ptr [esp + 0x14]
// 0043e894  d95804               fstp dword ptr [eax + 4]
// 0043e897  d9442418             fld dword ptr [esp + 0x18]
// 0043e89b  eb17                 jmp 0x43e8b4
// 0043e89d  d98620010000         fld dword ptr [esi + 0x120]
// 0043e8a3  d918                 fstp dword ptr [eax]
// 0043e8a5  d98624010000         fld dword ptr [esi + 0x124]
// 0043e8ab  d95804               fstp dword ptr [eax + 4]
// 0043e8ae  d98628010000         fld dword ptr [esi + 0x128]
// 0043e8b4  d95808               fstp dword ptr [eax + 8]
// 0043e8b7  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0043e8bb  64890d00000000       mov dword ptr fs:[0], ecx
// 0043e8c2  59                   pop ecx
// 0043e8c3  5e                   pop esi
// 0043e8c4  5b                   pop ebx
// 0043e8c5  83c438               add esp, 0x38
// 0043e8c8  c20400               ret 4

struct CStr {
    void* data;
    __declspec(dllimport) operator const char*() const;
    __declspec(dllimport) ~CStr() throw();
};

struct StdString {
    __declspec(dllimport) StdString(const char* s);
    __declspec(dllimport) ~StdString();
    int storage[7];
};

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {}
    float& operator[](int i) { return ((float*)this)[i]; }
};

bool __cdecl fromString(const StdString& text, float& value);

struct Vector3ComponentItem {
    char pad[0x11c];
    int component;
    Vector3 value;

    CStr getText();
    Vector3 parseValue();
};

Vector3 Vector3ComponentItem::parseValue() {
    Vector3 v = value;
    bool ok = fromString((const char*)getText(), v[component]);
    if (ok)
        return v;
    return value;
}
