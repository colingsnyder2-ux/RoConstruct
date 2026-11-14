// Inactive native 2008-06 recovery: the std::vector<RBX::Reflection::Value> (Reflection::ValueCollection) instances
// of the CLuaFunction unit inside the application range 0042c000..00430000 (tests/record_native_app_unit42c.py,
// receipt app-unit42c-working.json).
//
// LuaArgs::push 0042db20 (native-classes/LuaArgs.cpp, lua-args-trial) appends to a ValueCollection through
// vector::push_back 0042daa0, whose insert(where, value) 0042d980 calls _Insert_n 0042d6a0 (catch funclet 0042d8aa).
// CComObject<CLuaFunction>::Invoke 0042e0c0 (vtable 0080ebd8 slot 7) destroys its LuaArgs with ~vector 0042d630 and
// the std::auto_ptr<ValueCollection> that ScriptContext 005af830 returns; its unwind funclets call
// auto_ptr::~auto_ptr 0042d960. The remaining rows (_Construct 0042cfc0, Value::operator= 0042d0a0, the backward
// copies 0042d190 / 0042d500, _Fill 0042d370, allocator::destroy 0042d3d0, _Uninit_fill_n 0042d470 with its catch
// funclet 0042d4bb, _Ufill 0042d550, _Destroy 0042d590, _Tidy 0042d5c0 and _Umove 0042d600) are what these members
// emit. Value comes from native-headers/reflection/type.h, included read-only; this unit only instantiates the
// members explicitly (no helper function).
// Profile: as native-classes/LuaArgs.cpp (document-swap flags with native-headers/mfc-noinline-pcxstr and
// std-noinline-string first).
#include <memory>
#include <vector>
#include "reflection/type.h"

namespace {
typedef RBX::Reflection::Value Value;
typedef RBX::Reflection::ValueCollection ValueCollection;
}

template void ValueCollection::_Insert_n(ValueCollection::const_iterator, ValueCollection::size_type, const Value&);
template ValueCollection::iterator ValueCollection::insert(ValueCollection::const_iterator, const Value&);
template void ValueCollection::_Tidy();
template ValueCollection::~vector();
template std::auto_ptr<ValueCollection>::~auto_ptr();
