// from server: 100% by EspClaude
// roc 2009-06 00430240  unit: COutputView  size: 378 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00430240
//
// 00430240  6aff                 push -1
// 00430242  68a0f68400           push 0x84f6a0
// 00430247  64a100000000         mov eax, dword ptr fs:[0]
// 0043024d  50                   push eax
// 0043024e  64892500000000       mov dword ptr fs:[0], esp
// 00430255  83ec18               sub esp, 0x18
// 00430258  55                   push ebp
// 00430259  56                   push esi
// 0043025a  8b742430             mov esi, dword ptr [esp + 0x30]
// 0043025e  33ed                 xor ebp, ebp
// 00430260  57                   push edi
// 00430261  8bf9                 mov edi, ecx
// 00430263  896c240c             mov dword ptr [esp + 0xc], ebp
// 00430267  3bf5                 cmp esi, ebp
// 00430269  7411                 je 0x43027c
// 0043026b  8b06                 mov eax, dword ptr [esi]
// 0043026d  8b10                 mov edx, dword ptr [eax]
// 0043026f  8d4c240c             lea ecx, [esp + 0xc]
// 00430273  51                   push ecx
// 00430274  6818358b00           push 0x8b3518
// 00430279  56                   push esi
// 0043027a  ffd2                 call edx
// 0043027c  896c242c             mov dword ptr [esp + 0x2c], ebp
// 00430280  896c2410             mov dword ptr [esp + 0x10], ebp
// 00430284  8b871c010000         mov eax, dword ptr [edi + 0x11c]
// 0043028a  8b08                 mov ecx, dword ptr [eax]
// 0043028c  8d542410             lea edx, [esp + 0x10]
// 00430290  52                   push edx
// 00430291  8b542410             mov edx, dword ptr [esp + 0x10]
// 00430295  52                   push edx
// 00430296  50                   push eax
// 00430297  8b414c               mov eax, dword ptr [ecx + 0x4c]
// 0043029a  c644243801           mov byte ptr [esp + 0x38], 1
// 0043029f  ffd0                 call eax
// 004302a1  85c0                 test eax, eax
// 004302a3  0f85d0000000         jne 0x430379
// 004302a9  b902000000           mov ecx, 2
// 004302ae  33d2                 xor edx, edx
// 004302b0  66894c2414           mov word ptr [esp + 0x14], cx
// 004302b5  668954241c           mov word ptr [esp + 0x1c], dx
// 004302ba  8b542414             mov edx, dword ptr [esp + 0x14]
// 004302be  83ec10               sub esp, 0x10
// 004302c1  8bc4                 mov eax, esp
// 004302c3  8910                 mov dword ptr [eax], edx
// 004302c5  8b542428             mov edx, dword ptr [esp + 0x28]
// 004302c9  895004               mov dword ptr [eax + 4], edx
// 004302cc  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004302d0  895008               mov dword ptr [eax + 8], edx
// 004302d3  8b542430             mov edx, dword ptr [esp + 0x30]
// 004302d7  884c243c             mov byte ptr [esp + 0x3c], cl
// 004302db  8b0e                 mov ecx, dword ptr [esi]
// 004302dd  89500c               mov dword ptr [eax + 0xc], edx
// 004302e0  8b81b8000000         mov eax, dword ptr [ecx + 0xb8]
// 004302e6  56                   push esi
// 004302e7  ffd0                 call eax
// 004302e9  8d4c2414             lea ecx, [esp + 0x14]
// 004302ed  51                   push ecx
// 004302ee  c644243001           mov byte ptr [esp + 0x30], 1
// 004302f3  ff1528ea8900         call dword ptr [0x89ea28]
// 004302f9  8d54240c             lea edx, [esp + 0xc]
// 004302fd  8db7f8000000         lea esi, [edi + 0xf8]
// 00430303  52                   push edx
// 00430304  8bce                 mov ecx, esi
// 00430306  e8d5fcffff           call 0x42ffe0
// 0043030b  81bf14010000fa000000 cmp dword ptr [edi + 0x114], 0xfa
// 00430315  7662                 jbe 0x430379
// 00430317  896c2434             mov dword ptr [esp + 0x34], ebp
// 0043031b  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 0043031e  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00430321  8bbf1c010000         mov edi, dword ptr [edi + 0x11c]
// 00430327  03c5                 add eax, ebp
// 00430329  c644242c03           mov byte ptr [esp + 0x2c], 3
// 0043032e  3be8                 cmp ebp, eax
// 00430330  7606                 jbe 0x430338
// 00430332  ff15ace98900         call dword ptr [0x89e9ac]
// 00430338  8b0e                 mov ecx, dword ptr [esi]
// 0043033a  894c2414             mov dword ptr [esp + 0x14], ecx
// 0043033e  8d4c2414             lea ecx, [esp + 0x14]
// 00430342  896c2418             mov dword ptr [esp + 0x18], ebp
// 00430346  e8d5640600           call 0x496820
// 0043034b  8b00                 mov eax, dword ptr [eax]
// 0043034d  8b17                 mov edx, dword ptr [edi]
// 0043034f  8b5234               mov edx, dword ptr [edx + 0x34]
// 00430352  8d4c2434             lea ecx, [esp + 0x34]
// 00430356  51                   push ecx
// 00430357  50                   push eax
// 00430358  57                   push edi
// 00430359  ffd2                 call edx
// 0043035b  8bce                 mov ecx, esi
// 0043035d  e87ef8ffff           call 0x42fbe0
// 00430362  8b442434             mov eax, dword ptr [esp + 0x34]
// 00430366  c644242c01           mov byte ptr [esp + 0x2c], 1
// 0043036b  85c0                 test eax, eax
// 0043036d  7408                 je 0x430377
// 0043036f  8b08                 mov ecx, dword ptr [eax]
// 00430371  8b5108               mov edx, dword ptr [ecx + 8]
// 00430374  50                   push eax
// 00430375  ffd2                 call edx
// 00430377  33ed                 xor ebp, ebp
// 00430379  8b442410             mov eax, dword ptr [esp + 0x10]
// 0043037d  c644242c00           mov byte ptr [esp + 0x2c], 0
// 00430382  3bc5                 cmp eax, ebp
// 00430384  7408                 je 0x43038e
// 00430386  8b08                 mov ecx, dword ptr [eax]
// 00430388  8b5108               mov edx, dword ptr [ecx + 8]
// 0043038b  50                   push eax
// 0043038c  ffd2                 call edx
// 0043038e  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00430392  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0043039a  3bc5                 cmp eax, ebp
// 0043039c  7408                 je 0x4303a6
// 0043039e  8b08                 mov ecx, dword ptr [eax]
// 004303a0  8b5108               mov edx, dword ptr [ecx + 8]
// 004303a3  50                   push eax
// 004303a4  ffd2                 call edx
// 004303a6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004303aa  5f                   pop edi
// 004303ab  5e                   pop esi
// 004303ac  64890d00000000       mov dword ptr fs:[0], ecx
// 004303b3  5d                   pop ebp
// 004303b4  83c424               add esp, 0x24
// 004303b7  c20400               ret 4
// copied from an identical function in another client (function ?update@COutputView@ns_ROCX00001a@@QAEXPAUItem@2@@Z)

namespace ns_ROCX00001a {
struct Item;
struct Variant;

struct ItemVTable {
    int (__stdcall *query)(Item *, const void *, void **);
    unsigned long (__stdcall *addRef)(Item *);
    unsigned long (__stdcall *release)(Item *);
    void *unused0[10];
    int (__stdcall *remove)(Item *, Item *, Item **);
    void *unused1[5];
    int (__stdcall *append)(Item *, Item *, Item **);
    void *unused2[26];
    int (__stdcall *setValue)(Item *, Variant);
};

struct Item {
    ItemVTable *vtable;
};

extern const unsigned char itemInterface[16];
extern "C" {
    extern int (__stdcall *VariantClear)(Variant *);
    extern void (__cdecl *_invalid_parameter_noinfo)();
}

struct ItemPtr {
    Item *value;
    ItemPtr();
    ItemPtr(Item *);
    ~ItemPtr();
};

__forceinline ItemPtr::ItemPtr() : value(0) {}

__forceinline ItemPtr::ItemPtr(Item *source) : value(0) {
    if (source)
        source->vtable->query(source, itemInterface, (void **)&value);
}

__forceinline ItemPtr::~ItemPtr() {
    if (value)
        value->vtable->release(value);
}

struct Variant {
    unsigned short type;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned short reserved3;
    union {
        short shortValue;
        double doubleValue;
    };
    Variant();
    ~Variant();
};

__forceinline Variant::Variant() {
    type = 2;
    shortValue = 0;
}

__forceinline Variant::~Variant() {
    VariantClear(this);
}

struct Queue;

struct Iterator {
    Queue *owner;
    unsigned int position;
    Item **get();
};

struct Queue {
    Queue *owner;
    unsigned char padding[12];
    Item ***map;
    unsigned int mapSize;
    unsigned int first;
    unsigned int count;
    void append(ItemPtr *);
    void pop_front();
    Iterator begin();
};

__forceinline Iterator Queue::begin() {
    unsigned int position = first;
    if (position > first + count)
        _invalid_parameter_noinfo();
    Iterator result;
    result.owner = owner;
    result.position = position;
    return result;
}

struct COutputView {
    unsigned char padding[0xf8];
    Queue items;
    unsigned int reserved;
    Item *collection;
    void update(Item *);
};

void COutputView::update(Item *source) {
    ItemPtr item(source);
    ItemPtr added;
    if (collection->vtable->append(collection, item.value, &added.value) == 0) {
        {
            Variant value;
            source->vtable->setValue(source, value);
        }
        items.append(&item);
        if (items.count > 250) {
            ItemPtr removed;
            Item *target = collection;
            Iterator iterator = items.begin();
            Item *front = *iterator.get();
            target->vtable->remove(target, front, &removed.value);
            items.pop_front();
        }
    }
}
}
