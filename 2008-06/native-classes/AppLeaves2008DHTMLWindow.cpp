// Inactive native 2008-06 DHTMLWindow (native-headers/AppLeaves2008/DHTMLWindow2008.h): the reflected members of the
// DHTMLWindowService translation unit, their descriptors and DHTMLWindowService::askAddChild. The service itself and
// the Marshaller registry of the same unit stay in AppLeaves2008DHTMLWindowService.cpp.
// >>> native-status (generated) -- do not edit >>>
// AppLeaves2008DHTMLWindow | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src cbb12b82 | roc native-status --write
#include "AppLeaves2008/DHTMLWindow2008.h"
#include <boost/bind.hpp>
#include <stdexcept>
#include <G3D/format.h>
#ifdef NATIVE_DHTMLWINDOW_PENDING
// Proposed native CLuaHtmlView declaration (see the record_native_app_leaves2008_dhtml.py receipt); the recorder
// generates it under out/ for the pending build only.
#include "CLuaHtmlView.h"
#endif

char sDHTMLWindow[] = "HtmlWindow";   // 0092c204

bool DHTMLWindow::showAllowed;        // 0096cc49
Marshaller* htmlMarshaller;           // 0096cc4c (stored by initializeHtmlMarshaller 0041bc40)

// 00416e60: slot 2 of the DHTMLWindowService vtable 0080efd4.
bool DHTMLWindowService::askAddChild(const RBX::Instance* instance) const
{
    return dynamic_cast<const DHTMLWindow*>(instance) != 0;
}

void DHTMLWindow::close()
{
    setParent(NULL);
}

void DHTMLWindow::show()
{
    if (showAllowed)
        htmlMarshaller->post(boost::bind(&DHTMLWindow::doShow, RBX::shared_from(this)));
}

void DHTMLWindow::resize(int x, int y)
{
    htmlMarshaller->post(boost::bind(&DHTMLWindow::doResize, RBX::shared_from(this), x, y));
}

void DHTMLWindow::setCallback(RBX::Lua::FunctionRef function)
{
    htmlMarshaller->post(boost::bind(&DHTMLWindow::doSetCallback, RBX::shared_from(this), function));
}

void DHTMLWindow::navigate(std::string url)
{
    htmlMarshaller->post(boost::bind(&DHTMLWindow::doNavigate, RBX::shared_from(this), url));
}

void DHTMLWindow::setBody(std::string html)
{
    htmlMarshaller->post(boost::bind(&DHTMLWindow::doSetBody, RBX::shared_from(this), html));
}

void DHTMLWindow::bind(boost::shared_ptr<RBX::Instance> object, std::string property, std::string htmlElementId)
{
    if (!object)
        throw std::runtime_error("The object to bind to must not be nil");
    RBX::Reflection::PropertyIterator iter = object->findProperty(RBX::Name::lookup(property));
    if (iter == object->properties_end())
        // The std::string object itself goes through the ellipsis (the original copies its 7 dwords with rep movsd
        // at 0041d187 before calling G3D::format 00509b10).
        throw std::runtime_error(G3D::format("Instance does not have property %s", property));
    const RBX::Reflection::PropertyDescriptor& descriptor = (*iter).getDescriptor();
    htmlMarshaller->post(boost::bind(&DHTMLWindow::doBind, RBX::shared_from(this), object, boost::cref(descriptor),
                                     htmlElementId));
}

namespace RBX
{
	namespace Reflection
	{
		// BoundFuncDesc constructors reflection/reflection.h declares without a body; the descriptors below are
		// their only DHTMLWindow instances (0041be50 Navigate, 0041c220 Resize, 0041c4b0 Bind).
		template<typename Class, typename Function>
		BoundFuncDesc<Class, Function, 1>::BoundFuncDesc(
			typename BoundFuncDesc<Class, Function, 1>::FunctionSig function,
			const char* name,
			const char* arg1Name,
			typename BoundFuncDesc<Class, Function, 1>::Arg1 default1,
			Security security)
			: FuncDesc<Class>(name, security),
			  function(function),
			  default1(default1)
		{
			declareSignature(arg1Name);
		}

		template<typename Class, typename Function>
		BoundFuncDesc<Class, Function, 2>::BoundFuncDesc(
			typename BoundFuncDesc<Class, Function, 2>::FunctionSig function,
			const char* name,
			const char* arg1Name,
			const char* arg2Name,
			Security security)
			: FuncDesc<Class>(name, security),
			  function(function),
			  default1(),
			  default2()
		{
			declareSignature(arg1Name, arg2Name);
		}

		template<typename Class, typename Function>
		BoundFuncDesc<Class, Function, 3>::BoundFuncDesc(
			typename BoundFuncDesc<Class, Function, 3>::FunctionSig function,
			const char* name,
			const char* arg1Name,
			const char* arg2Name,
			const char* arg3Name,
			Security security)
			: FuncDesc<Class>(name, security),
			  function(function),
			  default1(),
			  default2(),
			  default3()
		{
			declareSignature(arg1Name, arg2Name, arg3Name);
		}

		template<typename Class, typename Function>
		void BoundFuncDesc<Class, Function, 3>::declareSignature(const char* arg1Name, const char* arg2Name, const char* arg3Name)
		{
			signature.resultType = &Type::singleton<typename result_type>();
			signature.addArgument(Name::declare(arg1Name, -1), Type::singleton<typename Arg1>(), default1);
			signature.addArgument(Name::declare(arg2Name, -1), Type::singleton<typename Arg2>(), default2);
			signature.addArgument(Name::declare(arg3Name, -1), Type::singleton<typename Arg3>(), default3);
		}

#ifdef NATIVE_DHTMLWINDOW_PENDING
		// 0041c610: the arguments go through a separate call<void> member (0041c560, ret 0x14) that the 3-argument
		// specialization of reflection/reflection.h does not declare yet (pending header proposal).
		template<typename Class, typename Function>
		void BoundFuncDesc<Class, Function, 3>::execute(DescribedBase* instance, Arguments& arguments) const
		{
			Value arg1 = default1;
			arguments.get(1, arg1);
			Value arg2 = default2;
			arguments.get(2, arg2);
			Value arg3 = default3;
			arguments.get(3, arg3);

			Class* o = dynamic_cast<Class*>(instance);
			if (!o)
				throw std::bad_cast();

			call<typename result_type>(o, arguments.returnValue, arg1, arg2, arg3);
		}
#endif
	}
}

#ifdef NATIVE_DHTMLWINDOW_PENDING
void DHTMLWindow::unbind()
{
    htmlMarshaller->post(boost::bind(&DHTMLWindow::doWithView, RBX::shared_from(this), &CLuaHtmlView::unbindAll));
}

// The workers (pending: they need the CLuaHtmlView declaration). doSetCallback 00417b40 is not built at all: it
// assigns the FunctionRef to +0x14 of the object CLuaHtmlView holds at +0xfc, whose type is not derived yet.
void DHTMLWindow::doShow()
{
    boost::recursive_mutex::scoped_lock lock(viewLock);
    if (view)
    {
        view->GetParentFrame()->CenterWindow();
        view->GetParentFrame()->ShowWindow(SW_SHOW);
    }
}

void DHTMLWindow::doResize(int x, int y)
{
    boost::recursive_mutex::scoped_lock lock(viewLock);
    if (view)
        view->GetParentFrame()->SetWindowPos(NULL, 0, 0, x, y, SWP_NOMOVE | SWP_NOZORDER);
}

void DHTMLWindow::doNavigate(std::string url)
{
    boost::recursive_mutex::scoped_lock lock(viewLock);
    if (view)
        view->Navigate(url.c_str());
}

void DHTMLWindow::doSetBody(std::string html)
{
    boost::recursive_mutex::scoped_lock lock(viewLock);
    if (view)
        view->setBody(html.c_str());
}

void DHTMLWindow::doBind(boost::shared_ptr<RBX::Instance> object, const RBX::Reflection::PropertyDescriptor& property,
                         std::string htmlElementId)
{
    boost::recursive_mutex::scoped_lock lock(viewLock);
    if (view)
        view->bindElement(object, property, htmlElementId.c_str());
}

void DHTMLWindow::doWithView(boost::function1<void, CLuaHtmlView*> function)
{
    boost::recursive_mutex::scoped_lock lock(viewLock);
    if (view)
        function(view);
}
#endif

using namespace RBX;

// Dynamic initializers 007eed70..007eef20, in this order (each registers its atexit destructor).
static Reflection::BoundFuncDesc<DHTMLWindow, void(std::string), 1> func_Navigate(&DHTMLWindow::navigate, "Navigate", "url", "about:blank", Reflection::FunctionDescriptor::NeedTrustedCaller);   // 0096cc50
static Reflection::BoundFuncDesc<DHTMLWindow, void(std::string), 1> func_SetBody(&DHTMLWindow::setBody, "SetBody", "html", Reflection::FunctionDescriptor::NeedTrustedCaller);   // 0096cc98
static Reflection::BoundFuncDesc<DHTMLWindow, void(Lua::FunctionRef), 1> func_SetCallback(&DHTMLWindow::setCallback, "SetCallback", "function", Reflection::FunctionDescriptor::NeedTrustedCaller);   // 0096cce0
static Reflection::BoundFuncDesc<DHTMLWindow, void(int, int), 2> func_Resize(&DHTMLWindow::resize, "Resize", "x", "y", Reflection::FunctionDescriptor::NeedTrustedCaller);   // 0096cd28
static Reflection::BoundFuncDesc<DHTMLWindow, void(), 0> func_Show(&DHTMLWindow::show, "Show", Reflection::FunctionDescriptor::NeedTrustedCaller);   // 0096cd78
static Reflection::BoundFuncDesc<DHTMLWindow, void(), 0> func_Close(&DHTMLWindow::close, "Close", Reflection::FunctionDescriptor::NeedTrustedCaller);   // 0096cdb8
static Reflection::BoundFuncDesc<DHTMLWindow, void(boost::shared_ptr<Instance>, std::string, std::string), 3> func_Bind(&DHTMLWindow::bind, "Bind", "object", "property", "htmlElementId", Reflection::FunctionDescriptor::NeedTrustedCaller);   // 0096cdf8
#ifdef NATIVE_DHTMLWINDOW_PENDING
static Reflection::BoundFuncDesc<DHTMLWindow, void(), 0> func_Unbind(&DHTMLWindow::unbind, "Unbind", Reflection::FunctionDescriptor::NeedTrustedCaller);   // 0096ce50
#endif
static Reflection::SignalDesc<DHTMLWindow, void(std::string)> event_DocumentComplete("DocumentComplete", "url");   // 0096ce90
