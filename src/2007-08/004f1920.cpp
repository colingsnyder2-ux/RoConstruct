// from server: 38% by colin
struct Instance {
    void* vtable;
    void* refcount;
};

struct WeakPtr {
    Instance* ptr;
};

struct RefCounted {
    void* vtable;
    int refcount;
};

struct Container {
    Instance** begin;
    Instance** end;
    Instance** capacity;
};

struct AggregatingSceneManager {
    void* vtable;
    void* field4;
    void removeChild(Instance* child);
    void addChild(Instance* child);
    void processChildren(Container* c);
    void visitDescendants(Container* c);
};

extern "C" {
    int __stdcall InterlockedDecrement(int*);
    int __stdcall InterlockedIncrement(int*);
    void __cdecl _invalid_parameter_noinfo();
}

void AggregatingSceneManager::removeChild(Instance* child) {
    Container* c = (Container*)((char*)this + 0xe0);
    Instance** it = c->begin;
    Instance** end = c->end;
    if (it > end) {
        _invalid_parameter_noinfo();
    }
    Instance** cap = c->capacity;
    if (c->begin > cap) {
        _invalid_parameter_noinfo();
    }
    if (c != c) {
        _invalid_parameter_noinfo();
    }
    while (it != cap) {
        if (it >= c->capacity) {
            _invalid_parameter_noinfo();
        }
        Instance* inst = *it;
        RefCounted* rc = (RefCounted*)((char*)inst + 0x14);
        rc->refcount = 0;
        InterlockedDecrement((int*)0x8bfbe0);
        Container* c2 = (Container*)((char*)this->field4 + 0x98);
        c2->begin = (Instance**)it;
        void* vt = *(void**)this;
        void (*fn)(AggregatingSceneManager*, Instance*, int) = *(void(**)(AggregatingSceneManager*, Instance*, int))((char*)vt + 0x10);
        fn(this, inst, 1);
        if (it >= c->capacity) {
            _invalid_parameter_noinfo();
        }
        it++;
    }
    Instance* p = 0;
    if (this != 0) {
        p = (Instance*)this;
        InterlockedIncrement((int*)((char*)this + 4));
    }
    this->processChildren(c);
    if (p != 0) {
        if (InterlockedDecrement((int*)((char*)p + 4)) == 0) {
            void* vt = *(void**)p;
            void (*fn)(Instance*, int) = *(void(**)(Instance*, int))vt;
            fn(p, 1);
        }
    }
    Instance** newEnd = c->capacity;
    if (c->begin > newEnd) {
        _invalid_parameter_noinfo();
    }
    Instance** first = c->begin;
    if (first > c->capacity) {
        _invalid_parameter_noinfo();
    }
    this->visitDescendants(c);
    if (this != 0) {
        if (InterlockedDecrement((int*)((char*)this + 4)) == 0) {
            void* vt = *(void**)this;
            void (*fn)(AggregatingSceneManager*, int) = *(void(**)(AggregatingSceneManager*, int))vt;
            fn(this, 1);
        }
    }
}
