#pragma once
// >>> native-status (generated) -- do not edit >>>
// DHTMLWindowService2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src df4bc9b9 | roc native-status --write
// Inactive native 2008-06 recovery: DHTMLWindowService (global namespace) and the per-thread Marshaller registry of
// its translation unit (0041b6f0..0041cf60, dynamic initializers 007eef40..007eef90, atexit 007fa610..007fa7a0).
#include "AppLeaves2008/Marshaller2008.h"   // first: MFC/ATL before anything that includes windows.h
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include <map>
#include <boost/thread/recursive_mutex.hpp>

// Class name "HtmlService": a non-const char array in .data at 0092c1f8 (RTTI mangles the template argument
// $1?sDHTMLWindowService@@3PADA; Name::declare 00416f90 and classDescriptor 0041bb70 push it).
extern char sDHTMLWindowService[];

// RTTI of vtable 0080efd4: DHTMLWindowService : DescribedCreatable<DHTMLWindowService, Instance,
// sDHTMLWindowService> (Described / FactoryProduct / Instance, 22 bases) and the empty Service at mdisp 0x130.
// sizeof 0x130 == sizeof(Instance): Creatable<Instance>::create<DHTMLWindowService> 0041cda0 mallocs 0x130 and
// calls the constructor 0041c9c0; no members of its own.
// Constructor 0041c9c0: DescribedCreatable<..>() 0041bc50 (FactoryProduct() 0041b970 -> Instance() 0055b7e0, then
// classDescriptor 0041bb70 into the Described member), the ten DHTMLWindowService vptrs, then setName with the
// literal "WindowService" (0080f014) called directly (0055af90).
// Destructor: implicit; ??_G 0041caa0 calls ~FactoryProduct 0041b910 (FactoryProduct vptrs, tail jump to ~Instance)
// then free (Creatable's operator delete); the eight ??_E adjustor thunks 0041b9d0..0041ca90 jump to it.
// Vtable: slot 2 askAddChild 00416e60 (dynamic_cast<const DHTMLWindow*> != 0; defined in the DHTMLWindow unit
// around 00416e60, not here); every other slot is Instance's.
class DHTMLWindowService : public RBX::DescribedCreatable<DHTMLWindowService, RBX::Instance, sDHTMLWindowService>,
                           public RBX::Service
{
public:
    DHTMLWindowService();   // 0041c9c0

protected:
    virtual bool askAddChild(const RBX::Instance* instance) const;   // 00416e60 (DHTMLWindow unit)
};

// The Marshaller registry (names provisional; the binary has no symbol names for them):
//   marshallers      std::map<DWORD, Marshaller*> at 0096cec4 (dynamic initializer 007eef40 builds the empty tree,
//                    atexit 007fa640 destroys it; find 00451600 and operator[] 005644a0 are ICF-shared with
//                    same-shaped pointer-keyed maps);
//   marshallersLock  boost::recursive_mutex at 0096cee4 (initializer 007eef70 = recursive_mutex() 00563070,
//                    atexit 007fa610 = ~recursive_mutex, ICF-shared 00594cb0; do_lock 00563090 / do_unlock 005630e0).
// 0041b6f0: under the lock, the Marshaller of GetCurrentThreadId() with its useCount (+0x24) incremented, creating
// it (new(0x54), Marshaller(threadId) 0041b310) and storing it in the map on first use.
Marshaller* acquireMarshaller();
// 0041bc40: htmlMarshaller = acquireMarshaller(); called once by CRobloxApp::InitInstance (0044db7c).
void initializeHtmlMarshaller();
// 0096cc4c: the UI-thread Marshaller every DHTMLWindow call posts to (Show 0041b2b0, Unbind 0041b660, ...; also read
// by the CLuaHtmlView unit at 0042c54e). Defined with the DHTMLWindow statics (0096cc2c..0096cc4c), not here.
extern Marshaller* htmlMarshaller;
