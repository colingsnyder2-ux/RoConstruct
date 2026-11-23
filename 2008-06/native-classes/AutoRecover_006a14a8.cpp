// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x006a14a8 is a one-instruction MFC import thunk (jmp [0x803730], mfc90 ordinal #4040).
// The bytes after it in the listing belong to other functions. No MFC headers are available here, so
// this declares minimal stand-in classes and defines the member. The real body lives in mfc90.dll.
class CFrameWnd;

class CWnd {
public:
    CFrameWnd* GetTopLevelFrame() const;
};

// INFERRED: MFC's CWnd::GetTopLevelFrame returns the first CFrameWnd found while walking up the parent chain.
CFrameWnd* CWnd::GetTopLevelFrame() const
{
    return 0;
}
