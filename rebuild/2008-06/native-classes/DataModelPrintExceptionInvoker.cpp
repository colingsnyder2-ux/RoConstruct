// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-function-pod-vtable
// boost::function0<void> invoker for boost::bind(&StandardOut::print_exception 005696f0, function0<void>, MessageType,
// bool), the background job DataModel builds in its asynchronous HTTP helpers 0057bc00 / 0057be10 (both push
// 005696f0 into the bind constructor 00577970 and pass the 0x38-byte bind_t to function0<void>::function0 0057b760,
// which stores the functor on the heap and the stored vtable 008302ec = { manager 0057a9b0, invoker 00577650 }).
// The owning DataModel bodies 0057bc00 / 0057be10 are not recovered (the batch 30 notes list a core
// v8datamodel/DataModel.h httpGet declaration blocker), so the boost templates they instantiate are explicit here.
// boost-function-pod-vtable: 0057b760 stores the constant stored-vtable address 008302ec without a static-local guard;
// with the stock boost 1.34.1 function_template.hpp the constructor is 177/184 B instead of 154 B.
#include "util/standardout.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>

typedef boost::_bi::bind_t<
	void,
	void (__cdecl*)(const boost::function0<void>&, RBX::MessageType, bool),
	boost::_bi::list3<
		boost::_bi::value<boost::function0<void> >,
		boost::_bi::value<RBX::MessageType>,
		boost::_bi::value<bool> > > PrintExceptionBind;

// 00577650 ?invoke@?$void_function_obj_invoker0@V?$bind_t@XP6AXABV?$function0@XV?$allocator@Vfunction_base@boost@@@std@@@boost@@W4MessageType@RBX@@_N@Z...
// (27 B: obj_ptr = buf; push bool +0x30, MessageType +0x28, &function0 +8; call f +0).
template struct boost::detail::function::void_function_obj_invoker0<PrintExceptionBind, void>;
// 0057a9b0 functor_manager<PrintExceptionBind, std::allocator<function_base> >::manage (registry name).
template struct boost::detail::function::functor_manager<PrintExceptionBind, std::allocator<boost::function_base> >;

// 0057b760 function0<void>::function0<PrintExceptionBind>(PrintExceptionBind, int): new 0x38, _Construct 00577b20,
// stores vtable 008302ec (ret 0x3c = the by-value bind_t plus the enable_if int).
template boost::function0<void>::function0(PrintExceptionBind, int);
// 00577970 boost::bind(&StandardOut::print_exception, function0<void>, MessageType, bool), called with 005696f0.
template PrintExceptionBind boost::bind<void, const boost::function0<void>&, RBX::MessageType, bool, boost::function0<void>, RBX::MessageType, bool>(
	void (__cdecl*)(const boost::function0<void>&, RBX::MessageType, bool), boost::function0<void>, RBX::MessageType, bool);

// The other asynchronous DataModel helper 0057be10 wraps a two-string bind of a std::string(std::string, std::string)
// function in function0<std::string>: the stored functor is 0x3c bytes (function pointer + two std::string values).
typedef boost::_bi::bind_t<
	std::string,
	std::string (__cdecl*)(std::string, std::string),
	boost::_bi::list2<
		boost::_bi::value<std::string>,
		boost::_bi::value<std::string> > > StringPairBind;

// 00577ae0 functor_manager<StringPairBind, std::allocator<function_base> >::manage (registry name) and its heap
// manager 005778c0 (registry func_005778c0, called only from 00577ae0: clone = new 0x3c + copy 00577370, destroy =
// ~list2 00575700 + delete, check_functor_type against typeid(StringPairBind) 00946a70).
template struct boost::detail::function::functor_manager<StringPairBind, std::allocator<boost::function_base> >;
// 00578ad0 (registry func_00578ad0) function0<std::string>::function0<StringPairBind>(StringPairBind, int): called
// from 0057be10 (0057befa); new 0x3c, stores the stored vtable 00830040 (ret 0x40 = the by-value bind_t plus the int).
template boost::function0<std::string>::function0(StringPairBind, int);
