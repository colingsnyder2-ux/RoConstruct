// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_signal_operators_ebdb8b08d3177f95.cpp

// Candidate translation unit (score above; library headers required).
#define _MT 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_inline_3639f053c7370446.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_header_7a4c998b489b0ddf.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"
#include "v8tree/Instance.h"
#include "v8datamodel/Value.h"
#include <boost/signal.hpp>
template boost::last_value<void>::result_type boost::signal0<void, boost::last_value<void>, int, std::less<int>, boost::function<void()> >::operator()();
template boost::last_value<void>::result_type boost::signal1<void, boost::shared_ptr<RBX::Instance>, boost::last_value<void>, int, std::less<int>, boost::function<void(boost::shared_ptr<RBX::Instance>)> >::operator()(boost::shared_ptr<RBX::Instance>);
template boost::last_value<void>::result_type boost::signal1<void, const RBX::Reflection::PropertyDescriptor*, boost::last_value<void>, int, std::less<int>, boost::function<void(const RBX::Reflection::PropertyDescriptor*)> >::operator()(const RBX::Reflection::PropertyDescriptor*);
template boost::last_value<void>::result_type boost::signal1<void, float, boost::last_value<void>, int, std::less<int>, boost::function<void(float)> >::operator()(float);
template boost::last_value<void>::result_type boost::signal2<void, boost::shared_ptr<RBX::Instance>, float, boost::last_value<void>, int, std::less<int>, boost::function<void(boost::shared_ptr<RBX::Instance>, float)> >::operator()(boost::shared_ptr<RBX::Instance>, float);
template boost::last_value<void>::result_type boost::signal1<void, int, boost::last_value<void>, int, std::less<int>, boost::function<void(int)> >::operator()(int);
template boost::last_value<void>::result_type boost::signal1<void, bool, boost::last_value<void>, int, std::less<int>, boost::function<void(bool)> >::operator()(bool);
template boost::last_value<void>::result_type boost::signal1<void, RBX::BrickColor, boost::last_value<void>, int, std::less<int>, boost::function<void(RBX::BrickColor)> >::operator()(RBX::BrickColor);
template boost::last_value<void>::result_type boost::signal1<void, std::string, boost::last_value<void>, int, std::less<int>, boost::function<void(std::string)> >::operator()(std::string);
template boost::last_value<void>::result_type boost::signal1<void, G3D::Vector3, boost::last_value<void>, int, std::less<int>, boost::function<void(G3D::Vector3)> >::operator()(G3D::Vector3);
template boost::last_value<void>::result_type boost::signal1<void, G3D::Color3, boost::last_value<void>, int, std::less<int>, boost::function<void(G3D::Color3)> >::operator()(G3D::Color3);
template boost::last_value<void>::result_type boost::signal1<void, G3D::CoordinateFrame, boost::last_value<void>, int, std::less<int>, boost::function<void(G3D::CoordinateFrame)> >::operator()(G3D::CoordinateFrame);
