// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Rect {
    float x, y, z, w;
    bool operator!=(const Rect &) const;
};

__forceinline bool Rect::operator!=(const Rect &other) const
{
    return x != other.x || y != other.y ||
           z != other.z || w != other.w;
}

struct Context;
struct Item;
struct S;

struct ContextVTable {
    char padding[44];
    void (__thiscall *draw)(Context *, const Rect &);
};

struct Context {
    ContextVTable *vtable;
};

struct ItemVTable {
    char padding[96];
    void (__thiscall *render)(Item *, Context *);
};

struct Item {
    ItemVTable *vtable;
};

struct Entry {
    void *object;
    void *owner;
    void *get() const;
};

__forceinline void *Entry::get() const
{
    return object;
}

struct Children {
    char padding[12];
    Entry *begin;
    Entry *end;
};

struct SVTable {
    char padding[84];
    bool (__thiscall *enabled)(S *);
};

struct S {
    SVTable *vtable;
    char padding0[260];
    Children *children;
    char padding1[56];
    Rect rectangle;

    unsigned int count();
    Rect query(const Rect &);
    void f(Context *);
};

extern const Rect &__cdecl emptyRectangle();
extern "C" void (__cdecl *_invalid_parameter_noinfo)();
extern "C" void *__cdecl runtimeCast(
    void *, int, const void *, const void *, int);
extern char instanceDescriptor;
extern char itemDescriptor;

void S::f(Context *context)
{
    if (vtable->enabled(this)) {
        const Rect &empty = emptyRectangle();

        if (rectangle != empty)
            context->vtable->draw(context, query(rectangle));

        for (unsigned int i = 0; i < count(); ++i) {
            Children *list = children;
            if (i >= static_cast<unsigned int>(list->end - list->begin))
                _invalid_parameter_noinfo();

            Item *item = static_cast<Item *>(
                runtimeCast(list->begin[i].get(), 0,
                            &instanceDescriptor, &itemDescriptor, 0));
            if (item)
                item->vtable->render(item, context);
        }
    }
}
