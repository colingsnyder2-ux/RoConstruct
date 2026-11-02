#pragma once
#include <afxwin.h>
#include <afxcmn.h>
#include <boost/shared_ptr.hpp>
#include <vector>
#include "CClassImages.h"

namespace RBX {
class Instance;
namespace Reflection {
class ClassDescriptor;
}
}

// Inactive layout recovery from CRuntimeClass 0080f2e0 (size 0xfc), constructor 0041fe00 and
// destructor 0041ff40. The constructor selects dialog template 107 with a parent and 214
// without one.
class CInsertObjectDialog : public CDialog {
    DECLARE_DYNAMIC(CInsertObjectDialog)
    DECLARE_MESSAGE_MAP()
public:
    CInsertObjectDialog(boost::shared_ptr<RBX::Instance> parent, CWnd* parentWindow);
    virtual ~CInsertObjectDialog();
    virtual BOOL OnInitDialog();
    virtual void DoDataExchange(CDataExchange*);
    void OnNMDblclk(NMHDR*, LRESULT*);
    // Original 004202b0; recursive over derived class descriptors. Body pending Metadata/settings layouts.
    void addClasses(const RBX::Reflection::ClassDescriptor&);
    static int CALLBACK compareItems(LPARAM, LPARAM, LPARAM);

    boost::shared_ptr<RBX::Instance> parent;                      // +0x74
    std::vector<boost::shared_ptr<RBX::Instance> > instances;     // +0x7c
    CString className;                                            // +0x94
    boost::shared_ptr<RBX::Instance> selected;                    // +0x98
    CClassImages images;                                          // +0xa0
    CListCtrl list;                                               // +0xa8
};
