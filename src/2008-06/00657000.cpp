// from server: 100% by Espeon
// from server: 90% by colin
// roc 2008-06 00657000  unit: RBX::ArrowPanel  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00657000
//
// 00657000  6aff                 push -1
// 00657002  683dbc7d00           push 0x7dbc3d
// 00657007  64a100000000         mov eax, dword ptr fs:[0]
// 0065700d  50                   push eax
// 0065700e  64892500000000       mov dword ptr fs:[0], esp
// 00657015  83ec0c               sub esp, 0xc
// 00657018  c744240400000000     mov dword ptr [esp + 4], 0
// 00657020  685c010000           push 0x15c
// 00657025  c744241801000000     mov dword ptr [esp + 0x18], 1
// 0065702d  c644240400           mov byte ptr [esp + 4], 0
// 00657032  ff15b0288000         call dword ptr [0x8028b0]
// 00657038  83c404               add esp, 4
// 0065703b  89442408             mov dword ptr [esp + 8], eax
// 0065703f  c644241402           mov byte ptr [esp + 0x14], 2
// 00657044  85c0                 test eax, eax
// 00657046  7415                 je 0x65705d
// 00657048  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0065704c  6a00                 push 0
// 0065704e  51                   push ecx
// 0065704f  8d542428             lea edx, [esp + 0x28]
// 00657053  52                   push edx
// 00657054  8bc8                 mov ecx, eax
// 00657056  e855ccf1ff           call 0x573cb0
// 0065705b  eb02                 jmp 0x65705f
// 0065705d  33c0                 xor eax, eax
// 0065705f  8b0c24               mov ecx, dword ptr [esp]
// 00657062  56                   push esi
// 00657063  8b742420             mov esi, dword ptr [esp + 0x20]
// 00657067  51                   push ecx
// 00657068  50                   push eax
// 00657069  8bce                 mov ecx, esi
// 0065706b  c644242001           mov byte ptr [esp + 0x20], 1
// 00657070  e81ba4faff           call 0x601490
// 00657075  8d4c2424             lea ecx, [esp + 0x24]
// 00657079  c744240801000000     mov dword ptr [esp + 8], 1
// 00657081  c644241800           mov byte ptr [esp + 0x18], 0
// 00657086  ff1568248000         call dword ptr [0x802468]
// 0065708c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00657090  8bc6                 mov eax, esi
// 00657092  5e                   pop esi
// 00657093  64890d00000000       mov dword ptr fs:[0], ecx
// 0065709a  83c418               add esp, 0x18
// 0065709d  c3                   ret 

//

extern "C" void* (__cdecl *allocate)(unsigned int);
extern "C" void __cdecl free(void*);

struct String {
    char storage[28];
    ~String();
};

extern void (__thiscall *destroyString)(String*);

inline String::~String()
{
    destroyString(this);
}

struct Deleter {
    unsigned char unused;
    Deleter();
};

inline Deleter::Deleter() : unused(0)
{
}

struct Node {
    char storage[0x15c];

    Node(const String&,void*,bool);
    static void* operator new(unsigned int) throw();
    static void operator delete(void*);
};

inline void* Node::operator new(unsigned int size) throw()
{
    return allocate(size);
}

inline void Node::operator delete(void* p)
{
    free(p);
}

struct Pointer {
    Node* object;
    void* control;

    Pointer(Node*, Deleter);
    ~Pointer();
};

Pointer __cdecl makePointer(String name, void* owner)
{
    Deleter deleter;
    return Pointer(new Node(name, owner, false), deleter);
}
