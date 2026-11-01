// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared-rtm roc_espeon_colorentrynativevector160b2e39d0f8f701.cpp

// Candidate translation unit (score above; library headers required).
#include <afxwin.h>
#include <vector>
struct ColorEntry { unsigned int first; unsigned int second; CString name; };
typedef char verifyColorEntry[(sizeof(ColorEntry)==12)?1:-1];
template class std::vector<ColorEntry>;
