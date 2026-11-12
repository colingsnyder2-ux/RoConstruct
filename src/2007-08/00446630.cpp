// from server: 100% by EspClaude
// from server: 46% by colin
// roc 2007-08 00446630  unit: VCRenderSettings::?$FactoryProduct  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00446630
#include <typeinfo>
#include <string>
#include <map>
#include <vector>

class CRenderSettings {
public:
    enum AASamples { AA_NONE = 1, AA_4 = 4, AA_8 = 8 };
};

class EnumDescriptor {
public:
    EnumDescriptor(const char* name, const std::type_info& type);   // 0x587360
    virtual ~EnumDescriptor();
private:
    char base_data[0x24];        // base object spans 0x00..0x27
};

template<class E>
class EnumDesc : public EnumDescriptor {
public:
    EnumDesc();
    virtual ~EnumDesc();
    void addPair(E value, const char* name);   // 0x4463f0
private:
    std::map<E, int> valueToIndex;             // +0x28, node value 8 bytes (isnil +0x15)
    std::map<int, E> indexToValue;             // +0x34
    std::vector<E> values;                     // +0x40
    std::map<E, std::string> valueToName;      // +0x50, node value 0x20 bytes (isnil +0x2d)
    std::map<std::string, E> nameToValue;      // +0x5c
    std::vector<int> v68;                      // +0x68
    std::vector<int> v78;                      // +0x78
    std::vector<int> v88;                      // +0x88
};

template<>
EnumDesc<CRenderSettings::AASamples>::EnumDesc()
    : EnumDescriptor("AASamples", typeid(CRenderSettings::AASamples))
{
    addPair(CRenderSettings::AA_NONE, "None");
    addPair(CRenderSettings::AA_4, "4");
    addPair(CRenderSettings::AA_8, "8");
}
