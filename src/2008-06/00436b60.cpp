// from server: 100% by king_originala
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
