// from server: 30% by colin
struct ICreator {
    virtual ~ICreator();
};

struct Creator : ICreator {
    Creator();
};

extern "C" void __stdcall InitializeCriticalSection(void*);

Creator::Creator() {
    InitializeCriticalSection(this);
}
