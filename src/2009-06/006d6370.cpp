// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct T { float compute(); bool test(); };
bool T::test() { return compute() > 0.0200000014f; }
