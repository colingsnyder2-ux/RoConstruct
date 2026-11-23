// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /D_XTP_STATICLINK /D_XTPLIB_NOAUTOLINK /I{headers}/instance-propertychanged /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/boost-function-pod-vtable
// Inactive native 2008-06 CLuaHtmlView::Binder / PropBinding (native-headers/LuaHtmlBinder2008/LuaHtmlBinder2008.h).
// Profile (tests/record_native_luahtml_binder2008.py): document-swap flags with native-headers/mfc-noinline-pcxstr,
// std-noinline-string and boost-function-pod-vtable put first. Instance::event_propertyChanged (00973f48), which the
// PropBinding constructor connects to, comes from the instance-propertychanged include profile (core v8tree/Instance.h
// lacks it; proposal).
#include "LuaHtmlBinder2008/LuaHtmlBinder2008.h"
#include "AppLeaves2008/DHTMLWindowService2008.h"
#include "security/SecurityContext.h"
#include <algorithm>
#include <stdexcept>
#include <boost/bind.hpp>
#include <G3D/format.h>
#include "v8datamodel/DataModel.h"

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
    // 0042c630 (registry placeholder func_0042c630): slot 0042b9a0, SignalDesc connect 0042b680 with group 10,
    // scoped_connection assignment 00595540.
    connection = RBX::Instance::event_propertyChanged.connect(
        instance.get(), boost::bind(&Binder::onPropertyChanged, _1, boost::cref(descriptor), binder), 10);
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

// 0042ae50
void CLuaHtmlView::setBody(const char* html)
{
    CComQIPtr<IHTMLDocument2> document(GetHtmlDocument());
    if (!document)
        throw std::runtime_error("The HtmlDocument is not loaded");
    CComPtr<IHTMLElement> body;
    document->get_body(&body);
    if (!body)
        throw std::runtime_error("The HtmlDocument does not contain a body");
    body->put_innerHTML(CComBSTR(html));
}

// 0042b5f0
void CLuaHtmlView::unbindAll()
{
    RBX::DataModel::Lock lock(dataModel);
    binders.clear();
}

// 0042a930. Batch 36: exact with the nested form of the openrbx Client/win/LuaHtmlView.cpp FUN_0042dd20 body (one
// shared `return false` tail, HRESULT hr locals). Rejected earlier (batch 26): early-return chain (540 B), `!= S_OK`
// return false / return true (547 B), one combined && condition (467 B).
bool CLuaHtmlView::isSameObject(IUnknown* first, IUnknown* second)
{
    CComPtr<IUnknown> firstUnknown;
    CComPtr<IUnknown> secondUnknown;
    CComPtr<IObjectIdentity> identity;
    if (first == second)
        return true;
    if (first != NULL && second != NULL)
    {
        first->QueryInterface(IID_IUnknown, (void**)&firstUnknown);
        second->QueryInterface(IID_IUnknown, (void**)&secondUnknown);
        if (firstUnknown == secondUnknown)
            return true;
        if (firstUnknown != NULL && secondUnknown != NULL)
        {
            HRESULT hr = firstUnknown->QueryInterface(IID_IObjectIdentity, (void**)&identity);
            if (SUCCEEDED(hr) && identity != NULL)
            {
                hr = identity->IsEqualObject(secondUnknown);
                if (hr == S_OK)
                    return true;
            }
        }
    }
    return false;
}

// 0042c8c0. Batch 36: exact (1026 B) with the statement form of the openrbx Client/win/LuaHtmlView.cpp
// FUN_00430c90 body: copy-initialized document, separate iter/end locals and a while loop, raw `.p` interface
// pointers passed to isSameObject 0042a930 and `(*iter).get()`; the list iterator's operator* 0042a8f0 and the
// shared_ptr copy for DataModel::Lock 004116f0 are then called out of line as in the target. Rejected earlier:
// for loop with it->get() (1180 B), (*it).get() (same), break + ternary after the loop (1202 B).
void CLuaHtmlView::bindElement(boost::shared_ptr<RBX::Instance> object,
                               const RBX::Reflection::PropertyDescriptor& property, const char* htmlElementId)
{
    CComQIPtr<IHTMLDocument2> document = GetHtmlDocument();
    if (!document)
        throw std::runtime_error("The HtmlDocument is not loaded");

    CComPtr<IHTMLElementCollection> all;
    document->get_all(&all);

    CComPtr<IDispatch> dispatch;
    all->item(CComVariant(htmlElementId), CComVariant(), &dispatch);
    if (!dispatch)
        throw std::runtime_error(G3D::format("%s not found", htmlElementId));

    CComQIPtr<IHTMLInputElement> input(dispatch);
    if (!input)
        throw std::runtime_error(G3D::format("%s is not an input element", htmlElementId));

    Binder* binder = NULL;
    std::list<boost::shared_ptr<Binder> >::iterator iter = binders.begin();
    std::list<boost::shared_ptr<Binder> >::iterator end = binders.end();
    while (iter != end)
    {
        if (isSameObject((*iter)->element.p, input.p))
        {
            binder = (*iter).get();
            break;
        }
        ++iter;
    }

    if (binder == NULL)
    {
        RBX::DataModel::Lock lock(dataModel);
        binder = new Binder(input);
        binders.push_back(boost::shared_ptr<Binder>(binder));
    }

    binder->bind(object, property);
}
