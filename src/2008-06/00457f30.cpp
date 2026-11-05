// from server: 100% by EspClaude
// from server: 93% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_338b4b802b570a5c.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Shared { void* object; boost::detail::shared_count control; };
struct Records;

struct Record {
    char padding[0xa8];
    void* object;
    Records* getRecords();
};

struct Records {
    int getCount() const;
    Record* getAt(int index);
    void removeAt(int index);
};

struct S {
    void f(int unused, Shared value);
};

void S::f(int unused, Shared value)
{
    Record* record = reinterpret_cast<Record*>(
        reinterpret_cast<char*>(this) - 0x78);

    for (int i = record->getRecords()->getCount() - 1; i >= 0; --i) {
        void* object = record->getRecords()->getAt(i)->object;
        if (object == value.object) {
            record->getRecords()->removeAt(i);
            break;
        }
    }
}

