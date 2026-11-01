// from server: 100% by colin
extern void (__cdecl* invalid_parameter)();
extern void __cdecl initialize_index();
extern void __cdecl initialize_type();
extern unsigned long index_once;
extern unsigned long type_once;
extern void __cdecl call_once(void (__cdecl*)(), unsigned long*);
extern void* __cdecl func_0042d030();
extern void* __cdecl func_0042ced0();

struct Control {
    void* value;
    Control();
    Control& operator=(const Control&);
};

__forceinline Control::Control() : value(0)
{
}

struct Pair {
    void* object;
    Control control;
    ~Pair();
};

struct EmptyPair {
    void* object;
    Control control;
    EmptyPair();
    EmptyPair(const EmptyPair&);
    ~EmptyPair();
};

__forceinline EmptyPair::EmptyPair()
    : object(0), control()
{
}

struct Vector {
    unsigned char padding[12];
    Pair* first;
    Pair* last;
    Pair* limit;
    void resize(unsigned int, EmptyPair);
    unsigned int size() const;
    Pair& at(unsigned int, void (__cdecl*)());
};

__forceinline unsigned int Vector::size() const
{
    return (unsigned int)(last - first);
}

__forceinline Pair& Vector::at(unsigned int index, void (__cdecl* handler)())
{
    if (index >= (unsigned int)(last - first))
        handler();
    return first[index];
}

struct S {
    unsigned char padding[0x190];
    Vector values;
    Pair create(void*);
    void* get();
};

void* S::get()
{
    call_once(initialize_index, &index_once);
    unsigned int index = (unsigned int)func_0042d030();
    void (__cdecl* handler)() = invalid_parameter;
    Vector& entries = values;

    if (index + 1 > values.size()) {
        entries.resize(index + 1, EmptyPair());
    } else {
        void* existing = entries.at(index, handler).object;
        if (existing)
            return existing;
    }

    call_once(initialize_type, &type_once);
    Pair result = create(func_0042ced0());

    if (!result.object)
        return 0;

    void* object = result.object;
    Pair& destination = entries.at(index, handler);
    destination.object = result.object;
    destination.control = result.control;
    return object;
}
