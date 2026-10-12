"""Library of a unit label: the same rules as the progress site's table (docs/index.html).
First rule wins; labels are approximate, so this estimates where code came from."""
import functools
import re

_MFC = re.compile(r"^(?:[A-Z0-9_$]*V)?C(?:Wnd|FrameWnd|MDIFrameWnd|MDIChildWnd|Edit|Static|ListBox|ComboBox|Button|Brush|Pen|Rgn|Rect|Point|Size|PtrList|PtrArray|ObList|StringList|StringArray|Ole\w*|CmdUI|EnabledCmdUI|Dialog|View|Document|WinApp|WinThread|Object|Archive|File|Exception|DC|ClientDC|PaintDC|WindowDC|GdiObject|Bitmap|Font|Menu|ImageList|ToolBar|StatusBar|ControlBar|SplitterWnd|ScrollView|FormView|EditView|HtmlView|HtmlEditView|DHtmlDialog|PropertySheet|PropertyPage|TreeCtrl|ListCtrl|TabCtrl|SpinButtonCtrl|ProgressCtrl|SliderCtrl|DockState|DockBar|DocTemplate|SingleDocTemplate|MultiDocTemplate|DocManager|MemFile|String|Map\w+|Array|CommandLineInfo|RecentFileList|Mini\w*Wnd)$")
RULES = [
    ("XTP (Codejock)", lambda u: re.search(r"CXTP|XTP[A-Z_]|(^|V)CXT[A-Z]", u)),
    ("G3D", lambda u: "G3D" in u),
    ("Ogre", lambda u: "Ogre" in u),
    ("boost", lambda u: "boost" in u),
    ("RakNet", lambda u: re.search(r"RakPeer|RakNet|PacketReliab", u)),
    ("Scintilla", lambda u: "Scintilla" in u),
    ("Lua", lambda u: re.search(r"(^|[^A-Za-z])lua_|^lua", u)),
    ("STL (std)", lambda u: re.match(r"std(::|$)", u)),
    ("ATL", lambda u: re.match(r"ATL(::|$)", u)),
    ("MFC", lambda u: _MFC.match(re.split(r"::|<|\?\$", u)[0])),
    ("Roblox engine (RBX)", lambda u: re.search(r"RBX|rbx", u)),
    ("Unlabeled (no RTTI nearby)", lambda u: not u or u.startswith("seg_")),
]
OTHER = "Roblox app / other"
NAMES = [name for name, _ in RULES] + [OTHER]


@functools.lru_cache(maxsize=65536)
def library_of(unit):
    unit = unit or ""
    return next((name for name, test in RULES if test(unit)), OTHER)


if __name__ == "__main__":
    assert library_of("CXTPCommandBar") == "XTP (Codejock)"
    assert library_of("RakPeer") == "RakNet"
    assert library_of("CWnd") == "MFC"
    assert library_of("seg_00401000") == "Unlabeled (no RTTI nearby)"
    assert library_of("Foo") == OTHER
    print("ok")
