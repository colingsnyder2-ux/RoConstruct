// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
#include <string>

struct Window {
    void navigate(std::string url, int flags);
};
extern Window* theWindow;

void openUrl(const char* url)
{
    theWindow->navigate(url, 0);
}
