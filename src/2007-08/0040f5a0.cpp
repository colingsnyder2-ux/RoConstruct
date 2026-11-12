// from server: 96% by EspClaude
// from server: 79% by Intel
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_7216fa2c986ba7bf.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _DLL
#define _DLL /* /MD, which the recipe's preprocess step does not pass */
#endif
#include <string>
#include <algorithm>

// 0x24-byte element seen in the target: string at +0 (assigned through the msvcp80 operator= import), dwords at +0x1c and +0x20.
struct roc_copy_backward_elem
{
    std::string text;
    int a;
    int b;
};
template roc_copy_backward_elem* std::_Copy_backward_opt<roc_copy_backward_elem*, roc_copy_backward_elem*, std::forward_iterator_tag>(
    roc_copy_backward_elem*, roc_copy_backward_elem*, roc_copy_backward_elem*,
    std::forward_iterator_tag, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
