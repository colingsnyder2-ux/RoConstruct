// from server: 100% by Yeetserama
// hypothesis: factory returning new CPatchedControlComboBox, two polymorphic
// base subobjects at offsets 0x00 and 0x20 (CXTPEdit layout), total size 0x1d4.

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*) throw();

struct XBaseA
{
    XBaseA();
    virtual ~XBaseA();
    char storage[0x1c];
};

struct XBaseB
{
    XBaseB();
    virtual ~XBaseB();
};

struct CXTPEdit : XBaseA, XBaseB
{
    CXTPEdit();
    virtual ~CXTPEdit();
    char storage[0x1d4 - 0x24];
};

struct CPatchedControlComboBox : CXTPEdit
{
    virtual ~CPatchedControlComboBox();
};

CPatchedControlComboBox* func_00430490()
{
    return new CPatchedControlComboBox;
}
