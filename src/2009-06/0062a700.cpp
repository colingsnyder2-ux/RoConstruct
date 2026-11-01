// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost { namespace signals { class connection { public: void disconnect() const; }; } }
namespace RBX {
class ServiceProvider;
namespace Reflection { class PropertyDescriptor; }
extern Reflection::PropertyDescriptor prop_BackendToolState;
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor&);
};
class Tool : public Instance {
public:
    enum ToolState { NOTHING, HAS_HANDLE, IN_WORKSPACE, IN_CHARACTER, HAS_TORSO, EQUIPPED };
private:
    char pad[0x120];
    ToolState backendToolState;
    char pad2[0x160 - 0x124];
    boost::signals::connection handleTouched;
public:
    void setBackendToolStateNoReplicate(int value);
    void setBackendToolState(int value)
    {
        if (value != backendToolState) {
            setBackendToolStateNoReplicate(value);
            raisePropertyChanged(prop_BackendToolState);
        }
    }
    void connectTouchEvent();
    void upTo_InWorkspace() {}
    void upTo_InCharacter();
    void upTo_HasTorso();
    void upTo_Equipped();
    void downFrom_Equipped();
    void downFrom_HasTorso();
    void downFrom_InCharacter();
    void downFrom_InWorkspace() {}
    void downFrom_HasHandle() { handleTouched.disconnect(); }
    void setDesiredState(ToolState desiredState, const ServiceProvider* serviceProvider);
};

void Tool::setDesiredState(ToolState desiredState, const ServiceProvider* serviceProvider)
{
    do
    {
        if (backendToolState < desiredState)
        {
            switch (backendToolState)
            {
            case HAS_TORSO:
                upTo_Equipped();
                break;
            case IN_CHARACTER:
                upTo_HasTorso();
                break;
            case IN_WORKSPACE:
                upTo_InCharacter();
                break;
            case HAS_HANDLE:
                upTo_InWorkspace();
                break;
            case NOTHING:
                connectTouchEvent();
                break;
            }
            setBackendToolState(backendToolState + 1);
        }
        else if (desiredState < backendToolState)
        {
            switch (backendToolState)
            {
            case EQUIPPED:
                downFrom_Equipped();
                break;
            case HAS_TORSO:
                downFrom_HasTorso();
                break;
            case IN_CHARACTER:
                downFrom_InCharacter();
                break;
            case IN_WORKSPACE:
                downFrom_InWorkspace();
                break;
            case HAS_HANDLE:
                downFrom_HasHandle();
                break;
            }
            setBackendToolState(backendToolState - 1);
        }
    } while (desiredState != backendToolState);
}
}
