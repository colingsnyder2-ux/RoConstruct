// from server: 29% by colin
struct RefCounted {
    void* vtable;
};

struct FunctionDescriptor {
    char pad[0x30];
    void* field_30;
    RefCounted* field_34;
    void* field_38;
    RefCounted* field_3c;
};

struct Arguments {
    void* vtable;
    void put(int index, void* value);
};

struct BoundFuncDesc : FunctionDescriptor {
    void construct(Arguments* args, int a, int b);
};

extern "C" int __stdcall sub_630D36(int, int, int, int, int);
extern "C" void __stdcall sub_630B9E(void*, void*);
extern "C" void* __stdcall sub_77E710(void*);
extern "C" void __stdcall sub_496190();

void BoundFuncDesc::construct(Arguments* args, int a, int b) {
    void* local14;
    void* local18;
    void* local0c;
    void* local10;

    local14 = this->field_30;
    if (this->field_34) {
        local18 = this->field_34->vtable;
        ((void (__thiscall*)(RefCounted*))((void**)local18)[2])(this->field_34);
    } else {
        local18 = 0;
    }

    args->put(1, &local14);

    local0c = this->field_38;
    if (this->field_3c) {
        local10 = this->field_3c->vtable;
        ((void (__thiscall*)(RefCounted*))((void**)local10)[2])(this->field_3c);
    } else {
        local10 = 0;
    }

    args->put(2, &local0c);

    int result = sub_630D36((int)local18, 0x88209c, 0x88e9fc, 0, 0);
    if (result == 0) {
        void* p = sub_77E710((void*)0x786e04);
        sub_630B9E(p, (void*)0x841e0c);
    }

    void* p1 = &local0c;
    void* p2 = &local14;
    void* p3 = (char*)args + 4;
    ((void (__thiscall*)(BoundFuncDesc*, int, void*, void*, void*))sub_496190)(this, result, p3, p2, p1);

    if (local10) {
        ((void (__thiscall*)(void*, int))((void**)local10)[0])(local10, 1);
    }
    if (local18) {
        ((void (__thiscall*)(void*, int))((void**)local18)[0])(local18, 1);
    }
}
