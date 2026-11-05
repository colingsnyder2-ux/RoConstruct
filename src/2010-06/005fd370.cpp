// from server: 64% by atomic.potato
struct RBX_BaseScript
{
    char pad[0xc4];
    void* field_c4;
    void method_54();
};

extern "C" void __stdcall sub_603e70(void*);

void RBX_BaseScript::method_54()
{
    if (*(int*)((char*)this + 0xc4) != 0)
    {
        void* p = *(void**)((char*)this + 0xc4);
        if (p != 0)
        {
            *(void**)((char*)this + 0xc4) = 0;
            sub_603e70(this);
        }
    }
    if (*(int*)((char*)this + 0xc4) != 0)
    {
        void (RBX_BaseScript::*fn)() = *(void (RBX_BaseScript::**)())((char*)(*(void**)this) + 0x54);
        (this->*fn)();
    }
}
