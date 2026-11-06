// Inactive native 2008-06 CLuaHtmlView::Binder / PropBinding (native-headers/LuaHtmlBinder2008/LuaHtmlBinder2008.h).
// Profile (tests/record_native_luahtml_binder2008.py): document-swap flags with native-headers/mfc-noinline-pcxstr,
// std-noinline-string and boost-function-pod-vtable put first. The NATIVE_LUAHTMLBINDER2008_PENDING connect in the
// PropBinding constructor needs Instance::event_propertyChanged (proposal in the receipt).
#include "LuaHtmlBinder2008/LuaHtmlBinder2008.h"
#include "AppLeaves2008/DHTMLWindowService2008.h"
#include "security/SecurityContext.h"
#include <algorithm>
#include <stdexcept>
#include <boost/bind.hpp>

namespace {
// 00565950 (ICF-shared): what the event handler calls once the binder is gone.
bool ignoreChange()
{
    return true;
}
}

CLuaHtmlView::Binder::PropBinding::PropBinding(boost::shared_ptr<RBX::Instance> instance,
                                               const RBX::Reflection::PropertyDescriptor& descriptor, Binder* binder)
    : instance(instance), descriptor(&descriptor)
{
#ifdef NATIVE_LUAHTMLBINDER2008_PENDING
    connection = RBX::Instance::event_propertyChanged.connect(
        instance.get(), boost::bind(&Binder::onPropertyChanged, _1, boost::cref(descriptor), binder), 10);
#endif
}

std::string CLuaHtmlView::Binder::PropBinding::getValue() const
{
    RBX::Security::Impersonator impersonate(RBX::Security::GameScript);
    return descriptor->getStringValue(instance.get());
}

void CLuaHtmlView::Binder::PropBinding::setValue(const std::string* value)
{
    RBX::Security::Impersonator impersonate(RBX::Security::GameScript);
    descriptor->setStringValue(instance.get(), *value);
}

CLuaHtmlView::Binder::Binder(IHTMLInputElement* element) : updatePending(false), element(element)
{
    handler = new EventHandler(boost::bind(&Binder::onChange, this));
    CComQIPtr<IHTMLElement2> element2(element);
    VARIANT_BOOL result;
    HRESULT hr = element2->attachEvent(CComBSTR("onchange"), handler, &result);
    if (hr != S_OK)
        throw std::runtime_error("attachEvent failed");
    if (!result)
        throw std::runtime_error("attachEvent failed");
}

CLuaHtmlView::Binder::~Binder()
{
    handler->handler = &ignoreChange;
    CComQIPtr<IHTMLElement2> element2(element);
    element2->detachEvent(CComBSTR("onchange"), handler);
}

void CLuaHtmlView::Binder::bind(boost::shared_ptr<RBX::Instance> instance,
                                const RBX::Reflection::PropertyDescriptor& descriptor)
{
    bindings.push_back(boost::shared_ptr<PropBinding>(new PropBinding(instance, descriptor, this)));
    updateElement();
}

bool CLuaHtmlView::Binder::onChange()
{
    CComBSTR value;
    element->get_value(&value);
    std::string text((LPCSTR)CStringA(value));
    std::for_each(bindings.begin(), bindings.end(), boost::bind(&PropBinding::setValue, _1, &text));
    return true;
}

void CLuaHtmlView::Binder::requestUpdate()
{
    if (!updatePending)
    {
        htmlMarshaller->post(boost::bind(&Binder::updateElement, shared_from_this()));
        updatePending = true;
    }
}

void CLuaHtmlView::Binder::updateElement()
{
    updatePending = false;
    std::string text;
    std::list<boost::shared_ptr<PropBinding> >::const_iterator it = bindings.begin(), end = bindings.end();
    if (it != end)
    {
        text = (*it)->getValue();
        ++it;
    }
    for (; it != end; ++it)
    {
        if (text != (*it)->getValue())
        {
            text.clear();
            break;
        }
    }
    element->put_value(CComBSTR(text.c_str()));
}

void CLuaHtmlView::Binder::onPropertyChanged(const RBX::Reflection::PropertyDescriptor* changed,
                                             const RBX::Reflection::PropertyDescriptor& descriptor, Binder* binder)
{
    if (changed == &descriptor)
        binder->requestUpdate();
}
