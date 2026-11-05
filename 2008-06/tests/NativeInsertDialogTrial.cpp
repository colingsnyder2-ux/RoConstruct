#include "NativeInsertServiceTrial.cpp"
typedef char dialog_size[(sizeof(CInsertObjectDialog)==0xfc)?1:-1];
typedef char selected_offset[(offsetof(CInsertObjectDialog,selected)==0x74)?1:-1];
typedef char objects_offset[(offsetof(CInsertObjectDialog,objects)==0x7c)?1:-1];
typedef char title_offset[(offsetof(CInsertObjectDialog,title)==0x94)?1:-1];
typedef char result_offset[(offsetof(CInsertObjectDialog,result)==0x98)?1:-1];
typedef char images_offset[(offsetof(CInsertObjectDialog,images)==0xa0)?1:-1];
typedef char list_offset[(offsetof(CInsertObjectDialog,list)==0xa8)?1:-1];
CInsertObjectDialog::CInsertObjectDialog(boost::shared_ptr<RBX::Instance> value, CWnd* parent)
    : CDialog(value ? 107 : 214, parent), selected(value), title(">Authoring") {}
CInsertObjectDialog::~CInsertObjectDialog() {}
