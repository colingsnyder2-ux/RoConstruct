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
    char gap0[0x154];
    float dopplerScale;
    float distanceFactor;
    void onSettingsChanged(const Reflection::PropertyDescriptor&);
public:
    static Reflection::BoundProp<float, 1> prop_DopplerScale;
};

Reflection::BoundProp<float, 1> SoundService::prop_DopplerScale("DopplerScale", "Data", &SoundService::dopplerScale, &SoundService::onSettingsChanged, Reflection::PropertyDescriptor::STANDARD);
}
}
