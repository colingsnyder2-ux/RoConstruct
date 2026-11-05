# Native reconciliation and failure isolation

123 focused tests passed. Local native finding now records module report hashes for external ownership, requires linked/tested external owners, distinguishes unique coverage regressions from ownership movement, and refreshes proofs before claims. A changed/missing external proof parks only dependent proposals. Bodies retained by another affected native TU are not counted as a coverage loss.

Shared-header variants that introduce compilation failures or true coverage losses are bisected into source-change groups (bounded to8 trials/header). Baseline setup failures remain blocking. Surviving groups are combined only after another complete affected-TU compilation and exact code+data scan; an already rejected combination is never blindly re-merged. Unsafe/untested groups remain recorded. Independent linked/runtime/ABI acceptance still mandatory; accepted baseline remains untouched by rejected candidates.

Current ten-family worker29920 and queued layer follow-up use this implementation. No new credits claimed until authoritative receipts. No binaries/vendor trees/credentials exported.
