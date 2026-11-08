#pragma once
// >>> native-status (generated) -- do not edit >>>
// LuaArgs | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 912a23a6 | roc native-status --write
#include <atlbase.h>
#include "reflection/type.h"

class LuaArgs {
public:
    RBX::Reflection::ValueCollection values;
    void push(ATL::CComVariant);

    template<class T> __forceinline void add(const T& value) { values.push_back(value); }
    template<class T> __forceinline void addv(T value) { values.push_back(value); }
};
