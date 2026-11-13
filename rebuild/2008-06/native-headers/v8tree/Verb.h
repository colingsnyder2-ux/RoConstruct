#pragma once
// >>> native-status (generated) -- do not edit >>>
// Verb | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8db91cec | roc native-status --write
#include "v8tree/IDataState.h"
#include "v8tree/VerbContainer.h"
#include "util/Name.h"
#include "util/Debug.h"
#include <string>

namespace RBX {
// novtable: 005833e0 never stores a vtable; the derived constructor does (View+0x10 sets 00819140 after the call).
class __declspec(novtable) Verb : public Debugable {
    const Name& name;
    VerbContainer* container;
protected:
    Verb(VerbContainer*, const Name&);
    Verb(VerbContainer*, std::string);
public:
    virtual ~Verb();
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    const Name& getName() const;
    virtual void doIt(IDataState*) = 0;
    VerbContainer* getContainer() const;
};
}
