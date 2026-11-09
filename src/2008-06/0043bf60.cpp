// from server: 100% by colin
// from server: 94% by king_originala
// roc 2008-06 0043bf60  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043bf60
//
// 0043bf60  6aff                 push -1
// 0043bf62  6831077c00           push 0x7c0731
// 0043bf67  64a100000000         mov eax, dword ptr fs:[0]
// 0043bf6d  50                   push eax
// 0043bf6e  64892500000000       mov dword ptr fs:[0], esp
// 0043bf75  51                   push ecx
// 0043bf76  56                   push esi
// 0043bf77  57                   push edi
// 0043bf78  c744240800000000     mov dword ptr [esp + 8], 0
// 0043bf80  8b742424             mov esi, dword ptr [esp + 0x24]
// 0043bf84  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0043bf88  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0043bf90  3bf7                 cmp esi, edi
// 0043bf92  7422                 je 0x43bfb6
// 0043bf94  8bce                 mov ecx, esi
// 0043bf96  ff54243c             call dword ptr [esp + 0x3c]
// 0043bf9a  8b542434             mov edx, dword ptr [esp + 0x34]
// 0043bf9e  8d4c2444             lea ecx, [esp + 0x44]
// 0043bfa2  51                   push ecx
// 0043bfa3  50                   push eax
// 0043bfa4  8b442440             mov eax, dword ptr [esp + 0x40]
// 0043bfa8  8d0c10               lea ecx, [eax + edx]
// 0043bfab  ff542438             call dword ptr [esp + 0x38]
// 0043bfaf  83c608               add esi, 8
// 0043bfb2  3bf7                 cmp esi, edi
// 0043bfb4  75de                 jne 0x43bf94
// 0043bfb6  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0043bfba  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0043bfbe  8b542434             mov edx, dword ptr [esp + 0x34]
// 0043bfc2  8b442438             mov eax, dword ptr [esp + 0x38]
// 0043bfc6  890e                 mov dword ptr [esi], ecx
// 0043bfc8  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0043bfcc  895604               mov dword ptr [esi + 4], edx
// 0043bfcf  8b542440             mov edx, dword ptr [esp + 0x40]
// 0043bfd3  894608               mov dword ptr [esi + 8], eax
// 0043bfd6  894e0c               mov dword ptr [esi + 0xc], ecx
// 0043bfd9  8d442444             lea eax, [esp + 0x44]
// 0043bfdd  8d4e14               lea ecx, [esi + 0x14]
// 0043bfe0  50                   push eax
// 0043bfe1  895610               mov dword ptr [esi + 0x10], edx
// 0043bfe4  ff155c248000         call dword ptr [0x80245c]
// 0043bfea  8d4c2444             lea ecx, [esp + 0x44]
// 0043bfee  c744240801000000     mov dword ptr [esp + 8], 1
// 0043bff6  c644241400           mov byte ptr [esp + 0x14], 0
// 0043bffb  ff1568248000         call dword ptr [0x802468]
// 0043c001  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043c005  5f                   pop edi
// 0043c006  8bc6                 mov eax, esi
// 0043c008  5e                   pop esi
// 0043c009  64890d00000000       mov dword ptr fs:[0], ecx
// 0043c010  83c410               add esp, 0x10
// 0043c013  c3                   ret 

extern void (__thiscall *copyString)(void*, const void*);
extern void (__thiscall *destroyString)(void*);

struct String {
    char data[28];
    String(const String&);
    ~String();
};

__forceinline String::String(const String& other) {
    copyString(this, &other);
}

__forceinline String::~String() {
    destroyString(this);
}

struct Item {
    char data[8];
};

struct Iterator {
    void* owner;
    Item* current;
};

struct Head {
    void (__thiscall *invoke)(void*, void*, const String*);
    char* object;
    int adjustment;
    void* (__thiscall *extract)(void*);
    int extra;
};
struct Function : Head {
    String value;
};

Function apply(Iterator first, Iterator last, Function function) {
    Item* current = first.current;
    Item* end = last.current;
    for (; current != end; ++current) {
        void* item = function.extract(current);
        function.invoke(function.object + function.adjustment,
                        item, &function.value);
    }
    return function;
}
