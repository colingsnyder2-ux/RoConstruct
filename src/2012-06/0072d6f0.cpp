// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct PropDesc { int dummy; };
extern PropDesc prop_BackendAccoutrementState;
struct Accoutrement
{
    char pad[0xbc];
    int backendAccoutrementState;
    void raisePropertyChanged(const PropDesc& desc);
    void setBackendAccoutrementState(int value);
};
void Accoutrement::setBackendAccoutrementState(int value)
{
    if (value != backendAccoutrementState)
    {
        backendAccoutrementState = value;
        raisePropertyChanged(prop_BackendAccoutrementState);
    }
}
