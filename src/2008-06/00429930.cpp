// from server: 100% by king_originala
typedef void (__cdecl *Cleanup)(void *, void *, int);

struct Adapter
{
    Cleanup *cleanup;
    unsigned long reserved;
    unsigned char object[24];
};

extern "C" void *__cdecl allocate(unsigned int);
extern "C" void __cdecl construct(void *, void *);
extern "C" void __cdecl release(void *);

extern const unsigned char adapterType[];
extern bool (__thiscall *sameType)(const void *, const void *);

void __cdecl manage(void **source, void **destination, int operation)
{
    if (operation == 0)
    {
        void *value = *source;
        void *storage = allocate(32);
        construct(storage, value);
        *destination = storage;
    }
    else if (operation == 1)
    {
        Adapter *storage = static_cast<Adapter *>(*destination);
        if (storage->cleanup)
        {
            Cleanup cleanup = *storage->cleanup;
            void *object = storage->object;
            if (cleanup)
                cleanup(object, object, 1);
            storage->cleanup = 0;
        }
        release(storage);
        *destination = 0;
    }
    else
    {
        if (sameType(*destination, adapterType))
            *destination = *source;
        else
            *destination = 0;
    }
}
