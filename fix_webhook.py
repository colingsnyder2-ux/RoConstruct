from pathlib import Path
p=Path("roc/rebuild.py")
lines=p.read_text(encoding="utf-8").splitlines()
start=next(i for i,l in enumerate(lines) if l.strip()=="def _send_rebuild_webhook(url, client, data):")
end=next(i for i,l in enumerate(lines[start:],start) if l.strip()=="payload = {")
new=[
'def _rebuild_emoji_bar(value, total, width=10, fill="🟦", empty="⬜"):',
'    if total <= 0:',
'        return empty * width',
'    filled = max(0, min(width, int(round(width * value / total))))',
'    return fill * filled + empty * (width - filled)',
'',
'',
'def _send_rebuild_webhook(url, client, data):',
'    bars = data["bars"]',
'    description = (',
'        "Phase %s - %s\\n\\n" % (data["phase"], data["phaseLabel"]) +',
'        "Modules reporting: %d/%d %s\\n" % (bars["compiled"]["value"], bars["compiled"]["total"], _rebuild_emoji_bar(bars["compiled"]["value"], bars["compiled"]["total"], fill="🟦")) +',
'        "Modules linked: %d/%d %s\\n" % (bars["linked"]["value"], bars["linked"]["total"], _rebuild_emoji_bar(bars["linked"]["value"], bars["linked"]["total"], fill="🟩")) +',
'        "Byte-exact: %s/%s %s\\n" % (format(bars["exact"]["value"], ","), format(bars["exact"]["total"], ","), _rebuild_emoji_bar(bars["exact"]["value"], bars["exact"]["total"], fill="🟩")) +',
'        "Unresolved: %d %s\\n" % (bars["unresolved"]["value"], _rebuild_emoji_bar(bars["unresolved"]["value"], bars["unresolved"]["total"], fill="🟥")) +',
'        "Stubs: %d %s\\n" % (bars["stubs"]["value"], _rebuild_emoji_bar(bars["stubs"]["value"], bars["stubs"]["total"], fill="🟨")) +',
'        "Runtime: %d/%d %s\\n\\n" % (bars["runtime"]["value"], bars["runtime"]["total"], _rebuild_emoji_bar(bars["runtime"]["value"], bars["runtime"]["total"], fill="🟪")) +',
'        "Next: %s" % data.get("next", ""))',
'',
]
p.write_text("\n".join(lines[:start] + new + lines[end:]), encoding="utf-8")
print("done")
