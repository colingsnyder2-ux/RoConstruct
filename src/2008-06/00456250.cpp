// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_recordbarrier_4f84f6b5e43237eb.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
// from server: 85% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

typedef boost::shared_ptr<void> SharedValue;
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Record
{
    char padding[0xa8];
    void* value;
};

struct Records
{
    int GetCount() const;
    Record* GetAt(int index) const;
    void RemoveAt(int index);
};

struct Report
{
    char padding[0xe8];
    Records* records;
};

struct Owner;

struct OwnerTable
{
    char padding[0x194];
    Report* (__thiscall *GetReport)(Owner*);
};

struct Owner
{
    OwnerTable* table;
};

struct S
{
    void remove(int unused, SharedValue value);
};

void S::remove(int unused, SharedValue value)
{
    Owner* owner = reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 0x39c);
    Records* records = owner->table->GetReport(owner)->records;

    for (int i = records->GetCount() - 1; i >= 0; --i)
    {
        void* recordValue = records->GetAt(i)->value;
        _ReadWriteBarrier();
        if (recordValue == value.get())
        {
            records->RemoveAt(i);
            break;
        }
    }
}
