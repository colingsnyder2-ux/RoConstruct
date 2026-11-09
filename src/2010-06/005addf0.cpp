// from server: 31% by tester
struct type_info {
    bool __thiscall operator==(const type_info&) const;
};

struct bad_cast {
    bad_cast(const char*);
};

struct EnumDescriptor {
    virtual void dummy();
};

struct EnumDesc : EnumDescriptor {
    void construct();
};

extern "C" {
    void* __stdcall __CxxFrameHandler3(void*, void*, void*, void*);
}

void EnumDesc::construct()
{
    EnumDescriptor* p = this;
    if (p != 0) {
        type_info* ti = *(type_info**)p;
        if (ti != 0) {
            ti = (type_info*)(*(void***)ti)[1];
        } else {
            ti = (type_info*)0xb7930c;
        }
        if (!ti->operator==(*(type_info*)0xba0ad4)) {
            goto fail;
        }
        if ((char*)p + 4 != 0) {
            return;
        }
    }
fail:
    {
        bad_cast bc((const char*)0xa00a54);
        *(void**)0xa00a4c = (void*)0xa00a4c;
        throw bc;
    }
}
