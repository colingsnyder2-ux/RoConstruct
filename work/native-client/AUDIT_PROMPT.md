# Hourly self-audit (run by your own agent, no extra provider)

Run once an hour while you work. Takes about two minutes. Do not stop other work for it.

0. **Stop condition first.** Run `python work/native-client/audit_digest.py --write`. If the first line says `STATE: IDLE`
   (no tool call for 45 minutes: the task ended, you are waiting on the user, or the user stopped working), do NOT audit.
   Cancel the hourly schedule that started you (Claude Code: delete the `/loop` or cron task; Codex: delete the recurring
   automation), write one line to `work/native-client/audit/YYYYMMDD-HH.md` ("idle, audit stopped"), and end. Restart it
   only when the next work session begins. Never keep an audit running against an idle session.
1. Read the digest (bytes/hour, time per tool, repeated command shapes, critique evidence, waste, tool health).
2. Decide, from the digest only (do not re-read the whole transcript):
   - **Rate.** One line: exact bytes gained this hour, bytes/hour, best and worst lane. If the rate fell, say why in a sentence.
   - **Automate.** Each repeated command shape (3+ runs): can one `.py` replace it? If yes and it saves more than 10 minutes a
     day, write it under `work/native-client/`, add `--help`, list it under "Fast native tools" in `docs/NATIVE_AGENT.md`.
     Otherwise record "not worth it" with the reason.
   - **Speed up.** Anything above 30% of the hour in "time per tool", or any single call over 10 minutes: background it,
     cache it, batch it, or cut its scope. Fix the cheapest one.
   - **Infer.** For blocked functions whose diff shows a missing member, padding, alignment or plausible inline asm
     (for example `rdtsc`), try the inference. The original source must plausibly have had it; comment it
     `// INFERRED: <evidence>`; never add it only to force a match. Report inferred names separately from proven ones.
   - **Health.** Fix any `MISS` line from `bootstrap_tools.py` first.
3. **Critique yourself.** Using the "critique evidence" line, name at most three concrete habits that cost time or tokens this
   hour, each with its evidence and one change:
   - polling or sleeping instead of one background task plus a single wait;
   - re-reading the same file, re-running an unchanged proof, or re-deriving something already in the handoff notes;
   - hand-written throwaway scripts that a tool already covers (or should);
   - work off the assigned scope (for example a library or RbxApp scope that was not requested), or many small commits;
   - fixing the same class of failure by hand more than twice instead of adding a deterministic fixer;
   - verifying by eye what a script can check.
   Then reduce tooling: list any tool in `work/native-client/` or `roc/` that this session never used and that overlaps
   another; propose merging or deleting it in the note (do not delete files you did not create). Prefer one tool with flags
   over several near-duplicates. Say what you will do differently next hour in one sentence, and then do it.
4. Save a note (8 lines at most) next to the digest: rate, what you automated or changed, the critique, what you rejected.
5. Never edit shared headers or inventory sources while a census runs. Never use the audit to skip leases, commit cadence or the
   no-`__emit`/no-byte-blob rules.

Privacy: the digest has counts and command shapes only. Do not paste transcript text, source code or personal details into any
external service.
