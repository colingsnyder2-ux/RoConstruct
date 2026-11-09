// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
namespace Reflection { class PropertyDescriptor { public: char data[0x50]; }; }
class Instance {
public:
    void setName(const std::string& value);
    void raisePropertyChanged(const Reflection::PropertyDescriptor& desc);
    static const Reflection::PropertyDescriptor desc_Name;
    char pad[0x54];
    std::string name;
};
void Instance::setName(const std::string& value)
{
    if (name != value) {
        if (value.size() > 100)
            name = value.substr(0, 100);
        else
            name = value;
        raisePropertyChanged(desc_Name);
    }
}
}
