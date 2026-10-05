# Source-first mode

Put authorized C/C++ source here when available:

```text
source/
  client/
    *.c  *.cpp  *.h  *.hpp
```

Source-first mode skips Ghidra entirely. RoConstruct can index, build, test,
package, and distribute this source. It cannot invent missing source from a
binary; binary-only work needs a decompiler/export step somewhere.

Do not add proprietary source or client files unless you have redistribution
permission. Keep private source local and use `ROCONSTRUCT_SOURCE_ROOT`.
