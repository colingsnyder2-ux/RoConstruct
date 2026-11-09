// from server: 100% by colin
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long *);

struct ControlBlock {
    virtual ~ControlBlock();
    volatile long references;
    void dispose();
};

struct Reference {
    ControlBlock *pointer;
    ~Reference();
};

__forceinline Reference::~Reference()
{
    if (pointer) {
        if (InterlockedDecrement(&pointer->references) == 0) {
            pointer->dispose();
            if (pointer)
                delete pointer;
        }
        pointer = 0;
    }
}

struct Base {
    char storage[0x134];
    ~Base();
};

struct ControllerService : Base {
    Reference first;
    Reference second;
    Reference third;
    Reference fourth;
    ~ControllerService();
};

ControllerService::~ControllerService()
{
}
