// from server: 100% by Yeetserama
// roc 2007-08 0040ada0  unit: CNullDoc  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040ada0
//
// 0040ada0  6aff                 push -1
// 0040ada2  68fad87300           push 0x73d8fa
// 0040ada7  64a100000000         mov eax, dword ptr fs:[0]
// 0040adad  50                   push eax
// 0040adae  51                   push ecx
// 0040adaf  56                   push esi
// 0040adb0  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040adb5  33c4                 xor eax, esp
// 0040adb7  50                   push eax
// 0040adb8  8d44240c             lea eax, [esp + 0xc]
// 0040adbc  64a300000000         mov dword ptr fs:[0], eax
// 0040adc2  6a58                 push 0x58
// 0040adc4  e82d512200           call 0x62fef6
// 0040adc9  8bf0                 mov esi, eax
// 0040adcb  83c404               add esp, 4
// 0040adce  89742408             mov dword ptr [esp + 8], esi
// 0040add2  85f6                 test esi, esi
// 0040add4  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040addc  7427                 je 0x40ae05
// 0040adde  8bce                 mov ecx, esi
// 0040ade0  e877512200           call 0x62ff5c
// 0040ade5  c70694587800         mov dword ptr [esi], 0x785894
// 0040adeb  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0040adf2  8bc6                 mov eax, esi
// 0040adf4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040adf8  64890d00000000       mov dword ptr fs:[0], ecx
// 0040adff  59                   pop ecx
// 0040ae00  5e                   pop esi
// 0040ae01  83c410               add esp, 0x10
// 0040ae04  c3                   ret 
// 0040ae05  33c0                 xor eax, eax
// 0040ae07  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040ae0b  64890d00000000       mov dword ptr fs:[0], ecx
// 0040ae12  59                   pop ecx
// 0040ae13  5e                   pop esi
// 0040ae14  83c410               add esp, 0x10
// 0040ae17  c3                   ret 
// copied from an identical function in another client (function ?CreateView@@YAPAUView@@XZ)

// from server: 100% by colin
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct BaseView {
    BaseView();
    virtual ~BaseView();
    unsigned char storage[0x50];
};

struct View : BaseView {
    View();
    virtual ~View();
    int state;
};

inline View::View() : state(0) {}

View* __cdecl CreateView()
{
    return new View;
}