// from server: 95% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct sp_counted_base
{
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy()
    {
        _InterlockedIncrement(&use_count_);
    }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

struct shared_count
{
    sp_counted_base* pi_;
    shared_count(sp_counted_base* p) : pi_(p)
    {
        if (p != 0)
            p->add_ref_copy();
    }
    shared_count(const shared_count& r) : pi_(r.pi_)
    {
        if (pi_ != 0)
            pi_->add_ref_copy();
    }
    ~shared_count()
    {
        if (pi_ != 0)
            pi_->release();
    }
};

struct Node;

struct NodePtr
{
    Node* px;
    shared_count pn;
    NodePtr(Node* p, sp_counted_base* c) : px(p), pn(c)
    {
    }
};

struct HeldPtr
{
    Node* px;
    sp_counted_base* pi_;
    ~HeldPtr()
    {
    }
};

struct Node
{
    void attach(NodePtr other, int value);
};

struct S
{
    NodePtr get(int key);
    HeldPtr getHeld(int key);
    void f(int a, int b, int c);
};

void S::f(int a, int b, int c)
{
    NodePtr first = get(a);
    sp_counted_base* pi;
    {
        HeldPtr second = getHeld(b);
        Node* p = first.px;
        pi = second.pi_;
        if (p != 0)
        {
            Node* q = second.px;
            if (q != 0)
                p->attach(NodePtr(q, pi), c);
        }
    }
    if (pi != 0)
        pi->release();
}
