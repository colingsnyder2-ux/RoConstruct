// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /EHsc /Ob0
// roc-lib: mfc-9.0-shared-rtm roc_unit_6b26449c3ccaeba4.cpp

// Candidate translation unit (score above; library headers required).
#include <afx.h>
#undef _AFX_ENABLE_INLINES
#include <afxwin.h>
#line 103 "C:\\Program Files\\Microsoft Visual Studio 9.0\\VC\\atlmfc\\include\\afxwin1.inl"
CGdiObject::~CGdiObject()
{
    AFX_BEGIN_DESTRUCTOR

        DeleteObject();

    AFX_END_DESTRUCTOR
}
