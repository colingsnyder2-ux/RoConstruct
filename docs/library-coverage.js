/* Library attribution is an estimate of executable code, not DLL completeness. */
const originalLibraryClassification = classify;
classify = function (data) {
  return originalLibraryClassification(data).map(([lib, part, exact], i) => {
    const f = data.funcs[i], src = f[2] === 100 && f[5], unit = data.units[f[3]] || "";
    if (src && /^(wildmagic-|templates-)/.test(src[0]))
      return ["Codegen analogs", src[0] + " (source authenticity unproven)", exact];
    if (lib === "Ogre") {
      part = src && /^ogre-1\.4\.5(?:-|$)/.test(src[0]) ? "Ogre 1.4.5 recipe"
        : src && /^ogre-/.test(src[0]) ? "Other Ogre versions (codegen analogs)"
        : /Rbx|VisualEngine|TwoDManager/.test(unit) ? "Roblox Ogre extensions (class label)"
        : "Ogre class label / shared bodies";
    }
    if (lib === "G3D" && src && /g3d/.test(src[0]))
      part = /-png(?:-|$)/.test(src[0]) ? "Bundled PNG source"
        : /(?:^|\/)GLG3Dcpp\//.test(src[1]) || /^contrib\//.test(src[1]) ? "GLG3D source"
        : /ijg|jpeg/.test(src[0] + "/" + src[1]) ? "Bundled JPEG source" : "G3D core source";
    return [lib, part, exact];
  });
};

libraryTable = function (data, integration = false, switcher = false) {
  const native = integrationData?.client === data.name ? integrationData : null;
  const integrated = new Set(native?.native || []);
  const blank = () => ({n: 0, m: 0, b: 0, mb: 0, sb: 0, pb: 0, native: 0, nb: 0, waiting: 0, parts: new Map(), fs: new Set()});
  const add = (r, f) => {
    r.n++; r.b += f[1];
    if (integrated.has(hex(f[0]))) {r.native++; r.nb += f[1];}
    else if (f[2] === 100) r.waiting += f[1];
    if (f[2] === 100) {r.m++; r.mb += f[1]; if (f[5]) r.sb += f[1];}
    else if (f[2] > 0) r.pb += f[1];
  };
  const rows = new Map();
  classify(data).forEach(([lib, part], i) => {
    if (!rows.has(lib)) rows.set(lib, blank());
    const r = rows.get(lib), f = data.funcs[i];
    if (!r.parts.has(part)) r.parts.set(part, blank());
    add(r, f); add(r.parts.get(part), f); r.parts.get(part).fs.add(f);
  });
  data.groups = new Map();
  const bySize = m => [...m].sort((a, b) => b[1].b - a[1].b);
  const cells = r => `<td>${fmt(r.m)} / ${fmt(r.n)}</td>${native ? `<td>${fmt(r.native)} / ${fmt(r.n)}</td>` : ""}
    <td>${pct(integration ? r.native : r.m, r.n)}</td><td>${pct(integration ? r.nb : r.mb, r.b)} <small>of ${mb(r.b)}</small></td>
    <td>${integration ? integrationCoverageBar({bytes:r.b,integratedBytes:r.nb,waitingBytes:r.waiting}) : codeBar(r.sb,r.mb-r.sb,r.pb,r.b)}</td>`;
  return `<div class="head"><h2><small>Breakdown</small>Libraries</h2><p>Executable functions only; membership estimated from recipes, symbols and nearby class labels. Imported DLL bodies are outside this denominator. <b>Byte-exact</b> means mined reproduction; <b>Integrated</b> uses published integration addresses. Local test passes add no integration credit. Expand Ogre for source origins; alternate SDK recipes remain codegen analogs.</p></div>
    ${switcher ? sectionMode("libraries", "Library coverage view") : ""}
    <div class="table"><table id="libs"><thead><tr><th>Library / source origin</th><th>Byte-exact</th>${native ? "<th>Integrated</th>" : ""}<th>${integration ? "Integrated" : "Matched"} %</th><th>Code</th><th>Bytes ${integration ? "integrated" : "matched"}</th></tr></thead><tbody>
    ${bySize(rows).map(([lib,r],i) => `<tr class="lib" data-lib="${i}"><td><span class="caret">â–¸</span>${esc(lib)}</td>${cells(r)}</tr>` +
      bySize(r.parts).map(([part,p],j) => (data.groups.set(`${i}.${j}`,[`${lib} â€º ${part}`,p.fs]),
        `<tr class="part" data-of="${i}" hidden><td>${esc(part)} <button class="mapbtn" data-g="${i}.${j}">Map</button></td>${cells(p)}</tr>`)).join("")).join("")}
    </tbody></table></div>
    <div class="legend">${integration ? '<span>purple: integrated Â· blue: exact, waiting Â· dark: not exact</span>' : '<span>blue: source recipe Â· green: mined Â· striped: partial source</span>'}</div>
    ${data.name === "2008-06" ? `<details><summary>Local native builds â€” separate from published integration</summary><p>2026-10-29 snapshot, Codex isolated worktree. Ogre: 300 selected roots pass code/data checks; full forced link blocked by 12 unresolved symbols. Native Ogre 1.4.5 header subset: 22 forced roots link and run successfully. RbxApp / RbxgsApp: 84 / 136 forced roots, both link and run successfully. These counts overlap mining and integration; do not add them.</p><p>G3D experiment: /fp:fast preserves all existing exact symbol/address pairs across 63 core files; 107 extra address candidates still need placement and integration checks. Bundled PNG: 21 forced roots link and run. Core G3D forced-link validation remains blocked. <a href="https://github.com/colingsnyder2-ux/RoConstruct-findings/tree/codex/force-link-findings-20261029/2008-06/verification/ogre-native-20261029" target="_blank" rel="noopener">Ogre evidence</a></p></details>` : ""}`;
};

if (typeof progress !== "undefined" && progress) route(false);
