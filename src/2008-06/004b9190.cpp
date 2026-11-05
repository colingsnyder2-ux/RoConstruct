// from server: 100% by king_originala
extern void* __cdecl operator new(unsigned int);
extern void __cdecl operator delete(void*);

struct Object {
    unsigned char storage[16];
    Object();
};

struct Count {
    void* control;
    void initialize(Object*);
};

struct Shared {
    Object* object;
    Count count;
    Shared();
    Shared(const Shared&);
};

inline Shared::Shared()
{
}

extern void __cdecl func_0047d410(Count*, Object*, Object*);

Shared __cdecl func_004b9190()
{
    Shared result;
    Object* object;
    *reinterpret_cast<Object* volatile*>(&object) = 0;
    object = new Object;
    result.object = object;
    result.count.initialize(object);
    func_0047d410(&result.count, object, object);
    return result;
}
