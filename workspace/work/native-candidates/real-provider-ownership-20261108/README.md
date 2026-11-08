# Real-provider shell ownership experiment

An isolated build based on the source revision in `comparison.json` compiled
recovered App, Frame, View and Doc units alongside the existing P6 shell. The
link reported 32 duplicate definitions and 134 distinct unresolved symbols.

The inactive `RobloxShellRecoveredTrial.cpp` uses existing native class headers
and removes two obsolete shell-only handlers. It compiled under the native-check
profile. A link-only replay using that object and the saved build objects reported
zero duplicate definitions and 136 unresolved symbols. The two new unresolved
symbols are the recovered command-line-info constructor and destructor; none of
the earlier unresolved symbols disappeared. Full logs, selected object hashes,
compile receipt, copied-input hashes and exact builder source are retained here.

This is an ownership experiment, not a working or safe client. P6-specific
helper classes and glue remain. The trial uses a different shell compile profile
from the first build. Original code/data matching, linked selection, ABI/layout,
exception handling, P5/P6 and runtime gates remain separate and unproven. No
diagnostic executable was run; this adds no integrated class or server credit.
