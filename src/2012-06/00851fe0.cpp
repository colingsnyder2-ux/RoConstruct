// from server: 68% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBX_CoreScript
{
    void* field_0;
    void* field_4;
    void* field_8;
    void* field_C;
    void* field_10;
    void* field_14;
    void assign(RBX_CoreScript* other);
};

void RBX_CoreScript::assign(RBX_CoreScript* other)
{
    void* p = other->field_0;
    this->field_0 = p;
    if (p != 0)
    {
        _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
    }
    this->field_8 = other->field_8;
    this->field_C = other->field_C;
    this->field_10 = other->field_10;
    this->field_14 = other->field_14;
}
