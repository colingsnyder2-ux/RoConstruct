// from server: 100% by king_originala
void* __cdecl func_0056cd10();
void* __cdecl operator new(unsigned int);

struct Holder
{
    virtual ~Holder();
    Holder(double);
    double value;
};

inline Holder::Holder(double v)
{
    value = v;
}

struct Getter
{
    virtual void slot0();
    virtual void slot1();
    virtual double get(void*);
};

struct Value
{
    void* type;
    Holder* holder;
};

struct S
{
    char padding[24];
    Getter* getter;
    void func_00564170(void*, Value*);
};

void S::func_00564170(void* object, Value* result)
{
    double value = getter->get(object);
    result->type = func_0056cd10();
    Holder** destination = &result->holder;
    Holder* fresh = new Holder(value);
    Holder* old = fresh;
    if (reinterpret_cast<Holder**>(&object) != destination)
    {
        old = *destination;
        *destination = fresh;
    }
    if (old)
        delete old;
}
