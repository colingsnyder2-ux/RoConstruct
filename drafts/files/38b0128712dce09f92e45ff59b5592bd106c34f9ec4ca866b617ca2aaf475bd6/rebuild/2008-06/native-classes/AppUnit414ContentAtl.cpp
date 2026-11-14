// Inactive native 2008-06 recovery: the ATL template instances of the CContent COM unit inside the application range
// 00414000..00418000 (tests/record_native_app_unit414.py, receipt app-unit414-working.json).
//
// Only ATL templates whose arguments name CContent (or its IID_IContent / LIBID_RobloxLib interface map) are
// instantiated here, so no other translation unit can emit them. The class comes from the committed
// native-headers/CContent.h (included read-only): CComObject<CContent> is 0x94 bytes (CreateInstance pushes 0x94 to
// operator new at 00416b05), the stringstream is at +0xc, and the vtables are 0080eabc / 0080ea98
// (CComObject<CContent>), 0080eb4c (CComAggObject<CContent>) and 0080eb38 / 0080eb14 (CComContainedObject<CContent>),
// each named by its RTTI complete-object locator. CContent::Upload 004166a0 is recovered by CContentUpload.cpp.
// Profile: document-swap flags, VS2008 RTM 21022 (as tests/record_native_content_factory.py).
#include <afxwin.h>
#include "CContent.h"

// Vtables and members: QueryInterface 00416900 (+ adjustor 00416920), Release 004168d0 (+ adjustor 00416930), the
// AddRef adjustor 00416940, the scalar deleting destructor 00416950, and the IDispatchImpl<IContent> members
// GetTypeInfo 004169d0, GetIDsOfNames 00416a30, Invoke 00416a60 with ISupportErrorInfoImpl::InterfaceSupportsErrorInfo
// 00416880 (all through vtable 0080ea98 / 0080eabc).
template class ATL::CComObject<CContent>;
// Constructor 00416bb0, QueryInterface 00416c30, destructor 00416ca0, scalar deleting destructor 00416d00.
template class ATL::CComAggObject<CContent>;
// The IDispatch adjustor thunks 004169a0 / 004169b0 / 004169c0 of vtable 0080eb14.
template class ATL::CComContainedObject<CContent>;
// CComCreator<CComObject<CContent>>::CreateInstance 00416ac0 (+ catch funclet 00416b89),
// CComCreator<CComAggObject<CContent>>::CreateInstance 00416d20 (+ catch funclet 00416dbe) and the
// CComCreator2 dispatcher 00416df0 (DECLARE_AGGREGATABLE of CComCoClass<CContent, &CLSID_Content>).
template HRESULT WINAPI ATL::CComCreator<ATL::CComObject<CContent> >::CreateInstance(void*, REFIID, LPVOID*);
template HRESULT WINAPI ATL::CComCreator<ATL::CComAggObject<CContent> >::CreateInstance(void*, REFIID, LPVOID*);
template HRESULT WINAPI ATL::CComCreator2<ATL::CComCreator<ATL::CComObject<CContent> >,
                                          ATL::CComCreator<ATL::CComAggObject<CContent> > >::CreateInstance(void*, REFIID,
                                                                                                          LPVOID*);
