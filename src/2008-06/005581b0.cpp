// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct S;

struct Entry {
    S* object;
    void* control;
};

struct Children {
    char padding[12];
    Entry* begin;
    Entry* end;
};

struct S {
    char padding[0x108];
    Children* children;

    S* match(const void* key);
    S* find(const void* key);
};

S* S::find(const void* key)
{
    S* result = match(key);
    if (result)
        return result;

    Children* list = children;
    if (!list)
        return 0;

    unsigned int i = 0;
    if (i < static_cast<unsigned int>(list->end - list->begin)) {
        void (__cdecl *handler)() = invalid_parameter_noinfo;
        do {
            if (i >= static_cast<unsigned int>(list->end - list->begin))
                handler();

            result = list->begin[i].object->find(key);
            if (result)
                return result;

            ++i;
        } while (i < static_cast<unsigned int>(list->end - list->begin));
    }

    return 0;
}
