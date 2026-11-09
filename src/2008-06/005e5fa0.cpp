// from server: 100% by tester
namespace RBX {
class Primitive;

class PrimIterator
{
    Primitive* primitive;
    int count;
public:
    PrimIterator(Primitive* primitive, int count) : primitive(primitive), count(count) {}
};

class Assembly
{
    char gap0[0x1c];
    Primitive* rootPrimitive;
public:
    PrimIterator assemblyPrimBegin() const;
};

PrimIterator Assembly::assemblyPrimBegin() const
{
    return PrimIterator(rootPrimitive, 1);
}
}
