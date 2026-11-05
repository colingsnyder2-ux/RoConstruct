// from server: 100% by tester
// roc-cl: 50727
// roc-flags: /Od /GS- /MD
struct Holder { void* value; bool present(); };
bool Holder::present() { return value != 0; }
