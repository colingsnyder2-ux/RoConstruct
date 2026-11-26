// from server: 100% by Xemicl
// roc 2012-06 0041b730  unit: VCRbxObject::?$CComObjectNoLock  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0041b730
//
// 0041b730  8b442404             mov eax, dword ptr [esp + 4]
// 0041b734  56                   push esi
// 0041b735  8bf1                 mov esi, ecx
// 0041b737  c70600000000         mov dword ptr [esi], 0
// 0041b73d  85c0                 test eax, eax
// 0041b73f  740d                 je 0x41b74e
// 0041b741  8b08                 mov ecx, dword ptr [eax]
// 0041b743  8b11                 mov edx, dword ptr [ecx]
// 0041b745  56                   push esi
// 0041b746  686c70b400           push 0xb4706c
// 0041b74b  50                   push eax
// 0041b74c  ffd2                 call edx
// 0041b74e  8bc6                 mov eax, esi
// 0041b750  5e                   pop esi
// 0041b751  c20400               ret 4
// copied from an identical function in another client (function ??0ItemPtr@ns_ROCX00001a@@QAE@PAUItem@1@@Z)

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