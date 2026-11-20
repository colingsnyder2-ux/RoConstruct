// from server: 100% by Intel_Inside

// Destructor: members destroyed 0xe8, 0xd4 (same dtor 0x7285a0, 0x14 apart), then
// shared count at 0xd0 (boost w32 sp_counted_base: use_count +4, weak_count +8,
// vt[1] dispose, vt[2] destroy, decrement == 0), then base dtor 0x4d2ee0.

extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)
// roc-flags: /O2 /GS- /EHsc /MD

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;

    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
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

template<class T> class shared_ptr {
public:
    T* px;
    sp_counted_base* pi_;
    ~shared_ptr() { if (pi_ != 0) pi_->release(); }
};

class Member {
    int data[5];
public:
    ~Member();
};

class ChunkBase {
public:
    virtual ~ChunkBase();
    int pad[50];
};

class Thing;

class Chunk : public ChunkBase {
public:
    shared_ptr<Thing> sp;
    Member m1;
    Member m2;
    virtual ~Chunk();
};

Chunk::~Chunk()
{
}
