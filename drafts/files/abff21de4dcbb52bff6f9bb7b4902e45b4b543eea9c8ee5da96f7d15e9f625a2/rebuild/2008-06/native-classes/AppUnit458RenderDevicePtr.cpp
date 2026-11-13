// 2008-06 native recovery (inactive): the CRobloxWnd unit's std::auto_ptr<G3D::RenderDevice> destructor 0045b620.
// Verified by tests/record_native_app_unit458.py (receipt work/2008-06/shared-layouts/app-unit458-working.json).
//
// Evidence (2008-06 Roblox.exe):
//   0045b620  ~auto_ptr: `if (p) { p->~RenderDevice() (0047bec0, non-virtual, called directly); operator delete(p) }`.
//             Its only callers are the EH unwind funclets 007c2c9b (unwind map 008da3b8 of the CRobloxWnd constructor
//             0045c730) and 007c3090 (unwind map 008da94c of the CRobloxWnd destructor 0045fbe0), i.e. a member of
//             CRobloxWnd (the native CRobloxView.h owner's class; that header is not edited here).
//   0045bde0  releases the same member: renderDevice->cleanup() (0047c3e0, "Shutting down RenderDevice."), then
//             `if (p) delete p;` before the store of 0, which is std::auto_ptr::reset(0) (compare, delete, store);
//             boost::scoped_ptr::reset would store before deleting.
//   0047bec0  G3D 6.09 RenderDevice::~RenderDevice (destroys members at +0x89c / +0x880 / +0x120, library code; bound
//             as an external by call-site identification).
// A matching source is a codegen analog of a Roblox-instantiated STL template that only this unit references.
#include <memory>
#include <GLG3D/RenderDevice.h>

template std::auto_ptr<G3D::RenderDevice>::~auto_ptr();
