// from server: 29% by Intel
struct TypeInfo {
    virtual int __stdcall Equals(const TypeInfo* other) = 0;
};

extern "C" void __stdcall RaiseException(unsigned long, unsigned long, unsigned long, unsigned long*);

struct LuaArguments {
    void* vfptr;
    void* field_4;

    int Method(void* arg);
};

void __stdcall sub_40f520(void*);

int LuaArguments::Method(void* arg) {
    void* vfptr = this->vfptr;
    int type_id;

    if (vfptr) {
        type_id = *reinterpret_cast<int*>(vfptr);
    } else {
        type_id = 0xD60AC8;
    }

    if (type_id == 0xDA201C) {
        int obj_type_id;
        if (vfptr) {
            obj_type_id = *reinterpret_cast<int*>(vfptr);
        } else {
            obj_type_id = 0xD60AC8;
        }

        if (reinterpret_cast<TypeInfo*>(obj_type_id)->Equals(reinterpret_cast<TypeInfo*>(0xDA201C))) {
            unsigned long args[2];
            args[0] = 0xB44128;
            args[1] = 0xB44120;
            RaiseException(0xE06D7363, 1, 2, args);
            sub_40f520(0);
        }
    }

    return reinterpret_cast<int>(this->field_4);
}
