// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-lib roc_tooltip_native_mbcs_compare_56c2ddd2d5b0e4ac.cpp

// Candidate translation unit (score above; library headers required).
// Native0070c410 imports MSVCR90!_mbscmp; source uses MBCS TCHAR comparison.
#include <mbstring.h>
#undef _tcscmp
#define _tcscmp(a,b) _mbscmp(reinterpret_cast<const unsigned char*>(a),reinterpret_cast<const unsigned char*>(b))
#include "Source/Common/XTPToolTipContext.cpp"
