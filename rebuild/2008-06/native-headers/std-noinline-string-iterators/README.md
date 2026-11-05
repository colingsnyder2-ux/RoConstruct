Opt-in VS2008 RTM xstring variant: only mutable/const `_Myptr()` and `size()`
are noinline. Reproduces the original 0046f9f0 string-comparison boundaries.
Use only for matching sources that need these boundaries; class layout unchanged.
