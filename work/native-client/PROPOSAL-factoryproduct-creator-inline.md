# Proposal: inline FactoryProduct::Creator bodies in native util/Object.h

Evidence: 128 creator initializers (??__E/??__F ?creator@?$FactoryProduct@...) are byte-exact with
native_creator_gate.py DEFINITIONS (Creator() inserts into getCreators() and sets isConstructed = 666;
~Creator() erases; `creator` defined as a template static member). The donor 2007 Object.h defines these
inline in the header; iOS 2013 Object.h confirms isConstructed/wasConstructed().

No native TU defines Creator()/~Creator()/creator today, so none of the 128 count on the site.

Change: move those three definitions from native_creator_gate.DEFINITIONS into util/Object.h (inline / after
the class). Each class TU that uses FactoryProduct<X> would then emit its own creator initializer pair.

Risk: every factory class TU gains two initializer functions (existing function bytes unchanged); needs a
prove.py --all regression check (~census) before commit. Owner sign-off needed (template bodies, shared header).
