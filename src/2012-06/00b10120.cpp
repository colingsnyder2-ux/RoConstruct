// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
#include <string.h>
const char* gs; int g; void f(){ g = 127 - (int)strlen(gs); }
