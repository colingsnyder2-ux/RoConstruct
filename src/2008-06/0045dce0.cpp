// from server: 100% by king_originala
extern "C" {
    extern void (__cdecl *invalid_parameter)();
}

extern void __cdecl register_type(void (__cdecl *)(), void *);
extern void __cdecl register_first();
extern void __cdecl register_second();
extern unsigned first_registration;
extern unsigned second_registration;
extern void *func_0045b2b0();
extern void *func_0045b160();

typedef void (__cdecl *InvalidHandler)();

struct Control {
    void *value;
    Control();
    Control &assign(const Control &);
};

inline Control::Control() : value(0) {}

struct EmptyValue {
    void *object;
    Control control;
    EmptyValue();
    EmptyValue(const EmptyValue &);
};

inline EmptyValue::EmptyValue() : object(0), control() {}

struct Value {
    void *object;
    Control control;
    ~Value();
    Value &operator=(const Value &);
};

inline Value &Value::operator=(const Value &other) {
    object = other.object;
    control.assign(other.control);
    return *this;
}

struct Values {
    unsigned char prefix[12];
    Value *first;
    Value *last;
    Value *limit;

    void resize(unsigned, EmptyValue);
    unsigned size() const;
    Value &at(unsigned, InvalidHandler);
};

inline unsigned Values::size() const {
    return static_cast<unsigned>(last - first);
}

inline Value &Values::at(unsigned index, InvalidHandler handler) {
    if (index >= size())
        handler();
    return first[index];
}

struct S {
    unsigned char prefix[0x190];
    Values values;

    Value create(void *);
    void *get();
};

void *S::get() {
    register_type(register_first, &first_registration);
    unsigned index = reinterpret_cast<unsigned>(func_0045b2b0());
    InvalidHandler handler = invalid_parameter;

    if (index + 1 > values.size()) {
        values.resize(index + 1, EmptyValue());
    } else {
        void *existing = values.at(index, handler).object;
        if (existing)
            return existing;
    }

    register_type(register_second, &second_registration);
    Value result = create(func_0045b160());
    if (!result.object)
        return 0;

    void *object = result.object;
    values.at(index, handler) = result;
    return object;
}
