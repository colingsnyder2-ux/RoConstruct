// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// RBX::ChangeHistoryService::getCanUndo / getCanRedo (00589d60 / 00589ed0)
// INFERRED: names from BoundFuncDesc N=0 registrations at 007f40b0 ("GetCanUndo",
// 007f40ba) and 007f40e0 ("GetCanRedo", 007f40ea) into BoundFuncDesc<ChangeHistoryService,
// RBX::Reflection::Tuple(void), 0>; result Tuple (RTTI .?AUTuple@Reflection@RBX@@).
// Body mirrors src/2008-06/00589d60.cpp / 00589ed0.cpp (mined analog, statement order)
// with the real RBX types. Value::set(text) reproduces the inlined
// Value::operator=(std::string) body of the original (any::swap + holder destroy).
#include "v8datamodel/ChangeHistoryService.h"
#include "reflection/reflection.h"
#include "reflection/type.h"
#include <string>

RBX::Reflection::Tuple RBX::ChangeHistoryService::getCanUndo()
{
    std::string text;
    if (enabled && queryUnplay(text, 0)) {
        RBX::Reflection::Tuple values(2);
        bool flag = true;
        values.values[0] = flag;
        values.values[1].set(text);
        return values;
    } else {
        RBX::Reflection::Tuple values(1);
        bool flag = false;
        values.values[0] = flag;
        return values;
    }
}

RBX::Reflection::Tuple RBX::ChangeHistoryService::getCanRedo()
{
    std::string text;
    if (enabled && queryPlay(text, 0)) {
        RBX::Reflection::Tuple values(2);
        bool flag = true;
        values.values[0] = flag;
        values.values[1].set(text);
        return values;
    } else {
        RBX::Reflection::Tuple values(1);
        bool flag = false;
        values.values[0] = flag;
        return values;
    }
}

// Reflection registrations of the two bodies above (dynamic initializers 007f40b0 / 007f40e0: security 1, name
// strings 008319a0 "GetCanUndo" / 008319ac "GetCanRedo", BoundFuncDesc<ChangeHistoryService, Tuple(), 0> ctor 0058b0f0,
// objects 00975a88 / 00975b08). They follow the four ChangeHistoryService registrations of
// InitStatics_ChangeHistoryService.cpp (007f3ff0..007f4080) in the original initializer order.
// INFERRED: object names (not in the binary).
namespace RBX {
	static Reflection::BoundFuncDesc<ChangeHistoryService, Reflection::Tuple(), 0> desc_GetCanUndo(&ChangeHistoryService::getCanUndo, "GetCanUndo", Reflection::FunctionDescriptor::AnyCaller);   // 00975a88 (007f40b0)
	static Reflection::BoundFuncDesc<ChangeHistoryService, Reflection::Tuple(), 0> desc_GetCanRedo(&ChangeHistoryService::getCanRedo, "GetCanRedo", Reflection::FunctionDescriptor::AnyCaller);   // 00975b08 (007f40e0)
}
