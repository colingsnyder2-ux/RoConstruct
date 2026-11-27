// from server: 43% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
int f(){ int r[4]; r[0]=0; __cpuid(r,0); return r[0]; }
