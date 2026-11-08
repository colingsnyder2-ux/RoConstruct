#pragma once
#include <afxwin.h>

class CChatPrompt;
namespace RBX { class DataModel; }
// Native constructor 00432e30 initializes the CWnd base and child pointer.
class CMultiPlayerPane : public CWnd {
    DECLARE_DYNAMIC(CMultiPlayerPane)
public:
    CChatPrompt* chatPrompt;
    BOOL initialize(CWnd*, RBX::DataModel*);
    CMultiPlayerPane();
    virtual ~CMultiPlayerPane();
    afx_msg void OnSize(UINT type, int width, int height);
    afx_msg void OnDestroy();
    DECLARE_MESSAGE_MAP()
};
