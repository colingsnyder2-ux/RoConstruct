// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Input {
    void* get();
};

struct S;

struct Entry {
    S* object;
    void* auxiliary;
};

struct Entries {
    char reserved[12];
    Entry* first;
    Entry* last;
};

struct S {
    char reserved[0x108];
    Entries* entries;

    unsigned int count();
    void apply(void*);
    void f(int, Input*);
};

void S::f(int, Input* input)
{
    if (input) {
        void* value = input->get();
        if (count() > 0) {
            void (__cdecl *handler)() = invalid_parameter_noinfo;
            do {
                Entries* list = entries;
                if ((unsigned int)(list->last - list->first) <= 0)
                    handler();
                list->first->object->apply(value);
            } while (count() > 0);
        }
        apply(0);
    }
}
