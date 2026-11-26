// from server: 100% by Xemicl
// roc 2012-06 004a72c0  unit: CTaskSchedulerPaneView  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a72c0
//
// 004a72c0  6aff                 push -1
// 004a72c2  683842aa00           push 0xaa4238
// 004a72c7  64a100000000         mov eax, dword ptr fs:[0]
// 004a72cd  50                   push eax
// 004a72ce  64892500000000       mov dword ptr fs:[0], esp
// 004a72d5  51                   push ecx
// 004a72d6  56                   push esi
// 004a72d7  8bf1                 mov esi, ecx
// 004a72d9  89742404             mov dword ptr [esp + 4], esi
// 004a72dd  c7060c25b600         mov dword ptr [esi], 0xb6250c
// 004a72e3  8d8e78030000         lea ecx, [esi + 0x378]
// 004a72e9  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004a72f1  e87ab54d00           call 0x982870
// 004a72f6  8bce                 mov ecx, esi
// 004a72f8  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004a7300  e8abf34f00           call 0x9a66b0
// 004a7305  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004a7309  5e                   pop esi
// 004a730a  64890d00000000       mov dword ptr fs:[0], ecx
// 004a7311  83c410               add esp, 0x10
// 004a7314  c3                   ret 
// copied from an identical function in another client (function ??1CTaskSchedulerPaneView@@UAE@XZ)

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