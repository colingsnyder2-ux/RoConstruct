// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
class CPropGrid {
public:
	CPropGrid();
	virtual ~CPropGrid();
	char pad[0x268 - 4];
};
extern long selectionGridCount;
class CSelectionPropGrid : public CPropGrid {
public:
	struct SC { void* pi; SC() : pi(0) {} }; struct SP { void* px; SC pn; SP() : px(0) {} } ab;
	struct M { void* c; void* d; M() { InterlockedIncrement(&selectionGridCount); c = 0; d = 0; } } cd;
	CSelectionPropGrid() {}
};
class ActiveDocView {
public:
	ActiveDocView();
	virtual ~ActiveDocView();
};
class CDataModelPropGrid : public CSelectionPropGrid, public ActiveDocView {
public:
	CDataModelPropGrid();
};
CDataModelPropGrid::CDataModelPropGrid() {}
