VS2008 RTM `<ios>` with only `basic_ios::rdbuf() const` marked noinline, so the call goes
through the msvcp90 import `?rdbuf@?$basic_ios@DU?$char_traits@D@std@@@std@@QBEPAV?$basic_streambuf@DU?$char_traits@D@std@@@2@XZ`
(IAT 008023c4) as in CWorkspace::insert 0046b9d0 (`add ecx, eax; call [008023c4]`).
Opt-in boundary profile; no layout changes.
