// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class Vector3 { public: float x,y,z; Vector3(const Vector3& o):x(o.x),y(o.y),z(o.z){} }; }
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
        virtual bool isReadOnly() const { return false; }
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
    char data[0x14];
public:
    virtual ~Instance();
};
class VB { public: int v; };
class Pad { char p[0x90-0x1c]; };
class PartInstance : public Instance, public Reflection::DescribedBase, public Pad, public virtual VB
{
public:
    const G3D::Vector3& getV() const;
    void setV(const G3D::Vector3&);
};
}
typedef RBX::Reflection::PropDescriptor<RBX::PartInstance, G3D::Vector3>::GetSetImpl<const G3D::Vector3& (RBX::PartInstance::*)() const, void (RBX::PartInstance::*)(const G3D::Vector3&)> G;
template G3D::Vector3 G::getValue(const RBX::Reflection::DescribedBase*) const;
