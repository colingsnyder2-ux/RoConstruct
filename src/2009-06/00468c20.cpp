// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
class CXTPReportView {
public:
	virtual ~CXTPReportView();
	char pad[0x374];
};
class CMfcMember { public: ~CMfcMember(); int d; };
class CTaskSchedulerPaneView : public CXTPReportView {
public:
	virtual ~CTaskSchedulerPaneView();
	CMfcMember m;
};
CTaskSchedulerPaneView::~CTaskSchedulerPaneView() {}
