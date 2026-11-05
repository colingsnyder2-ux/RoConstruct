// from server: 100% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>

namespace RBX {
class Name {
public:
    static const Name& declare(const char* name, int dictionaryIndex);
    static const Name& lookup(const char* name);
};
extern const Name& name_name;
class XmlValue {
public:
    bool getValue(const Name*& value) const;
    bool getValue(std::string& value) const;
    bool getValue(float& value) const;
};
class XmlAttribute {
public:
    void* pad[2];
    XmlValue value;
};
class XmlElement {
public:
    XmlElement* next;
    XmlElement* firstChild;
    char pad[8];
    XmlValue value;
    bool isXsiNil() const;
    const XmlAttribute* findAttribute(const Name& name) const;
};
class IReferenceBinder;
struct once_flag { long v; };
void __cdecl call_once(void (*func)(), once_flag& flag);
namespace Reflection {
template<class T> class EnumDesc {
public:
    static void init();
    static once_flag flag;
    static EnumDesc& instance();
    static EnumDesc& singleton() { call_once(&init, flag); return instance(); }
    bool convertToValue(const Name& name, T& value) const;
};
}
enum NormalId { NORM_X };
enum SurfaceInput { NOINPUT };
struct ConstraintResult { bool ok() const; };
ConstraintResult& __stdcall parseConstraint(const char* s, NormalId& value);

class FaceInstance {
public:
    void setFace(NormalId face);
    void setSurfaceInput(SurfaceInput input);
    void setParamA(float value);
    void setParamB(float value);
    void readProperties(const XmlElement* element, IReferenceBinder& binder);
};

void FaceInstance::readProperties(const XmlElement* element, IReferenceBinder& binder)
{
    static const Name& name_Type = Name::declare("Type", -1);
    static const Name& name_SurfaceInput = Name::declare("SurfaceInput", -1);
    static const Name& name_ParamA = Name::declare("ParamA", -1);
    static const Name& name_ParamB = Name::declare("ParamB", -1);
    static const Name& name_Constraint = Name::declare("Constraint", -1);

    for (const XmlElement* child = element->firstChild; child; child = child->next) {
        const Name* name = 0;
        if (child->isXsiNil())
            continue;
        const XmlAttribute* attr = child->findAttribute(name_name);
        if (!attr || !attr->value.getValue(name))
            continue;
        if (name == &name_Type) {
            std::string value;
            if (child->value.getValue(value)) {
                NormalId face;
                if (Reflection::EnumDesc<NormalId>::singleton().convertToValue(Name::lookup(value.c_str()), face))
                    setFace(face);
                else
                    setFace((NormalId)0);
            }
        } else if (name == &name_SurfaceInput) {
            std::string value;
            if (child->value.getValue(value)) {
                SurfaceInput input;
                if (Reflection::EnumDesc<SurfaceInput>::singleton().convertToValue(Name::lookup(value.c_str()), input))
                    setSurfaceInput(input);
            }
        } else if (name == &name_ParamA) {
            float f;
            if (child->value.getValue(f))
                setParamA(f);
        } else if (name == &name_ParamB) {
            float f;
            if (child->value.getValue(f))
                setParamB(f);
        } else if (name == &name_Constraint) {
            std::string value;
            if (child->value.getValue(value)) {
                NormalId face;
                if (parseConstraint(value.c_str(), face).ok() && face)
                    setFace(face);
            }
        }
    }
}
}
