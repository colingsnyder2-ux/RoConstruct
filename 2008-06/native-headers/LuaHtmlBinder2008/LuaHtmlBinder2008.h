#pragma once
// >>> native-status (generated) -- do not edit >>>
// LuaHtmlBinder2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 16c75a4f | roc native-status --write
// Inactive native 2008-06 recovery: CLuaHtmlView::Binder and CLuaHtmlView::Binder::PropBinding, the two-way binding
// between an HTML <input> element and the string value of one or more Instance properties (CLuaHtmlView unit,
// 0042ac20..0042ced0, together with EventHandler).
//
// Names of the methods are provisional (the binary has no symbol names for them); the classes, their nesting and the
// bases come from RTTI: .?AVBinder@CLuaHtmlView@@ (vtable 00810654: Binder, enable_shared_from_this<Binder> at +4,
// noncopyable at +0xc), sp_counted_impl_p<CLuaHtmlView::Binder::PropBinding> (vtable 00810524) and
// sp_counted_impl_p<CLuaHtmlView::Binder> (vtable 00810538); the bind_t RTTI names in .rdata give the bound
// callables: bind_t<bool, mf0<bool, Binder>, list1<value<Binder*>>> (onchange handler),
// bind_t<void, mf0<void, Binder>, list1<value<shared_ptr<Binder>>>> (the posted update) and
// bind_t<void, void(*)(const PropertyDescriptor*, const PropertyDescriptor&, Binder*),
//        list3<arg<1>, reference_wrapper<const PropertyDescriptor>, value<Binder*>>> (the property-changed slot).
#include "AppLeaves2008/Marshaller2008.h"     // first: MFC/ATL before anything that includes windows.h
#include "AppLeaves2008/EventHandler2008.h"
#include <atlbase.h>
#include <mshtml.h>
#include <list>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/signals/connection.hpp>
#include "v8tree/Instance.h"

// CLuaHtmlView itself is not recovered natively; only the nesting its Binder needs is declared here.
class CLuaHtmlView
{
public:
    class Binder;
};

// sizeof 0x34: the binding view (0042c8c0) news 0x34 before the constructor 0042c0d0 (vptr 00810654). Constructor
// order: weak_ptr +4/+8 = 0 (enable_shared_from_this), list +0xc (ctor 004aefe0, ICF-shared with the
// list<shared_ptr<Replicator::Item>> one), updatePending +0x28 = false, handler +0x2c = 0, element +0x30 (AddRef).
// Destructor 0042c3c0: handler->handler = a function returning true (00565950), detachEvent, then the members in
// reverse order (element/handler Release, ~list 004b0a80, weak_ptr release).
class CLuaHtmlView::Binder : public boost::enable_shared_from_this<CLuaHtmlView::Binder>, boost::noncopyable
{
public:
    // sizeof 0x20: Binder::bind (0042c760) news 0x20 before the constructor 0042c630; destructor 0042a720 (inline,
    // emitted out of line and ICF-shared), deleted by sp_counted_impl_p<PropBinding>::dispose 0042b310.
    class PropBinding
    {
    public:
        // 0042c630 (ret 0x10): instance +0/+4 (shared_ptr copy), descriptor +8, connection +0xc = connect to
        // Instance::event_propertyChanged (00973f48) with group 10.
        PropBinding(boost::shared_ptr<RBX::Instance> instance, const RBX::Reflection::PropertyDescriptor& descriptor,
                    Binder* binder);
        // 0042bd70: the property value as a string under a GameScript (2) impersonation (descriptor slot +0x1c).
        std::string getValue() const;
        // 0042bcd0: sets the property from a string under a GameScript (2) impersonation (descriptor slot +0x20).
        void setValue(const std::string* value);

    protected:
        boost::shared_ptr<RBX::Instance> instance;                 // +0x00 (px), +0x04 (pn)
        const RBX::Reflection::PropertyDescriptor* descriptor;     // +0x08
        boost::signals::scoped_connection connection;              // +0x0c (0x14; dtor 005954b0)
    };

    explicit Binder(IHTMLInputElement* element);   // 0042c0d0 (attachEvent "onchange", throws "attachEvent failed")
    virtual ~Binder();                             // 0042c3c0; ??_G 0042c4e0 is the only vtable slot

    // 0042c760: adds a PropBinding for (instance, descriptor), then updateElement().
    void bind(boost::shared_ptr<RBX::Instance> instance, const RBX::Reflection::PropertyDescriptor& descriptor);

private:
    // 0042c000: the onchange handler: the element's value (IHTMLInputElement::get_value, slot +0x28) to every
    // binding. Returns true.
    bool onChange();
    // 0042c500: once (updatePending), posts updateElement on htmlMarshaller (0096cc4c, Marshaller::post 0041a530).
    void requestUpdate();
    // 0042be20: clears updatePending; the common value of all bindings (empty when they differ) to the element
    // (IHTMLInputElement::put_value, slot +0x24).
    void updateElement();
    // 0042c570: the property-changed slot.
    static void onPropertyChanged(const RBX::Reflection::PropertyDescriptor* changed,
                                  const RBX::Reflection::PropertyDescriptor& descriptor, Binder* binder);

protected:
    std::list<boost::shared_ptr<PropBinding> > bindings;   // +0x0c (0x1c: aux proxy +0xc, head +0x20, size +0x24)
    bool updatePending;                                    // +0x28
    ATL::CComPtr<EventHandler> handler;                    // +0x2c
    ATL::CComPtr<IHTMLInputElement> element;               // +0x30
};
