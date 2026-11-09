// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern void __cdecl construct(void*, void*);

struct Payload {
    void destroy();
};

struct TypeTag;
extern const TypeTag target_type;
extern bool (__thiscall *type_equal)(const void*, const TypeTag*);

void __cdecl manage(void** source, void** destination, int operation)
{
    if (operation == 0) {
        void* value = *source;
        void* storage = operator new(0x50);
        construct(storage, value);
        *destination = storage;
    } else if (operation == 1) {
        void* storage = *destination;
        reinterpret_cast<Payload*>(static_cast<char*>(storage) + 8)->destroy();
        operator delete(storage);
        *destination = 0;
    } else {
        if (type_equal(*destination, &target_type))
            *destination = *source;
        else
            *destination = 0;
    }
}
