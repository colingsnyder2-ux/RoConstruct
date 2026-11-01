// from server: 100% by colin
struct Assembly;

struct Assembly {
    Assembly* getAssembly();
    Assembly* getAssemblyConst();
    Assembly* getAssemblyFromPrimitive(int);
};

Assembly* Assembly::getAssemblyFromPrimitive(int a)
{
    Assembly* p1 = *(Assembly**)(a + 8);
    Assembly* r1 = p1->getAssembly();
    Assembly* p2 = *(Assembly**)(a + 12);
    Assembly* r2 = p2->getAssembly();
    if (r1 == this)
        return r2;
    return r1;
}
