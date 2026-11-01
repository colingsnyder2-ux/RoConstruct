// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

template<class T> struct ScopedAssign {
    T& ref; T old;
    ScopedAssign(T& r, T v) : ref(r), old(r) { r = v; }
    ~ScopedAssign() { ref = old; }
};

class Deletable { public: virtual ~Deletable(); };

class CWndBase {
public:
    void mfcCall();
    char pad0[0x20];
    void* m_hWnd;
};

class CRobloxTreeCtrl : public CWndBase {
public:
    char pad1[0x94 - 0x24];
    Deletable* field_94;
    char pad2[0xb8 - 0x98];
    bool field_b8;
    void func_0041d5a0();
};

void CRobloxTreeCtrl::func_0041d5a0()
{
    mfcCall();
    ScopedAssign<bool> guard(field_b8, true);
    SendMessageA(m_hWnd, 0x1101, 0, 0xffff0000);
    if (field_94) {
        delete field_94;
        field_94 = 0;
    }
}
