#include "util/Name.h"

extern "C" const RBX::Name* donorNameNull() { return &RBX::Name::getNullName(); }
extern "C" const RBX::Name* donorNameDeclare(const char* value, int index) { return &RBX::Name::declare(value, index); }
extern "C" const RBX::Name* donorNameLookup(const char* value) { return &RBX::Name::lookup(value); }
extern "C" unsigned donorNameSize() { return sizeof(RBX::Name); }
extern "C" int donorNameIndex(const RBX::Name* value) { return value->getDictionaryIndex(); }
extern "C" const char* donorNameText(const RBX::Name* value) { return value->c_str(); }
