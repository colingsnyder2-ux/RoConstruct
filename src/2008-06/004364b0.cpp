// from server: 100% by colin
// from server: 92% by colin
// roc 2008-06 004364b0  unit: COutputView  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004364b0
//

// from server: 89% by king_originala
// roc 2008-06 004364b0  unit: COutputView  size: 442 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004364b0
//

struct Guid {
    unsigned long a;
    unsigned short b, c;
    unsigned char d[8];
};

extern const Guid objectId;
extern const Guid outputId;

struct VariantData {
    unsigned short type;
    unsigned short reserved1, reserved2, reserved3;
    unsigned long value1, value2;
};

extern "C" {
    __declspec(dllimport) void __stdcall VariantInit(VariantData *);
    __declspec(dllimport) long __stdcall VariantClear(VariantData *);
}

struct Variant : VariantData {
    Variant();
    Variant(const char *);
    ~Variant() { VariantClear(this); }
    void assign(const char *);
};

inline Variant::Variant() {
    VariantInit(this);
}

inline Variant::Variant(const char *text) {
    type = 0;
    assign(text);
}

struct Object;

struct ObjectTable {
    long (__stdcall *query)(Object *, const Guid &, Object **);
    unsigned long (__stdcall *retain)(Object *);
    unsigned long (__stdcall *release)(Object *);
    void *unused3;
    void *unused4;
    void *unused5;
    void *unused6;
    void *unused7;
    long (__stdcall *get)(Object *, Object **);
    void *unused9;
    void *unused10;
    long (__stdcall *create)(Object *, VariantData, VariantData, Object **);
};

struct Object {
    ObjectTable *table;
};

struct Pointer {
    Object *value;
    Pointer();
    ~Pointer();
};

inline Pointer::Pointer() : value(0) {
}

inline Pointer::~Pointer() {
    if (value)
        value->table->release(value);
}

struct COutputView {
    unsigned char padding[0x118];
    Object *object;
    Object *output;

    Object *getObject();
    void update(int);
};

void COutputView::update(int) {
    Object *next = getObject();
    Object *previous = object;

    if (previous != next) {
        object = 0;
        if (next)
            next->table->query(next, objectId, &object);
        if (previous)
            previous->table->release(previous);
    }

    if (object) {
        Pointer source;
        object->table->get(object, &source.value);

        Pointer result;
        {
            Variant argument;
            VariantData argumentValue = argument;
            Variant name("output");
            source.value->table->create(
                source.value, name, argumentValue, &result.value);
        }

        Object *old = output;
        if (old != result.value) {
            output = 0;
            if (result.value)
                result.value->table->query(
                    result.value, outputId, &output);
            if (old)
                old->table->release(old);
        }
    } else {
        Object *old = output;
        if (old) {
            output = 0;
            old->table->release(old);
        }
    }
}
