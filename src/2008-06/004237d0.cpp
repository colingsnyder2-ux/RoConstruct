// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_da5a2b380f6d46c8.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afxwin.h>
#include <afxcmn.h>

namespace RBX { class Instance; }
template<class T> class SharedPtr {
	T* px;
	void* pn;
public:
	SharedPtr(const SharedPtr& other);
	template<class Y> SharedPtr(const SharedPtr<Y>& other);
	~SharedPtr();
	operator bool() const { return px != 0; }
};
template<class T> class WeakPtr {
	T* px;
	void* pn;
};
template<class T> SharedPtr<T> make_shared(const WeakPtr<T>& r);
class SelectionState;
class SelectionLock {
	unsigned char storage[12];
public:
	SelectionLock(SharedPtr<RBX::Instance> state);
	~SelectionLock();
};
struct TreeItemData {
	int reserved[3];
	WeakPtr<RBX::Instance> instance;
};
class CRobloxApp : public CWinApp {
public:
	void selectInstance(SharedPtr<RBX::Instance> instance);
};
class CObjectTree : public CTreeCtrl {
public:
	virtual void reserved0();
	virtual void reserved1();
	virtual void reserved2();
	virtual void reserved3();
	virtual SharedPtr<SelectionState> getSelectionState();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
void CObjectTree::OnLButtonDown(UINT nFlags, CPoint point)
{
	CTreeCtrl::OnLButtonDown(nFlags, point);
	if (nFlags & (MK_SHIFT | MK_CONTROL))
		return;
	HTREEITEM hItem = HitTest(point, &nFlags);
	if (hItem && (nFlags & TVHT_ONITEM))
	{
		if (TreeItemData* data = (TreeItemData*)GetItemData(hItem))
		{
			SharedPtr<RBX::Instance> instance = make_shared(data->instance);
			if (instance)
			{
				SelectionLock lock(getSelectionState());
				static_cast<CRobloxApp*>(AfxGetApp())->selectInstance(instance);
			}
		}
	}
}
