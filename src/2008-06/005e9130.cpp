// from server: 100% by king_originala
struct PartInstance;

struct GetSetImpl {
    static PartInstance* get(PartInstance* p);
};

struct PhysicsService {
    void g(PartInstance* p);
};

struct S {
    void f(void* unused, PartInstance* p);
};

void S::f(void* unused, PartInstance* p)
{
    PartInstance* part = GetSetImpl::get(p);
    ((PhysicsService*)((char*)this - 0x134))->g(part);
}
