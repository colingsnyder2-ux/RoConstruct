// Inactive native 2008-06 recovery: the CLuaHtmlView::Binder template instances of the CLuaHtmlView unit inside the
// application range 00428000..0042c000 (tests/record_native_app_unit428.py, receipt app-unit428-working.json).
//
// Only boost / std templates whose arguments name CLuaHtmlView::Binder or CLuaHtmlView::Binder::PropBinding are
// instantiated here, so no other translation unit of the binary can emit them. The types come from the RTTI of
// .rdata (sp_counted_impl_p<Binder> 00810538, sp_counted_impl_p<PropBinding> 00810524 and the bind_t type names the
// function managers return) and from the Binder declarations in native-headers/LuaHtmlBinder2008/LuaHtmlBinder2008.h,
// which this unit includes read-only. The Binder methods that use these templates are recovered by
// native-classes/LuaHtmlBinder2008.cpp; this unit only instantiates them explicitly (no helper function).
// Profile: as record_native_luahtml_binder2008.py (document-swap flags with native-headers/mfc-noinline-pcxstr,
// std-noinline-string and boost-function-pod-vtable first).
#include "LuaHtmlBinder2008/LuaHtmlBinder2008.h"
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/signals/slot.hpp>

namespace {
typedef CLuaHtmlView::Binder Binder;
typedef CLuaHtmlView::Binder::PropBinding PropBinding;
typedef RBX::Reflection::PropertyDescriptor PropertyDescriptor;

// Binder::Binder 0042c0d0: boost::bind(&Binder::onChange, this) into the EventHandler's function0<bool>.
typedef boost::_bi::bind_t<bool, boost::_mfi::mf0<bool, Binder>, boost::_bi::list1<boost::_bi::value<Binder*> > >
    OnChangeCall;
// Binder::requestUpdate 0042c500: boost::bind(&Binder::updateElement, shared_from_this()) posted as function0<void>.
typedef boost::_bi::bind_t<void, boost::_mfi::mf0<void, Binder>,
                           boost::_bi::list1<boost::_bi::value<boost::shared_ptr<Binder> > > > UpdateCall;
// PropBinding::PropBinding 0042c630: boost::bind(&Binder::onPropertyChanged, _1, boost::cref(descriptor), binder).
typedef boost::_bi::bind_t<void, void (*)(const PropertyDescriptor*, const PropertyDescriptor&, Binder*),
                           boost::_bi::list3<boost::arg<1>, boost::reference_wrapper<const PropertyDescriptor>,
                                             boost::_bi::value<Binder*> > > PropertyChangedCall;
// Binder::onChange 0042c000: std::for_each(bindings, boost::bind(&PropBinding::setValue, _1, &text)).
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, PropBinding, const std::string*>,
                           boost::_bi::list2<boost::arg<1>, boost::_bi::value<std::string*> > > SetValueCall;
typedef std::list<boost::shared_ptr<PropBinding> > Bindings;
}

// 0042b6d0 (with functor_manager<OnChangeCall>::manage 0042aba0 / manager 0042a6c0).
template boost::function0<bool, std::allocator<boost::function_base> >::function0(OnChangeCall, int);
// 0042b950 (with assign_to 0042b8b0, functor_manager<UpdateCall>::manage 0042b870 / manager 0042b550).
template boost::function0<void, std::allocator<boost::function_base> >::function0(UpdateCall, int);
// 0042b9a0 (with function<void(const PropertyDescriptor*)>::function 0042b800, functor_manager::manage 0042abe0 /
// manager 0042a8a0 and void_function_obj_invoker1::invoke 0042b330).
template boost::slot<boost::function<void(const PropertyDescriptor*)> >::slot(const PropertyChangedCall&);
// 0042b7c0.
template SetValueCall std::for_each(Bindings::iterator, Bindings::iterator, SetValueCall);
// 0042b280 + catch funclet 0042b2ee (checked_delete<PropBinding> 0042b0e0) and, through its vtable,
// sp_counted_impl_p<PropBinding>::dispose 0042b310.
template boost::detail::shared_count::shared_count(PropBinding*);
// 0042aaf0 (the enable_shared_from_this hookup) and shared_count(Binder*) 0042a630 + catch funclet 0042a69e.
template boost::shared_ptr<Binder>::shared_ptr(Binder*);
