// Inactive 2008-06 native template rows of the ViewRbxGfx unit (ViewNew/ViewRbxGfx.cpp, original 004d6f50..004d8000+)
// inside the application range 004d4000..004d8000, recorded by tests/record_native_app_unit4d4.py.
// Built against the read-only native RenderLib/ViewNew2008.h / ViewBase2008.h (render-scene owner) and
// v8tree/Instance.h (core owner) with the ViewRbxGfx unit profile of tests/record_native_render_scene.py (document-swap
// flags, VS2008 RTM 21022, /fp:fast). The ViewRbxGfx members themselves are recovered by the render-scene recorder;
// this unit holds only explicit instantiations of the templates the unit emits (row evidence in the recorder).
#include "RenderLib/ViewNew2008.h"
#include "v8tree/Instance.h"
#include <boost/any.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <memory>

// The ViewBase auto_ptr members (+0x4 sceneManager, +0x10 materialFactory): their out-of-line destructors are the
// unwind actions of the ViewRbxGfx ctor (funclets 007c9c96 / 007c9cb7).
template std::auto_ptr<RBX::RenderBase::SceneManager>::~auto_ptr();
template std::auto_ptr<RBX::ViewNew::MaterialFactory>::~auto_ptr();

// The ViewRbxGfx ctor binds invalidateLighting(bool) (Lighting::event_LightingChanged) and
// onWorkspaceDescendentAdded(shared_ptr<Instance>) (the workspace descendant visit and Instance::event_descendentAdded)
// to `this`: the functor types are the RTTI type descriptors 00940b90 / 00940c30 compared by the managers.
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, RBX::ViewNew::ViewRbxGfx, bool>,
	boost::_bi::list2<boost::_bi::value<RBX::ViewNew::ViewRbxGfx*>, boost::arg<1> > > InvalidateLightingBind;
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, RBX::ViewNew::ViewRbxGfx, boost::shared_ptr<RBX::Instance> >,
	boost::_bi::list2<boost::_bi::value<RBX::ViewNew::ViewRbxGfx*>, boost::arg<1> > > DescendantAddedBind;

template struct boost::detail::function::functor_manager<InvalidateLightingBind, std::allocator<boost::function_base> >;
template struct boost::detail::function::functor_manager<DescendantAddedBind, std::allocator<boost::function_base> >;

// workspace->visitDescendents(boost::bind(&ViewRbxGfx::onWorkspaceDescendentAdded, this, _1)) in the ctor (004d9bba).
template void RBX::Instance::visitDescendents<DescendantAddedBind>(DescendantAddedBind) const;

// boost::any holding a boost::function<void(bool)> (vtable 00826bd4): the signal slot of the Lighting-changed connection.
template class boost::any::holder<boost::function<void(bool)> >;
template boost::any::any(const boost::function<void(bool)>&);
