// from server: 100% by EspClaude
// roc 2007-08 00423f10  unit: CSelectionTreeCtrl  size: 257 bytes
// roc-flags: /O2 /GS /EHsc /MD
// Rewritten from target: this->refresh() (0x4201a0); if shared_ptr at +0xe4 and hwnd (+0x20):
// root = new Node(shared_ptr<Base>(model), this) (operator new 0x50, ctor 0x423e70 with a
// converted shared_ptr temporary destroyed by 0x492360), root->vfunc slot 0xc, root->expand
// (0x423b70), SendMessage(hwnd, TVM_SELECTITEM 0x1102, TVGN_CARET 2, root->hItem (+0x44)).
#include <intrin.h>

typedef struct HWND__* HWND;
extern "C" __declspec(dllimport) long __stdcall SendMessageA(HWND, unsigned int, unsigned int, long);

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    template<class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pn(r.pn) {}
    ~shared_ptr();                  // 0x492360
    T* get() const { return px; }
};

class Instance { public: virtual ~Instance(); };
class Model : public Instance { };
class CSelectionTreeCtrl;

class TreeNode {
public:
    TreeNode(const shared_ptr<Instance>& inst, CSelectionTreeCtrl* tree);   // 0x423e70
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void build();           // vtbl+0xc
    void expand();                  // 0x423b70
    char pad4[0x44 - 4];
    long hItem;                     // +0x44
    char pad48[0x50 - 0x48];
};

class CSelectionTreeCtrl {
public:
    char pad0[0x20];
    HWND m_hWnd;                    // +0x20
    char pad24[0x94 - 0x24];
    TreeNode* root;                 // +0x94
    char pad98[0xe4 - 0x98];
    shared_ptr<Model> model;        // +0xe4
    void clear();                   // 0x4201a0
    void rebuild();
};

void CSelectionTreeCtrl::rebuild()
{
    clear();
    if (model.get() && m_hWnd) {
        root = new TreeNode(model, this);
        root->build();
        root->expand();
        SendMessageA(m_hWnd, 0x1102, 2, root->hItem);
    }
}
