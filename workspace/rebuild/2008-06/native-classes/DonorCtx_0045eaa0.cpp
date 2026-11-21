// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/RbxGraphics/include /I{headers}/../../../tools/rbxgs/Client/Network/include /I{headers}/../../../tools/rbxgs/Client/RbxView/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/zlib /I{headers}/../../../tools/rbxgs/Client/Rendering/RenderLib/include /I{headers}/../../../tools/rbxgs/Client/Rendering/AppDraw/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}/../../../tools/rbxgs/Client/App/lua-5.1.1/src /I{headers}/../../../tools/rbxgs/Client/Rendering/SDL-1.2.6/include /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0045eaa0: translated from its byte-exact mined analog against the 2007 rbxgs donor headers (donor_translate.py); byte-proved standalone
struct Data { int data[2]; };
struct Pad { char padding0[0x54]; };
struct Receiver {
    void notify(Data&);
};

struct CRobloxWnd : Pad, Data {
    int mode;
    char padding1[0x18];
    Receiver* receiver;

    bool first();
    bool second();
    void sub_0045eaa0();
};

void CRobloxWnd::sub_0045eaa0()
{
    bool handled;
    if (mode == 2)
        handled = first();
    else
        handled = second();

    if (!handled && receiver)
        receiver->notify(*this);
}

