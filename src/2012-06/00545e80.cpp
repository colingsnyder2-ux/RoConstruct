// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
struct sp_counted_base {
    long use_count_; long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
struct Node;
struct NodePtr {
    Node* px; shared_count pn;
    Node* get() const { return px; }
    Node* operator->() const { return px; }
    operator bool() const { return px != 0; }
};
struct Node { void attach(NodePtr other, int value); };
struct S {
    NodePtr get(int key);
    void f(int a, int b, int c);
};
// The callees' bodies are visible in the original translation unit; that is what lets the
// compiler keep both shared_ptr locals' fields in registers across the calls.
struct Table { int count; NodePtr* items; int* keys; };
Table* lookupTable(S* s, int key);
NodePtr S::get(int key)
{
    Table* t = lookupTable(this, key);
    for (int i = 0; i < t->count; ++i) {
        if (t->keys[i] == key) {
            for (int j = i; j < t->count; ++j)
                if (t->keys[j] == key + i)
                    return t->items[j];
            return t->items[i];
        }
    }
    return t->items[0];
}
void noteAttach(Node* n, int value, Node* other);
void Node::attach(NodePtr other, int value)
{
    for (int i = 0; i < value; ++i) {
        noteAttach(this, i, other.px);
        if (i == value / 2)
            noteAttach(other.px, i, this);
    }
    noteAttach(this, value, other.px);
}// Two shared_ptr locals, both real objects with destructors; the second is copied
// by value into the call.
void S::f(int a, int b, int c)
{
    NodePtr first = get(a);
    NodePtr second = get(b);
    if (first && second)
        first->attach(second, c);
}