// from server: 24% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void AddRef();
    void Release();
};

struct Container {
    char pad0[0x14];
    int getSomething(int);
    char pad1[0x104 - 0x18];
    int* begin;
    int* end;
};

struct Inner {
    char pad0[0xf8];
    int* begin;
    int* end;
};

struct AttachCameraCommand {
    char pad0[0x14];
    int getSomething(int);
    char pad1[0x20 - 0x18];
    int field20;
    bool execute();
};

int AttachCameraCommand::getSomething(int) {
    return 0;
}

bool AttachCameraCommand::execute() {
    Container* c = (Container*)this->getSomething(1);
    int* b = c->begin;
    if (b == 0 || (c->end - b) >> 3 == 0) {
        return false;
    }
    int v = this->field20;
    int local8 = v;
    int localc = 0;
    int local10 = 0;
    Inner* inner = (Inner*)this->getSomething(1);
    int count;
    if (inner->begin == 0) {
        count = 0;
    } else {
        count = (inner->end - inner->begin) >> 2;
    }
    bool result = (count == 1);
    RefCounted* rc = (RefCounted*)local10;
    if (rc != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)rc + 4), -1) == 1) {
            rc->Release();
        }
        if (_InterlockedExchangeAdd((volatile long*)((char*)rc + 8), -1) == 1) {
            rc->Release();
        }
    }
    return result;
}
