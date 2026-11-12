// from server: 94% by EspClaude
// from server: 50% by colin
// roc 2007-08 0041dbf0  unit: CInstanceExplorer  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041dbf0
//
// 0041dbf0  6aff                 push -1
// 0041dbf2  6818b77300           push 0x73b718
// 0041dbf7  64a100000000         mov eax, dword ptr fs:[0]
// 0041dbfd  50                   push eax
// 0041dbfe  53                   push ebx
// 0041dbff  56                   push esi
// 0041dc00  57                   push edi
// 0041dc01  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041dc06  33c4                 xor eax, esp
// 0041dc08  50                   push eax
// 0041dc09  8d442410             lea eax, [esp + 0x10]
// 0041dc0d  64a300000000         mov dword ptr fs:[0], eax
// 0041dc13  8b8118fdffff         mov eax, dword ptr [ecx - 0x2e8]
// 0041dc19  8b908c010000         mov edx, dword ptr [eax + 0x18c]
// 0041dc1f  8d9918fdffff         lea ebx, [ecx - 0x2e8]
// 0041dc25  8bcb                 mov ecx, ebx
// 0041dc27  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0041dc2f  ffd2                 call edx
// 0041dc31  8bb8a8000000         mov edi, dword ptr [eax + 0xa8]
// 0041dc37  8bcf                 mov ecx, edi
// 0041dc39  e812602400           call 0x663c50
// 0041dc3e  8bf0                 mov esi, eax
// 0041dc40  83ee01               sub esi, 1
// 0041dc43  7820                 js 0x41dc65
// 0041dc45  56                   push esi
// 0041dc46  8bcf                 mov ecx, edi
// 0041dc48  e8b33a2400           call 0x661700
// 0041dc4d  8b4054               mov eax, dword ptr [eax + 0x54]
// 0041dc50  3b442424             cmp eax, dword ptr [esp + 0x24]
// 0041dc54  7407                 je 0x41dc5d
// 0041dc56  83ee01               sub esi, 1
// 0041dc59  79ea                 jns 0x41dc45
// 0041dc5b  eb08                 jmp 0x41dc65
// 0041dc5d  56                   push esi
// 0041dc5e  8bcf                 mov ecx, edi
// 0041dc60  e81b3c2400           call 0x661880
// 0041dc65  80bb0c03000000       cmp byte ptr [ebx + 0x30c], 0
// 0041dc6c  7518                 jne 0x41dc86
// 0041dc6e  8b03                 mov eax, dword ptr [ebx]
// 0041dc70  8b908c010000         mov edx, dword ptr [eax + 0x18c]
// 0041dc76  8bcb                 mov ecx, ebx
// 0041dc78  ffd2                 call edx
// 0041dc7a  8b10                 mov edx, dword ptr [eax]
// 0041dc7c  8bc8                 mov ecx, eax
// 0041dc7e  8b8250010000         mov eax, dword ptr [edx + 0x150]
// 0041dc84  ffd0                 call eax
// 0041dc86  8d4c2424             lea ecx, [esp + 0x24]
// 0041dc8a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0041dc92  e869fdffff           call 0x41da00
// 0041dc97  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041dc9b  64890d00000000       mov dword ptr fs:[0], ecx
// 0041dca2  59                   pop ecx
// 0041dca3  5f                   pop edi
// 0041dca4  5e                   pop esi
// 0041dca5  5b                   pop ebx
// 0041dca6  83c40c               add esp, 0xc

#define V1(n) virtual void v##n();
#define V10(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3) V1(n##4) V1(n##5) V1(n##6) V1(n##7) V1(n##8) V1(n##9)

struct Item {
    char pad[0x54];
    void* key;
};

class ItemList {
public:
    int count();
    Item* get(int i);
    void remove(int i);
};

class View {
public:
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7)
    V1(80) V1(81) V1(82) V1(83)
    virtual void refresh();          // vtable +0x150
};

class Doc {
public:
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7)
    V1(80) V1(81) V1(82) V1(83)
    virtual void refresh();          // vtable +0x150
    char pad[0xa4];
    ItemList* items;                 // +0xa8 (vptr at +0)
};

class Base1 {
public:
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8)
    V1(90) V1(91) V1(92) V1(93) V1(94) V1(95) V1(96) V1(97) V1(98)
    virtual Doc* getDoc();           // vtable +0x18c
    virtual View* getView() ;
    char pad[0x2e8 - 4];
};

struct Event {
    void* key;
    int rest[3];
    ~Event();
};

class Listener {
public:
    virtual void onEvent(int arg, Event e);
};

class CInstanceExplorer : public Base1, public Listener {
public:
    char pad2[0x30c - 0x2ec];
    bool flag;                       // +0x30c
    virtual void onEvent(int arg, Event e);
    __forceinline void handle(const Event& e)
    {
    ItemList* list = getDoc()->items;
    for (int i = list->count() - 1; i >= 0; --i) {
        if (list->get(i)->key == e.key) {
            list->remove(i);
            break;
        }
    }
    if (!flag)
        getDoc()->refresh();
    }
};

void CInstanceExplorer::onEvent(int arg, Event e)
{
    handle(e);
}
