#pragma once
#include <string>

namespace RBX {
// INFERRED: reconstructed from the authentic util/Evaluator.h declaration in
// work/libcache/rbxgs/50727/v8datamodel__DataModel.cpp.i.
class __declspec(novtable) Evaluator {
public:
    virtual std::string evaluate(const std::string& valueName) const = 0;
};
}
