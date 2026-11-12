// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 004669b0  unit: CWebToolbox  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004669b0
//
// Shape: MFC DECLARE_DYNCREATE CreateObject: return new CWebToolbox; base ctor at 0x461c60,
// object size 0xfc, member at +0xf8 zeroed.
struct CObject;

struct CWebToolboxBase {
    CWebToolboxBase();
    virtual ~CWebToolboxBase();
    char pad[0xf8 - 4];
};

struct CWebToolbox : CWebToolboxBase {
    void* field_f8;
    CWebToolbox() : field_f8(0) {}
    virtual ~CWebToolbox();
    static CObject* __stdcall CreateObject();
};

CObject* __stdcall CWebToolbox::CreateObject()
{
    return (CObject*)new CWebToolbox;
}
