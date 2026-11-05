// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0055b6f0  unit: RBX::VInstance::?$SignalDesc  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055b6f0
//
// 0055b6f0  a110539700           mov eax, dword ptr [0x975310]
// 0055b6f5  53                   push ebx
// 0055b6f6  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0055b6fa  56                   push esi
// 0055b6fb  57                   push edi
// 0055b6fc  8bf1                 mov esi, ecx
// 0055b6fe  50                   push eax
// 0055b6ff  8bcb                 mov ecx, ebx
// 0055b701  e8aa0b0200           call 0x57c2b0
// 0055b706  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0055b70a  85c0                 test eax, eax
// 0055b70c  740d                 je 0x55b71b
// 0055b70e  8b17                 mov edx, dword ptr [edi]
// 0055b710  83c008               add eax, 8
// 0055b713  56                   push esi
// 0055b714  50                   push eax
// 0055b715  8b02                 mov eax, dword ptr [edx]
// 0055b717  8bcf                 mov ecx, edi
// 0055b719  ffd0                 call eax
// 0055b71b  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0055b71e  3b0d5c539700         cmp ecx, dword ptr [0x97535c]
// 0055b724  752a                 jne 0x55b750
// 0055b726  8b150c539700         mov edx, dword ptr [0x97530c]
// 0055b72c  52                   push edx
// 0055b72d  8bcb                 mov ecx, ebx
// 0055b72f  e8fc0a0200           call 0x57c230
// 0055b734  85c0                 test eax, eax
// 0055b736  7409                 je 0x55b741
// 0055b738  57                   push edi
// 0055b739  50                   push eax
// 0055b73a  8bce                 mov ecx, esi
// 0055b73c  e8dfc1ffff           call 0x557920
// 0055b741  57                   push edi
// 0055b742  53                   push ebx
// 0055b743  8bce                 mov ecx, esi
// 0055b745  e856ffffff           call 0x55b6a0
// 0055b74a  5f                   pop edi
// 0055b74b  5e                   pop esi
// 0055b74c  5b                   pop ebx
// 0055b74d  c20800               ret 8
// 0055b750  8b06                 mov eax, dword ptr [esi]
// 0055b752  8b502c               mov edx, dword ptr [eax + 0x2c]
// 0055b755  57                   push edi
// 0055b756  53                   push ebx
// 0055b757  8bce                 mov ecx, esi
// 0055b759  ffd2                 call edx
// 0055b75b  5f                   pop edi
// 0055b75c  5e                   pop esi
// 0055b75d  5b                   pop ebx
// 0055b75e  c20800               ret 8

struct S;
struct Visitor;
struct Object;

extern void* key975310;
extern void* key97530c;
extern void* key97535c;

struct Object {
    unsigned char padding[16];
    void* type;

    char* __thiscall findSignal(void*);
    void* __thiscall findProduct(void*);
};

struct Visitor {
    virtual void visit(void*, S*);
};

typedef void (__thiscall *Dispatch)(S*, Object*, Visitor*);

struct DispatchTable {
    unsigned char padding[60];
    Dispatch dispatch;
};

struct S {
    DispatchTable* table;

    void __thiscall process(Object*, Visitor*);
    void __thiscall processProduct(void*, Visitor*);
    void __thiscall processSignal(Object*, Visitor*);
};

void S::process(Object* object, Visitor* visitor)
{
    char* signal = object->findSignal(key975310);
    if (signal)
        visitor->visit(signal + 8, this);

    if (object->type == key97535c) {
        void* product = object->findProduct(key97530c);
        if (product)
            processProduct(product, visitor);
        processSignal(object, visitor);
    } else {
        table->dispatch(this, object, visitor);
    }
}
