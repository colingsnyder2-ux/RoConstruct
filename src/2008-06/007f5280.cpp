// from server: 100% by tester
namespace RBX {
namespace Reflection {
class PropertyDescriptor
{
public:
    enum Functionality { STANDARD = 5 };
};

template<typename PropType, int Unknown>
class BoundProp
{
    char data[0x40];
public:
    template<typename Class>
    BoundProp(const char* name, const char* category, PropType (Class::*member),
              void (Class::*changed)(const PropertyDescriptor&), PropertyDescriptor::Functionality flags);
    ~BoundProp();
};
}

class Instance { public: virtual ~Instance(); };
class Listener { public: virtual ~Listener(); };
namespace Soundscape {
class SoundService : public Instance, public Listener
{
    char gap0[0x15c];
    float rolloffScale;
    void onSettingsChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<float, 1> prop_RolloffScale;
};

Reflection::BoundProp<float, 1> SoundService::prop_RolloffScale("RolloffScale", "Data", &SoundService::rolloffScale, &SoundService::onSettingsChanged, (Reflection::PropertyDescriptor::Functionality)5);
}
}
