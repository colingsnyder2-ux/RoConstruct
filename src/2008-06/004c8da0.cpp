// from server: 100% by king_originala
typedef void (__thiscall *ConstructFunction)(void*, unsigned int,
                                           unsigned int, unsigned int);

extern "C" void __cdecl releaseObject(void* object);

struct ObjectSet
{
    bool insert(void* object);
};

struct Receiver
{
    char padding0[12];
    ObjectSet objects;
    char padding1[35];
    unsigned int count;

    bool construct(ConstructFunction function, unsigned int a,
                   unsigned int b, unsigned int c, void* object);
};

bool Receiver::construct(ConstructFunction function, unsigned int a,
                         unsigned int b, unsigned int c, void* object)
{
    function(object, a, b, c);

    try
    {
        if (!objects.insert(object))
        {
            releaseObject(object);
            --count;
            return false;
        }
        return true;
    }
    catch (...)
    {
        releaseObject(object);
        --count;
        throw;
    }
}
