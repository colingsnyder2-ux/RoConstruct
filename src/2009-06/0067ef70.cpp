// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Primitive;
class ContactManager { public: void onPrimitiveChanged(Primitive* p); };
template<class T>
struct MemFnBinder {
    void (T::*f)(Primitive*);
    T* obj;
    MemFnBinder(void (T::*ff)(Primitive*), T* o) { obj = o; f = ff; }
    void operator()(Primitive* p) const { (obj->*f)(p); }
};
template<class T> inline MemFnBinder<T> bindMem(void (T::*f)(Primitive*), T* o) { return MemFnBinder<T>(f, o); }
class Assembly {
public:
    Primitive* getAssemblyPrimitive();
    template<class F> void visitPrimitives(F f, Primitive* p);
};
class World {
public:
    virtual ~World();
    char pad[0xb0 - 4];
    ContactManager* contactManager;
    void onAssemblyChanged(Assembly* a);
};
void World::onAssemblyChanged(Assembly* a)
{
    a->visitPrimitives(bindMem(&ContactManager::onPrimitiveChanged, contactManager), a->getAssemblyPrimitive());
}
}
