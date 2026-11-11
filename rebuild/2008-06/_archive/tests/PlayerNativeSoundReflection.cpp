#include "util/Sound.h"
#include "reflection/property.h"
#include "v8xml/XmlElement.h"

// SoundId follows the existing ContentId XML and text adapter. Behavioral glue;
// original type/template bodies have not yet been byte matched.
namespace RBX { namespace Reflection {
template<> const Type& Type::singleton<Soundscape::SoundId>(){
    static Type type("Content",typeid(Soundscape::SoundId));return type;
}
template<> std::string TypedPropertyDescriptor<Soundscape::SoundId>::getStringValue(const DescribedBase* instance) const{
    return getValue(instance).toString();
}
template<> bool TypedPropertyDescriptor<Soundscape::SoundId>::setStringValue(DescribedBase* instance,const std::string& value) const{
    setValue(instance,Soundscape::SoundId(value));return true;
}
template<> void TypedPropertyDescriptor<Soundscape::SoundId>::readValue(DescribedBase* instance,const XmlElement* element,IReferenceBinder&) const{
    if(!element->isXsiNil()){
        ContentId value;
        if(element->getValue(value))setValue(instance,Soundscape::SoundId(value));
    }
}
template<> void TypedPropertyDescriptor<Soundscape::SoundId>::writeValue(const DescribedBase* instance,XmlElement* element) const{
    element->setValue(ContentId(getValue(instance)));
}
} }
