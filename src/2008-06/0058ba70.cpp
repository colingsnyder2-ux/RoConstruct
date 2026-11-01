// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;

    void release();
    void weakRelease();
};

inline void Control::weakRelease()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        weakRelease();
    }
}

struct ChangeHistoryService;

struct Shared {
    ChangeHistoryService* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Record {
    void update();
};

struct History {
    Record* find(Shared object, int value);
};

struct ChangeHistoryService {
    unsigned char padding0[0x134];
    History* history;
    unsigned char padding1[0x2c];
    bool blocked;

    void notify(Shared object, int value);
};

void ChangeHistoryService::notify(Shared object, int value)
{
    if (!blocked && object.pointer != this && history)
        history->find(object, value)->update();
}
