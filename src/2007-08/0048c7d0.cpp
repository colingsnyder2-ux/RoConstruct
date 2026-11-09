// from server: 24% by colin
extern "C" void* __stdcall malloc(unsigned int size);

struct ICreator {
    void* vtable;
};

struct Creator : public ICreator {
    void construct(int);
};

struct VTimerService {
    void* creator;
    void init(Creator* c);
};

void VTimerService::init(Creator* c) {
    Creator* p = (Creator*)malloc(0x1a8);
    if (p) {
        p->construct(1);
    } else {
        p = 0;
    }
    this->creator = p;
}
