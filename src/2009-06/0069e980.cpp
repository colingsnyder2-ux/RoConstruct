// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)

class sp_counted_base
{
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
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
private:
    long use_count_;
    long weak_count_;
};

template <class T>
class shared_ptr
{
public:
    ~shared_ptr() { if (pn) pn->release(); }
    T* operator->() const { return px; }
    T* get() const { return px; }
private:
    T* px;
    sp_counted_base* pn;
};

namespace RBX {
class Instance
{
public:
    virtual ~Instance();
};

class Backpack : public Instance
{
};

class Player : public Instance
{
public:
    void onChildAdded(shared_ptr<Instance> child);
    void updateBackpack();
};

void Player::onChildAdded(shared_ptr<Instance> child)
{
    if (dynamic_cast<Backpack*>(child.get()))
        updateBackpack();
}
}
