// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string.h>
extern char buf[128];
void f(const char* a) { strncpy(buf, a, 127); buf[127] = 0; }