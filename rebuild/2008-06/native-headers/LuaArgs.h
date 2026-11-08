#pragma once
#include <atlbase.h>
#include "reflection/type.h"

class LuaArgs {
public:
    RBX::Reflection::ValueCollection values;
    void push(ATL::CComVariant);

    template<class T> __forceinline void add(const T& value) { values.push_back(value); }
    template<class T> __forceinline void addv(T value) { values.push_back(value); }
};
