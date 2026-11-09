// from server: 73% by tester
struct EnumPropDescriptor {
    char pad[0x30];
    void* m_getset;
    void* m_enumDesc;
    bool setValue(void* object, void* value);
};

extern "C" void* __stdcall sub_469C20(void* a, void* b, void* c, void* d, void* e);
extern "C" void* sub_469C00;

bool EnumPropDescriptor::setValue(void* object, void* value)
{
    void* p = m_getset;
    void* v24 = *(void**)((char*)p + 0x24);
    void* v20 = *(void**)((char*)p + 0x20);
    void* result = sub_469C20(&sub_469C00, v20, v24, &sub_469C00, value);
    if (*(void**)result != v24) {
        void* ecx = m_enumDesc;
        void* edx = *(void**)ecx;
        void* fn = *(void**)((char*)edx + 0xc);
        void* tmp = value;
        ((void (__stdcall*)(void*, void*))fn)(tmp, &tmp);
        return true;
    }
    return false;
}
