// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Object {
    void process(void *);
};

struct Entry {
    Object *object;
    unsigned int value;
};

struct Container {
    char padding[12];
    Entry *first;
    Entry *last;
};

struct S {
    char padding[0x104];
    void *argument;
    Container *container;

    unsigned int size();
    void processAll();
};

void S::processAll()
{
    if (size()) {
        void (__cdecl *handler)() = invalid_parameter_noinfo;
        do {
            Container *c = container;
            void *arg = argument;
            if (static_cast<unsigned int>(c->last - c->first) <= 0)
                handler();
            c->first->object->process(arg);
        } while (size());
    }
}
