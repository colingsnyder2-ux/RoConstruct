// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor { public: PropertyDescriptor(); int x; }; }
class Instance { public: void raisePropertyChanged(const Reflection::PropertyDescriptor&); };
class DebugSettings : public Instance {
public:
    enum ErrorReporting { DontReport, Prompt, Report };
    char pad[0x94];
    ErrorReporting errorReporting;
    void setErrorReporting(ErrorReporting value);
};
extern Reflection::PropertyDescriptor prop_errorReporting;
void DebugSettings::setErrorReporting(ErrorReporting value)
{
    if (value != errorReporting)
    {
        errorReporting = value;
        raisePropertyChanged(prop_errorReporting);
    }
}
}
