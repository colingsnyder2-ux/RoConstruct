// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace std {
template<class T> class auto_ptr {
public:
    T* p;
    explicit auto_ptr(T* x = 0) throw() : p(x) {}
    auto_ptr(auto_ptr& o) throw() : p(o.release()) {}
    ~auto_ptr() { delete p; }
    T* release() throw() { T* t = p; p = 0; return t; }
};
}
namespace boost { struct once_flag { long v; }; void call_once(once_flag& f, void (*fn)()); }
namespace RBX {
class PartInstance;
namespace Reflection {
class Type;
class EnumDescriptor;
class PropertyDescriptor {
public:
    enum Functionality { STANDARD = 7 };
};
class EnumPropertyDescriptor {
public:
    EnumPropertyDescriptor(const Type& type, const EnumDescriptor& e, const char* name, const char* category, PropertyDescriptor::Functionality f);
    virtual ~EnumPropertyDescriptor();
    char pad[0x14];
};
template<class E> class EnumDesc {
public:
    static void init();
    static boost::once_flag flag;
    static EnumDesc& singleton2();
    static EnumDesc& singleton() { boost::call_once(flag, &init); return singleton2(); }
};
template<class T> class TypeOf { public: static const Type& impl(); static const Type& singleton() { return impl(); } };
template<class C, class V> class GetSet { public: int dummy; };
template<class C, class V> class TypedEnumPropertyDescriptor : public EnumPropertyDescriptor {
public:
    const EnumDescriptor& enumDescriptor;
    TypedEnumPropertyDescriptor(const EnumDescriptor& e, const char* name, const char* category, PropertyDescriptor::Functionality f)
        : EnumPropertyDescriptor(TypeOf<V>::singleton(), e, name, category, f), enumDescriptor(e) {}
};
template<class C, class V> class EnumPropDescriptor : public TypedEnumPropertyDescriptor<C, V> {
public:
    std::auto_ptr<GetSet<C, V> > getset;
    EnumDesc<V>& enumDesc;
    template<class G, class S>
    static std::auto_ptr<GetSet<C, V> > make(G g, S s);
    template<class G, class S>
    EnumPropDescriptor(const char* name, const char* category, G g, S s, PropertyDescriptor::Functionality f)
        : TypedEnumPropertyDescriptor<C, V>((const EnumDescriptor&)EnumDesc<V>::singleton(), name, category, f),
          getset(make(g, s).release()), enumDesc(EnumDesc<V>::singleton()) {}
    virtual ~EnumPropDescriptor();
};
}
class A1 { public: int a; };
class A2 { public: int b; };
class Camera : public A1, public A2 {
public:
    enum CameraType { A };
    CameraType getCameraType() const;
    void setCameraType(CameraType);
};
template RBX::Reflection::EnumPropDescriptor<Camera, Camera::CameraType>::EnumPropDescriptor(const char*, const char*, Camera::CameraType (Camera::*)() const, void (Camera::*)(Camera::CameraType), RBX::Reflection::PropertyDescriptor::Functionality);
}
