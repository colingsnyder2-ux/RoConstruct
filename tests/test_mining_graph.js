"use strict";
const assert = require("node:assert/strict"), fs = require("node:fs"), vm = require("node:vm");
const html = fs.readFileSync("docs/index.html", "utf8");
const context = {history: [], progress: {updated: "2026-10-20 17:00 UTC"}, fmt: n => String(n)};
vm.createContext(context);
vm.runInContext(html.slice(html.indexOf("function miningDays("), html.indexOf("function bar(")), context);
const stats = (matched, functions = 100) => ({matched, functions, partial: 5});
const client = {...stats(40), name: "2008-06"};
context.history = [
  {date: "2026-10-17 08:00 UTC", clients: {"2008-06": stats(10)}},
  {date: "2026-10-17 20:00 UTC", clients: {"2008-06": stats(15)}},
  {date: "2026-10-19 20:00 UTC", clients: {"2008-06": stats(30), other: stats(90)}},
];
const days = context.miningDays(client);
assert.deepEqual(Array.from(days, d => d.matched), [15, 15, 30, 40]);
assert.deepEqual(Array.from(days, d => d.gain), [null, 0, 15, 10]);
assert.deepEqual(Array.from(days, d => d.percent), [15, 15, 30, 40]);
const graph = context.miningGraph(client);
assert.match(graph, /100%<\/text>/);
assert.match(graph, /2026-10-20: 40 matched total \/ 100 \(40.00%\); daily change \+10/);
assert.match(graph, /Daily function counts/);
const split = context.miningGraph({...client, source_matched: 30, mined_matched: 10});
assert.match(split, /30 original source \/ 100/);
assert.match(split, /10 mined \/ 100/);
assert.match(split, /5 partial \/ 100/);
assert.equal((split.match(/class="mining-stack"/g) || []).length, days.length);
assert.doesNotMatch(split, /<polyline|<circle/);
assert.match(split, /data-series="source"[^>]*height="72"/); // 30% of 240px
assert.match(split, /data-series="mined"[^>]*height="24"/);
assert.match(split, /data-series="partial"[^>]*height="12"/);
assert.match(split, /Remaining · 55/);
assert.match(split, /split unavailable/); // Missing historical categories stay honest.
for (const color of ["#58a6ff", "#3fb950", "#b6a04c"]) assert.ok(split.includes(color));
context.history = [];
assert.equal(context.miningDays(client).length, 1);
assert.doesNotMatch(context.miningGraph(client), /NaN|Infinity/);
assert.equal(context.miningGraph({name: "empty", functions: 0, matched: 0}), "");
context.history = [{date: "2026-10-19 20:00 UTC", clients: {"2008-06": stats(45)}}];
assert.equal(context.miningDays(client).at(-1).gain, -5); // corrections stay truthful
context.history = [{date: "2026-10-07 02:53 UTC", clients: {"2008-06": stats(1)}}];
assert.equal(context.miningDays(client)[0].day, "2026-10-06"); // full history, Eastern date
assert.match(context.miningGraph(client), /Full history since 2026-10-06/);
// Published history must contain actual category counts, not only today's dots.
context.history = JSON.parse(fs.readFileSync("docs/history.json", "utf8"));
for (const name of new Set(context.history.flatMap(s => Object.keys(s.clients)))) {
  const snapshots = context.history.filter(s => s.clients[name]?.functions);
  const latest = snapshots.at(-1).clients[name];
  const recorded = context.miningDays({...latest, name}).filter(d => d.source != null && d.mined != null);
  assert.ok(recorded.length > 1, `${name}: missing source/mined history`);
  for (const d of recorded) assert.equal(d.source + d.mined, d.matched);
  const rendered = context.miningGraph({...latest, name});
  for (const color of ["#58a6ff", "#3fb950"]) {
    const bars = rendered.match(new RegExp(`fill="${color}"`, "g")) || [];
    assert.ok(bars.length > 1, `${name}: category missing from daily stacks`);
  }
}
new vm.Script(html.match(/<script>([\s\S]*?)<\/script>/)[1]);
console.log("Mining graph tests passed.");
