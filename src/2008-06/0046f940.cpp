// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct StringData {
    char storage[20];
    unsigned int length;
};

extern char *(__thiscall *string_myptr)(StringData *);

struct S {
    StringData *owner;
    char *position;
    char *f();
};

char *S::f()
{
    if (owner == reinterpret_cast<StringData *>(-4))
        goto done;

    {
        void (__cdecl *invalid)() = invalid_parameter_noinfo;
        if (!owner)
            invalid();
        char *end = string_myptr(owner) + owner->length;
        if (reinterpret_cast<unsigned int>(position) >=
            reinterpret_cast<unsigned int>(end))
            invalid();
    }

done:
    return position;
}
