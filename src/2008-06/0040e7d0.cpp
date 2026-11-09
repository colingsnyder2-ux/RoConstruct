// from server: 100% by colin
// roc 2008-06 0040e7d0  unit: CBrowserView  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e7d0
//
// 0040e7d0  8b81f0000000         mov eax, dword ptr [ecx + 0xf0]
// 0040e7d6  8b08                 mov ecx, dword ptr [eax]
// 0040e7d8  8b5130               mov edx, dword ptr [ecx + 0x30]
// 0040e7db  50                   push eax
// 0040e7dc  ffd2                 call edx
// 0040e7de  c3                   ret 

struct IBrowser {
    virtual int __stdcall f0() = 0; virtual int __stdcall f1() = 0; virtual int __stdcall f2() = 0;
    virtual int __stdcall f3() = 0; virtual int __stdcall f4() = 0; virtual int __stdcall f5() = 0;
    virtual int __stdcall f6() = 0; virtual int __stdcall f7() = 0; virtual int __stdcall f8() = 0;
    virtual int __stdcall f9() = 0; virtual int __stdcall f10() = 0; virtual int __stdcall f11() = 0;
    virtual int __stdcall Refresh() = 0;
};

struct CBrowserView {
    char pad[0xf0];
    IBrowser* m_browser;
    int Refresh();
};

int CBrowserView::Refresh()
{
    return m_browser->Refresh();
}
