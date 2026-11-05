// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: rbxgs-net roc_espclaude_457f1e6c0cc51a3c.cpp

// Candidate translation unit (score above; library headers required).
#define _MT 1
#ifndef _DLL
#define _DLL
#endif
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#pragma inline_depth(255)
void showHelp();
class CLuaHtmlView {
public:
    int m_0;
    boost::function0<void> m_onLoad;
    void resetHandler();
};
void CLuaHtmlView::resetHandler()
{
    boost::function0<void>& handler = m_onLoad;
    boost::function0<void>(&showHelp).swap(handler);
}
