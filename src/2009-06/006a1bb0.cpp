// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
    float getX() const;
    void setX(float value);
};
}
typedef RBX::Reflection::PropDescriptor<RBX::PartInstance, float>::GetSetImpl<float (RBX::PartInstance::*)() const, void (RBX::PartInstance::*)(float)> G;
template void G::setValue(RBX::Reflection::DescribedBase*, const float&) const;
