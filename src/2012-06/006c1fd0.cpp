// from server: 28% by atomic.potato
extern "C" void* __cdecl func_00791490(void*);
extern "C" void* __stdcall func_00745360(void*, void*);

struct VRbxRay_PropertyDescriptor {
    void* method_006c1fd0(void* arg1, void* arg2);
};

void* VRbxRay_PropertyDescriptor::method_006c1fd0(void* arg1, void* arg2) {
    void* fs0 = *(void**)0;
    *(void**)0 = &fs0 + 1;
    
    void* result = 0;
    void* temp = func_00791490(&result);
    
    void* temp2 = func_00745360(arg2, temp);
    *(void**)0 = fs0;
    
    return arg2;
}
