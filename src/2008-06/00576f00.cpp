// from server: 100% by colin
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Object {
    void acquire();
};

struct Reference {
    void* value;
    Reference& operator=(const Reference&);
};

struct Source {
    char padding[0x25c];
    Object* object;
    Reference reference;
};

struct Guard {
    Object* object;
    bool acquired;

    Guard(Object* p) : object(p), acquired(false) {
        object->acquire();
        acquired = true;
    }
};

struct S {
    Object* object;
    Reference reference;
    Guard* guard;

    void set(Source*);
};

void S::set(Source* source) {
    if (source) {
        object = source->object;
        reference = source->reference;
        guard = new Guard(object);
    }
}
