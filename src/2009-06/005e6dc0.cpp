// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e850  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e850
//
// 0056e850  83ec0c               sub esp, 0xc
// 0056e853  55                   push ebp
// 0056e854  56                   push esi
// 0056e855  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0056e859  8be9                 mov ebp, ecx
// 0056e85b  8bce                 mov ecx, esi
// 0056e85d  e8aedf0000           call 0x57c810
// 0056e862  84c0                 test al, al
// 0056e864  0f8580000000         jne 0x56e8ea
// 0056e86a  a134539700           mov eax, dword ptr [0x975334]
// 0056e86f  53                   push ebx
// 0056e870  50                   push eax
// 0056e871  8bce                 mov ecx, esi
// 0056e873  e8b8d90000           call 0x57c230
// 0056e878  8bd8                 mov ebx, eax
// 0056e87a  85db                 test ebx, ebx
// 0056e87c  746b                 je 0x56e8e9
// 0056e87e  8b0d80539700         mov ecx, dword ptr [0x975380]
// 0056e884  57                   push edi
// 0056e885  51                   push ecx
// 0056e886  8bce                 mov ecx, esi
// 0056e888  e8a3d90000           call 0x57c230
// 0056e88d  8b1518539700         mov edx, dword ptr [0x975318]
// 0056e893  52                   push edx
// 0056e894  8bce                 mov ecx, esi
// 0056e896  8bf8                 mov edi, eax
// 0056e898  e893d90000           call 0x57c230
// 0056e89d  d9ee                 fldz 
// 0056e89f  8bf0                 mov esi, eax
// 0056e8a1  d9542410             fst dword ptr [esp + 0x10]
// 0056e8a5  8d442410             lea eax, [esp + 0x10]
// 0056e8a9  d9542414             fst dword ptr [esp + 0x14]
// 0056e8ad  50                   push eax
// 0056e8ae  d95c241c             fstp dword ptr [esp + 0x1c]
// 0056e8b2  8d4b10               lea ecx, [ebx + 0x10]
// 0056e8b5  e856dd0000           call 0x57c610
// 0056e8ba  8d4c2414             lea ecx, [esp + 0x14]
// 0056e8be  51                   push ecx
// 0056e8bf  8d4f10               lea ecx, [edi + 0x10]
// 0056e8c2  e849dd0000           call 0x57c610
// 0056e8c7  8d542418             lea edx, [esp + 0x18]
// 0056e8cb  52                   push edx
// 0056e8cc  8d4e10               lea ecx, [esi + 0x10]
// 0056e8cf  e83cdd0000           call 0x57c610
// 0056e8d4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0056e8d7  8b01                 mov eax, dword ptr [ecx]
// 0056e8d9  8b400c               mov eax, dword ptr [eax + 0xc]
// 0056e8dc  8d542410             lea edx, [esp + 0x10]
// 0056e8e0  52                   push edx
// 0056e8e1  8b542424             mov edx, dword ptr [esp + 0x24]
// 0056e8e5  52                   push edx
// 0056e8e6  ffd0                 call eax
// 0056e8e8  5f                   pop edi
// 0056e8e9  5b                   pop ebx
// 0056e8ea  5e                   pop esi
// 0056e8eb  5d                   pop ebp
// 0056e8ec  83c40c               add esp, 0xc
// 0056e8ef  c20c00               ret 0xc

struct Vector3 {
    float x, y, z;
};

struct Value {
    bool readFloat(float* result);
};

struct Node {
    char padding[16];
    Value value;
};

struct Source {
    bool isSpecial();
    Node* find(void* key);
};

extern void* keyX;
extern void* keyY;
extern void* keyZ;

struct Setter {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(void* object, const Vector3& value) = 0;
};

struct Descriptor {
    char padding[24];
    Setter* setter;

    void read(void* object, Source* source, void* unused);
};

void Descriptor::read(void* object, Source* source, void* unused)
{
    if (!source->isSpecial()) {
        Node* x = source->find(keyX);
        if (x) {
            Node* y = source->find(keyY);
            Node* z = source->find(keyZ);
            Vector3 value = { 0.0f, 0.0f, 0.0f };
            x->value.readFloat(&value.x);
            y->value.readFloat(&value.y);
            z->value.readFloat(&value.z);
            setter->set(object, value);
        }
    }
}
