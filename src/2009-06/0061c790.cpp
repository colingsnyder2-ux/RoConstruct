// from server: 100% by EspClaude
// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_6c8e4c2e59922fcc.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
namespace RBX {
class Instance { public: virtual ~Instance(); };
class Service { public: virtual ~Service(); };
}
struct Record { void reset(); };
struct Records { Record* get(boost::shared_ptr<RBX::Instance>); };
class ChangeHistoryService : public RBX::Instance {
public:
    char padding0[0x8c];
    Records* records;
    char padding1[0x2c];
    bool disabled;
    void onChanged(boost::shared_ptr<RBX::Instance> instance);
};
void ChangeHistoryService::onChanged(boost::shared_ptr<RBX::Instance> instance)
{
    if (disabled)
        return;
    if (instance.get() == this)
        return;
    if (dynamic_cast<RBX::Service*>(instance.get()))
        return;
    if (records)
        records->get(instance)->reset();
}
typedef char recordsOffset[offsetof(ChangeHistoryService, records) == 0x90 ? 1 : -1];
typedef char disabledOffset[offsetof(ChangeHistoryService, disabled) == 0xc0 ? 1 : -1];

