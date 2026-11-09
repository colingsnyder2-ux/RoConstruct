# Native integration workflow

Use this workflow for 2008-06 native integration. Work in an existing private
checkout with one writer and one build at a time. Do not build in a checkout
another session is using. Keep RoConstruct and the accepted server baseline
up to date before starting; preserve local edits and pending proposals.

## Batch-first integration

1. Review module reports and prioritize common causes that unlock many existing
   byte-exact sources: shared headers and class layouts, compiler flags, shared
   inline/template symbols, dependencies and address placement.
2. Group candidates by the same evidence-backed cause. Use genuine vendor or
   application declarations and source; mined snippets are matching evidence,
   not proof of native source identity. Never invent fields, padding or layouts.
3. Make the smallest shared fix. Compile the affected real units, compare target
   bytes and referenced data, and check existing matches for losses. Split a
   failing batch to isolate the cause; do not repeat an unchanged failed sweep.
4. Build and force-link the affected module. Run its applicable link, ABI,
   ownership and runtime checks. Shared or ambiguous symbols require separate
   ownership and placement evidence; matching bytes alone do not prove identity.
5. Submit each completed passing fix or inseparable batch immediately through
   the supported server workflow as the configured contributor. Record the job
   ID, continue discovery and check pending jobs between batches. Reconcile and
   recheck proposals whenever the accepted baseline changes.
6. Run placement after relevant modules finish linking. Report local matches,
   queued jobs and server-accepted native integrations separately. Only accepted
   server receipts count as verified native credit.

If the server cannot accept a required module, source layer or supporting fix,
retain the proof and report the limitation; do not claim submission or credit.
Use the existing server mining webhook format for accepted gains when supported,
under the configured contributor. Never announce unaccepted candidates as gains.

For commands and detailed evidence rules, see [NATIVE_AGENT.md](NATIVE_AGENT.md)
and the current RoConstruct integration documentation. Check installed CLI help
before using a command; do not assume unsupported server actions exist.
