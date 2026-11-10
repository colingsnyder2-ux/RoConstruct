# Inactive boost thread-exception provider candidate

Use only as an isolated recovery probe. This does not replace any canonical
source, select a native provider, or activate the native-Doc diagnostic.

The translation unit reproduces the genuine vendor `boost::thread`
exception definitions (`thread_exception`, `lock_error`,
`thread_resource_error`) against the stock `boost/thread/exceptions.hpp`.
It exists to supply the missing provider for the CRobloxDoc RunService
lifetime dependency (swap target from the validated RunService EH receipt).

Fresh proof (native_check_runner, vendor `/O2 /Ob2 /Oy /GF /GS- /EHsc /MD`):
- `boost::thread_resource_error::thread_resource_error()` at 00568430
  is byte-exact (26B, score 100) with the vtable data reference matched
  (8 bytes at 0x8104d4). The inlined `thread_exception()` base sets
  `m_sys_err=0` at +0xc and the vtable is stored last, exactly as in the
  original; the body only calls the `std::exception` ctor, so the indirect
  import binding has no direct-call identity to claim.
- `boost::thread_resource_error::what()` at 00568450 is byte-exact (6B)
  with the `"boost::thread_resource_error"` string data matched (29 bytes
  at 0x82ef10) and leaf call-identity passed.
- `boost::lock_error::what()` at 00568420 is byte-exact (6B) with the
  `"boost::lock_error"` string data matched (18 bytes at 0x82eefc) and
  leaf call-identity passed.
- With `#pragma auto_inline(off)` on the destructor definitions
  (`BoostThreadExceptionsNoinline.cpp`), the scalar deleting destructor
  `??_Gthread_resource_error@boost@@UAEPAXI@Z` at 00406be0 is byte-exact
  (30B) and the complete destructor `??1thread_exception@boost@@UAE@XZ`
  at 00568410 is byte-exact (12B) with the vtable data at 0x80b49c matched.
  The original calls the base destructor out-of-line; the inlined form
  (37B) is rejected.

These are separate from linked provider selection and P5/P6/runtime proof.

Open obligations (not proven by this object):
- Re-audit the RunService ctor EH graph (00556b00) with this provider
  attached; it previously advanced through 79 events and stopped at
  00568430. The RunService candidate object is not in this Worker checkout,
  so that advance is the next gate, not claimed here.
