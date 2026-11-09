// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern "C" void* __stdcall getDescriptor(void*, void*);
extern "C" void* __cdecl getSingleton();

struct Base {
    unsigned char storage[52];
    Base(void*);
    virtual ~Base();
};

struct Value {
    void* data;
    unsigned int tag;
    Value();
    ~Value();
};

struct TimedObject {
    double lifetime;
    TimedObject(double);
    virtual ~TimedObject();
};

inline TimedObject::TimedObject(double t) : lifetime(t) {}

struct Owner {
    TimedObject* pointer;
    Owner(TimedObject*);
    ~Owner();
};

inline Owner::Owner(TimedObject* p) : pointer(p) {}

struct DebrisService : Base {
    void* first;
    void* second;
    Value value;
    void* singleton;
    Owner object;

    DebrisService(void*, void*, void*, unsigned int, unsigned int,
                  double, void*);
    virtual ~DebrisService();
    void configure(unsigned int, unsigned int);
};

DebrisService::DebrisService(
    void* a, void* b, void* descriptorArgument,
    unsigned int c, unsigned int d, double lifetime,
    void* descriptorContext)
    : Base(getDescriptor(descriptorArgument, descriptorContext)),
      first(a),
      second(b),
      value(),
      singleton(getSingleton()),
      object(new TimedObject(lifetime))
{
    configure(c, d);
}
