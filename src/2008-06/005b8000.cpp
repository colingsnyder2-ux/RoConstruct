// from server: 100% by king_originala
struct TypeInfo {};

extern const TypeInfo emptyType;
extern const TypeInfo soundType;
extern const unsigned long badCastVtable;
extern bool (__thiscall *typeEqual)(const TypeInfo*, const TypeInfo&);
extern void (__thiscall *constructBadCast)(void*, const char*);
extern __declspec(noreturn) void __cdecl raise_bad_cast(const void*);

struct Placeholder {
    virtual ~Placeholder();
    virtual const TypeInfo& type() const;
};

struct Any {
    Placeholder* content;
};

struct BadCast {
    unsigned long data[3];
    BadCast();
    ~BadCast();
};

inline BadCast::BadCast()
{
    constructBadCast(this, "bad cast");
    data[0] = reinterpret_cast<unsigned long>(&badCastVtable);
}

void* __cdecl castSound(Any* value)
{
    if (value) {
        const TypeInfo* type = value->content
            ? &value->content->type()
            : &emptyType;
        if (typeEqual(type, soundType)) {
            void* result = reinterpret_cast<char*>(value->content) + 4;
            if (result)
                return result;
        }
    }

    BadCast error;
    raise_bad_cast(&error);
}
