# Link speed: `quicktest.py` / `lld_link.py`

Goal: shorten the donor-free `RobloxQT.exe` link that `quicktest.py` runs (HANDOFF §3 says "about 4-5 min").

The changes below were written and unit-tested on Linux, from the code and its own timing comments. **No time on
this page was measured on the real link.** The link needs Windows, lld-link and about 59 GB of generated objects, and
none of those were available. Every saving below is an estimate, with the reasoning given. Measure with the steps in
section 4 before you trust any of them.

## 1. Phases of one `quicktest.py` run

Each `_tm` checkpoint prints `[qt N s] label`. The labels below are the ones in the code now, and each run also
writes them to `linkexp/qt_timing.json`.

| # | Phase (`_tm` label) | Main work | Evidence of its cost before | Change |
|---|---|---|---|---|
| 1 | results swap + draft scan | build the object list, `--results` swap, receipt cache | small (caches) | none |
| 2 | draft/gap-fill strip | `import defined_now` (**fully reloads `link/obj_ext_cache` whenever its inputs changed**); **full load of `obj_ext_cache` (~2 GB)**; draft definitions (cached) | shardcache docstring: "~2 GB"; GC note "doubled the load time" | **A**, **E** |
| 3 | strip passes (vt_orig / prefer_converted / DLL copies) | prefer_converted **read and regex-scanned every native object on every run**; vt_orig and DLL-copy scans use the cache | none recorded | **B** |
| 4 | alias generator scripts | 5 Python scripts, started here and waited on | none recorded | **E** |
| – | pre-link audits | `audits_all.py` inline only when it has no stamp, or when `QT_AUDITS` is set | 231-290 s when inline (now in the background) | **G** (opt-in) |
| 5 | alias rebuild + base stubs copy | 37 alias files, previous-map parse, base `stubs.obj`: **6 parses of its symbol table** and a **rewrite on every run** | none recorded | **C**, **D** |
| 6 | object patch passes (callfix .. natinit) | callfix, natdata, natinit (**~16k converted objects read and regex-scanned on every run**), hardaddr, collidefix, switchfix, dtorfix | natinit comment: "16 s" before its regex | **B** |
| 7 | relocsplit / dllexstrip / spellunify | other modules (not in this lease) | – | none |
| 8 | luarbx + dtorfix final + chain prep | luarbx (cached), qt_stubs_prev copies, qt.rsp | – | none |
| 9 | first lld link | `_predict_new_und`: **full load of `qt_ext_cache` (~2 GB)**, previous-map parse | comments: the skipped discovery link is ~40 s | **A**, **C** |
| 10 | stub classification | qualname_alias, undname, make_stubs, **4 pefile parses of Roblox.exe**, **3 more map parses** | – | **C** |
| 11 | second/third link + copy | 1-2 `lld_link.py` runs (each: mfc static check, alias index over every object, lld itself), the map rewrite, xcudedup, copy | lld_link comment: "lld itself takes 19 s"; quicktest comments: pass 2/3 ~35-70 s each | **C**, **F**, **H** (opt-in) |

## 2. Changes

### Default-on

These changes do not reuse any patched copy a previous run wrote. They only cache what they read, and each cache is
validated against the file it came from. They leave the outputs identical, and each one has an environment switch
that turns it off, so it can be bisected.

| | Change | File | Off switch | Estimated saving (reasoning) |
|---|---|---|---|---|
| **A** | **Read-through view of the two ~2 GB symbol caches** (`shardcache.ShardView`). `get(k)` returns exactly what `ShardCache.get(k)` returns. A sidecar copy holds only the keys this script looks up. An entry is used only while the main shard file holding it has the same `(mtime_ns, size, file id)`; otherwise only that one shard (1/64) is unpickled. `ShardCache.save` always writes a new temp file and `os.replace`s it, so the file id changes on every save. The view falls back to the old full load when the layout is not trusted: no `.d` directory yet, a foreign file, or a key in the wrong shard. The first run builds the sidecar and checks every shard, which costs the same as before. In `_predict_new_und`, the native objects' entries come from the sidecar whenever the converted-object aggregate (`ren_agg_cache`) hits. Sidecars: `linkexp/qt_obj_ext_side.pkl.d`, `linkexp/qt_ext_side.pkl.d`. | shardcache.py, quicktest.py | `QT_NO_SIDECAR=1` | **10-40 s per cache, from the second run on.** Unpickling about 2 GB of small strings and frozensets in CPython runs at roughly 50-200 MB/s. The saving depends on how much of each cache is stale (old native-check-run paths) or converted-object entries that this run never reads. Peak RAM also drops by up to the size of the skipped shards. |
| **F** | `lld_link.py`: `mfc_static_cache.json` is written only when it changed (the decisions were already cached), and each lld pass prints `[lld_link] lld-link N s` for lld alone. | lld_link.py | – | Negligible. |
| **C** | **Parse-once caches.** The link map is parsed once per file version (`_map_rows`, keyed by path, mtime and size). That covers the 6 pre-link parses (the `_pdef` scan and 5 later ones) and the post-link draftstrip and zero-address scans. The post-link 16→8 digit map rewrite is skipped when `lld_link.py` has already done it (it always does). The original `Roblox.exe` is parsed by pefile once instead of four times (`_orig_pe`). The base `stubs.obj` symbol table is parsed once instead of six times. | quicktest.py | `QT_NO_MAPCACHE=1` | **5-20 s.** Each parse means reading, `splitlines` and `split` over about 10^5 lines, plus one avoided rewrite of the whole map. The exact figure depends on the map's size. |
| **E** | **Earlier start for 4 of the 5 alias generators.** `qualname_alias`, `draft_imports`, `rtclass` and `stubalias` now start right after `import defined_now`, so they run during phases 2-3. Before, they started at the end of phase 3. Their inputs are `link/stubs.json`, `renamed/defined.json` (current from that point), `rename.json`, the registry, the previous `linkexp/qt.map`, `link/donorfree.rsp` with its receipts, and the native headers. quicktest writes none of these before the old start point. Their outputs are only their own `aliases_*.txt`, which quicktest reads after it waits for them (checked with grep). `createinst.py` stays where it was, because it rewrites `linkexp/createinst.obj` and phase 3 reads that file. | quicktest.py | `QT_NO_EARLY_PREPROCS=1` | **Up to the scripts' own run time,** taken off the critical path. They load pefile, capstone, the map and the registry, so probably 5-30 s; this was not measured. |

New files that quicktest writes by default: `linkexp/qt_timing.json` (phase times) and the two sidecar directories.
Deleting any of them only costs one slower run.

To run the old code path for an A/B comparison, set all three switches:
`QT_NO_SIDECAR=1 QT_NO_MAPCACHE=1 QT_NO_EARLY_PREPROCS=1`.

**Expected total (default-on only):** roughly 20-90 s off a 4-5 min run, from the second run after pulling. This is
an estimate. The first run builds the sidecars and is about as slow as before. The opt-in copy reuse (B) may add
another 5-30 s.

### Opt-in

| | Change | Switch | Why it is not on by default |
|---|---|---|---|
| **B** | **Copy reuse** (`QT_REUSE_COPIES=1`; for `lld_link.py` also `LLD_REUSE_BLANKS=1`). It keeps four kinds of patched copy instead of rewriting them on every run: prefer_converted `pc_` copies and "no hit" results (in `draft_defs_cache.pkl`, key `('pc', path)`); natinit `ni_` copies and "no hit" results (`linkexp/qt_scan_cache.pkl`); the base stubs copy `qt_base_stubs.obj` (`.stamp.json` next to it); and lld_link's blanked alias copies `pre<i>_*` (`linkexp/patched/_blank_cache.json`). Each key holds the source's `(mtime_ns, size)`, the plan or drop-set digest, and **a code version**: a hash of `quicktest.py` + `roc/rebuild.py`, or of `lld_link.py` for the blanked copies. A copy is reused only while **its bytes hash to what this source produced**. So a copy whose shared name was overwritten by another source (`ni_candidate.obj` is shared by many drafts) is rebuilt. A reused copy gets **its mtime refreshed**, so mtime-gated later passes see it as new, just as when it was rewritten. | env | Before the review fix, copies were reused by input stamps alone. A fix to the code that writes them (the inline natinit rewrite, `roc/rebuild.py` `strip_symbols`/`coff_externals`, the blanking regex) then kept stale copies. The copies' unchanged mtimes also stopped mtime-gated consumers from rebuilding: `dllexstrip.py` rewrites a `dx_` copy only when it is missing or older than its source, and callfix chains depend on it, so a changed strip/hit set (identity registry, rgmain exports) could link an old `dx_` copy. The code-version key and the mtime refresh address both. The code version covers only the files named above, though: a change in another module that writes into these copies would still be missed. **Verify:** run once with `QT_REUSE_COPIES=1` and once without, on the same inputs, then `shard_libs.py --compare-exe` / `--compare-map`. To see what was reused, look for `natinit: ... copies reused`, `base stubs copy reused` and `(N copies reused)` in the log. Estimated 5-30 s: whole-file reads plus a regex over about 5k native and 16k converted objects become one `stat` each. |
| **G** | `audits_all.py`: `AUDIT_NICE=1` runs the audits at below-normal priority. `AUDIT_JOBS=N` runs at most N first-wave audits at once, each with its own `AUDIT_TIMEOUT`. The last stamp shows 7 of the 9 first-wave audits ending on the 300 s timeout. When the next quicktest starts within about 5 min of a link, it competes with 9 cache-loading processes. | env | It changes scheduling, so audits that are starved can time out where they finished before, and their plans feed the next link. |
| **H** | **`.lib` shards (HANDOFF 6.G).** `QT_SHARD_LIBS=1` runs lld on `<rsp>.sharded.rsp`, where the converted objects are packed into `/WHOLEARCHIVE` shards. The same switch works for `fastlink.py`, and `lldprof.py --shards` profiles it. | env | It is not yet proven byte-identical; see below. |

#### The shard_libs evaluation

The `shard_libs.py` plan that was there before was **not equivalent** to the loose link:

- **The wrong definition wins.** An archive member loads only when it resolves a symbol that is still undefined
  when lld reaches it. Under `/FORCE:MULTIPLE` the first loaded definition wins. quicktest deliberately links the
  converted objects first (`first_wins.json`, "exact definitions win"). As lazy members placed after the loose objects,
  they would lose to every native object that defines the same name, and COMDAT-any picks would change.
- **Unreferenced members are dropped.** A member nothing references is never loaded, so its body leaves the image.
  The layout changes, and the map-based audits lose those `func_` names. Its `.drectve` directives (`/alternatename`,
  `/INCLUDE`, `/DEFAULTLIB`) disappear with it.
- **The exclusion list was incomplete.** It kept only `.CRT$XC*` objects loose. Other content that has only side
  effects (`.CRT$XI/XP/XT/XL`, `.tls`, directives) has the same problem.
- **Two bugs.** The manifest hashed object names only, so a reconverted object kept a stale shard. The round-robin
  buckets also reordered the objects.

The rewritten `shard_libs.py` keeps the loose semantics:

- **Order and loading.** Each contiguous run of converted objects becomes consecutive shards, with the members in
  their original order. Each shard is passed as `"/WHOLEARCHIVE:<lib>"` at the run's position. lld-link handles
  `/wholearchive:file` positionally, in the same input loop as plain files, and loads every member in archive order.
  The load order, and with it every first-definition and COMDAT choice, should therefore be unchanged.
- **Conservative exclusions.** Objects with any `.CRT$*` or `.tls` section stay loose anyway.
- **Content keys.** A shard is named by a hash of each member's `(path, mtime_ns, size)`. Chunk boundaries are
  content-defined (crc32 of the member name, about 256 members per shard), so a changed, added or removed object
  rebuilds only its own shard. Shards no recent plan uses are deleted (`linkexp/shards<tag>/`). The tool is
  `llvm-lib.exe` (next to lld-link), falling back to VC2005 `lib.exe`; `QT_SHARD_LIBTOOL` overrides both.
- **Map owners.** lld names a member's owner `<lib>:<member>`. `unshard_map_text` rewrites shard owners back to the
  member name, so quicktest's `':' in owner` means library heuristic sees what a loose link shows.
- **Other tools' input.** `qt.final.rsp`, which `srcaddr_alias`, `descinit`, `callpair`, `mine_frontier`,
  `comdatdiv`, `fastlink` and `lldprof` read, keeps the loose list.
- **Safety in `lld_link.py`.** The sharding runs after `apply_mfc_static`, `_preresolve_aliases` and
  `_blank_alias`, so those still see the loose objects. MFC-static renaming never touches a shard. Any failure falls
  back to the loose response file.

Still unproven, which is why it stays opt-in:

- **Exact output.** Confirm that the exe and map are identical. Example `shard_libs.py --compare-exe` /
  `--compare-map` against a loose link of the same inputs (section 4). The owner format of lld's map was not seen
  here; `unshard_map_text` accepts `lib:member`, `lib.lib(member)` and full-path variants.
- **Real speedup.** It may not be faster. lld still parses every member. Sharding saves only about 16k file
  opens/mmaps, plus any antivirus scanning on those opens, and building shards costs a copy of the converted objects.
  Look at lld's own `Input File Reading` time in `lldprof.py`. If that is already small, sharding cannot help.

## 3. Things not changed: possible next steps

- **Antivirus exclusion: probably the cheapest large win, not verified.** Add a Windows Defender exclusion for the
  checkout, or at least `work\donorfree-route\renamed`, `linkexp`, `link` and `work\2008-06\native-check-runs`, and
  for `lld-link.exe` and `python.exe`. Every link and every scan pass opens about 21k objects. Real-time scanning of
  those opens can cost more than lld itself. Compare `lldprof.py --repeat 3` with Defender on and off.
- **`defined_now.py`** (not in this lease) runs `_main()` at import inside quicktest whenever its signature changes.
  That reloads the whole `link/obj_ext_cache` and iterates it. It is a third ~2 GB load on those runs. It could run
  in the background after a link, or use a `ShardView`, but it iterates all entries, so it would need an index of
  definitions instead.
- **Other modules** (not in this lease) such as `relocsplit`, `dllexstrip`, `spellunify`, `hardaddr`, `dtorfix` and
  `collidefix` each walk the object list. Phase 7's `_tm` line shows whether they matter.
- **lld options:** lld-link already uses every core and has no `/INCLUDE`-style incremental mode, so nothing was
  changed here.
  - **`/MAP`:** `lldprof.py --no-map` shows what the map costs; quicktest needs the map.
  - **Missing flags:** if `lldprof.py` shows no `/DEBUG` and no `/OPT:REF`/`/OPT:ICF`, there is nothing to turn off.
  - **Present flags:** if `/OPT:ICF` is present, removing it would change the image, so it was not touched.

## 4. How Colin measures it

1. **Phase times.** After a normal `python quicktest.py 0`, `linkexp/qt_timing.json` lists every phase's cumulative
   seconds. The log also shows the new lines `obj_ext_cache opened in N s`, `qt_ext_cache: N s {...}`,
   and `[lld_link] lld-link N s` for lld alone in each pass. With `QT_REUSE_COPIES=1` you also get `natinit: ... copies
   reused`, `base stubs copy reused` and `(N copies reused)`.
2. **A/B comparison.** Run once with the three `QT_NO_*` switches from section 2, then once without, and keep both
   `qt_timing.json` files. Run each case twice, because the first run after pulling builds the sidecars, and the
   OS file cache warms up.
3. **Same output.** Compare `linkexp/qt.exe` from the two runs with `python shard_libs.py --compare-exe A.exe B.exe`,
   which ignores the timestamp and checksum. Compare `qt.map` with `--compare-map`. The default-on changes must give
   identical results, if the inputs did not change between the two runs.
4. **lld alone:**
   - `python lldprof.py --repeat 3` gives lld's `/time` phases on the last final rsp. lld runs with the caller's
     environment, as before; add `--env roc` for lld_link.py's LIB/INCLUDE environment.
   - `--no-map` shows the cost of the map.
   - `--shards` shows the sharded link; its first run builds the shards.
5. **Shards, opt-in.**
   1. Run `set QT_SHARD_LIBS=1` then `python quicktest.py 0`.
   2. Copy `linkexp\qt.exe` and `qt.map` aside.
   3. Relink with `QT_SHARD_LIBS=` unset.
   4. Run `shard_libs.py --compare-exe` and `--compare-map` on the two pairs.

   Make it the default only if both are identical and `qt_timing.json` shows a gain.

   **`shard_libs.py` CLI change.** Planning is still the default; `--dry-run` is accepted and means the same. `--build`
   packs the shards. `--shards N` is accepted but ignored, with a message: the shard count now follows `--avg`
   (members per shard). The default `--rsp` is now `linkexp/qt.final.rsp` (was `linkexp/qt.rsp`). The default
   `--out-dir` is now `linkexp/shards` (was `work/native-client/lib-shards`).
6. **Audits.** Set `AUDIT_NICE=1` (optionally `AUDIT_JOBS=4`) before starting the quicktest that launches the
   background `audits_all.py`. Watch `auto/audits_stamp.json` for timeouts.

## 5. Tests

`python test_link_speed.py` (or `python -m unittest test_link_speed`) runs on any OS, with synthetic inputs:

- **ShardView:** its results equal `ShardCache` in every state (first run, sidecar hits, another writer's save,
  writes through the view, single-file and foreign-file fallback, misplaced key, keep predicate, corrupt sidecar).
- **Shard plan:**
  - it preserves order and content, and every shard expands back to the original list;
  - side-effect objects stay loose;
  - removing one object changes only its own chunk;
  - shard names change with a member's stamp;
  - built shards are reused.
- **Map rewrite:** `unshard_map_text` turns shard owners into member names and leaves library owners alone.
- **`compare_exes`:** it ignores the timestamp and checksum and reports a real difference.
- **`_map_rows`:** taken from quicktest by AST, it gives the same rows as before and drops an old file version.
- **`_preresolve_aliases`:** taken from lld_link by AST. It blanks the same bytes. By default it rewrites the copies
  on every call and keeps no cache. With `LLD_REUSE_BLANKS=1` it reuses a copy and refreshes its mtime, and rebuilds
  the copy when the copy's bytes, the lld_link code or the source change.
- **`_reuse_copy`:** it checks the copy's content digest and refreshes the mtime. Every `pc_`/`ni_`/base-stubs cache
  use in quicktest sits behind `_REUSE` (`QT_REUSE_COPIES=1`), and the keys include the code version.
- **ShardView.pending:** True only when a save would write; False in full-load fallback.
- **CLI defaults:** lldprof uses the caller's environment unless `--env roc` is given, and `shard_libs.py` accepts the
  old `--dry-run`/`--shards`/`--out-dir` flags.
- **Compile:** every edited file compiles, and every quicktest off switch is documented here.
