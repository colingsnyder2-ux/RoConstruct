// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared-rtm roc_espclaude_c57b15cd240943b9.cpp

// Candidate translation unit (score above; library headers required).
#include <afxwin.h>
#include <vector>
struct ColorEntry { unsigned int first; unsigned int second; CString name; };
typedef char verifyColorEntry[(sizeof(ColorEntry)==12)?1:-1];
template class std::vector<ColorEntry>;
std::vector<ColorEntry> g_colorEntries;
