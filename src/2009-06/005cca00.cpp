// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor { public: int x; }; }
extern Reflection::PropertyDescriptor prop_errorReporting;
class DebugSettings {
public:
    enum ErrorReporting { DontReport, Prompt, Report };
    virtual ~DebugSettings();
    void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
    char pad[0x9c - 4];
    ErrorReporting errorReporting;
    void setErrorReporting(ErrorReporting value);
};
void DebugSettings::setErrorReporting(ErrorReporting value)
{
    if (value != errorReporting)
    {
        errorReporting = value;
        raisePropertyChanged(prop_errorReporting);
    }
}
}
