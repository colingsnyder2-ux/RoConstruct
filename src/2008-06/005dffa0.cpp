// from server: 100% by tester
namespace G3D {
class Color3
{
public:
    float r, g, b;

    Color3(const Color3& other) : r(other.r), g(other.g), b(other.b) {}
};
}

namespace RBX {
namespace Reflection {
class DescribedBase
{
public:
    virtual ~DescribedBase();
};

template<typename PropType>
class TypedPropertyDescriptor
{
public:
    class GetSet
    {
        char gap4[4];
    public:
        virtual bool isReadOnly() const = 0;
        virtual PropType getValue(const DescribedBase*) const = 0;
        virtual void setValue(DescribedBase*, const PropType&) const = 0;
    };
};

template<typename Class, typename ReturnType>
class PropDescriptor : public TypedPropertyDescriptor<ReturnType>
{
public:
    template<typename GetFunction, typename SetFunction>
    class GetSetImpl : public TypedPropertyDescriptor<ReturnType>::GetSet
    {
    private:
        GetFunction get;
        SetFunction set;

    public:
        virtual bool isReadOnly() const
        {
            return false;
        }
        virtual ReturnType getValue(const DescribedBase* object) const
        {
            Class* o = (Class*)object;
            return (o->*get)();
        }
        virtual void setValue(DescribedBase* object, const ReturnType& value) const
        {
            Class* o = (Class*)object;
            (o->*set)(value);
        }
    };
};
}

class Instance
{
    char data[0x10];
public:
    virtual ~Instance();
};

class Lighting : public Instance, public Reflection::DescribedBase
{
public:
    G3D::Color3 getTopAmbient() const;
    void setTopAmbient(G3D::Color3 value);
};
}

typedef RBX::Reflection::PropDescriptor<RBX::Lighting, G3D::Color3>::GetSetImpl<G3D::Color3 (RBX::Lighting::*)() const, void (RBX::Lighting::*)(G3D::Color3)> LightingColorGetSet;
template G3D::Color3 LightingColorGetSet::getValue(const RBX::Reflection::DescribedBase*) const;
