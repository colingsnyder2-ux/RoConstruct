// from server: 100% by Intel
﻿// from server: 89% by EspClaude
// roc-cl: 50727
// 2007-08 hand variant: CRobloxDoc::context sits at 0x78 here (0x94 in the 2008-06 original)
// from server: 100% by king_originala
// roc 2008-06 0044fc50  unit: CRobloxDoc  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044fc50
//

struct Dialog
{
    char storage[0x12C];
    Dialog(void *, int);
    virtual ~Dialog();
    int DoModal();
};

struct CRobloxDoc
{
    char padding[0x78];
    void *context;
    void func_0044fc50();
};

void CRobloxDoc::func_0044fc50()
{
    Dialog dialog(context, 0);
    dialog.DoModal();
}
