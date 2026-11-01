// from server: 100% by king_originala
struct Holder;

struct HolderTable {
    void* (__thiscall *destroy)(Holder*, unsigned int);
    void* reserved;
    Holder* (__thiscall *clone)(Holder*);
};

struct Holder {
    const HolderTable* table;
};

struct Value {
    void* data;
    Holder* holder;

    Value(void* d, Holder* h) : data(d) {
        Holder* copy;
        if (h)
            copy = h->table->clone(h);
        else
            copy = 0;
        holder = copy;
    }

    ~Value() {
        if (holder)
            holder->table->destroy(holder, 1);
    }

    bool* getBool();
};

struct Arguments;

struct ArgumentsTable {
    void* reserved;
    void (__thiscall *get)(Arguments*, int, Value*);
};

struct Arguments {
    const ArgumentsTable* table;
};

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

extern unsigned char sourceType;
extern unsigned char destinationType;
extern unsigned char badCastThrowInfo;

struct BadCast {
    unsigned char storage[12];
};

extern void (__thiscall *constructBadCast)(BadCast*, const char*);

extern "C" __declspec(noreturn) void __stdcall throwException(
    void*, void*);

struct __multiple_inheritance Service;

struct S {
    unsigned char padding[0x38];
    void (Service::*invoke)(bool);
    void* data;
    Holder* holder;

    void f(void* object, Arguments* arguments);
};

void S::f(void* object, Arguments* arguments) {
    Value value(data, holder);
    arguments->table->get(arguments, 1, &value);

    Service* service = static_cast<Service*>(__RTDynamicCast(
        object, 0, &sourceType, &destinationType, 0));

    if (!service) {
        BadCast error;
        constructBadCast(&error, "bad cast");
        throwException(&error, &badCastThrowInfo);
    }

    (service->*invoke)(*value.getBool());
}
