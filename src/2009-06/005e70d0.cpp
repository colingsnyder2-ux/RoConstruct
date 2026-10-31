// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0056f5f0  unit: G3D::VColor3::?$TypedPropertyDescriptor  size: 229 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056f5f0
//
// 0056f5f0  83ec10               sub esp, 0x10
// 0056f5f3  55                   push ebp
// 0056f5f4  56                   push esi
// 0056f5f5  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056f5f9  8be9                 mov ebp, ecx
// 0056f5fb  8bce                 mov ecx, esi
// 0056f5fd  e80ed20000           call 0x57c810
// 0056f602  84c0                 test al, al
// 0056f604  0f85c3000000         jne 0x56f6cd
// 0056f60a  8d442408             lea eax, [esp + 8]
// 0056f60e  50                   push eax
// 0056f60f  8d4e10               lea ecx, [esi + 0x10]
// 0056f612  e839cf0000           call 0x57c550
// 0056f617  84c0                 test al, al
// 0056f619  7444                 je 0x56f65f
// 0056f61b  8b442408             mov eax, dword ptr [esp + 8]
// 0056f61f  8bc8                 mov ecx, eax
// 0056f621  c1e910               shr ecx, 0x10
// 0056f624  8bd0                 mov edx, eax
// 0056f626  88442422             mov byte ptr [esp + 0x22], al
// 0056f62a  8d442420             lea eax, [esp + 0x20]
// 0056f62e  884c2420             mov byte ptr [esp + 0x20], cl
// 0056f632  c1ea08               shr edx, 8
// 0056f635  50                   push eax
// 0056f636  8d4c2410             lea ecx, [esp + 0x10]
// 0056f63a  88542425             mov byte ptr [esp + 0x25], dl
// 0056f63e  e8bd55faff           call 0x514c00
// 0056f643  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0056f646  8b11                 mov edx, dword ptr [ecx]
// 0056f648  8b520c               mov edx, dword ptr [edx + 0xc]
// 0056f64b  8d44240c             lea eax, [esp + 0xc]
// 0056f64f  50                   push eax
// 0056f650  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056f654  50                   push eax
// 0056f655  ffd2                 call edx
// 0056f657  5e                   pop esi
// 0056f658  5d                   pop ebp
// 0056f659  83c410               add esp, 0x10
// 0056f65c  c20c00               ret 0xc
// 0056f65f  a16c539700           mov eax, dword ptr [0x97536c]
// 0056f664  53                   push ebx
// 0056f665  57                   push edi
// 0056f666  50                   push eax
// 0056f667  8bce                 mov ecx, esi
// 0056f669  e8c2cb0000           call 0x57c230
// 0056f66e  8b0d3c539700         mov ecx, dword ptr [0x97533c]
// 0056f674  51                   push ecx
// 0056f675  8bce                 mov ecx, esi
// 0056f677  8bf8                 mov edi, eax
// 0056f679  e8b2cb0000           call 0x57c230
// 0056f67e  8b1540539700         mov edx, dword ptr [0x975340]
// 0056f684  52                   push edx
// 0056f685  8bce                 mov ecx, esi
// 0056f687  8bd8                 mov ebx, eax
// 0056f689  e8a2cb0000           call 0x57c230
// 0056f68e  8bf0                 mov esi, eax
// 0056f690  8d442414             lea eax, [esp + 0x14]
// 0056f694  50                   push eax
// 0056f695  8d4f10               lea ecx, [edi + 0x10]
// 0056f698  e873cf0000           call 0x57c610
// 0056f69d  8d4c2418             lea ecx, [esp + 0x18]
// 0056f6a1  51                   push ecx
// 0056f6a2  8d4b10               lea ecx, [ebx + 0x10]
// 0056f6a5  e866cf0000           call 0x57c610
// 0056f6aa  8d54241c             lea edx, [esp + 0x1c]
// 0056f6ae  52                   push edx
// 0056f6af  8d4e10               lea ecx, [esi + 0x10]
// 0056f6b2  e859cf0000           call 0x57c610
// 0056f6b7  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0056f6ba  8b01                 mov eax, dword ptr [ecx]
// 0056f6bc  8b400c               mov eax, dword ptr [eax + 0xc]
// 0056f6bf  8d542414             lea edx, [esp + 0x14]
// 0056f6c3  52                   push edx
// 0056f6c4  8b542428             mov edx, dword ptr [esp + 0x28]
// 0056f6c8  52                   push edx
// 0056f6c9  ffd0                 call eax
// 0056f6cb  5f                   pop edi
// 0056f6cc  5b                   pop ebx
// 0056f6cd  5e                   pop esi
// 0056f6ce  5d                   pop ebp
// 0056f6cf  83c410               add esp, 0x10
// 0056f6d2  c20c00               ret 0xc

struct Color8 {
    unsigned char r, g, b;
};

struct Color {
    float r, g, b;
    Color(const Color8&);
};

struct Value {
    bool readPacked(unsigned int*);
    bool readFloat(float*);
};

struct Node {
    unsigned char padding[16];
    Value value;
    bool isEmpty();
    Node* find(const void*);
};

extern const void* redKey;
extern const void* greenKey;
extern const void* blueKey;

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const Color&);
};

struct Descriptor {
    unsigned char padding[24];
    Setter* setter;
    void read(void*, Node*, void*);
};

void Descriptor::read(void* object, Node* node, void*)
{
    Node* source = node;
    if (source->isEmpty())
        return;

    unsigned int packed;
    if (source->value.readPacked(&packed)) {
        Color8 bytes;
        bytes.r = static_cast<unsigned char>(packed >> 16);
        bytes.g = static_cast<unsigned char>(packed >> 8);
        bytes.b = static_cast<unsigned char>(packed);
        Color color(bytes);
        setter->set(object, color);
    } else {
        Node* red = source->find(redKey);
        Node* green = source->find(greenKey);
        Node* blue = source->find(blueKey);
        float components[3];
        red->value.readFloat(&components[0]);
        green->value.readFloat(&components[1]);
        blue->value.readFloat(&components[2]);
        setter->set(object, *reinterpret_cast<Color*>(components));
    }
}
