// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};
}
namespace RBX {
class B0 { public: virtual ~B0(); char p[0x14]; };
class DescribedBase { public: virtual ~DescribedBase(); char p[0x74]; };
class VB { public: virtual void v(); };
class PartInstance : public B0, public DescribedBase, public virtual VB {
public:
    G3D::Vector3 getV() const;
};
namespace Reflection {
template<class C, class V> class PropDescriptor {
public:
    class GetSet {
    public:
        virtual V getValue(const DescribedBase* object) const = 0;
        int dummy;
    };
    template<class G, class S> class GetSetImpl : public GetSet {
    public:
        G get;
        S set;
        virtual V getValue(const DescribedBase* object) const;
    };
};
template<class C, class V> template<class G, class S>
V PropDescriptor<C, V>::GetSetImpl<G, S>::getValue(const DescribedBase* object) const
{
    return (static_cast<const C*>(object)->*get)();
}
template class PropDescriptor<PartInstance, G3D::Vector3>::GetSetImpl<G3D::Vector3 (PartInstance::*)() const, void (PartInstance::*)(const G3D::Vector3&)>;
}
}
