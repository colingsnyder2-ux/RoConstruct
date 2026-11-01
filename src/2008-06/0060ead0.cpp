// from server: 100% by king_originala
struct Value
{
    void* first;
    void* second;

    Value(const Value&);
    ~Value();
    Value convert() const;
};

struct Container
{
    unsigned int reserved[3];
    Value* begin;
    Value* end;
    Value* capacity;

    __forceinline Value& operator[](unsigned int index) const;
};

__forceinline Value& Container::operator[](unsigned int index) const
{
    return begin[index];
}

extern "C" void (__cdecl *invalid_parameter_noinfo)();
extern bool __cdecl testValue(Value value);

bool __cdecl checkValues(const Container* values)
{
    unsigned int i = 0;
    if (static_cast<unsigned int>(values->end - values->begin) > 0)
    {
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        do
        {
            if (i >= static_cast<unsigned int>(values->end - values->begin))
                invalid();

            if (testValue((*values)[i].convert()))
                return true;

            ++i;
        }
        while (i < static_cast<unsigned int>(values->end - values->begin));
    }
    return false;
}
