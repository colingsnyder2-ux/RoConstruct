// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Object {
    unsigned char storage[36];
    ~Object();
};

extern "C" void __cdecl construct_object(Object*, const Object*);

struct TypeInfo {};
extern const TypeInfo object_type;
extern bool (__thiscall* type_equal)(const TypeInfo*, const TypeInfo&);

void __cdecl manage_object(Object* const* source, Object** destination, int operation)
{
    if (operation == 0) {
        Object* original = *source;
        Object* copy = static_cast<Object*>(operator new(36));
        construct_object(copy, original);
        *destination = copy;
    } else if (operation == 1) {
        Object* object = *destination;
        object->~Object();
        operator delete(object);
        *destination = 0;
    } else {
        if (type_equal(reinterpret_cast<const TypeInfo*>(*destination), object_type))
            *destination = *source;
        else
            *destination = 0;
    }
}
