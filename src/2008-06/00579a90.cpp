// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_a5db8c566c5ff1e7.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#include "v8datamodel/DataModel.h"
#include "reflection/function.h"
namespace RBX {
	static Reflection::BoundFuncDesc<DataModel, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>>(ContentId), 1> getContentFunctionOld(&DataModel::get, "get", "url", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<DataModel, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>>(ContentId), 1> getContentFunction(&DataModel::get, "GetObjects", "url", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<DataModel, void(ContentId), 1> loadFunction(&DataModel::loadContent, "Load", "url", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, void(ContentId), 1> saveFunction(&DataModel::save, "Save", "url", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, std::string(std::string, bool), 2> httpGetFunction(&DataModel::httpGet, "HttpGet", "url", "synchronous", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<DataModel, std::string(std::string, std::string, bool), 3> httpPostFunction(&DataModel::httpPost, "HttpPost", "url", "data", "synchronous", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, void(void), 0> sanitizeFunction(&DataModel::clearContents, "ClearContent", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, void(void), 0> closeFunction(&DataModel::close, "Close", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, void(std::string), 1> func_SetUIMessage(&DataModel::setUiMessage, "SetMessage", "message", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, void(void), 0> func_ClearUIMessage(&DataModel::clearUiMessage, "ClearMessage", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::BoundFuncDesc<DataModel, void(void), 0> func_SetUIMessageBrickCount(&DataModel::setUiMessageBrickCount, "SetMessageBrickCount", Reflection::FunctionDescriptor::NeedTrustedCaller);
	static Reflection::SignalDesc<DataModel, void(void)> event_Closing("Close");
}
