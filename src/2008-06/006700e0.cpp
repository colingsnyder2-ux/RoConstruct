// from server: 100% by colin
// from server: 94% by king_originala
// roc 2008-06 006700e0  unit: RBX::AdornRbxGfx  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006700e0
//
// 006700e0  6aff                 push -1
// 006700e2  68c8c77d00           push 0x7dc7c8
// 006700e7  64a100000000         mov eax, dword ptr fs:[0]
// 006700ed  50                   push eax
// 006700ee  64892500000000       mov dword ptr fs:[0], esp
// 006700f5  51                   push ecx
// 006700f6  56                   push esi
// 006700f7  8bf1                 mov esi, ecx
// 006700f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006700fd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00670105  8d4e08               lea ecx, [esi + 8]
// 00670108  85c0                 test eax, eax
// 0067010a  7560                 jne 0x67016c
// 0067010c  6816b78000           push 0x80b716
// 00670111  ff154c248000         call dword ptr [0x80244c]
// 00670117  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0067011b  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00670123  85c0                 test eax, eax
// 00670125  0f84cb000000         je 0x6701f6
// 0067012b  83c004               add eax, 4
// 0067012e  50                   push eax
// 0067012f  ff15ac218000         call dword ptr [0x8021ac]
// 00670135  85c0                 test eax, eax
// 00670137  0f85b9000000         jne 0x6701f6
// 0067013d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00670141  e84aacdeff           call 0x45ad90
// 00670146  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0067014a  85c9                 test ecx, ecx
// 0067014c  0f84a4000000         je 0x6701f6
// 00670152  8b01                 mov eax, dword ptr [ecx]
// 00670154  8b10                 mov edx, dword ptr [eax]
// 00670156  6a01                 push 1
// 00670158  ffd2                 call edx
// 0067015a  5e                   pop esi
// 0067015b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0067015f  64890d00000000       mov dword ptr fs:[0], ecx
// 00670166  83c410               add esp, 0x10
// 00670169  c20800               ret 8
// 0067016c  83c00c               add eax, 0xc
// 0067016f  50                   push eax
// 00670170  ff150c248000         call dword ptr [0x80240c]
// 00670176  8b5604               mov edx, dword ptr [esi + 4]
// 00670179  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0067017d  8b01                 mov eax, dword ptr [ecx]
// 0067017f  8b4018               mov eax, dword ptr [eax + 0x18]
// 00670182  52                   push edx
// 00670183  8d542408             lea edx, [esp + 8]
// 00670187  52                   push edx
// 00670188  ffd0                 call eax
// 0067018a  8b442404             mov eax, dword ptr [esp + 4]
// 0067018e  8b35ac218000         mov esi, dword ptr [0x8021ac]
// 00670194  85c0                 test eax, eax
// 00670196  742b                 je 0x6701c3
// 00670198  83c004               add eax, 4
// 0067019b  50                   push eax
// 0067019c  ffd6                 call esi
// 0067019e  85c0                 test eax, eax
// 006701a0  7519                 jne 0x6701bb
// 006701a2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006701a6  e8e5abdeff           call 0x45ad90
// 006701ab  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006701af  85c9                 test ecx, ecx
// 006701b1  7408                 je 0x6701bb
// 006701b3  8b11                 mov edx, dword ptr [ecx]
// 006701b5  8b02                 mov eax, dword ptr [edx]
// 006701b7  6a01                 push 1
// 006701b9  ffd0                 call eax
// 006701bb  c744240400000000     mov dword ptr [esp + 4], 0
// 006701c3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006701c7  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006701cf  85c0                 test eax, eax
// 006701d1  7423                 je 0x6701f6
// 006701d3  83c004               add eax, 4
// 006701d6  50                   push eax
// 006701d7  ffd6                 call esi
// 006701d9  85c0                 test eax, eax
// 006701db  7519                 jne 0x6701f6
// 006701dd  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006701e1  e8aaabdeff           call 0x45ad90
// 006701e6  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006701ea  85c9                 test ecx, ecx
// 006701ec  7408                 je 0x6701f6
// 006701ee  8b11                 mov edx, dword ptr [ecx]
// 006701f0  8b02                 mov eax, dword ptr [edx]
// 006701f2  6a01                 push 1
// 006701f4  ffd0                 call eax
// 006701f6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006701fa  5e                   pop esi
// 006701fb  64890d00000000       mov dword ptr fs:[0], ecx
// 00670202  83c410               add esp, 0x10
// 00670205  c20800               ret 8
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);


struct String {
    char data[28];
};

extern String& (__thiscall *assignText)(String*, const char*);
extern String& (__thiscall *assignString)(String*, const String&);

struct Object;

struct Reference {
    Object* pointer;
    ~Reference();
};

struct Object {
    virtual ~Object();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual Reference invoke(void*);

    volatile long count;
    void* resource;
    String name;

    void release();
};

Reference::~Reference()
{
    if (pointer) {
        if (InterlockedDecrement(&pointer->count) == 0) {
            pointer->release();
            delete pointer;
        }
        pointer = 0;
    }
}

struct S {
    void* unused;
    void* context;
    String name;

    void f(int unusedArgument, Reference value);
};

void S::f(int unusedArgument, Reference value)
{
    if (!value.pointer) {
        assignText(&name, "");
        return;
    }

    assignString(&name, value.pointer->name);
    value.pointer->invoke(context);
}
