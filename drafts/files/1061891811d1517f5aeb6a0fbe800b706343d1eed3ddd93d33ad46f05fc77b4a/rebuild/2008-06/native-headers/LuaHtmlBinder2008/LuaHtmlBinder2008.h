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
#include <afxext.h>                           // CFormView (afxhtml.h needs it first)
#include <afxhtml.h>                          // CHtmlView, the base of CLuaHtmlView
#include <atlbase.h>
#include <atlcom.h>                           // CComObjectRootEx, the reference count of CLuaFunction
#include <mshtml.h>
#include <list>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/signals/connection.hpp>
#include "v8tree/Instance.h"
#include "script/ThreadRef.h"                // RBX::Lua::FunctionRef (CLuaFunction +0x14, 0x24 bytes)
#include "security/SecurityContext.h"       // RBX::Security::Identities (CLuaFunction +0x38)

// ILuaFunction: the dual interface of CLuaFunction. IID {D5AB3A9C-C462-48BA-A430-34B227340E42} (008164a8, compared by
// InterfaceSupportsErrorInfo 00417e20; the first COM map entry 0080ec14 has the same GUID at 0080ec44, offset 4).
// Its vtable is the second one of CComObject<CLuaFunction> (0080ebd8: IUnknown and IDispatchImpl slots 0..6, then
// its own methods 0042e0c0 (slot 7: four VARIANTs by value and a VARIANT* result, calls the FunctionRef) and 0042da40
// (slot 8: returns E_NOTIMPL)). Those two methods have no proven names or parameter types and are not declared here.
struct __declspec(uuid("D5AB3A9C-C462-48BA-A430-34B227340E42")) __declspec(novtable) ILuaFunction : public IDispatch
{
};

// CLuaFunction: the COM object a Lua function is handed to the page through (RTTI CComObject<CLuaFunction> 0087cfe0
// / 0087cdd0, CComContainedObject / CComAggObject / CComCoClass<CLuaFunction, &CLSID_LuaFunction> type descriptors).
// sizeof 0x3c: CComCreator<CComObject<CLuaFunction> >::CreateInstance 004186d0 news 0x3c, calls the constructor
// 004179b0, then stores the vptrs 0080ec00 (+0) and 0080ebd8 (+4). The COM map 0080ec14 is ILuaFunction (+4),
// IDispatch (+4), ISupportErrorInfo (+0). Constructor 004179b0: m_dwRef +8 = 0, shared_ptr +0xc/+0x10 = 0,
// FunctionRef() +0x14 (vptrs 0080ebc8 / 0080ebd0, functionId +0x34 = 0), +0x38 = 0. Destructor 00417120:
// ~FunctionRef 00594470 on +0x14, then the shared_ptr release (+0x10); ~CComObject 00417ea0 stores m_dwRef =
// 0xc0000001 and unlocks the module. AddRef (00417e70, ICF-shared) is a plain `inc [this+8]`: single-threaded model.
// CComCoClass and IDispatchImpl<ILuaFunction, ...> add no data and are not declared (their GUID arguments are not
// derived). Only DHTMLWindow::doSetCallback 00417b40 uses the layout natively (function, +0x14).
class CLuaFunction : public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>, public ISupportErrorInfo,
                     public ILuaFunction
{
public:
    // +0x0c: Invoke 0042e0c0 copies it as a shared_ptr (px +0xc, pn +0x10 with a lock xadd on pn+4) and asks
    // ServiceProvider::create<ScriptContext> 0042dfd0 with its pointer.
    boost::shared_ptr<RBX::Instance> context;   // INFERRED: pointee type (only the shared_ptr shape and the
                                                //   ServiceProvider lookup are visible)
    RBX::Lua::FunctionRef function;             // +0x14 (assigned by DHTMLWindow::doSetCallback 00417b40)
    // +0x38: Invoke 0042e0c0 passes it to Security::Impersonator::Impersonator(Identities) 0042bc10.
    RBX::Security::Identities identity;         // INFERRED: name (type from the Impersonator argument)
};

// CLuaHtmlView: the CHtmlView-based browser view of the HtmlWindow. Only partially declared: the image keeps no
// constructor, vtable or RTTI for it (only its nested Binder has RTTI), so neither its exact base nor its size is
// derivable. Members used by native code: the CLuaFunction pointer at +0xfc (DHTMLWindow::doSetCallback 00417b89:
// `mov ecx, [view + 0xfc]; add ecx, 0x14`, no null test). Members not declared yet: +0x100/+0x104 (read by
// 0042b60b / 0042b618, copied by 0042cb5a as a shared_ptr-like pair), +0x108 / +0x10c (0042c1ee / 0042c43e) and the
// container at +0x110 (+0x124; 0042b63e, 0042caba).
class CLuaHtmlView : public CHtmlView
{
public:
    class Binder;

    // Methods the DHTMLWindow workers call (bodies in the CLuaHtmlView unit, not recovered natively; names
    // provisional, taken from the reflected DHTMLWindow members that post them).
    void setBody(const char* html);             // 0042ae50 (ret 4), called by DHTMLWindow::doSetBody 00417cc9
    // 0042c8c0 (ret 0x10): GetHtmlDocument, the element by id, then a new Binder (0x34) bound to the property.
    void bindElement(boost::shared_ptr<RBX::Instance> object, const RBX::Reflection::PropertyDescriptor& property,
                     const char* htmlElementId);    // called by DHTMLWindow::doBind 00417d98
    void unbindAll();                           // 0042b5f0 (plain ret), bound by DHTMLWindow::unbind 0041b665

    // INFERRED: +0xf4..+0xfb. CHtmlView (mfc90) is 0xf4 bytes (CDeclarationView.h, CSecureHtmlView.h) and the
    // CLuaFunction pointer is at +0xfc, so the class has 8 more bytes there that no surviving code reads or writes.
    DWORD unknownF4;                            // +0xf4 INFERRED
    DWORD unknownF8;                            // +0xf8 INFERRED
    CLuaFunction* callback;                     // +0xfc INFERRED: pointee type (CComObject<CLuaFunction> starts at
                                                //   CLuaFunction; +0x14 is its FunctionRef)
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
