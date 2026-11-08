#include "v8tree/Verb.h"

RBX::Verb::~Verb()
{
    if (container) container->verbs.erase(&name);
}
