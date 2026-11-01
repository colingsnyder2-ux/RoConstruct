// from server: 100% by king_originala
typedef void (__cdecl *Manager)(void *, void *, int);

struct Object {
    unsigned char padding0[8];
    Manager *manager;
    unsigned char padding1[4];
    unsigned char storage[40];
};

extern void *__cdecl allocate(unsigned int);
extern void __cdecl copy_construct(void *, const void *);
extern void __cdecl deallocate(void *);

extern bool (__thiscall *type_equal)(const void *, const void *);
extern const unsigned char target_type[];

void __cdecl manage(const void *const *source, void **destination, int operation)
{
    if (operation == 0) {
        const void *value = *source;
        void *result = allocate(56);
        copy_construct(result, value);
        *destination = result;
    } else if (operation == 1) {
        Object *object = static_cast<Object *>(*destination);
        if (object->manager) {
            Manager function = *object->manager;
            void *buffer = object->storage;
            if (function)
                function(buffer, buffer, 1);
            object->manager = 0;
        }
        deallocate(object);
        *destination = 0;
    } else {
        if (type_equal(*destination, target_type))
            *destination = const_cast<void *>(*source);
        else
            *destination = 0;
    }
}
