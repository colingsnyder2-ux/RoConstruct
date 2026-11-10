# Native ABI headers

These headers describe original 2008-06 ABI: inheritance, field order,
calling convention, reflection names, and inline behavior needed to reproduce
machine code.  They are source-of-truth overrides for recovery work.

Rules:

- Put a recovered declaration here at its original include path.
- Prove layouts with both constructor and destructor when possible.
- Keep compatibility shims opt-in (`mfc-noinline-pcxstr`,
  `std-noinline-string`); include them only through a trial's pinned flags.
- Do not edit `tools/`, `Source/`, or imported vendor headers to force a match.
- No padding fields, fake implementation bodies, or address calls.

`../tests/NATIVE_TRIALS.md` explains experiment status.  `../native-classes/`
contains promoted bodies, not declarations guessed from a trial.
