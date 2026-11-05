// from server: 100% by king_originala
struct Object {
    void apply(void*);
};

struct Entry {
    Object* object;
    void* ownership;
};

struct Arguments {
    char padding[12];
    Entry* first;
    Entry* last;
};

struct Service {
    void* value();
};

extern "C" void* __cdecl findService(void*);
extern "C" void* __cdecl castObject(void*, int, const void*, const void*, int);

extern const char instanceType[];
extern const char hopperBinType[];

struct Root {
    void dispatch(Arguments*, void*);
    void fallback(Arguments*, Root*, void*);
    void finish(void*);
};

void Root::dispatch(Arguments* args, void* context)
{
    if (((unsigned int)args->last - (unsigned int)args->first) / 8 == 1) {
        Object* object = args->first->object;
        if (castObject(object, 0, instanceType, hopperBinType, 0)) {
            Service* service = (Service*)findService(this);
            if (service) {
                object->apply(service->value());
                return;
            }
        }
    }

    fallback(args, this, context);
    finish(context);
}
