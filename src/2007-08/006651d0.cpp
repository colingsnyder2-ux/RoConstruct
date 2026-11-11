// from server: 73% by EspClaude
// from server: 72% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-11.2.2 roc_claude_4ba0d989931c824a.cpp

// Candidate translation unit (score above; library headers required).
// XTTreeBase.cpp : implementation file
//
// This file is a part of the XTREME CONTROLS MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

// trial: CXTTreeBase vtable one slot shorter before OnButtonDown (target 006651d0 calls DoPreSelection/DoAction/DoBanding at 0x54/0x58/0x5c;
// 00666e00 calls OnButtonDown at 0x50); hypothesis: the uState colour overloads were not virtual
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>
#endif
#include <afxpriv.h>
#include <afxtempl.h>
#include <afxcview.h>
#include <shlobj.h>
#ifndef AFX_STATIC
#define AFX_STATIC static
#endif
#undef _XTP_EXT_CLASS
#if !defined(_AFXDLL) || defined(_XTP_STATICLINK)
#define _XTP_EXT_CLASS
#else
#define _XTP_EXT_CLASS  __declspec(dllimport)
#endif
#include "Common/Includes.h"
#include "TabManager/Includes.h"
#include "GraphicLibrary/Includes.h"
#include "Controls/Resource.h"
#include "Controls/XTThemeManager.h"
#include "Controls/XTDefines.h"
#include "Controls/XTGlobal.h"
#include "Controls/XTVC50Helpers.h"
#include "Controls/XTWndHook.h"
#include "Controls/XTUtil.h"
#include "Controls/XTNotify.h"
#include "Controls/XTFunctions.h"
#include "Controls/XTMemDC.h"
#include "Controls/XTAnimationMemDC.h"
#include "Controls/XTButton.h"
#include "Controls/XTHexEdit.h"
#include "Controls/XTCaption.h"
#include "Controls/XTCaptionPopupWnd.h"
#include "Controls/XTColorRef.h"
#include "Controls/XTColorSelectorCtrl.h"
#include "Controls/XTColorPopup.h"
#include "Controls/XTColorPicker.h"
#include "Controls/XTColorDialog.h"
#include "Controls/XTListBox.h"
#include "Controls/XTEditListBox.h"
#include "Controls/XTComboBoxEx.h"
#include "Controls/XTTabCtrl.h"
#include "Controls/XTTabCtrlButtons.h"
#include "Controls/XTExcelTabCtrl.h"
// XTTreeBase.h interface for the CXTTreeBase class.
//
// This file is a part of the XTREME CONTROLS MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

//{{AFX_CODEJOCK_PRIVATE
#if !defined(__XTTREEBASE_H__)
#define __XTTREEBASE_H__
//}}AFX_CODEJOCK_PRIVATE

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//===========================================================================
// Summary:
//     CXTTreeBase is a CTreeView derived class. It extends the CTreeView
//     class to add additional functionality, including tree traversal, searching,
//     color, and settings.
//===========================================================================
class _XTP_EXT_CLASS CXTTreeBase
{
protected:
	// ----------------------------------------------------------------------
	// Summary:
	//     CLRFONT structure is used to by the CXTShellTreeCtrl and
	//     CXTShellTreeView class to maintain font information for a
	//     particular tree item.
	// See Also:
	//     CXTShellTreeCtrl, CXTShellTreeView
	// ----------------------------------------------------------------------
	struct CLRFONT
	{
		// ----------------------------------------------------------------------
		// Summary: Constructs a CLRFONT struct and initializes member data.
		// ----------------------------------------------------------------------
		CLRFONT();

		LOGFONT  logfont;   // A LOGFONT object that represents the tree item font.
		COLORREF color;     // An RGB value that represents the text color for a tree item.
		COLORREF colorBack; // An RGB value that represents the background color for a tree item.
	};

	// ----------------------------------------------------------------------
	// Summary:
	//     Map for maintaining HTREEITEM to CLRFONT structure relationships.
	// Remarks:
	//     CMap definition used by the CXTTreeBase class to maintain
	//     a list of HTREEITEM to CLRFONT structure relationships representing
	//     tree item that has user defined color information.
	// See Also:
	//     CXTTreeBase, CLRFONT
	// ----------------------------------------------------------------------
	typedef CMap<void*, void*, CLRFONT, CLRFONT&> CColorFontMap;

protected:
	//-----------------------------------------------------------------------
	// Summary:
	//     Protected constructor used by dynamic creation. Constructs a CXTTreeBase
	//     object
	//-----------------------------------------------------------------------
	CXTTreeBase();

	//-----------------------------------------------------------------------
	// Summary:
	//     Destroys a CXTTreeBase object, handles cleanup and deallocation
	//-----------------------------------------------------------------------
	virtual ~CXTTreeBase();

public:

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function will retrieve the tree view item that has the
	//     specified relationship, indicated by the 'nCode' parameter, to 'hItem'.
	// Parameters:
	//     hItem -  Handle of a tree item.
	//     nCode - A flag indicating the type of relation to 'hItem'. This flag can be
	//             one of the values listed in the Remarks section.
	// Remarks:
	//     nCode can be one of the following values:
	//     * <b>TVGN_CARET</b> Retrieves the currently selected item.
	//     * <b>TVGN_CHILD</b> Retrieves the first child item. The 'hItem'
	//       parameter must be NULL.
	//     * <b>TVGN_DROPHILITE</b> Retrieves the item that is the target
	//       of a drag-and-drop operation.
	//     * <b>TVGN_FIRSTVISIBLE</b> Retrieves the first visible item.
	//     * <b>TVGN_NEXT</b> Retrieves the next sibling item.
	//     * <b>TVGN_NEXTVISIBLE</b> Retrieves the next visible item
	//        that follows the specified item.
	//     * <b>TVGN_PARENT</b> Retrieves the parent of the specified
	//       item.
	//     * <b>TVGN_PREVIOUS</b> Retrieves the previous sibling item.
	//     * <b>TVGN_PREVIOUSVISIBLE</b> Retrieves the first visible
	//       item that precedes the specified item.
	//     * <b>TVGN_ROOT</b> Retrieves the first child item of the
	//       root item of which the specified item is a part.
	//
	//  The Non nCode version gets the next item as if the outline was completely
	//     expanded.
	// Returns:
	//     The handle of the next item if successful, otherwise returns
	//     NULL.
	//-----------------------------------------------------------------------
	virtual HTREEITEM GetNextItem(HTREEITEM hItem) const;
	virtual HTREEITEM GetNextItem(HTREEITEM hItem, UINT nCode) const; // <combine CXTTreeBase::GetNextItem@HTREEITEM@const>

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function gets the previous item as if the outline was
	//     completely expanded.
	// Parameters:
	//     hItem - Handle of the reference item.
	// Returns:
	//     The handle of the item immediately above the reference item.
	//-----------------------------------------------------------------------
	virtual HTREEITEM GetPrevItem(HTREEITEM hItem) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function retrieves the last item in the branch.
	// Parameters:
	//     hItem - Node identifying the branch. NULL will return the last item in the
	//             outline.
	// Returns:
	//     The handle of the last item.
	//-----------------------------------------------------------------------
	virtual HTREEITEM GetLastItem(HTREEITEM hItem) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function searches the entire tree for an item label
	//     that contains the search string.
	// Parameters:
	//     lpszSearch     - String to search for.
	//     bCaseSensitive - TRUE if the search should be case sensitive.
	//     bDownDir       - TRUE for down.
	//     bWholeWord     - TRUE if search should match whole words.
	//     hItem          - Handle of the tree item to start searching from, NULL to use
	//     the currently selected tree item.
	// Returns:
	//     The handle to the item, or returns NULL.
	// See Also:
	//     IsFindValid
	//-----------------------------------------------------------------------
	virtual HTREEITEM FindItem(LPCTSTR lpszSearch, BOOL bCaseSensitive = FALSE, BOOL bDownDir = TRUE, BOOL bWholeWord = FALSE, HTREEITEM hItem = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function searches the entire branch specified by htiItem for an item label
	//     that contains the search string.
	// Parameters:
	//     lpszSearch     - String to search for.
	//     bCaseSensitive - TRUE if the search should be case sensitive.
	//     bWholeWord     - TRUE if search should match whole words.
	//     htiItem        - Handle of the tree item to start searching from, NULL to use
	//                      the currently selected tree item.
	// Returns:
	//     The handle to the item, or returns NULL.
	// See Also:
	//     IsFindValid
	//-----------------------------------------------------------------------
	virtual HTREEITEM FindItemInBranch(LPCTSTR lpszSearch, BOOL bCaseSensitive /*= FALSE*/, BOOL bWholeWord /*= FALSE*/, HTREEITEM htiItem /*= NULL*/);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function sets the font for the reference tree item.
	// Parameters:
	//     hItem   - Handle of the reference item.
	//     logfont - New font for the tree item.
	//-----------------------------------------------------------------------
	virtual void SetItemFont(HTREEITEM hItem, LOGFONT& logfont);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function retrieves the current LOGFONT font used by
	//     the tree item.
	// Parameters:
	//     hItem    - Handle of the reference item.
	//     plogfont - Pointer to receive LOGFONT information.
	// Returns:
	//     TRUE if successful, otherwise returns FALSE.
	//-----------------------------------------------------------------------
	virtual BOOL GetItemFont(HTREEITEM hItem, LOGFONT* plogfont);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function sets the reference tree item font to bold.
	// Parameters:
	//     hItem - Handle of the reference item.
	//     bBold - TRUE for bold font.
	//-----------------------------------------------------------------------
	virtual void SetItemBold(HTREEITEM hItem, BOOL bBold = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function checks whether or not the tree item has a bold font.
	// Parameters:
	//     hItem - Handle of the reference item.
	// Returns:
	//     TRUE if the tree item has a bold font, otherwise returns FALSE.
	//-----------------------------------------------------------------------
	virtual BOOL GetItemBold(HTREEITEM hItem);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function sets the tree item text color.
	// Parameters:
	//     hItem - Handle of the reference item.
	//     color - RGB value for the tree item's text.
	//-----------------------------------------------------------------------
	virtual void SetItemColor(HTREEITEM hItem, COLORREF color);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function sets the tree item background color.
	// Parameters:
	//     hItem - Handle of the reference item.
	//     color - RGB value for the tree item's text.
	//-----------------------------------------------------------------------
	virtual void SetItemBackColor(HTREEITEM hItem, COLORREF color);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function returns the RGB value for the specified
	//     tree item text color or (COLORREF)-1, if color was not set.
	// Parameters:
	//     hItem - Handle of the reference item.
	// Returns:
	//     The RGB value for the specified tree item text color, or (COLORREF)-1, if the
	//     color was not set.
	//-----------------------------------------------------------------------
	virtual COLORREF GetItemColor(HTREEITEM hItem);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function returns the RGB value for the specified
	//     tree item background color or (COLORREF)-1, if color was not set.
	// Parameters:
	//     hItem - Handle of the reference item.
	// Returns:
	//     The RGB value for the specified tree item background color, or (COLORREF)-1, if the
	//     color was not set.
	//-----------------------------------------------------------------------
	virtual COLORREF GetItemBackColor(HTREEITEM hItem);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function enables or disables multi-selection for the
	//     tree control.
	// Parameters:
	//     bMultiSelect - TRUE for a multi-selection tree control.
	// Returns:
	//     TRUE if successful, otherwise returns FALSE.
	//-----------------------------------------------------------------------
	virtual BOOL EnableMultiSelect(BOOL bMultiSelect = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function returns the previously selected tree item in
	//     a multi-selection tree control.
	// Parameters:
	//     hItem - Handle of the reference item.
	// Returns:
	//     A handle to the previously selected tree item.
	//-----------------------------------------------------------------------
	virtual HTREEITEM GetPrevSelectedItem(HTREEITEM hItem) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function returns the next selected item in a multi-selection
	//     tree control.
	// Parameters:
	//     hItem - Handle of the reference item.
	// Returns:
	//     A handle to the next selected tree item.
	//-----------------------------------------------------------------------
	HTREEITEM GetNextSelectedItem(HTREEITEM hItem) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function returns the first selected item in a multi-selection
	//     tree control.
	// Returns:
	//     A handle to the first selected tree item.
	//-----------------------------------------------------------------------
	HTREEITEM GetFirstSelectedItem() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function returns the number of tree items that are selected.
	// Returns:
	//     A UNIT value that represents the number of tree items selected.
	//-----------------------------------------------------------------------
	UINT GetSelectedCount() const;

	// --------------------------------------------------------------------------
	// Summary:
	//     This member function is a replacement for the base class function
	//     of the same name, to handle TVIS_FOCUSED in a multi-select
	//     tree control. It sets the state of the item specified by <i>hItem</i>.
	// Parameters:
	//     hItem -       Handle of the item whose state is to be set.
	//     nState -      Specifies the new states for the item.
	//     nStateMask -  Specifies which states are to be changed.
	// Returns:
	//     Nonzero if successful, otherwise returns zero.
	// Remarks:
	//     The TVIS_FOCUSED state flag when set will draw a focus
	//     rectangle around the tree item that currently has input focus.
	//     Only one tree item can have focus at any given time. For a list of
	//     possible item state flags, see Tree-View Control Item States in
	//     the MSDN documentation.
	// --------------------------------------------------------------------------
	BOOL SetItemState(HTREEITEM hItem, UINT nState, UINT nStateMask);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function is a replacement for the base class function of
	//     the same name to handle TVIS_FOCUSED in a multi-select tree control.
	// Parameters:
	//     hItem      - Handle of the item whose state is to be retrieved.
	//     nStateMask - Mask indicating which states are to be retrieved. For more information
	//                  on possible values for 'nStateMask', see the discussion of the 'state'
	//                  and 'stateMask' members of the TVITEM structure in the Platform SDK.
	// Returns:
	//     The state of the item specified by 'hItem'.
	//-----------------------------------------------------------------------
	UINT GetItemState(HTREEITEM hItem, UINT nStateMask) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function is a replacement for the base class function of
	//     the same name, to handle TVIS_FOCUSED in a multi-select tree control.
	//     Call this function to select the given tree view item. If 'hItem' is
	//     NULL, then no items are selected.
	// Parameters:
	//     hItem - Handle of a tree item.
	// Returns:
	//     Nonzero if successful, otherwise returns zero.
	//-----------------------------------------------------------------------
	BOOL SelectItem(HTREEITEM hItem);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function returns the handle to the tree item that currently
	//     has focus.
	// Returns:
	//     The handle of the item that has focus, otherwise returns NULL.
	//-----------------------------------------------------------------------
	HTREEITEM GetFocusedItem() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function will set the focus for the tree item specified
	//     by 'hItem'.
	// Parameters:
	//     hItem - Handle of a tree item.
	// Returns:
	//     TRUE if successful, otherwise returns FALSE.
	//-----------------------------------------------------------------------
	BOOL FocusItem(HTREEITEM hItem);

	//-----------------------------------------------------------------------
	// Summary:
	//     Call this member function to clear, or select, all of the visible items
	//     in the tree control. This will not effect the focus of the tree items.
	// Parameters:
	//     bSelect - TRUE to select all the items, or FALSE to clear the selection.
	//     htItem  - Tree item to start selection from. If NULL selection will begin at the root.
	//-----------------------------------------------------------------------
	void SelectAll(BOOL bSelect = TRUE, HTREEITEM htItem = NULL);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function selects items from 'hItemFrom' to 'hItemTo' in
	//     a multi-selection tree control. It does not select a child item if
	//     the parent is collapsed. It will remove the selection from all other
	//     items if 'bOnly' is set to TRUE.
	// Parameters:
	//     hItemFrom - Handle of the item to start selecting from.
	//     hItemTo   - Handle of the item to end selection at.
	//     bOnly     - TRUE to only select the specified range, or FALSE to keep existing
	//                 selections.
	//-----------------------------------------------------------------------
	void SelectItems(HTREEITEM hItemFrom, HTREEITEM hItemTo, BOOL bOnly = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function checks whether or not the specified item is selected.
	// Parameters:
	//     hItem - Handle of a tree item.
	// Returns:
	//     TRUE if the specified item is selected, otherwise returns FALSE.
	//-----------------------------------------------------------------------
	BOOL IsSelected(HTREEITEM hItem) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function will cause all of the children of the specified
	//     tree item to be selected or deselected.
	// Parameters:
	//     hParent  - Handle of tree item to begin selection from.
	//     bSelect  - TRUE to select only the child items or FALSE to keep existing selections.
	//     bRecurse - TRUE to recurse all siblings or FALSE to select only children of the
	//                parent item.
	// Returns:
	//     TRUE if focus was on a child item, otherwise returns FALSE.
	//-----------------------------------------------------------------------
	BOOL SelectChildren(HTREEITEM hParent, BOOL bSelect = TRUE, BOOL bRecurse = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function will retrieve a reference to the typed pointer
	//     array that contains the items selected in the tree control.
	// Parameters:
	//     list - Reference to a CTypedPtrList\<CPtrList, HTREEITEM\> object.
	//-----------------------------------------------------------------------
	void GetSelectedList(CTypedPtrList<CPtrList, HTREEITEM>& list) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function checks to see if the tree control is a multi-select
	//     tree.
	// Returns:
	//     TRUE if the tree control is a multi-select tree, otherwise returns FALSE.
	//-----------------------------------------------------------------------
	BOOL IsMultiSelect() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function sets the banding mode for a multi-selection tree
	//     control. If 'bLabel' is TRUE, then items are selected only when the
	//     banding rect passes over the tree item label. If FALSE, passing
	//     over any part of the tree item will cause selection to be made when
	//     the banding rect passes over it.
	// Parameters:
	//     bLabel - TRUE to select items only when banding rect passes over the text label,
	//              or FALSE to select items when banding rect passes over any part of
	//              the tree item.
	// Returns:
	//     The previous banding state.
	//-----------------------------------------------------------------------
	BOOL SetBandingHit(BOOL bLabel);

protected:

	//-----------------------------------------------------------------------
	// Summary:
	//     This member function is called by the CXTTreeBase class to
	//     perform initialization when the window is created or sub-classed.
	// Returns:
	//     TRUE if the window was successfully initialized, otherwise FALSE.
	//-----------------------------------------------------------------------
	virtual bool Init();

	//-----------------------------------------------------------------------
	// Summary:
	//     Sends a WM_NOTIFY message to the tree control owner window.
	// Parameters:
	//     pNMHDR - Pointer to an NMHDR structure that contains the notification
	//              code and additional information. For some notification messages,
	//              this parameter points to a larger structure that has the NMHDR
	//              structure as its first member.
	// Remarks:
	//     Called by the tree control to package and send a WM_NOTIFY message
	//     to the tree control's owner window. You can override this member
	//     to provide additional functionality.
	// Returns:
	//     The return value is ignored except for notification messages that
	//     specify otherwise.
	//-----------------------------------------------------------------------
	virtual LRESULT SendNotify(LPNMHDR pNMHDR);

	//-----------------------------------------------------------------------
	// Summary:
	//     Toggles selection for all items in a multiple selection tree control.
	// Parameters:
	//     bSelect - TRUE to select, FALSE to remove selection.
	//     hIgnore - Handle to a tree item to skip while performing the operation.
	// Remarks:
	//     Called to toggle selection for all items in a multiple selection
	//     tree control. You can override this member to provide additional
	//     functionality.
	//-----------------------------------------------------------------------
	virtual void SelectAllIgnore(BOOL bSelect, HTREEITEM hIgnore);

	//-----------------------------------------------------------------------
	// Summary:
	//     Called when a mouse button click event occurs.
	// Parameters:
	//     bLeft  - TRUE if the left mouse button is down.
	//     nFlags - Indicates whether various virtual keys are down. See Remarks
	//              section for a list of values.
	//     point  - xy cursor location.
	// Remarks:
	//     <i>nFlags, /i> can be any combination of the following values:<p/>
	//     * <b>MK_CONTROL</b> Set if the CTRL key is down.
	//     * <b>MK_LBUTTON</b> Set if the left mouse button is down.
	//     * <b>MK_MBUTTON</b> Set if the middle mouse button is down.
	//     * <b>MK_RBUTTON</b> Set if the right mouse button is down.
	//     * <b>MK_SHIFT</b>   Set if the SHIFT key is down.
	// Returns:
	//     TRUE if successful, otherwise FALSE.
	//-----------------------------------------------------------------------
	virtual BOOL OnButtonDown(BOOL bLeft, UINT nFlags, CPoint point);

	//-----------------------------------------------------------------------
	// Summary:
	//     Called during item selection in a multiple selection tree control.
	// Parameters:
	//     hItem  - Handle to the last item clicked that will receive focus.
	//     bLeft  - TRUE if the left mouse button is down.
	//     nFlags - Indicates whether various virtual keys are down. See Remarks
	//              section for a list of values.
	// Remarks:
	//     <i>nFlags, /i> can be any combination of the following values:<p/>
	//     * <b>MK_CONTROL</b> Set if the CTRL key is down.
	//     * <b>MK_LBUTTON</b> Set if the left mouse button is down.
	//     * <b>MK_MBUTTON</b> Set if the middle mouse button is down.
	//     * <b>MK_RBUTTON</b> Set if the right mouse button is down.
	//     * <b>MK_SHIFT</b>   Set if the SHIFT key is down.
	//-----------------------------------------------------------------------
	virtual void DoPreSelection(HTREEITEM hItem, BOOL bLeft, UINT nFlags);

	//-----------------------------------------------------------------------
	// Summary:
	//     Called during item selection in a multiple selection tree control.
	// Parameters:
	//     hItem  - Handle to the last item clicked that will receive focus.
	//     bLeft  - TRUE if the left mouse button is down.
	//     nFlags - Indicates whether various virtual keys are down. See Remarks
	//              section for a list of values.
	//     point  - Mouse cursor position.
	// Remarks:
	//     <i>nFlags, /i> can be any combination of the following values:<p/>
	//     * <b>MK_CONTROL</b> Set if the CTRL key is down.
	//     * <b>MK_LBUTTON</b> Set if the left mouse button is down.
	//     * <b>MK_MBUTTON</b> Set if the middle mouse button is down.
	//     * <b>MK_RBUTTON</b> Set if the right mouse button is down.
	//     * <b>MK_SHIFT</b>   Set if the SHIFT key is down.
	//-----------------------------------------------------------------------
	virtual void DoAction(HTREEITEM hItem, BOOL bLeft, UINT nFlags, CPoint point);

	//-----------------------------------------------------------------------
	// Summary:
	//     Draws a selection rectangle during item selection.
	// Parameters:
	//     point  - xy location of the mouse cursor.
	//     nFlags - Indicates whether various virtual keys are down. See Remarks
	//              section for a list of values.
	// Remarks:
	//     <i>nFlags, /i> can be any combination of the following values:<p/>
	//     * <b>MK_CONTROL</b> Set if the CTRL key is down.
	//     * <b>MK_LBUTTON</b> Set if the left mouse button is down.
	//     * <b>MK_MBUTTON</b> Set if the middle mouse button is down.
	//     * <b>MK_RBUTTON</b> Set if the right mouse button is down.
	//     * <b>MK_SHIFT</b>   Set if the SHIFT key is down.
	//-----------------------------------------------------------------------
	virtual void DoBanding(UINT nFlags, CPoint point);

	//-----------------------------------------------------------------------
	// Summary:
	//     Updates tree item selection.
	// Parameters:
	//     pRect  - Cursor drag rectangle representing tree items to select.
	//     nFlags - Indicates whether various virtual keys are down. See Remarks
	//              section for a list of values.
	//     list   - An array of tree items that are currently selected.
	// Remarks:
	//     Called by the tree control to select tree items based upon the area
	//     specified by <i>pRect</i>.
	//     <i>nFlags, /i> can be any combination of the following values:<p/>
	//     * <b>MK_CONTROL</b> Set if the CTRL key is down.
	//     * <b>MK_LBUTTON</b> Set if the left mouse button is down.
	//     * <b>MK_MBUTTON</b> Set if the middle mouse button is down.
	//     * <b>MK_RBUTTON</b> Set if the right mouse button is down.
	//     * <b>MK_SHIFT</b>   Set if the SHIFT key is down.
	//-----------------------------------------------------------------------
	virtual void UpdateSelectionForRect(LPCRECT pRect, UINT nFlags, CTypedPtrList<CPtrList, HTREEITEM>& list);

	//-----------------------------------------------------------------------
	// Summary:
	//     Member override to determine if a tree item is valid.
	// Parameters:
	//     hti - Handle to the tree item that was found when FindItem or
	//           FindItemInBranch has been called.
	// Remarks:
	//     Override this member function to determine if the tree item
	//     specified by <i>hti</i> is a valid. If IsFindValid returns
	//     FALSE the calling functions FindItem and FindItemInBranch
	//     will return NULL.
	// Returns:
	//     TRUE in the base class. Derived classes must return TRUE to
	//     indicate success and FALSE to indicate failure.
	//-----------------------------------------------------------------------
	virtual BOOL IsFindValid(HTREEITEM hti);

	//-----------------------------------------------------------------------
	// Summary:
	//     Called to render the tree control.
	// Parameters:
	//     dc        - Reference to the tree control device context.
	//     bInternal - FALSE to skip extended rendering tasks and to
	//                 the tree control's default rendering.
	// Remarks:
	//     This member is called to render the tree control using user defined
	//     fonts and colors. You can override this member to provide additional
	//     functionality.
	//-----------------------------------------------------------------------
	virtual void DoPaint(CDC& dc, BOOL bInternal = TRUE);

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the tree control background color.
	// Returns:
	//     An RGB value representing the tree control background color.
	// See Also:
	//     CTreeCtrl::SetBkColor, CTreeCtrl::GetBkColor, GetTreeTextColor,
	//     GetItemBackColor, GetItemTextColor
	//-----------------------------------------------------------------------
	virtual COLORREF GetTreeBackColor() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves the tree control text color.
	// Returns:
	//     An RGB value representing the tree control text color.
	// See Also:
	//     CTreeCtrl::SetTextColor, CTreeCtrl::GetTextColor, GetTreeBackColor,
	//     GetItemBackColor, GetItemTextColor
	//-----------------------------------------------------------------------
	virtual COLORREF GetTreeTextColor() const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves a tree items background color.
	// Parameters:
	//     uState        - Mask indicating which states are to be retrieved. For
	//                     more information on possible values for nStateMask, see
	//                     the discussion of the state and stateMask members of
	//                     the TVITEM structure in the Platform SDK.
	//     bTreeHasFocus - true if the tree item has input focus.
	//     dwStyle       - Set of flags specifying tree item state.
	//     crBack        - Default color to be returned, usually the tree control background color.
	// Remarks:
	//     This member function is called to retrieve a tree items background
	//     color. The value retrieved will depend on the tree items state and
	//     TVS_ style.
	// Returns:
	//     An RGB value representing the specified item background color.
	// See Also:
	//     GetTreeBackColor, GetTreeTextColor, GetItemTextColor
	//-----------------------------------------------------------------------
	COLORREF GetItemBackColor(UINT uState, bool bTreeHasFocus, DWORD dwStyle, COLORREF crBack) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Retrieves a tree items text color.
	// Parameters:
	//     uState        - Mask indicating which states are to be retrieved. For
	//                     more information on possible values for nStateMask, see
	//                     the discussion of the state and stateMask members of
	//                     the TVITEM structure in the Platform SDK.
	//     bTreeHasFocus - true if the tree item has input focus.
	//     dwStyle       - Set of flags specifying tree item state.
	//     crText        - Default color to be returned, usually the tree control text color.
	// Remarks:
	//     This member function is called to retrieve a tree items text
	//     color. The value retrieved will depend on the tree items state and
	//     TVS_ style.
	// Returns:
	//     An RGB value representing the specified item text color.
	// See Also:
	//     GetTreeBackColor, GetTreeTextColor, GetItemBackColor
	//-----------------------------------------------------------------------
	COLORREF GetItemTextColor(UINT uState, bool bTreeHasFocus, DWORD dwStyle, COLORREF crText) const;

	//-----------------------------------------------------------------------
	// Summary:
	//     Determines if the tree control has edit labels.
	// Returns:
	//     true if the TVS_EDITLABELS style is set for the tree control, otherwise false.
	//-----------------------------------------------------------------------
	bool HasEditLabels() const;


protected:

//{{AFX_CODEJOCK_PRIVATE
	//{{AFX_VIRTUAL(CXTTreeBase)
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CXTTreeBase)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnDeleteItem(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnItemExpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnBeginLabelEdit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnEndLabelEdit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	//}}AFX_MSG
//}}AFX_CODEJOCK_PRIVATE



protected:
//{{AFX_CODEJOCK_PRIVATE
	// Needed in order to access protected functions.
	class CTreeCtrl_Friendly : public CTreeCtrl { friend class CXTTreeBase; };
//}}AFX_CODEJOCK_PRIVATE

protected:
	BOOL                m_bMultiSelect; // TRUE for a multi-selection tree control.
	BOOL                m_bBandLabel;   // TRUE to include the label when selecting tree items.
	HTREEITEM           m_hSelect;      // For shift selection.
	HTREEITEM           m_htiEdit;      // Tree item that is currently edited.
	HTREEITEM           m_htiLast;      // Tree item that was last had the mouse over.
	CColorFontMap       m_mapColorFont; // Maps HTREEITEM handles with CLRFONT structures that contains the color and logfont information for the tree item.
	CTreeCtrl_Friendly* m_pTreeCtrl;    // Self tree pointer.

private:

	bool m_bActionDone;
	bool m_bOkToEdit;
};

//////////////////////////////////////////////////////////////////////

AFX_INLINE HTREEITEM CXTTreeBase::GetNextItem(HTREEITEM hItem, UINT nCode) const {
	ASSERT(::IsWindow(m_pTreeCtrl->m_hWnd)); return m_pTreeCtrl->GetNextItem(hItem, nCode);
}
AFX_INLINE HTREEITEM CXTTreeBase::GetFocusedItem() const {
	ASSERT(m_bMultiSelect); return m_pTreeCtrl->GetSelectedItem();
}
AFX_INLINE BOOL CXTTreeBase::IsSelected(HTREEITEM hItem) const {
	return !!(TVIS_SELECTED & m_pTreeCtrl->GetItemState(hItem, TVIS_SELECTED));
}
AFX_INLINE BOOL CXTTreeBase::IsMultiSelect() const {
	return m_bMultiSelect;
}
AFX_INLINE BOOL CXTTreeBase::SetBandingHit(BOOL bLabel) {
	BOOL bReturn = m_bBandLabel; m_bBandLabel = bLabel; return bReturn;
}
AFX_INLINE CXTTreeBase::CLRFONT::CLRFONT() : color((COLORREF)-1), colorBack((COLORREF)-1) {
	::ZeroMemory(&logfont, sizeof(LOGFONT));
}

//{{AFX_CODEJOCK_PRIVATE
#define DECLATE_TREE_BASE(ClassName, Tree, Base)\
class _XTP_EXT_CLASS ClassName : public Tree, public Base\
{\
public:\
	ClassName() {\
		m_bPreSubclassInit = true;\
	}   \
	virtual UINT GetItemState(HTREEITEM hItem, UINT nStateMask) const  {\
		return Base::GetItemState(hItem, nStateMask);\
	}\
	virtual BOOL SelectItem(HTREEITEM hItem) {\
		return Base::SelectItem(hItem);\
	}\
	virtual BOOL SetItemState(HTREEITEM hItem, UINT nState, UINT nStateMask) {\
		return Base::SetItemState(hItem, nState, nStateMask);\
	}\
	virtual HTREEITEM GetNextItem(HTREEITEM hItem, UINT nCode) const {\
		return Base::GetNextItem(hItem, nCode);\
	}\
	virtual HTREEITEM GetNextItem(HTREEITEM hItem) const {\
		return Base::GetNextItem(hItem);\
	}\
protected:\
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) {\
		return Base::OnNotify(wParam, lParam, pResult);\
	}   \
	virtual BOOL PreTranslateMessage(MSG* pMsg) {\
		return Base::PreTranslateMessage(pMsg);\
	}   \
	virtual bool Init() {\
		return Base::Init();\
	}   \
	virtual void PreSubclassWindow()\
	{\
		Tree::PreSubclassWindow();\
		if (m_bPreSubclassInit)\
			Init();\
	}   \
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs)\
	{\
		if (!Tree::PreCreateWindow(cs))\
			return FALSE;\
		m_bPreSubclassInit = false;\
		return TRUE;\
	}   \
	bool m_bPreSubclassInit;\
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point) {\
		Base::OnLButtonDown(nFlags, point);\
	}   \
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point) {\
		Base::OnRButtonDown(nFlags, point);\
	}   \
	afx_msg void OnSetFocus(CWnd* pOldWnd) {\
		Base::OnSetFocus(pOldWnd);\
	}   \
	afx_msg void OnKillFocus(CWnd* pNewWnd) {\
		Base::OnKillFocus(pNewWnd); \
	}   \
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {\
		Base::OnKeyDown(nChar, nRepCnt, nFlags);\
	}   \
	afx_msg BOOL OnBeginLabelEdit(NMHDR* pNMHDR, LRESULT* pResult) {\
		return Base::OnBeginLabelEdit(pNMHDR, pResult); \
	}   \
	afx_msg BOOL OnEndLabelEdit(NMHDR* pNMHDR, LRESULT* pResult) {\
		return Base::OnEndLabelEdit(pNMHDR, pResult);\
	}   \
	afx_msg BOOL OnItemExpanding(NMHDR* pNMHDR, LRESULT* pResult) {\
		return Base::OnItemExpanding(pNMHDR, pResult);\
	}   \
	afx_msg BOOL OnDeleteItem(NMHDR* pNMHDR, LRESULT* pResult) {\
		return Base::OnDeleteItem(pNMHDR, pResult);\
	}   \
	afx_msg void OnSize(UINT nType, int cx, int cy) {\
		Base::OnSize(nType, cx, cy);\
	}   \
	afx_msg void OnMouseMove(UINT nFlags, CPoint point) {   \
		Base::OnMouseMove(nFlags, point);\
	}   \
	afx_msg void OnTimer(UINT_PTR nIDEvent) {       \
		Base::OnTimer(nIDEvent);\
	}   \
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point) {\
		Base::OnNcMouseMove(nHitTest, point);\
	}\
	afx_msg BOOL OnEraseBkgnd(CDC*) {\
		return TRUE;\
	}\
	afx_msg void OnPaint() {\
		CPaintDC dc(this);\
		DoPaint(dc); \
	}\
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct)\
	{\
		if (Tree::OnCreate(lpCreateStruct) == -1)\
			return -1;\
		Init();\
		return 0;\
	}   \
};

#define ON_TREECTRL_REFLECT\
	ON_WM_LBUTTONDOWN()\
	ON_WM_SETFOCUS()\
	ON_WM_KILLFOCUS()\
	ON_WM_RBUTTONDOWN()\
	ON_WM_KEYDOWN()\
	ON_WM_ERASEBKGND()\
	ON_WM_PAINT()\
	ON_WM_SIZE()\
	ON_NOTIFY_REFLECT_EX(TVN_DELETEITEM, OnDeleteItem)\
	ON_NOTIFY_REFLECT_EX(TVN_ITEMEXPANDING, OnItemExpanding)\
	ON_NOTIFY_REFLECT_EX(TVN_BEGINLABELEDIT, OnBeginLabelEdit)\
	ON_NOTIFY_REFLECT_EX(TVN_ENDLABELEDIT, OnEndLabelEdit)\
	ON_WM_MOUSEMOVE()\
	ON_WM_TIMER()\
	ON_WM_NCMOUSEMOVE()\
	ON_WM_CREATE

//}}AFX_CODEJOCK_PRIVATE

const DWORD TVIS_FOCUSED           = 0x0001;   //<ALIAS CXTTreeBase::SetItemState@HTREEITEM@UINT@UINT>

#endif // !defined(__XTTREEBASE_H__)

#include "stdafx.h"
#include <windowsx.h>
#include "Common/XTPColorManager.h"
#include "Common/XTPDrawHelpers.h"
#include "Common/XTPSystemHelpers.h"

#include "Controls/XTVC50Helpers.h"
#include "Controls/XTTreeBase.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifndef SCROLL_TIMER_PERIOD
#define SCROLL_TIMER_PERIOD 75
#endif

#ifndef HOVER_TIMER_PERIOD
#define HOVER_TIMER_PERIOD  85
#endif

#ifndef COLOR_HOTLIGHT
#define COLOR_HOTLIGHT      26
#endif // COLOR_HOTLIGHT



/////////////////////////////////////////////////////////////////////////////
// CXTTreeBase

CXTTreeBase::CXTTreeBase()
: m_hSelect(NULL)
, m_bMultiSelect(false)
, m_bBandLabel(true)
, m_bActionDone(false)
, m_bOkToEdit(true)
, m_htiEdit(NULL)
, m_htiLast(NULL)
{
	m_pTreeCtrl = NULL;
}

CXTTreeBase::~CXTTreeBase()
{
}

/////////////////////////////////////////////////////////////////////////////
// CXTTreeBase message handlers

void CXTTreeBase::OnLButtonDown(UINT nFlags, CPoint point)
{
	// If multiselect control, process possible left
	// click drag selection.
	if (m_bMultiSelect)
	{
		UINT nHitFlags = 0;

		HTREEITEM hItemHit = m_pTreeCtrl->HitTest(point, &nHitFlags);
		HTREEITEM hItemSel = m_pTreeCtrl->GetSelectedItem();

		// if expanding/contracting call base class.
		if ((nHitFlags & (TVHT_ONITEMBUTTON | TVHT_ONITEMSTATEICON)) != 0)
		{
			m_pTreeCtrl->Default();
			return;
		}

		if (HasEditLabels())
		{
			if (!(nFlags & (MK_CONTROL | MK_SHIFT)) && (nHitFlags & TVHT_ONITEMLABEL))
			{
				if (m_bOkToEdit && hItemHit == hItemSel)
				{
					SelectAll(FALSE);
					SelectItem(hItemHit);

					m_pTreeCtrl->Default();
					return;
				}
			}

			if ((nHitFlags & TVHT_ONITEM) == 0)
			{
				m_bOkToEdit = false;
			}
			else if (GetFocusedItem() == hItemSel)
			{
				m_bOkToEdit = true;
			}
		}

		OnButtonDown(TRUE, nFlags, point);
	}

	else
	{
		m_pTreeCtrl->Default();
	}
}

void CXTTreeBase::OnRButtonDown(UINT /*nFlags*/, CPoint point)
{
	if (m_pTreeCtrl->GetStyle() & TVS_SINGLEEXPAND)
	{
		m_pTreeCtrl->Default();
		return;
	}


	// hittest to get the tree item under the cursor
	// and select it.
	UINT uFlags = 0;
	HTREEITEM hItem = m_pTreeCtrl->HitTest(point, &uFlags);
	if (hItem != NULL && (uFlags & TVHT_ONITEM) != 0)
	{
		// if the item is not selected, clear previous
		// selections and select the item under cursor.
		if (!IsSelected(hItem))
		{
			SelectAll(FALSE);
			SelectItem(hItem);
		}
	}
	else
	{
		// clear previous selections.
		SelectAll(FALSE);
	}

	// call Default() so correct notification messages are
	// sent such as TVN_BEGINRDRAG.
	m_pTreeCtrl->Default();

	// get the owner of the tree control.
	//HWND hWnd = m_pTreeCtrl->GetOwner()->m_hWnd;

	//if (::IsWindow(hWnd))
	//{
		// construct a NMHDR struct...
		//NMHDR mHDR;
		//mHDR.hwndFrom = m_pTreeCtrl->m_hWnd;
		//mHDR.code = NM_RCLICK;
		//mHDR.idFrom = m_pTreeCtrl->GetDlgCtrlID();

		// and send a WM_NOTIFY message to our owner.
		//SendNotify(&mHDR);
	//}
}

void CXTTreeBase::OnSetFocus(CWnd* /*pOldWnd*/)
{
	if (m_bMultiSelect)
	{
		//'emulated' selected items will remain greyed
		// if application gets covered
		HTREEITEM hItem = GetFirstSelectedItem();
		while (hItem)
		{
			RECT rect;
			m_pTreeCtrl->GetItemRect(hItem, &rect, TRUE);
			m_pTreeCtrl->InvalidateRect(&rect);
			hItem = GetNextSelectedItem(hItem);
		}
	}

	m_pTreeCtrl->Default();
}

void CXTTreeBase::OnKillFocus(CWnd* /*pNewWnd*/)
{
	m_pTreeCtrl->Default();

	if (m_bMultiSelect)
	{
		//'emulated' selected items may not get
		// refreshed to grey
		HTREEITEM hItem = GetFirstSelectedItem();
		while (hItem)
		{
			RECT rect;
			m_pTreeCtrl->GetItemRect(hItem, &rect, TRUE);
			m_pTreeCtrl->InvalidateRect(&rect);
			hItem = GetNextSelectedItem(hItem);
		}
	}
}

void CXTTreeBase::OnKeyDown(UINT nChar, UINT /*nRepCnt*/, UINT /*nFlags*/)
{
	if (!m_bMultiSelect)
	{
		m_pTreeCtrl->Default();
		return;
	}

	BOOL bCtrl = (::GetKeyState(VK_CONTROL) < 0);
	BOOL bShift = (::GetKeyState(VK_SHIFT) < 0);


	if (!bCtrl && !bShift)
	{
		UINT uCount = GetSelectedCount();

		if ((uCount > 1) || (uCount == 1 && !IsSelected(GetFocusedItem())))
			SelectAll(FALSE);
	}

	HTREEITEM hSel = NULL;
	switch (nChar)
	{
	case VK_UP:
	case VK_DOWN:
	case VK_PRIOR:
	case VK_NEXT:
		hSel = m_pTreeCtrl->GetSelectedItem();
		if (!m_hSelect)
		{
			m_hSelect = hSel;
		}
		if (!bCtrl && !bShift)
		{
			m_hSelect = NULL;   //reset
		}
		break;
	}

	BOOL bDir = (nChar == VK_UP) || (nChar == VK_PRIOR);

	m_pTreeCtrl->Default();
	if (!hSel || (!bCtrl && !bShift))
	{
		return;
	}

	HTREEITEM hNext = (nChar == VK_NEXT) || (nChar == VK_PRIOR) ? GetFocusedItem() :
		bDir ? m_pTreeCtrl->GetPrevVisibleItem(hSel) : m_pTreeCtrl->GetNextVisibleItem(hSel);

	if (!hNext)
	{
		hNext = hSel;
	}
	if (bShift)
	{
		SelectItems(m_hSelect, hNext, TRUE);
	}
	else if (bCtrl)
	{
		SetItemState(hNext, TVIS_FOCUSED, TVIS_FOCUSED);
	}
}

BOOL CXTTreeBase::OnBeginLabelEdit(NMHDR* pNMHDR, LRESULT* pResult)
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	*pResult = 0;

	// set m_htiEdit equal to pTVDispInfo->item.hItem.
	m_htiEdit = pTVDispInfo->item.hItem;

	return FALSE;   //pass to parent
}

BOOL CXTTreeBase::OnEndLabelEdit(NMHDR* /*pNMHDR*/, LRESULT* pResult)
{
	*pResult = 0;

	// set m_htiEdit equal to NULL.
	m_htiEdit = NULL;

	return FALSE;   //pass to parent
}

BOOL CXTTreeBase::OnItemExpanding(NMHDR* pNMHDR, LRESULT* pResult)
{
	if (!m_bMultiSelect)
		return FALSE;

	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	*pResult = 0;

	if ((pNMTreeView->action == TVE_COLLAPSE) || (pNMTreeView->action == TVE_COLLAPSERESET))
	{
		// clear selection of children, it would be confusing otherwise
		// - the notifications can be over-ridden to stop the de-selection
		// if required.
		// Unfortunately, the parent window can't over-ride this functionality
		// because MFC gives this class first crack.  So if changes are required
		// a derived class will have to be used..
		ASSERT(pNMTreeView->itemNew.hItem);

		// if a descendent item has focus the parent will get selected as a
		// consequence of collapsing the tree, so preserve
		// (if the parent was already selected it will gain focus, but
		// that's acceptable)
		BOOL bWasSel = IsSelected(pNMTreeView->itemNew.hItem);
		BOOL bWasFocus = SelectChildren(pNMTreeView->itemNew.hItem, FALSE, TRUE);

		if (bWasFocus && !bWasSel)
		{
			FocusItem(pNMTreeView->itemNew.hItem); // give parent focus.
		}
	}

	return FALSE;   //pass to parent
}

HTREEITEM CXTTreeBase::GetNextItem(HTREEITEM hItem) const
{
	HTREEITEM hti = NULL;

	if (m_pTreeCtrl->ItemHasChildren(hItem))
	{
		hti = m_pTreeCtrl->GetChildItem(hItem);
	}

	if (hti == NULL)
	{
		while ((hti = m_pTreeCtrl->GetNextSiblingItem(hItem)) == NULL)
		{
			if ((hItem = m_pTreeCtrl->GetParentItem(hItem)) == NULL)
				return NULL;
		}
	}

	return hti;
}

HTREEITEM CXTTreeBase::GetPrevItem(HTREEITEM hItem) const
{
	HTREEITEM hti = NULL;

	hti = m_pTreeCtrl->GetPrevSiblingItem(hItem);
	if (hti == NULL)
	{
		hti = m_pTreeCtrl->GetParentItem(hItem);
	}
	else
	{
		hti = GetLastItem(hti);
	}

	return hti;
}

HTREEITEM CXTTreeBase::GetLastItem(HTREEITEM hItem) const
{
	// Temporary used variable
	HTREEITEM htiNext;

	// Get the last item at the top level
	if (hItem == NULL)
	{
		hItem = m_pTreeCtrl->GetRootItem();
	}

	while (m_pTreeCtrl->ItemHasChildren(hItem) != NULL)
	{
		// Find the last child of hItem
		htiNext = m_pTreeCtrl->GetChildItem(hItem);
		while (htiNext != NULL)
		{
			hItem = htiNext;
			htiNext = m_pTreeCtrl->GetNextSiblingItem(htiNext);
		}
	}

	return hItem;

}

HTREEITEM CXTTreeBase::FindItemInBranch(LPCTSTR lpszSearch, BOOL bCaseSensitive /*= FALSE*/,
	BOOL bWholeWord /*= FALSE*/, HTREEITEM htiItem /*= NULL*/)
{
	HTREEITEM htiFound = NULL;

	if (!m_pTreeCtrl->ItemHasChildren(htiItem))
		return NULL;

	CString strSearch = lpszSearch;
	int iLen = strSearch.GetLength();
	if (iLen == 0)
	{
		return NULL;
	}

	if (!bCaseSensitive)
	{
		strSearch.MakeLower();
	}

	HTREEITEM htiChild = m_pTreeCtrl->GetChildItem(htiItem);
	while (htiChild != NULL)
	{
		if (m_pTreeCtrl->ItemHasChildren(htiChild))
		{
			htiFound = FindItemInBranch(lpszSearch, bCaseSensitive, bWholeWord, htiChild);
			if (htiFound != NULL)
				return htiFound;
		}

		CString strItemText = m_pTreeCtrl->GetItemText(htiChild);
		if (!bCaseSensitive)
		{
			strItemText.MakeLower();
		}

		int iIndex;
		while ((iIndex = strItemText.Find(strSearch)) != -1)
		{
			// Search string found
			if (bWholeWord)
			{
				// Check preceding char
				if (iIndex != 0)
				{
					if (_istalpha(strItemText[iIndex-1]) || strItemText[iIndex-1] == '_')
					{
						// Not whole word
						strItemText = strItemText.Right(strItemText.GetLength() -
							iIndex - iLen);
						continue;
					}
				}

				// Check succeeding char
				if (strItemText.GetLength() > iIndex + iLen &&
					(_istalpha(strItemText[iIndex + iLen]) ||
					(strItemText[iIndex + iLen] == '_')))
				{
					// Not whole word
					strItemText = strItemText.Right(strItemText.GetLength() -
						iIndex - strSearch.GetLength());
					continue;
				}
			}

			if (IsFindValid(htiChild))
			{
				return htiChild;
			}

			else
			{
				break;
			}
		}

		htiChild = m_pTreeCtrl->GetNextSiblingItem(htiChild);
	}

	return NULL;
}

HTREEITEM CXTTreeBase::FindItem(LPCTSTR lpszSearch, BOOL bCaseSensitive /*= FALSE*/,
	BOOL bDownDir /*= TRUE*/, BOOL bWholeWord /*= FALSE*/, HTREEITEM hItem /*= NULL*/)
{
	CString str = lpszSearch;

	int lenSearchStr = str.GetLength();
	if (lenSearchStr == 0)
	{
		return NULL;
	}

	// For the first pass, set the current item equal to the selection
	HTREEITEM htiSel = hItem ? hItem : m_pTreeCtrl->GetSelectedItem();

	// If NULL, use root item.
	if (htiSel == NULL)
		htiSel = m_pTreeCtrl->GetRootItem();

	HTREEITEM htiCur = htiSel;
	CString strSearch = str;

	// make sure it ends if we started with no selection
	if ((htiCur == NULL) && (htiSel != NULL))
	{
		if (bDownDir)
		{
			htiCur = m_pTreeCtrl->GetRootItem();
		}
		else
		{
			htiCur = GetLastItem(NULL);
		}
	}

	if (!bCaseSensitive)
	{
		strSearch.MakeLower();
	}

	// For the first pass only, we check to see if it
	// is the item we're looking for.
	BOOL bFirstPass = TRUE;

	while (htiCur && (htiCur != htiSel || bFirstPass))
	{
		bFirstPass = FALSE;

		CString strItemText = m_pTreeCtrl->GetItemText(htiCur);
		if (!bCaseSensitive)
		{
			strItemText.MakeLower();
		}

		int iIndex;
		while ((iIndex = strItemText.Find(strSearch)) != -1)
		{
			// Search string found
			if (bWholeWord)
			{
				// Check preceding char
				if (iIndex != 0)
				{
					if (_istalpha(strItemText[iIndex-1]) || strItemText[iIndex-1] == '_')
					{
						// Not whole word
						strItemText = strItemText.Right(strItemText.GetLength() -
							iIndex - lenSearchStr);
						continue;
					}
				}

				// Check succeeding char
				if (strItemText.GetLength() > iIndex + lenSearchStr &&
					(_istalpha(strItemText[iIndex + lenSearchStr]) ||
					(strItemText[iIndex + lenSearchStr] == '_')))
				{
					// Not whole word
					strItemText = strItemText.Right(strItemText.GetLength() -
						iIndex - strSearch.GetLength());
					continue;
				}
			}

			if (IsFindValid(htiCur))
			{
				return htiCur;
			}
			else
			{
				break;
			}
		}

		htiCur = bDownDir ? GetNextItem(htiCur) : GetPrevItem(htiCur);
		if (htiCur == NULL)
		{
			if (bDownDir)
			{
				htiCur = m_pTreeCtrl->GetRootItem();
			}
			else
			{
				htiCur = GetLastItem(NULL);
			}
		}
	}

	return NULL;
}

BOOL CXTTreeBase::IsFindValid(HTREEITEM)
{
	return TRUE;
}

void CXTTreeBase::SetItemFont(HTREEITEM hItem, LOGFONT& logfont)
{
	CLRFONT cf;
	if (!m_mapColorFont.Lookup(hItem, cf))
	{
		cf.color = COLORREF_NULL;
	}

	cf.logfont = logfont;
	m_mapColorFont[hItem] = cf;
}

BOOL CXTTreeBase::GetItemFont(HTREEITEM hItem, LOGFONT* plogfont)
{
	CLRFONT cf;
	if (!m_mapColorFont.Lookup(hItem, cf))
	{
		return FALSE;
	}

	if (cf.logfont.lfFaceName[0] == _T('\0'))
	{
		return FALSE;
	}

	*plogfont = cf.logfont;

	return TRUE;

}

void CXTTreeBase::SetItemBold(HTREEITEM hItem, BOOL bBold)
{
	SetItemState(hItem, bBold ? TVIS_BOLD : 0, TVIS_BOLD);
	m_pTreeCtrl->InvalidateRect(NULL);
}

BOOL CXTTreeBase::GetItemBold(HTREEITEM hItem)
{
	return GetItemState(hItem, TVIS_BOLD) & TVIS_BOLD;
}

void CXTTreeBase::SetItemColor(HTREEITEM hItem, COLORREF color)
{
	CLRFONT cf;
	m_mapColorFont.Lookup(hItem, cf);

	cf.color = color;
	m_mapColorFont[hItem] = cf;
	m_pTreeCtrl->InvalidateRect(NULL);
}

COLORREF CXTTreeBase::GetItemColor(HTREEITEM hItem)
{
	CLRFONT cf;
	if (m_mapColorFont.Lookup(hItem, cf))
		return cf.color;

	return COLORREF_NULL;
}

void CXTTreeBase::SetItemBackColor(HTREEITEM hItem, COLORREF color)
{
	CLRFONT cf;
	m_mapColorFont.Lookup(hItem, cf);

	cf.colorBack = color;
	m_mapColorFont[hItem] = cf;
	m_pTreeCtrl->InvalidateRect(NULL);
}

COLORREF CXTTreeBase::GetItemBackColor(HTREEITEM hItem)
{
	CLRFONT cf;
	if (m_mapColorFont.Lookup(hItem, cf))
		return cf.colorBack;

	return COLORREF_NULL;
}

COLORREF CXTTreeBase::GetTreeBackColor() const
{
	// if the tree is disabled return disabled back color.
	if (!m_pTreeCtrl->IsWindowEnabled())
		return GetXtremeColor(COLOR_3DFACE);

#if _MSC_VER >= 1200 // MFC 6.0

	if (XTPSystemVersion()->GetComCtlVersion() >= MAKELONG(71, 4))
	{
		// is there a user defined color available ?
		COLORREF crBack = m_pTreeCtrl->GetBkColor();
		if (crBack != COLORREF_NULL)
			return crBack;
	}

#endif

	// return the system window color.
	return GetXtremeColor(COLOR_WINDOW);
}

COLORREF CXTTreeBase::GetTreeTextColor() const
{
	// if the tree is disabled return disabled text color.
	if (!m_pTreeCtrl->IsWindowEnabled())
		return GetXtremeColor(COLOR_GRAYTEXT);

#if _MSC_VER >= 1200 // MFC 6.0
	if (XTPSystemVersion()->GetComCtlVersion() >= MAKELONG(71, 4))
	{
		// is ther a user defined color available ?
		COLORREF crText = m_pTreeCtrl->GetTextColor();
		if (crText != COLORREF_NULL)
			return crText;
	}

#endif

	// return the system window text color.
	return GetXtremeColor(COLOR_WINDOWTEXT);
}

COLORREF CXTTreeBase::GetItemBackColor(UINT uState, bool bTreeHasFocus, DWORD dwStyle, COLORREF crBack) const
{
	// if the tree item is selected or drop highlighted.
	if (uState & TVIS_SELECTED || uState & TVIS_DROPHILITED)
	{
		// if the tree has focus and draw the text background hilite color.
		if (bTreeHasFocus || uState & TVIS_DROPHILITED)
		{
			if (m_pTreeCtrl->IsWindowEnabled())
				return GetXtremeColor(COLOR_HIGHLIGHT);
			else
				return GetXtremeColor(COLOR_GRAYTEXT);
		}

		// if the tree does not have focus and the TVS_SHOWSELALWAYS flag is
		// set draw the text background hilite color.
		else if (dwStyle & TVS_SHOWSELALWAYS)
		{
			if (m_pTreeCtrl->IsWindowEnabled())
				return GetXtremeColor(COLOR_3DFACE);
			else
				return GetXtremeColor(COLOR_GRAYTEXT);
		}
	}

	return crBack;
}

COLORREF CXTTreeBase::GetItemTextColor(UINT uState, bool bTreeHasFocus, DWORD dwStyle, COLORREF crText) const
{
	// if the tree item is selected or drop highlighted.
	if (uState & TVIS_SELECTED || uState & TVIS_DROPHILITED)
	{
		// if the tree has focus and draw the text hilite color.
		if (bTreeHasFocus || uState & TVIS_DROPHILITED)
		{
			if (m_pTreeCtrl->IsWindowEnabled())
				return GetXtremeColor(COLOR_HIGHLIGHTTEXT);
			else
				return GetXtremeColor(COLOR_3DFACE);
		}

		// if the tree does not have focus and the TVS_SHOWSELALWAYS flag is
		// set draw the text hilite color.
		else if (dwStyle & TVS_SHOWSELALWAYS)
		{
			if (m_pTreeCtrl->IsWindowEnabled())
				return GetXtremeColor(COLOR_WINDOWTEXT);
			else
				return GetXtremeColor(COLOR_3DFACE);
		}
	}

	return crText;
}


void CXTTreeBase::DoPaint(CDC& dc, BOOL bInternal)
{
	// Get the client rect.
	CRect rcClient;
	m_pTreeCtrl->GetClientRect(&rcClient);

	const COLORREF crTreeBack = GetTreeBackColor();
	const COLORREF crTreeText = GetTreeTextColor();

	// Paint to a memory device context to help
	// eliminate screen flicker.
	CXTPBufferDC memDC(dc, rcClient);
	memDC.FillSolidRect(rcClient, crTreeBack);

	// Now let the window do its default painting...
	m_pTreeCtrl->DefWindowProc(WM_PAINT, (WPARAM)memDC.m_hDC, 0);

	if (!bInternal)
		return;

	int nSavedDC = memDC.SaveDC();

	// check to see if a tree label is getting edited.
	BOOL bEditing = (HasEditLabels() && m_pTreeCtrl->GetEditControl());

	// if not editing, make sure the edit item is set to NULL.
	if (!bEditing)
		m_htiEdit = NULL;

	// check to see if the tree is enabled.
	BOOL bIsEnabled = m_pTreeCtrl->IsWindowEnabled();

	// check to see if the tree has focus.
	bool bTreeHasFocus = (CWnd::GetFocus() == m_pTreeCtrl);

	// get the style for the tree.
	DWORD dwStyle = m_pTreeCtrl->GetStyle();

	// get the visible count.
	HTREEITEM hItem = m_pTreeCtrl->GetFirstVisibleItem();
	int iVisibleCount = m_pTreeCtrl->GetVisibleCount()+1;

	LOGFONT treefont;
	if (!m_pTreeCtrl->GetFont()->GetLogFont(&treefont))
	{
		::GetObject(::GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &treefont);
	}


	while (hItem && iVisibleCount--)
	{
		// get the tree item rect.
		CRect rcItem;
		m_pTreeCtrl->GetItemRect(hItem, &rcItem, TRUE);

		// refresh the background.
		CRect rcFill = rcItem;
		rcFill.right = rcClient.right;
		memDC.FillSolidRect(&rcFill, crTreeBack);

		// get the state of the tree item.
		UINT uState = GetItemState(hItem, TVIS_SELECTED | TVIS_FOCUSED | TVIS_DROPHILITED);

		if (m_pTreeCtrl->GetDropHilightItem() && uState & TVIS_SELECTED && hItem != m_pTreeCtrl->GetDropHilightItem())
			uState ^= TVIS_SELECTED;

		BOOL bSelected = ((uState & (TVIS_SELECTED | TVIS_DROPHILITED)) != 0);

		bool bUnderline = m_htiLast == hItem;

		// define the background and text colors.
		COLORREF crItemBack = GetItemBackColor(
			uState, bTreeHasFocus, dwStyle, crTreeBack);
		COLORREF crItemText = GetItemTextColor(
			uState, bTreeHasFocus, dwStyle, crTreeText);

		// if the item is getting edited paint white.
		if (m_htiEdit == hItem)
		{
			crItemBack = crTreeBack;
			crItemText = crTreeBack;
		}

		// create the LOGFONT used by the tree item.
		LOGFONT logfont;
		logfont = treefont;


		CLRFONT cf;
		if (m_mapColorFont.Lookup(hItem, cf))
		{
			if (!bSelected && bIsEnabled)
			{
				if (cf.color != COLORREF_NULL)
					crItemText = cf.color;

				if (cf.colorBack != COLORREF_NULL)
					crItemBack = cf.colorBack;
			}

			if (cf.logfont.lfFaceName[0] != _T('\0'))
			{
				logfont = cf.logfont;
			}
		}

		if (GetItemBold(hItem))
		{
			logfont.lfWeight = FW_BOLD;
		}

		if (dwStyle & TVS_TRACKSELECT)
		{
			logfont.lfUnderline = bUnderline ? (BYTE)1 : (BYTE)0;

			if (logfont.lfUnderline && !bSelected)
			{
				if (XTOSVersionInfo()->IsWin95() || XTOSVersionInfo()->IsWinNT4())
					crItemText = GetXtremeColor(COLOR_HIGHLIGHT);
				else
					crItemText = GetXtremeColor(COLOR_HOTLIGHT);
			}
		}

		// create a CFont object from the LOGFONT structure and
		// select it into the current device context.
		CFont fontDC;
		fontDC.CreateFontIndirect(&logfont);
		CFont* pOldFont = memDC.SelectObject(&fontDC);

		// get the text for the tree item and determine its size.
		CString strItem = m_pTreeCtrl->GetItemText(hItem);
		CSize sizeText = memDC.GetTextExtent(strItem);

		// if the text is wider than the tree item label, adjust accordingly.
		if (rcItem.Width() < sizeText.cx)
		{
			rcItem.right = rcItem.left + sizeText.cx + 2;
		}

		// set the font foreground and background colors.
		memDC.SetBkColor(crItemBack);
		memDC.SetTextColor(crItemText);

		// draw the label background if selected.
		if (bSelected)
		{
			memDC.FillSolidRect(&rcItem, crItemBack);
		}

		CRect rcText(rcItem);
		rcText.OffsetRect(3, 0);

		// draw the text and restore the device context.
		memDC.DrawText(strItem, &rcText, DT_SINGLELINE | DT_LEFT | DT_VCENTER | DT_NOPREFIX);

		// draw the focus rect.
		if ((uState & TVIS_FOCUSED))
		{
			if (!bEditing && bIsEnabled && CWnd::GetFocus() == m_pTreeCtrl)
			{
				memDC.SetTextColor(crTreeText);
				memDC.DrawFocusRect(&rcItem);
			}
		}

		memDC.SelectObject(pOldFont);
		fontDC.DeleteObject();

		// move to the next visible item.
		hItem = m_pTreeCtrl->GetNextVisibleItem(hItem);
	}

	memDC.RestoreDC(nSavedDC);
}


HTREEITEM CXTTreeBase::GetPrevSelectedItem(HTREEITEM hItem) const
{
	for (hItem = m_pTreeCtrl->GetPrevVisibleItem(hItem);
		hItem != NULL;
		hItem = m_pTreeCtrl->GetPrevVisibleItem(hItem))
	{
		if (GetItemState(hItem, TVIS_SELECTED) & TVIS_SELECTED)
		{
			return hItem;
		}
	}

	return NULL;
}

UINT CXTTreeBase::GetSelectedCount() const
{
	UINT nCount = 0;
	HTREEITEM hItem = GetFirstSelectedItem();
	while (hItem)
	{
		nCount++;
		hItem = GetNextSelectedItem(hItem);
	}
	return nCount;
}

BOOL CXTTreeBase::EnableMultiSelect(BOOL bMultiSelect)
{
	BOOL bReturn = m_bMultiSelect;
	m_bMultiSelect = bMultiSelect;

	if (!m_bMultiSelect)
	{
		HTREEITEM hItem = m_pTreeCtrl->GetSelectedItem();
		if (hItem && !IsSelected(hItem))
		{
			hItem = NULL;
		}
		SelectAllIgnore(FALSE, hItem);
		if (hItem)
		{
			SelectItem(hItem);
		}
	}

	return bReturn;
}

BOOL CXTTreeBase::SetItemState(HTREEITEM hItem, UINT nState, UINT nStateMask)
{
	ASSERT(hItem);
	if (!hItem)
		return FALSE;

	if (!m_bMultiSelect)
	{
		return m_pTreeCtrl->SetItemState(hItem, nState, nStateMask);
	}

	HTREEITEM hFocus = m_pTreeCtrl->GetSelectedItem();           // current focus
	BOOL bWasFocus = (hFocus == hItem);
	BOOL bFocusWasSel = hFocus && IsSelected(hFocus); // selection state of current focus
	BOOL bWasSel = IsSelected(hItem);            // select state of acting item

	UINT nS = (nState & ~TVIS_FOCUSED);
	UINT nSM = (nStateMask & ~TVIS_FOCUSED);

	BOOL bVista = XTPSystemVersion()->IsWinVistaOrGreater();

	if (nStateMask & TVIS_FOCUSED)
	{
		//wanted to affect focus
		if (nState & TVIS_FOCUSED)
		{
			if (bVista)
			{
				//wanted to set focus
				if (!bWasFocus && hFocus)
				{
					//because SelectItem would de-select the current 'real' selection
					// (the one with focus), need to make the tree ctrl think there is
					// no 'real' selection but still keep the the old item selected
					//it has to be done before the SelectItem call because
					// otherwise the TVN_SELCHANGING/ED notification handlers
					// wouldn't be able to get the proper list of selected items
					m_pTreeCtrl->SelectItem(NULL); //will cause notify, but can be taken as focus change
					m_pTreeCtrl->SetItemState(hFocus, TVIS_SELECTED, TVIS_SELECTED);
				}

				if (!m_pTreeCtrl->SelectItem(hItem))    //set focus (will consequently select, if not already focused)
				{
					return FALSE;
				}

				if (!bWasFocus && hFocus)
				{
					m_pTreeCtrl->SetItemState(hFocus, bFocusWasSel ? TVIS_SELECTED : 0, TVIS_SELECTED);
				}
			}
			else
			{
				//wanted to set focus
				if (!bWasFocus && bFocusWasSel)
				{
					//because SelectItem would de-select the current 'real' selection
					// (the one with focus), need to make the tree ctrl think there is
					// no 'real' selection but still keep the the old item selected
					//it has to be done before the SelectItem call because
					// otherwise the TVN_SELCHANGING/ED notification handlers
					// wouldn't be able to get the proper list of selected items
					m_pTreeCtrl->SelectItem(NULL); //will cause notify, but can be taken as focus change
					m_pTreeCtrl->SetItemState(hFocus, TVIS_SELECTED, TVIS_SELECTED);
					m_pTreeCtrl->UpdateWindow();
				}

				if (!m_pTreeCtrl->SelectItem(hItem))    //set focus (will consequently select, if not already focused)
				{
					return FALSE;
				}
			}

			if (nStateMask & TVIS_SELECTED)
			{
				//wanted to affect select state
				if (nState & TVIS_SELECTED)
				{
					//wanted to select, already done if wasn't focused
					if (!bVista && (!bWasFocus || bFocusWasSel))
					{
						nS &= ~TVIS_SELECTED;
						nSM &= ~TVIS_SELECTED;
					}
				}
				//else wanted to clear, base call will do that
			}
			else
			{
				//didn't want to affect select state
				if (!bWasSel)
				{
					//it wasn't previously selected, let base clear (correct)
					nS &= ~TVIS_SELECTED;
					nSM |= TVIS_SELECTED;
				}
				//else was already selected, no harm done
			}
		}
		else
		{
			//wanted to clear focus
			if (bWasFocus)
			{
				//it had the focus
				m_pTreeCtrl->SelectItem(NULL);  //clear focus
				if (!(nStateMask & TVIS_SELECTED))
				{
					//didn't want to affect select state
					if (bWasSel)
					{
						//it was selected, so restore
						ASSERT(!(nS & TVIS_SELECTED));
						ASSERT(!(nSM & TVIS_SELECTED));
						//set state here, to avoid double-notify
						m_pTreeCtrl->SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);
						//let base do other states
					}
				}
				else if (nState & TVIS_SELECTED)
				{
					//wanted to select (but clear focus)
					if (bWasSel)
					{
						//if was selected, restore
						m_pTreeCtrl->SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);
					}
					//don't want to notify, default did it
					nS &= ~TVIS_SELECTED;
					nSM &= ~TVIS_SELECTED;
				}
			}
		}
	}

	if (!nSM)
	{
		return TRUE;    //no other states to alter
	}

	if (nSM & TVIS_SELECTED)
	{
		//still need to alter selection state
		NMTREEVIEW nmtv;
		nmtv.hdr.hwndFrom = m_pTreeCtrl->m_hWnd;
		nmtv.hdr.idFrom = ::GetDlgCtrlID(m_pTreeCtrl->m_hWnd);
		nmtv.hdr.code = TVN_SELCHANGING;
		nmtv.itemOld.mask = nmtv.itemNew.mask = 0;
		nmtv.itemOld.hItem = nmtv.itemNew.hItem = NULL;

		TVITEM& item = (nS & TVIS_SELECTED) ? nmtv.itemNew : nmtv.itemOld;
		item.mask = TVIF_HANDLE | TVIF_PARAM;
		item.hItem = hItem;
		item.lParam = m_pTreeCtrl->GetItemData(hItem);
		item.state = nS;
		item.stateMask = nSM;

		if (SendNotify(&nmtv.hdr))
		{
			return FALSE;   //sel-changing stopped
		}

		VERIFY(m_pTreeCtrl->SetItemState(hItem, nS, nSM));
		nmtv.hdr.code = TVN_SELCHANGED;
		SendNotify(&nmtv.hdr);
		nS &= ~TVIS_SELECTED;
		nSM &= ~TVIS_SELECTED;
	}

	if (!nSM)
	{
		return TRUE;
	}

	return m_pTreeCtrl->SetItemState(hItem, nS, nSM);
}

UINT CXTTreeBase::GetItemState(HTREEITEM hItem, UINT nStateMask) const
{
	UINT n = m_pTreeCtrl->GetItemState(hItem, nStateMask & ~TVIS_FOCUSED);
	if (nStateMask & TVIS_FOCUSED)
	{
		if (m_pTreeCtrl->GetSelectedItem() == hItem)
		{
			n |= TVIS_FOCUSED;
		}
	}
	return n;
}

BOOL CXTTreeBase::SelectItem(HTREEITEM hItem)
{
	if (m_bMultiSelect)
	{
		return SetItemState(hItem,
			TVIS_SELECTED | TVIS_FOCUSED, TVIS_SELECTED | TVIS_FOCUSED);
	}
	else
	{
		return m_pTreeCtrl->SelectItem(hItem);
	}
}

BOOL CXTTreeBase::FocusItem(HTREEITEM hItem)
{
	ASSERT(m_bMultiSelect);

	BOOL bRet = FALSE;
	if (hItem)
	{
		bRet = SetItemState(hItem, TVIS_FOCUSED, TVIS_FOCUSED);
	}
	else
	{
		hItem = m_pTreeCtrl->GetSelectedItem();
		if (hItem)
		{
			bRet = SetItemState(hItem, 0, TVIS_FOCUSED);
		}
	}
	return bRet;
}

LRESULT CXTTreeBase::SendNotify(LPNMHDR pNMHDR)
{
	CWnd* pWndOwner = m_pTreeCtrl->GetOwner();
	if (pWndOwner->GetSafeHwnd())
	{
		return ::SendMessage(pWndOwner->m_hWnd, WM_NOTIFY,
			(WPARAM)pNMHDR->idFrom, (LPARAM)pNMHDR);
	}

	return NULL;
}

HTREEITEM CXTTreeBase::GetFirstSelectedItem() const
{
	HTREEITEM hItem = m_pTreeCtrl->GetRootItem();
	while (hItem)
	{
		if (IsSelected(hItem))
		{
			break;
		}
		hItem = m_pTreeCtrl->GetNextVisibleItem(hItem);
	}
	return hItem;
}

HTREEITEM CXTTreeBase::GetNextSelectedItem(HTREEITEM hItem) const
{
	hItem = m_pTreeCtrl->GetNextVisibleItem(hItem);
	while (hItem)
	{
		if (IsSelected(hItem))
		{
			break;
		}
		hItem = m_pTreeCtrl->GetNextVisibleItem(hItem);
	}
	return hItem;
}

void CXTTreeBase::SelectAll(BOOL bSelect /*= TRUE*/, HTREEITEM htItem/*= NULL*/)
{
	bSelect = !!bSelect;    //ensure 0 or 1
	UINT nState = bSelect ? TVIS_SELECTED : 0;

	if (htItem == NULL)
		htItem = m_pTreeCtrl->GetRootItem();

	while (htItem)
	{
		if (IsSelected(htItem) != bSelect)
		{
			SetItemState(htItem, nState, TVIS_SELECTED);
		}
		htItem = m_pTreeCtrl->GetNextVisibleItem(htItem);
	}
}

void CXTTreeBase::SelectAllIgnore(BOOL bSelect, HTREEITEM hIgnore)
{
	//special case to avoid multiple notifications for
	// the same item
	bSelect = !!bSelect;    //ensure 0 or 1
	UINT nState = bSelect ? TVIS_SELECTED : 0;
	HTREEITEM hItem = m_pTreeCtrl->GetRootItem();
	while (hItem)
	{
		if (hItem != hIgnore)
		{
			if (IsSelected(hItem) != bSelect)
			{
				SetItemState(hItem, nState, TVIS_SELECTED);
			}
		}
		hItem = m_pTreeCtrl->GetNextVisibleItem(hItem);
	}
}

void CXTTreeBase::SelectItems(HTREEITEM hFirst, HTREEITEM hLast, BOOL bOnly /*= TRUE*/)
{
	//locate (and select) either first or last
	// (so order is arbitrary)
	HTREEITEM hItem = m_pTreeCtrl->GetRootItem();
	while (hItem)
	{
		if ((hItem == hFirst) || (hItem == hLast))
		{
			if (hFirst != hLast)
			{
				if (!IsSelected(hItem))
				{
					SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);
				}
				hItem = m_pTreeCtrl->GetNextVisibleItem(hItem);
			}
			break;
		}

		if (bOnly && IsSelected(hItem))
		{
			SetItemState(hItem, 0, TVIS_SELECTED);
		}

		hItem = m_pTreeCtrl->GetNextVisibleItem(hItem);
	}

	//select rest of range
	while (hItem)
	{
		if (!IsSelected(hItem))
		{
			SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);
		}
		if ((hItem == hFirst) || (hItem == hLast))
		{
			hItem = m_pTreeCtrl->GetNextVisibleItem(hItem);
			break;
		}
		hItem = m_pTreeCtrl->GetNextVisibleItem(hItem);
	}
	if (!bOnly)
	{
		return;
	}
	while (hItem)
	{
		if (IsSelected(hItem))
		{
			SetItemState(hItem, 0, TVIS_SELECTED);
		}
		hItem = m_pTreeCtrl->GetNextVisibleItem(hItem);
	}
}

BOOL CXTTreeBase::OnButtonDown(BOOL bLeft, UINT nFlags, CPoint point)
{
	UINT      nHF = 0;
	HTREEITEM hItem = NULL;

	if (!m_bMultiSelect)
		return TRUE;

	BOOL bBase = FALSE;

	hItem = m_pTreeCtrl->HitTest(point, &nHF);
	if (hItem)
	{
		//base always handles expanding items
		//(doesn't really mean much to right button, but pass anyway)
		bBase = (nHF & (TVHT_ONITEMBUTTON));
		if (!bBase && bLeft && (m_pTreeCtrl->GetStyle() & TVS_CHECKBOXES))
		{
			//when the tree has check-boxes, the default handler makes
			// a quick selection of the clicked item, then re-selects
			// the previously selected item - to cause a sel-changed
			// notification.  Fortunately it doesn't affect the multi-
			// selection, so can pass on.
			bBase = (nHF & TVHT_ONITEMSTATEICON);

#ifdef _MST_MULTI_CHECK
			//Use the above define if you want all selected items to
			// be checked the same when any one of them is checked
			// - Interestingly this doesn't happen in the listview control
			//  (LVS_EX_CHECKBOXES)
			if (bBase)
			{
				//the default selection notification would mess
				// the multi-selection up, so generate the notification
				// manually
				// (anyway, this is smoother than the selection flicker
				//  the default gives)
				NMTREEVIEW nmtv;
#ifdef TVN_CHKCHANGE
				nmtv.hdr.code = TVN_CHKCHANGE;
#else
				nmtv.hdr.code = TVN_SELCHANGED;
#endif
				nmtv.hdr.hwndFrom = m_hWnd;
				nmtv.hdr.idFrom = ::GetDlgCtrlID(m_hWnd);
				nmtv.itemOld.hItem = NULL;
				nmtv.itemNew.mask = TVIF_HANDLE | TVIF_PARAM;

				BOOL bChk = !GetCheck(hItem);
				if (IsSelected(hItem))
				{
					HTREEITEM h = GetFirstSelectedItem();
					while (h)
					{
						if (!GetCheck(h) == bChk) //! to ensure 0 or 1
						{
							SetCheck(h, bChk);
#ifdef TVN_CHKCHANGE
							//only send multiple check-change
							// notifications (not sel-changed)
							if (h != hItem) //clicked item will be done last
							{
								nmtv.itemNew.hItem = h;
								nmtv.itemNew.lParam = m_pTreeCtrl->GetItemData(h);
								SendNotify(&nmtv.hdr);
							}
#endif
						}
						h = GetNextSelectedItem(h);
					}
				}
				else
				{
					SetCheck(hItem, bChk);
				}
				//notify clicked item
				nmtv.itemNew.hItem = hItem;
				nmtv.itemNew.lParam = m_pTreeCtrl->GetItemData(hItem);
				SendNotify(&nmtv.hdr);
				return TRUE;
			}
#endif
		}
	}

	if (bBase)
		return TRUE;

	if (!hItem || (nHF & (TVHT_ONITEMRIGHT | TVHT_NOWHERE | TVHT_ONITEMINDENT)))
	{
		//clicked in space, do rubber-banding
		DoBanding(nFlags, point);
		return TRUE;
	}

	ASSERT(nHF & (TVHT_ONITEM | TVHT_ONITEMSTATEICON));   //nothing else left

	DoPreSelection(hItem, bLeft, nFlags);
	DoAction(hItem, bLeft, nFlags, point);

	return m_bActionDone;  // as set in doaction
}

void CXTTreeBase::DoPreSelection(HTREEITEM hItem, BOOL bLeft, UINT nFlags)
{
	if (bLeft)
	{
		//if shift key down, select immediately
		if ((nFlags & MK_SHIFT))
		{
			if (!m_hSelect)
			{
				m_hSelect = m_pTreeCtrl->GetSelectedItem(); //focus
			}

			SetItemState(hItem, TVIS_FOCUSED, TVIS_FOCUSED);    //focus changes to last clicked
			SelectItems(m_hSelect, hItem, !(nFlags & MK_CONTROL));
		}
		else
		{
			if (!(nFlags & MK_CONTROL))
			{
				//if ctrl was down, then the selection is delayed until
				// mouse up, otherwise select the one item
				if (!IsSelected(hItem))
				{
					SelectAllIgnore(FALSE, hItem);
				}
				SetItemState(hItem, TVIS_SELECTED | TVIS_FOCUSED, TVIS_SELECTED | TVIS_FOCUSED);
			}
			m_hSelect = NULL;   //reset when a non-shift operation occurs
		}
		return;
	}

	//right mouse
	if (nFlags & (MK_CONTROL | MK_SHIFT))
	{
		if (!(nFlags & MK_SHIFT))
		{
			m_hSelect = hItem;
		}
		return;     //do nothing if shift or ctrl
	}
	if (!IsSelected(hItem))
	{
		SelectAllIgnore(FALSE, hItem);
	}
	SetItemState(hItem, TVIS_SELECTED | TVIS_FOCUSED, TVIS_SELECTED | TVIS_FOCUSED);
}

void CXTTreeBase::DoAction(HTREEITEM hItem, BOOL bLeft, UINT nFlags, CPoint point)
{
	m_bActionDone = false;
	::SetCapture(m_pTreeCtrl->m_hWnd);
	ASSERT(::GetCapture() == m_pTreeCtrl->m_hWnd);

	MSG msg;
	UINT nDone = 0;
	CPoint pt;
	CSize sizeDrag(::GetSystemMetrics(SM_CXDRAG), ::GetSystemMetrics(SM_CYDRAG));

	while (!nDone && ::GetMessage(&msg, NULL, 0, 0))
	{
		if (::GetCapture() != m_pTreeCtrl->m_hWnd)
		{
			break;
		}
		switch (msg.message)
		{
			case WM_MOUSEMOVE:
				pt.x = GET_X_LPARAM(msg.lParam);
				pt.y = GET_Y_LPARAM(msg.lParam);
				if ((abs(pt.x - point.x) > sizeDrag.cx) ||
					((abs(pt.y - point.y) > sizeDrag.cy)))
				{
					nDone = 2;
				}
				//because we exit loop, button up will still be dispatched
				// which means WM_CONTEXTMENU will be sent after TVN_BEGINRDRAG
				// - this is the same behavior as original tree
				break;

			case WM_LBUTTONUP:
			case WM_RBUTTONUP:
				nDone = 1;
				break;

			default:
				::DispatchMessage(&msg);
				break;
		}

	}

	::ReleaseCapture();
	ASSERT(::GetCapture() != m_pTreeCtrl->m_hWnd);

	//construct tree notification info
	NMTREEVIEW nmtv;
	nmtv.hdr.hwndFrom = m_pTreeCtrl->m_hWnd;
	nmtv.hdr.idFrom = ::GetDlgCtrlID(m_pTreeCtrl->m_hWnd);
	nmtv.itemNew.mask = TVIF_HANDLE | TVIF_PARAM;
	nmtv.itemNew.hItem = hItem;
	nmtv.itemNew.lParam = m_pTreeCtrl->GetItemData(hItem);
	DWORD dwStyle = m_pTreeCtrl->GetStyle();

	if (nDone == 1)
	{
		//click
		if (!(nFlags & MK_SHIFT) && bLeft)
		{
			if ((nFlags & MK_CONTROL))
			{
				UINT nState = (GetItemState(hItem, TVIS_SELECTED) & TVIS_SELECTED) ? 0 : TVIS_SELECTED;
				SetItemState(hItem, TVIS_FOCUSED | nState, TVIS_FOCUSED | TVIS_SELECTED);
			}
			else
			{
				SelectAllIgnore(FALSE, hItem);
				SetItemState(hItem, TVIS_FOCUSED | TVIS_SELECTED, TVIS_FOCUSED | TVIS_SELECTED);
			}
		}
		if (::GetFocus() != m_pTreeCtrl->m_hWnd)
		{
			::SetFocus(m_pTreeCtrl->m_hWnd);
		}

		nmtv.hdr.code = bLeft ? NM_CLICK : NM_RCLICK;
		SendNotify(&nmtv.hdr);
		m_bActionDone = true;
	}
	else if (nDone == 2)
	{
		//drag
		SetItemState(hItem, TVIS_FOCUSED | TVIS_SELECTED, TVIS_FOCUSED | TVIS_SELECTED);
		if (!(dwStyle & TVS_DISABLEDRAGDROP))
		{
			nmtv.hdr.code = bLeft ? TVN_BEGINDRAG : TVN_BEGINRDRAG;
			nmtv.ptDrag = point;
			SendNotify(&nmtv.hdr);
		}
		m_bActionDone = true;
	}
}

void CXTTreeBase::DoBanding(UINT nFlags, CPoint point)
{
	if (::GetFocus() != m_pTreeCtrl->m_hWnd)
	{
		::SetFocus(m_pTreeCtrl->m_hWnd);
	}

	::SetCapture(m_pTreeCtrl->m_hWnd);

	CTypedPtrList<CPtrList, HTREEITEM> list;
	if (nFlags & (MK_SHIFT | MK_CONTROL))
	{
		GetSelectedList(list);
	}

	CClientDC dc(m_pTreeCtrl);
	CRect rectCli;
	m_pTreeCtrl->GetClientRect(&rectCli);

	MSG msg;
	BOOL bDone = FALSE;
	CPoint pt;
	CSize sizeDrag(::GetSystemMetrics(SM_CXDRAG), ::GetSystemMetrics(SM_CYDRAG));
	BOOL bDrag = FALSE;
	CSize sizeEdge(1, 1);

	UINT_PTR nTimer = m_pTreeCtrl->SetTimer(1, SCROLL_TIMER_PERIOD, NULL);  //for scroll
	CPoint ptScr(m_pTreeCtrl->GetScrollPos(SB_HORZ), m_pTreeCtrl->GetScrollPos(SB_VERT));
	CRect rect(0, 0, 0, 0);
	UINT h = 0;
	HTREEITEM hItem = m_pTreeCtrl->GetRootItem();
	if (hItem)
	{
		m_pTreeCtrl->GetItemRect(hItem, &rect, FALSE);
		ptScr.y *= (h = rect.Height());     //this assumes equal height items
	}
	point += ptScr;

	while (!bDone && ::GetMessage(&msg, NULL, 0, 0))
	{
		if (::GetCapture() != m_pTreeCtrl->m_hWnd)
		{
			break;
		}

		switch (msg.message)
		{
			case WM_TIMER:
				{
					if (msg.wParam == SCROLL_TIMER_PERIOD)
					{
						pt = msg.pt;
						m_pTreeCtrl->ScreenToClient(&pt);
						if (rectCli.PtInRect(pt))
						{
							::DispatchMessage(&msg);
							break;
						}
						msg.lParam = MAKELPARAM(pt.x, pt.y);
					}
					else
					{
						break;
					}
				}
				//fall through to mouse move

			case WM_MOUSEMOVE:
				pt.x = GET_X_LPARAM(msg.lParam);
				pt.y = GET_Y_LPARAM(msg.lParam);
				if (!bDrag)
				{
					if ((abs(pt.x - point.x) <= sizeDrag.cx) &&
						((abs(pt.y - point.y) <= sizeDrag.cy)))
					{
						break;
					}
					bDrag = TRUE;
					if (!(nFlags & (MK_CONTROL | MK_SHIFT)))
					{
						SelectAll(FALSE);
					}
					m_pTreeCtrl->UpdateWindow();
					rect.SetRect(point, point);
					dc.DrawDragRect(rect, sizeEdge, NULL, sizeEdge);
				}

				dc.DrawDragRect(rect, sizeEdge, NULL, sizeEdge);    //delete

				if (pt.y < rectCli.top)
				{
					::SendMessage(m_pTreeCtrl->m_hWnd, WM_VSCROLL, SB_LINEUP, 0);
				}
				else if (pt.y >= rectCli.bottom)
				{
					::SendMessage(m_pTreeCtrl->m_hWnd, WM_VSCROLL, SB_LINEDOWN, 0);
				}
				if (pt.x < rectCli.left)
				{
					::SendMessage(m_pTreeCtrl->m_hWnd, WM_HSCROLL, SB_LINELEFT, 0);
				}
				else if (pt.x >= rectCli.right)
				{
					::SendMessage(m_pTreeCtrl->m_hWnd, WM_HSCROLL, SB_LINERIGHT, 0);
				}

				ptScr = point;
				ptScr.x -= m_pTreeCtrl->GetScrollPos(SB_HORZ);
				ptScr.y -= m_pTreeCtrl->GetScrollPos(SB_VERT) * h;
				rect.SetRect(ptScr, pt);
				rect.NormalizeRect();
				UpdateSelectionForRect(rect, nFlags, list);
				dc.DrawDragRect(rect, sizeEdge, NULL, sizeEdge);    //draw
				break;

			case WM_LBUTTONUP:
			case WM_RBUTTONUP:
				bDone = TRUE;
				break;

			case WM_KEYDOWN:
				if (LOWORD(msg.wParam) == VK_ESCAPE)
				{
					SelectAll(FALSE);
					bDone = TRUE;
					break;
				}
				//dispatch

			default:
				::DispatchMessage(&msg);
				break;
		}
	}
	m_pTreeCtrl->KillTimer(nTimer);
	::ReleaseCapture();

	if (bDrag)
	{
		dc.DrawDragRect(rect, sizeEdge, NULL, sizeEdge);
	}
	else
	{
		if (!(nFlags & (MK_CONTROL | MK_SHIFT)))
		{
			SelectAll(FALSE);
		}
	}
}

void CXTTreeBase::UpdateSelectionForRect(LPCRECT pRect, UINT nFlags, CTypedPtrList<CPtrList, HTREEITEM>& list)
{
	CRect rect;
	BOOL bSel;
	POSITION pos;

	HTREEITEM hItem = m_pTreeCtrl->GetRootItem();
	while (hItem)
	{
		bSel = IsSelected(hItem);
		m_pTreeCtrl->GetItemRect(hItem, &rect, m_bBandLabel);
		if (rect.IntersectRect(rect, pRect))
		{
			//item in rect
			pos = list.Find(hItem);
			if (!bSel && !pos)
			{
				SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);
			}
			else if ((nFlags & MK_CONTROL) && pos)
			{
				SetItemState(hItem, 0, TVIS_SELECTED);
			}
			else if ((nFlags & MK_SHIFT) && pos)
			{
				list.RemoveAt(pos);     //if shift and in rect, don't lock anymore
			}
		}
		else
		{
			//item not in rect
			pos = list.Find(hItem);
			if (bSel && !pos)
			{
				SetItemState(hItem, 0, TVIS_SELECTED);
			}
			else if (pos)
			{
				SetItemState(hItem, TVIS_SELECTED, TVIS_SELECTED);
			}
		}
		hItem = m_pTreeCtrl->GetNextVisibleItem(hItem);
	}
	m_pTreeCtrl->UpdateWindow();
}

BOOL CXTTreeBase::SelectChildren(HTREEITEM hParent, BOOL bSelect /*= TRUE*/, BOOL bRecurse /*= TRUE*/)
{
	UINT nS = bSelect ? TVIS_SELECTED : 0;

	BOOL bFocusWasInHere = FALSE;

	HTREEITEM hItem = GetNextItem(hParent, TVGN_CHILD);
	while (hItem)
	{
		UINT nState = GetItemState(hItem, TVIS_SELECTED | TVIS_EXPANDED | TVIS_FOCUSED);
		if ((nState & TVIS_SELECTED) != nS)
		{
			SetItemState(hItem, nS, TVIS_SELECTED);
		}
		bFocusWasInHere |= (nState & TVIS_FOCUSED);
		if (bRecurse && (nState & TVIS_EXPANDED))
		{
			bFocusWasInHere |= SelectChildren(hItem, bSelect, bRecurse);
		}
		hItem = m_pTreeCtrl->GetNextSiblingItem(hItem);
	}
	return bFocusWasInHere;
}

void CXTTreeBase::GetSelectedList(CTypedPtrList<CPtrList, HTREEITEM>& list) const
{
	list.RemoveAll();

	HTREEITEM hItem = GetFirstSelectedItem();
	while (hItem)
	{
		list.AddTail(hItem);
		hItem = GetNextSelectedItem(hItem);
	}
}

BOOL CXTTreeBase::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	NMHDR* pNMHDR = (NMHDR*)lParam;

	switch (pNMHDR->code)
	{
	case TTN_SHOW:
		{
			// get a pointer to the tooltip control.
			HWND hWnd = TreeView_GetToolTips(m_pTreeCtrl->m_hWnd);
			if (hWnd != NULL)
			{
				// make sure the tooltip is at the top of the "Z" order, otherwise
				// it will appear behind popup windows....
				::SetWindowPos(hWnd, HWND_TOP, 0, 0, 0, 0,
					SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
			}
		}
		break;
	}

	return m_pTreeCtrl->CTreeCtrl::OnNotify(wParam, lParam, pResult);
}

BOOL CXTTreeBase::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		// ensure that keystrokes are handled by the edit control.
		if (HasEditLabels() && m_pTreeCtrl->GetEditControl())
		{
			::TranslateMessage(pMsg);
			::DispatchMessage(pMsg);

			return TRUE;
		}

		// toggle expand / contract when return key is hit.
		if (pMsg->wParam == VK_RETURN)
		{
			HTREEITEM htItem = m_pTreeCtrl->GetSelectedItem();
			if (htItem != NULL)
			{
				m_pTreeCtrl->Expand(htItem, TVE_TOGGLE);
			}
		}
	}

	return m_pTreeCtrl->CTreeCtrl::PreTranslateMessage(pMsg);
}

BOOL CXTTreeBase::OnDeleteItem(NMHDR* pNMHDR, LRESULT* pResult)
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	// Remove the tree item from the map.
	m_mapColorFont.RemoveKey(pNMTreeView->itemOld.hItem);
	*pResult = 0;

	return FALSE;
}

// target 00666e00 calls HasEditLabels (mov ecx, esi; call; test al, al) instead of inlining it
__declspec(noinline) bool CXTTreeBase::HasEditLabels() const
{
	return ((m_pTreeCtrl->GetStyle() & TVS_EDITLABELS) == TVS_EDITLABELS);
}

void CXTTreeBase::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	m_pTreeCtrl->Default();

	// MFCBUG: During label editing if the tree is resized while
	// there is an edit box open the edit box is not moved to the
	// new location of the tree item, but is left in it previous
	// location.

	if (HasEditLabels() && m_htiEdit)
	{
		CEdit* pEdit = m_pTreeCtrl->GetEditControl();
		if (pEdit && ::IsWindow(pEdit->m_hWnd))
		{
			CRect rcEdit;
			pEdit->GetWindowRect(&rcEdit);

			CRect rcItem;
			m_pTreeCtrl->GetItemRect(m_htiEdit, &rcItem, TRUE);

			rcItem.top -= 1;
			rcItem.left -= 3;
			rcItem.right = rcItem.left + rcEdit.Width();
			rcItem.bottom = rcItem.top + rcEdit.Height();

			pEdit->MoveWindow(&rcItem);
		}
	}
}

void CXTTreeBase::OnMouseMove(UINT /*nFlags*/, CPoint point)
{
	if (m_pTreeCtrl->GetStyle() & TVS_TRACKSELECT)
	{
		TV_HITTESTINFO hit;
		::ZeroMemory(&hit, sizeof(hit));

		hit.pt = point;
		m_pTreeCtrl->HitTest(&hit);

		HTREEITEM hItem = hit.hItem && hit.flags & TVHT_ONITEM ? hit.hItem : NULL;

		if (m_htiLast != hItem)
		{
			m_htiLast = hItem;

			if (m_htiLast)
			{
				UINT_PTR uID = m_pTreeCtrl->SetTimer(HOVER_TIMER_PERIOD, 55, NULL);
				ASSERT(uID == HOVER_TIMER_PERIOD);
			}

			m_pTreeCtrl->Invalidate(FALSE);
		}
	}


	m_pTreeCtrl->Default();
}

void CXTTreeBase::OnTimer(UINT_PTR nIDEvent)
{
	if (m_pTreeCtrl->GetStyle() & TVS_TRACKSELECT)
	{
		if (nIDEvent == HOVER_TIMER_PERIOD)
		{
			if (m_htiLast != NULL)
			{
				CPoint pt(::GetMessagePos());
				CRect rc;
				m_pTreeCtrl->GetWindowRect(&rc);

				if (rc.PtInRect(pt) == FALSE)
				{
					m_pTreeCtrl->KillTimer(HOVER_TIMER_PERIOD);

					m_htiLast = NULL;
					m_pTreeCtrl->Invalidate(FALSE);
				}
			}
			else
			{
				m_pTreeCtrl->KillTimer(HOVER_TIMER_PERIOD);
			}
			return;
		}
	}

	m_pTreeCtrl->Default();
}

void CXTTreeBase::OnNcMouseMove(UINT /*nHitTest*/, CPoint /*point*/)
{
	if (m_pTreeCtrl->GetStyle() & TVS_TRACKSELECT)
	{
		if (m_htiLast)
		{
			m_htiLast = NULL;
			m_pTreeCtrl->Invalidate(FALSE);
		}
	}

	m_pTreeCtrl->Default();
}

bool CXTTreeBase::Init()
{
	if (!::IsWindow(m_pTreeCtrl->GetSafeHwnd()))
		return false;

	return true;
}
