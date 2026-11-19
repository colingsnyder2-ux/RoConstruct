// from server: 100% by Intel_Inside
// sibling shape from 00434700/0040c7b0: plain factory, ctor declared not defined
// roc-lang: cpp
// roc-cl: 50727

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct CPatchedControlComboBox
{
    char storage[0x148];
    CPatchedControlComboBox();
};

CPatchedControlComboBox* createPatchedControlComboBox()
{
    return new CPatchedControlComboBox;
}
