// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: minimal local declarations; real headers not available for this excerpt.
namespace RBX {
class Instance;
namespace Reflection {
class PropertyDescriptor;
template<class C, class Sig>
class SignalDesc {
public:
    SignalDesc(const char* name, const char* category);
    ~SignalDesc();
    char storage[64];
};
}
class Instance {
public:
    static Reflection::SignalDesc<Instance, void(const Reflection::PropertyDescriptor*)> event_propertyChanged;
};
}

RBX::Reflection::SignalDesc<RBX::Instance, void(const RBX::Reflection::PropertyDescriptor*)> RBX::Instance::event_propertyChanged("propertyChanged", "Changed");
