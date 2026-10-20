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
for (const color of ["#58a6ff", "#3fb950", "#b6a04c"]) assert.ok(split.includes(color));
context.history = [];
assert.equal(context.miningDays(client).length, 1);
assert.doesNotMatch(context.miningGraph(client), /NaN|Infinity/);
assert.equal(context.miningGraph({name: "empty", functions: 0, matched: 0}), "");
context.history = [{date: "2026-10-19 20:00 UTC", clients: {"2008-06": stats(45)}}];
assert.equal(context.miningDays(client).at(-1).gain, -5); // corrections stay truthful
new vm.Script(html.match(/<script>([\s\S]*?)<\/script>/)[1]);
console.log("Mining graph tests passed.");
