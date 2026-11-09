// from server: 100% by colin
// roc 2008-06 00595a80  size: 56 bytes
// Exact: flag-guarded empty __try / __except (EXCEPTION_CONTINUE_EXECUTION) stub.
// Key facts: the filter block 'or eax,-1; ret' is the EXCEPTION_CONTINUE_EXECUTION filter;
// the flag check precedes the try (try-state set only when flag != 0); both bodies empty.
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <excpt.h>
extern unsigned char flag;

void f()
{
    if (flag)
    {
        __try
        {
        }
        __except (EXCEPTION_CONTINUE_EXECUTION)
        {
        }
    }
}
