#include "util/Name.h"

extern "C" const RBX::Name* nativeNameNull() { return &RBX::Name::getNullName(); }
extern "C" const RBX::Name* nativeNameDeclare(const char* value, int index) { return &RBX::Name::declare(value, index); }
extern "C" const RBX::Name* nativeNameLookup(const char* value) { return &RBX::Name::lookup(value); }
extern "C" unsigned nativeNameSize() { return sizeof(RBX::Name); }
extern "C" int nativeNameIndex(const RBX::Name* value) { return value->getDictionaryIndex(); }
extern "C" const char* nativeNameText(const RBX::Name* value) { return value->c_str(); }
