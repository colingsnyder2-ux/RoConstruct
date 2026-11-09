// from server: 72% by atomic.potato
struct EnumDesc {
    int field_24;
    void** field_88;
};

struct UnknownType {
    virtual void method(int);
};

extern "C" void* __cdecl operator_new(unsigned int);

bool __stdcall EnumDesc_method(EnumDesc* this_, unsigned int arg1, UnknownType** arg2, UnknownType** arg3) {
    UnknownType* value;
    bool result;
    
    if (arg1 < this_->field_24) {
        value = *(UnknownType**)((char*)this_->field_88 + arg1 * 4);
        result = true;
    } else {
        value = *arg3;
        result = false;
    }
    
    UnknownType* newObj = (UnknownType*)operator_new(8);
    if (newObj) {
        *(int*)newObj = 0xa89320;
        *(UnknownType**)((char*)newObj + 4) = value;
    } else {
        newObj = 0;
    }
    
    UnknownType* temp = *arg2;
    *arg2 = newObj;
    
    if (temp) {
        temp->method(1);
    }
    
    return result;
}
