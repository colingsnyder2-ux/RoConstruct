// from server: 100% by king_originala
extern "C" void __cdecl register_value(void (__cdecl *)(), void *);
extern void __cdecl initialize_first();
extern void __cdecl initialize_second();
extern unsigned char first_storage;
extern unsigned char second_storage;
extern void * __cdecl func_0049f030();
extern void * __cdecl func_004961d0();
extern void (__cdecl *invalid_parameter_handler)();

struct Control {
    void *value;

    Control() : value(0) {}
    Control &operator=(const Control &);
};

struct Value {
    void *object;
    Control control;

    Value() : object(0) {}
    Value(const Value &);
    ~Value();
};

struct Vector {
    unsigned char prefix[12];
    Value *first;
    Value *last;
    Value *limit;

    void resize(unsigned, Value);

    unsigned size() const {
        return static_cast<unsigned>(last - first);
    }

    Value &at(unsigned index, void (__cdecl *handler)()) {
        if (index >= size())
            handler();
        return first[index];
    }
};

struct S {
    unsigned char prefix[0x190];
    Vector values;

    Value create(void *);
    void *f();
};

void *S::f()
{
    register_value(initialize_first, &first_storage);
    unsigned index = reinterpret_cast<unsigned>(func_0049f030());
    void (__cdecl *handler)() = invalid_parameter_handler;

    if (index + 1 > values.size()) {
        values.resize(index + 1, Value());
    } else {
        void *existing = values.at(index, handler).object;
        if (existing)
            return existing;
    }

    register_value(initialize_second, &second_storage);
    Value value = create(func_004961d0());
    if (!value.object)
        return 0;

    void *result = value.object;
    Value &entry = values.at(index, handler);
    entry.object = value.object;
    entry.control = value.control;
    return result;
}
