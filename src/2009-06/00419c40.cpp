// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0041fbb0  unit: CListCtrl  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041fbb0
//
// 0041fbb0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0041fbb4  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0041fbb7  8b5004               mov edx, dword ptr [eax + 4]
// 0041fbba  83c110               add ecx, 0x10
// 0041fbbd  56                   push esi
// 0041fbbe  8b742408             mov esi, dword ptr [esp + 8]
// 0041fbc2  83c610               add esi, 0x10
// 0041fbc5  ffd2                 call edx
// 0041fbc7  50                   push eax
// 0041fbc8  8b06                 mov eax, dword ptr [esi]
// 0041fbca  8b5004               mov edx, dword ptr [eax + 4]
// 0041fbcd  8bce                 mov ecx, esi
// 0041fbcf  ffd2                 call edx
// 0041fbd1  50                   push eax
// 0041fbd2  e8c9feffff           call 0x41faa0
// 0041fbd7  83c408               add esp, 8
// 0041fbda  5e                   pop esi
// 0041fbdb  c20c00               ret 0xc

struct Value
{
    virtual void reserved();
    virtual int get();
};

struct Item
{
    char padding[20];
    Value value;
};

extern int __cdecl compareValues(int, int);

int __stdcall func_0041fbb0(Item* first, Item* second, int)
{
    return compareValues(first->value.get(), second->value.get());
}
