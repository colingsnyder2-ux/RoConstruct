// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct StringData;

extern void (__thiscall *copyString)(StringData *, const StringData *);
extern void (__thiscall *destroyString)(StringData *);

struct StringData {
    char data[28];
    StringData(const StringData &);
    ~StringData();
};

__forceinline StringData::StringData(const StringData &other) {
    copyString(this, &other);
}

__forceinline StringData::~StringData() {
    destroyString(this);
}

struct Value {
    StringData string;
    int extra;
};

struct Item {
    int data[2];
};

struct Iterator {
    int unused;
    Item *position;
};

typedef void *(__thiscall *Getter)(Item *);
typedef void (__thiscall *Setter)(void *, void *, const Value *);

struct Head {
    Setter setter;
    int adjustment;
    int object;
    Getter getter;
    int unused;
};
struct Function : Head {
    Value value;
};

Function apply(Iterator first, Iterator last, Function function) {
    Item *current = first.position;
    Item *end = last.position;
    for (; current != end; ++current) {
        void *value = function.getter(current);
        function.setter((void *)(function.adjustment + function.object),
                        value, &function.value);
    }
    return function;
}