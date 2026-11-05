// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
class CPatchedControlComboBox {
public:
    CPatchedControlComboBox();
    static CPatchedControlComboBox* __stdcall CreateObject();
private:
    char pad[0x190];
};
CPatchedControlComboBox* __stdcall CPatchedControlComboBox::CreateObject() { return new CPatchedControlComboBox; }
