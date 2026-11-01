// from server: 83% by EspClaude
// from server: 100% by colin
// roc 2008-06 00433ea0  unit: CMemberTreeView  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00433ea0
//
// 00433ea0  56                   push esi
// 00433ea1  57                   push edi
// 00433ea2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00433ea6  8b4704               mov eax, dword ptr [edi + 4]
// 00433ea9  8bf1                 mov esi, ecx
// 00433eab  8d4804               lea ecx, [eax + 4]
// 00433eae  ff1564248000         call dword ptr [0x802464]
// 00433eb4  680200ffff           push 0xffff0002
// 00433eb9  680000ffff           push 0xffff0000
// 00433ebe  6a00                 push 0
// 00433ec0  6a00                 push 0
// 00433ec2  6a00                 push 0
// 00433ec4  6a0a                 push 0xa
// 00433ec6  6a0a                 push 0xa
// 00433ec8  50                   push eax
// 00433ec9  6a23                 push 0x23
// 00433ecb  8bce                 mov ecx, esi
// 00433ecd  e8fed12600           call 0x6a10d0
// 00433ed2  57                   push edi
// 00433ed3  6a00                 push 0
// 00433ed5  6a00                 push 0
// 00433ed7  6a00                 push 0
// 00433ed9  6a00                 push 0
// 00433edb  6a00                 push 0
// 00433edd  6a04                 push 4
// 00433edf  50                   push eax
// 00433ee0  8bce                 mov ecx, esi
// 00433ee2  e8efd12600           call 0x6a10d6
// 00433ee7  5f                   pop edi
// 00433ee8  5e                   pop esi
// 00433ee9  c20400               ret 4

struct String {
    unsigned char unused;
};

extern const char* (__thiscall *string_c_str)(const String*);

struct ItemData {
    unsigned char padding[4];
    String text;
};

struct Item {
    unsigned char padding[4];
    ItemData* data;
};

struct CMemberTreeView {
    void* insertItem(unsigned int, const char*, int, int, unsigned int,
                     unsigned int, unsigned int, void*, void*);
    void setItem(void*, unsigned int, const char*, int, int,
                 unsigned int, unsigned int, Item*);
    void addItem(Item*);
};

void CMemberTreeView::addItem(Item* item)
{
    ItemData* data = item->data;
    const char* text = string_c_str(&data->text);
    void* handle = insertItem(35, text, 10, 10, 0, 0, 0,
                              (void*)0xffff0000, (void*)0xffff0002);
    setItem(handle, 4, 0, 0, 0, 0, 0, item);
}
