# Hourly self-audit (run by your own agent, no extra provider)

Run once an hour while you work. Takes about two minutes. Do not stop other work for it.

1. `python work/native-client/audit_digest.py --write` and read the printed digest.
2. Decide, from the digest only (do not re-read the whole transcript):
   - **Rate.** One line: exact bytes gained this hour, bytes/hour, and the best and worst lane. If the rate fell, say why in one sentence.
   - **Automate.** For each repeated command shape (3+ runs): can one `.py` replace it? If yes and it saves more than 10 minutes a day, write it under `work/native-client/`, add `--help`, and add it to the "Fast native tools" list in `docs/NATIVE_AGENT.md`. Otherwise record "not worth it" with the reason.
   - **Speed up.** Anything in "time per tool" above 30% of the hour: can it run in the background, be cached or be batched? Fix the cheapest one.
   - **Waste.** Unchanged re-runs, voided censuses, commits under 45 minutes apart: change one habit or add a guard.
   - **Infer.** For blocked functions whose diff shows a missing member, padding, alignment or plausible inline asm (for example `rdtsc`), try the inference. Rules: the original source must plausibly have had it; comment it `// INFERRED: <evidence>`; never add it only to force a match. Report inferred names separately from proven ones.
   - **Health.** Fix any `MISS` line from `bootstrap_tools.py` first.
3. Save a short note (5 lines at most) in `work/native-client/audit/YYYYMMDD-HH.md`, next to the digest: rate, what you automated or changed, what you rejected.
4. Never edit shared headers or inventory sources while a census runs. Never use the audit to skip leases, commit cadence or the no-`__emit`/no-byte-blob rules.

Privacy: the digest has counts and command shapes only. Do not paste transcript text, source code or personal details into any external service.
