// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

namespace FLog { extern unsigned char ToggleViewMode; }
namespace RBX { void FastLog(unsigned char, const char*, const void*); }
struct View { void toggle(); };
struct ToggleViewMode
{
    char pad[0xc];
    View *view;
    void Toggle(int);
};
extern const char g_name[];
void ToggleViewMode::Toggle(int)
{
    if (FLog::ToggleViewMode)
        RBX::FastLog(FLog::ToggleViewMode, g_name, 0);
    view->toggle();
}
