// Inactive native 2008-06 recovery: the boost::function0<bool> instances for a plain bool(*)() target inside the
// CLuaHtmlView unit tail of the application range 0042c000..00430000 (tests/record_native_app_unit42c.py, receipt
// app-unit42c-working.json).
//
// CLuaHtmlView::Binder::~Binder 0042c3c0 (native-classes/LuaHtmlBinder2008.cpp) stores a plain function pointer
// into the EventHandler's boost::function0<bool> (handler->handler = &ignoreChange). It calls
// function0<bool>::operator=(bool(*)()) 0042c320 (catch funclet 0042c391), whose stored vtable 00810658 holds
// functor_manager<bool(*)()>::manage 0042c2c0 (it compares against the type_info at 0092eb08, '.P6A_NXZ') and
// function_invoker0<bool(*)(), bool>::invoke 0042c2b0. ~Binder is the only caller of 0042c320. This unit only
// instantiates that member explicitly (no helper function); the boost headers are included read-only.
// Profile: as record_native_luahtml_binder2008.py (document-swap flags with native-headers/mfc-noinline-pcxstr,
// std-noinline-string and boost-function-pod-vtable first).
#include <memory>
#include <boost/function.hpp>

namespace {
typedef bool (*PlainBoolCall)();
typedef boost::function0<bool, std::allocator<boost::function_base> > BoolFunction;
}

template BoolFunction& BoolFunction::operator=<PlainBoolCall>(PlainBoolCall);
