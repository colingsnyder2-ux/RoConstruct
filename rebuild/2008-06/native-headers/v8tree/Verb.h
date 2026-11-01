#pragma once
#include "v8tree/IDataState.h"
#include "v8tree/VerbContainer.h"
#include "util/Name.h"
#include "util/Debug.h"
#include <string>

namespace RBX {
class Verb : public Debugable {
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
