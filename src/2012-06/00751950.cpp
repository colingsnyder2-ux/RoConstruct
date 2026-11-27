// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Part {
public:
    char body[0x68];
    Part(const Part& other);
    Part& operator=(const Part& other);
};
class PVInstanceBase { public: char pad[0x84]; };
class IRenderable { public: virtual ~IRenderable(); };
class PartInstance : public PVInstanceBase, public virtual IRenderable {
public:
    Part getPart() const;
};
template<typename T, typename U>
class ComputeProp
{
private:
    mutable T val;
    mutable bool dirty;
    U* object;
    T(U::* getFunc)() const;
public:
    T getValue() const
    {
        if (dirty)
        {
            val = (object->*getFunc)();
            dirty = false;
        }
        return val;
    }
};
template class ComputeProp<Part, PartInstance>;
}
