#include "CScriptEditor.h"
#include "script/Script.h"
#include "v8datamodel/DataModel.h"
#include "util/ContentProvider.h"
#include <boost/iostreams/copy.hpp>
#include <algorithm>
#include <memory>
#include <sstream>

namespace RBX {
}

// Posted by setScript 00465260 and dispatched by the message map entry at 0081b648+0x1b0.
#define WM_SCRIPT_RELOAD (WM_USER + 0x65)

IMPLEMENT_DYNCREATE(CScriptEditor, Scintilla::CScintillaView)

// Entry order and command ids from the AFX_MSGMAP_ENTRY table at 0081b648.
BEGIN_MESSAGE_MAP(CScriptEditor, Scintilla::CScintillaView)
    ON_WM_CREATE()
    ON_COMMAND(0x80e5, &CScriptEditor::OnAddBookmark)
    ON_COMMAND(0x80e6, &CScriptEditor::OnRemoveBookmark)
    ON_UPDATE_COMMAND_UI(0x80e6, &CScriptEditor::OnUpdateRemoveBookmark)
    ON_COMMAND(0x80e7, &CScriptEditor::OnNextBookmark)
    ON_COMMAND(0x80e8, &CScriptEditor::OnPreviousBookmark)
    ON_COMMAND(0x80e4, &CScriptEditor::OnToggleFoldMargin)
    ON_COMMAND(0x80e3, &CScriptEditor::OnToggleSelectionMargin)
    ON_UPDATE_COMMAND_UI(0x80e3, &CScriptEditor::OnUpdateToggleSelectionMargin)
    ON_COMMAND(0x80e2, &CScriptEditor::OnToggleLineNumbers)
    ON_UPDATE_COMMAND_UI(0x80e2, &CScriptEditor::OnUpdateToggleLineNumbers)
    ON_UPDATE_COMMAND_UI(0x80e5, &CScriptEditor::OnUpdateAddBookmark)
    ON_UPDATE_COMMAND_UI(0x80e4, &CScriptEditor::OnUpdateToggleFoldMargin)
    ON_UPDATE_COMMAND_UI(0xcb, &CScriptEditor::OnUpdateLine)
    ON_UPDATE_COMMAND_UI(0xcc, &CScriptEditor::OnUpdateStyle)
    ON_UPDATE_COMMAND_UI(0xcd, &CScriptEditor::OnUpdateFold)
    ON_UPDATE_COMMAND_UI(0xe704, &CScriptEditor::OnUpdateInsert)
    ON_WM_ACTIVATE()
    ON_MESSAGE(WM_SCRIPT_RELOAD, &CScriptEditor::OnReload)
END_MESSAGE_MAP()

int CScriptEditor::instanceCount;
HMODULE CScriptEditor::sciLexer;

// Original 00465010.
CScriptEditor::CScriptEditor()
    : frame(NULL),
      loading(false),
      running(false),
      embedded(false)
{
}

// Original 00465830.
CScriptEditor::~CScriptEditor()
{
    setScript(boost::shared_ptr<RBX::Script>());
}

// Original 00463910.
BOOL CScriptEditor::PreCreateWindow(CREATESTRUCT& cs)
{
    return CScintillaView::PreCreateWindow(cs) != FALSE;
}

// Original 00463980.
void CScriptEditor::PostNcDestroy()
{
    if (--instanceCount == 0)
        FreeLibrary(sciLexer);
    CScintillaView::PostNcDestroy();
}

// Original 00463930.
int CScriptEditor::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (instanceCount == 0) {
        sciLexer = LoadLibrary("SciLexer.dll");
        if (sciLexer == NULL)
            return -1;
    }
    ++instanceCount;
    if (CScintillaView::OnCreate(lpCreateStruct) == -1)
        return -1;
    return 0;
}

// Original 00463ed0.
void CScriptEditor::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
    CScintillaView::OnActivate(nState, pWndOther, bMinimized);
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    if (nState == WA_INACTIVE && ctrl.CallTipActive())
        ctrl.CallTipCancel();
}

// Original 004644e0.
void CScriptEditor::OnDwellEnd(SCNotification*)
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    if (ctrl.CallTipActive())
        ctrl.CallTipCancel();
}

// Original 00464960 (tail jump to 00464830).
void CScriptEditor::OnKillFocus()
{
    saveScript();
}

// Original 004657f0.
void CScriptEditor::OnUpdate(CView*, LPARAM lHint, CObject*)
{
    if (lHint == 1)
        setScript(static_cast<CScriptDoc*>(GetDocument())->script);
}

// Original 00465500.
void CScriptEditor::onEvent(const RBX::Instance*, RBX::AncestorChanged event)
{
    if (event.newParent == NULL) {
        setScript(boost::shared_ptr<RBX::Script>());
        ::PostMessage(frame->m_hWnd, WM_CLOSE, 0, 0);
    }
}

// Original 004638d0.
void CScriptEditor::onMarshaledEvent(const RBX::RunService*, RBX::RunState state)
{
    running = state != RBX::RS_NORMAL;
    GetCtrl().SetReadOnly(running || !embedded);
}

// Original 00465260.
void CScriptEditor::setScript(boost::shared_ptr<RBX::Script> value)
{
    if (script) {
        boost::recursive_mutex::scoped_lock lock(*mutex);
        RBX::Notifier<RBX::Instance, RBX::AncestorChanged>::disconnect(script, this);
        RBX::Notifier<RBX::Instance, RBX::PropertyChanged>::disconnect(script, this);
        RBX::Notifier<RBX::RunService, RBX::RunState>::disconnect(runService, this);
        script.reset();
        runService.reset();
        mutex.reset();
    }
    if (value) {
        mutex = RBX::DataModel::getMutex(value.get());
        script = value;
        boost::recursive_mutex::scoped_lock lock(*mutex);
        runService = RBX::shared_from(RBX::ServiceProvider::create<RBX::RunService>(value.get()));
        RBX::Notifier<RBX::RunService, RBX::RunState>::connect(runService, this);
        RBX::Notifier<RBX::Instance, RBX::PropertyChanged>::connect(script, this);
        RBX::Notifier<RBX::Instance, RBX::AncestorChanged>::connect(script, this);
    }
    if (m_hWnd)
        ::PostMessage(m_hWnd, WM_SCRIPT_RELOAD, 0, 0);
}

// Draft for 00465110 (47 vs 77 bytes): target keeps two separate base-marshal call paths;
// only EmbeddedSourceCode and Name changes are marshaled to the UI thread.
void CScriptEditor::marshal(const RBX::Instance* source, RBX::PropertyChanged event) throw()
{
    if (&event.getDescriptor() == &RBX::Script::prop_EmbeddedSourceCode)
        RBX::MarshaledListener<RBX::Instance, RBX::PropertyChanged>::marshal(source, event);
    else if (&event.getDescriptor() == &RBX::Instance::desc_Name)
        RBX::MarshaledListener<RBX::Instance, RBX::PropertyChanged>::marshal(source, event);
}

// Original 004659f0.
void CScriptEditor::onMarshaledEvent(const RBX::Instance*, RBX::PropertyChanged event)
{
    if (&event.getDescriptor() == &RBX::Script::prop_EmbeddedSourceCode)
        reload();
    else if (&event.getDescriptor() == &RBX::Instance::desc_Name)
        updateTitle();
}

// Original 00463f10.
void CScriptEditor::OnAddBookmark()
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    long position = ctrl.GetCurrentPos();
    int line = ctrl.LineFromPosition(position);
    ctrl.MarkerAdd(line, 0);
}

// Original 00463f40.
void CScriptEditor::OnUpdateAddBookmark(CCmdUI* pCmdUI)
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    long position = ctrl.GetCurrentPos();
    int line = ctrl.LineFromPosition(position);
    int markers = ctrl.MarkerGet(line);
    pCmdUI->Enable((markers & 1) == 0);
}

// Original 00463f80.
void CScriptEditor::OnRemoveBookmark()
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    long position = ctrl.GetCurrentPos();
    int line = ctrl.LineFromPosition(position);
    ctrl.MarkerDelete(line, 0);
}

// Original 00463fb0.
void CScriptEditor::OnUpdateRemoveBookmark(CCmdUI* pCmdUI)
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    long position = ctrl.GetCurrentPos();
    int line = ctrl.LineFromPosition(position);
    int markers = ctrl.MarkerGet(line);
    pCmdUI->Enable(markers & 1);
}

// Original 00463ff0.
void CScriptEditor::OnNextBookmark()
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    long position = ctrl.GetCurrentPos();
    int current = ctrl.LineFromPosition(position);
    int line = ctrl.MarkerNext(current + 1, 1);
    if (line >= 0)
        ctrl.GotoLine(line);
    else
        MessageBeep(MB_ICONHAND);
}

// Original 00464040.
void CScriptEditor::OnPreviousBookmark()
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    long position = ctrl.GetCurrentPos();
    int current = ctrl.LineFromPosition(position);
    int line = ctrl.MarkerPrevious(current - 1, 1);
    if (line >= 0)
        ctrl.GotoLine(line);
    else
        MessageBeep(MB_ICONHAND);
}

// Original 00464090.
void CScriptEditor::OnToggleFoldMargin()
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    if (ctrl.GetMarginWidthN(2))
        ctrl.SetMarginWidthN(2, 0);
    else
        ctrl.SetMarginWidthN(2, 16);
}

// Original 004640d0.
void CScriptEditor::OnUpdateToggleFoldMargin(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck(GetCtrl().GetMarginWidthN(2) != 0);
}

// Original 00464100.
void CScriptEditor::OnToggleSelectionMargin()
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    if (ctrl.GetMarginWidthN(1))
        ctrl.SetMarginWidthN(1, 0);
    else
        ctrl.SetMarginWidthN(1, 16);
}

// Original 00464140.
void CScriptEditor::OnUpdateToggleSelectionMargin(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck(GetCtrl().GetMarginWidthN(1) != 0);
}

// Original 00464170.
void CScriptEditor::OnToggleLineNumbers()
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    if (ctrl.GetMarginWidthN(0))
        ctrl.SetMarginWidthN(0, 0);
    else
        ctrl.SetMarginWidthN(0, 32);
}

// Original 004641b0.
void CScriptEditor::OnUpdateToggleLineNumbers(CCmdUI* pCmdUI)
{
    pCmdUI->SetCheck(GetCtrl().GetMarginWidthN(0) != 0);
}

// Original 004641e0.
void CScriptEditor::OnUpdateInsert(CCmdUI* pCmdUI)
{
    CString text;
    if (GetCtrl().GetOvertype())
        text.LoadString(0xe704);
    pCmdUI->SetText(text);
}

// Original 004643b0.
void CScriptEditor::OnUpdateLine(CCmdUI* pCmdUI)
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    long position = ctrl.GetCurrentPos();
    int line = ctrl.LineFromPosition(position);
    int column = ctrl.GetColumn(position);
    CString text;
    text.Format(0xc7, line, column, position);
    pCmdUI->SetText(text);
}

// Original 00464270.
void CScriptEditor::OnUpdateStyle(CCmdUI* pCmdUI)
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    long position = ctrl.GetCurrentPos();
    int style = ctrl.GetStyleAt(position);
    CString text;
    text.Format(0xc8, style);
    pCmdUI->SetText(text);
}

// Original 00464300.
void CScriptEditor::OnUpdateFold(CCmdUI* pCmdUI)
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    long position = ctrl.GetCurrentPos();
    int line = ctrl.LineFromPosition(position);
    int level = (ctrl.GetFoldLevel(line) & SC_FOLDLEVELNUMBERMASK) - SC_FOLDLEVELBASE;
    CString text;
    text.Format(0xc9, level);
    pCmdUI->SetText(text);
}

// Original 00464540.
void CScriptEditor::updateTitle()
{
    if (GetParentFrame()) {
        if (!script)
            GetParentFrame()->SetWindowText("");
        else
            GetParentFrame()->SetWindowText(script->getName().c_str());
    }
}

// Original 004659a0.
LRESULT CScriptEditor::OnReload(WPARAM, LPARAM)
{
    updateTitle();
    reload();
    return 0;
}

void CScriptEditor::SetAStyle(int style, COLORREF fore, COLORREF back, int size, const char* face)
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    ctrl.StyleSetFore(style, fore);
    ctrl.StyleSetBack(style, back);
    if (size >= 1)
        ctrl.StyleSetSize(style, size);
    if (face)
        ctrl.StyleSetFont(style, face);
}

void CScriptEditor::DefineMarker(int marker, int markerType, COLORREF fore, COLORREF back)
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    ctrl.MarkerDefine(marker, markerType);
    ctrl.MarkerSetFore(marker, fore);
    ctrl.MarkerSetBack(marker, back);
}

// Original 004639a0.
void CScriptEditor::OnInitialUpdate()
{
    CScintillaView::OnInitialUpdate();
    CFrameWnd* parentFrame = GetParentFrame();
    ENSURE(parentFrame != NULL);
    frame = parentFrame;

    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    ctrl.SetLexer(SCLEX_LUA);
    ctrl.SetKeyWords(0, "and break do else elseif end false for function if in local nil not or repeat return then true until while");

    SetAStyle(STYLE_DEFAULT, RGB(0, 0, 0), RGB(0xff, 0xff, 0xff), 9, "Verdana");
    ctrl.StyleClearAll();
    SetAStyle(SCE_LUA_DEFAULT, RGB(0, 0, 0));
    SetAStyle(SCE_LUA_COMMENT, RGB(0, 0x80, 0));
    SetAStyle(SCE_LUA_COMMENTLINE, RGB(0, 0x80, 0));
    SetAStyle(SCE_LUA_COMMENTDOC, RGB(0, 0x80, 0));
    SetAStyle(SCE_LUA_NUMBER, RGB(0, 0x80, 0x80));
    SetAStyle(SCE_LUA_WORD, RGB(0, 0, 0x80));
    SetAStyle(SCE_LUA_WORD2, RGB(0, 0, 0x80));
    SetAStyle(SCE_LUA_WORD3, RGB(0, 0, 0x80));
    SetAStyle(SCE_LUA_WORD4, RGB(0, 0, 0x80));
    SetAStyle(SCE_LUA_WORD5, RGB(0, 0, 0x80));
    SetAStyle(SCE_LUA_WORD6, RGB(0, 0, 0x80));
    SetAStyle(SCE_LUA_WORD7, RGB(0, 0, 0x80));
    SetAStyle(SCE_LUA_WORD8, RGB(0, 0, 0x80));
    ctrl.StyleSetBold(SCE_LUA_WORD, 1);
    SetAStyle(SCE_LUA_STRING, RGB(0x80, 0, 0x80));
    SetAStyle(SCE_LUA_IDENTIFIER, RGB(0, 0, 0));
    SetAStyle(SCE_LUA_PREPROCESSOR, RGB(0x80, 0, 0));
    SetAStyle(SCE_LUA_OPERATOR, RGB(0x80, 0x80, 0));

    ctrl.SetMarginWidthN(2, 16);
    ctrl.SetMarginSensitiveN(2, TRUE);
    ctrl.SetMarginTypeN(2, SC_MARGIN_SYMBOL);
    ctrl.SetMarginMaskN(2, SC_MASK_FOLDERS);
    ctrl.SetProperty("fold", "1");

    DefineMarker(SC_MARKNUM_FOLDEROPEN, SC_MARK_MINUS, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0xff));
    DefineMarker(SC_MARKNUM_FOLDER, SC_MARK_PLUS, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));
    DefineMarker(SC_MARKNUM_FOLDERSUB, SC_MARK_EMPTY, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));
    DefineMarker(SC_MARKNUM_FOLDERTAIL, SC_MARK_EMPTY, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));
    DefineMarker(SC_MARKNUM_FOLDEREND, SC_MARK_EMPTY, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));
    DefineMarker(SC_MARKNUM_FOLDEROPENMID, SC_MARK_EMPTY, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));
    DefineMarker(SC_MARKNUM_FOLDERMIDTAIL, SC_MARK_EMPTY, RGB(0xff, 0xff, 0xff), RGB(0, 0, 0));

    ctrl.AutoCSetSeparator(10);
    ctrl.SetMouseDwellTime(1000);
    ctrl.SetMarginWidthN(0, 32);
}

// Original 00464460 (the wrapper's demo auto-completion).
void CScriptEditor::OnCharAdded(SCNotification*)
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    long start = ctrl.GetSelectionStart();
    long end = ctrl.GetSelectionEnd();
    if (start == end && start > 12) {
        TextRange range;
        range.chrg.cpMin = start - 13;
        range.chrg.cpMax = end - 1;
        char text[14];
        range.lpstrText = text;
        ctrl.GetTextRange(&range);
        if (_stricmp(text, "scintilla is") == 0)
            ctrl.AutoCShow(0, "very cool\neasy to use\nway cool!!");
    }
}

// Original 00464590 (the wrapper's demo call tip).
void CScriptEditor::OnDwellStart(SCNotification* pSCNotification)
{
    Scintilla::CScintillaCtrl& ctrl = GetCtrl();
    CWnd* focus = GetFocus();
    if (focus && focus->GetSafeHwnd() == ctrl.GetSafeHwnd()) {
        TextRange range;
        range.chrg.cpMin = std::max(0, pSCNotification->position - 7);
        range.chrg.cpMax = std::min(pSCNotification->position + 7, ctrl.GetLength());
        char text[15];
        range.lpstrText = text;
        ctrl.GetTextRange(&range);
        _strupr(text);
        if (strstr(text, "AUTHOR "))
            ctrl.CallTipShow(pSCNotification->position, "PJ Naughter");
    }
}

// Original 00464830.
void CScriptEditor::saveScript()
{
    if (GetCtrl().GetModify() && !loading) {
        if (script) {
            boost::recursive_mutex::scoped_lock lock(*mutex);
            int length = GetCtrl().GetTextLength();
            CString text;
            GetCtrl().GetText(length + 1, text.GetBuffer(length + 1));
            text.ReleaseBuffer();
            std::string code(text);
            script->setEmbeddedCode(code);
        }
        GetCtrl().SetSavePoint();
    }
}

// Original 00465550 (inventory extent 0x1ed is truncated: the catch funclet sits at 0046573d
// and the function returns at 004657eb).
void CScriptEditor::reload()
{
    if (!m_hWnd)
        return;
    loading = true;
    if (script) {
        try {
            boost::recursive_mutex::scoped_lock lock(*mutex);
            embedded = script->getScriptId().toString().size() == 0;
            if (embedded) {
                GetCtrl().SetText(script->getEmbeddedCode().c_str());
            } else {
                std::auto_ptr<std::istream> input = RBX::ServiceProvider::create<RBX::ContentProvider>(script.get())->getContent(script->getScriptId());
                std::ostringstream output;
                boost::iostreams::copy(*input, output, 4096);
                GetCtrl().SetText(output.str().c_str());
            }
            GetCtrl().SetReadOnly(running || !embedded);
        } catch (std::exception& e) {
            CString message;
            message.Format("An error occurred while getting the script\n\n%s", e.what());
            GetCtrl().SetText(message);
            GetCtrl().SetReadOnly(FALSE);
        }
    } else {
        GetCtrl().SetText("");
    }
    GetCtrl().SetSavePoint();
    loading = false;
}
