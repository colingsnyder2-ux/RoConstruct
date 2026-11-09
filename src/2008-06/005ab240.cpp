// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct TypeInfo {};
typedef bool (__thiscall *TypeEqual)(const TypeInfo*, const TypeInfo&);
extern TypeEqual typeEqual;
extern const TypeInfo emptyType;
extern const TypeInfo sharedType;

struct Control {
    void* vtable;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;
};

struct Placeholder {
    virtual void destroy();
    virtual const TypeInfo& type() const;
};

struct Holder : Placeholder {
    Shared value;
};

struct Any {
    Placeholder* content;
};

struct BadCast {
    void* vtable;
    const char* message;
    int ownsMessage;
    BadCast(const char*);
    ~BadCast();
};

typedef void (__thiscall *BadCastConstructor)(BadCast*, const char*);
extern BadCastConstructor constructBadCast;
extern void* badCastVtable;
__declspec(noreturn) void __cdecl throwBadCast(const BadCast&);

__forceinline BadCast::BadCast(const char* text)
{
    constructBadCast(this, text);
    vtable = &badCastVtable;
}

Shared* __cdecl extractShared(Shared* result, const Any* source)
{
    volatile int constructed = 0;
    Shared* value = 0;

    if (source) {
        const TypeInfo& type =
            source->content ? source->content->type() : emptyType;
        if (typeEqual(&type, sharedType))
            value = &static_cast<Holder*>(source->content)->value;
    }

    if (!value) {
        BadCast exception("bad cast");
        throwBadCast(exception);
    }

    result->object = value->object;
    result->control = value->control;
    if (result->control) {
        volatile long* references = &result->control->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(references, 1);
    }
    return result;
}
