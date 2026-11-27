// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdlib.h>
struct N;struct It{N* p;};
struct N { N* next; };
struct S { int a[4]; N* head; int size; void erase(It* out, It first, It last); void clear(); };
void S::clear(){ It r; It f={head->next}; It l={head}; erase(&r, f, l); free(head); head = 0; size = 0; }
