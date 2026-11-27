// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Node { void* a; char* next; };
struct S { char pad[8]; Node* head; char p2[0x34 - 0xc]; unsigned count; unsigned limit; void evict(const void* k); void setMax(unsigned n); };
void S::setMax(unsigned n) { limit = n; while (count > limit) evict(head->next + 8); }
