# RoConstruct TTD runner (installed to C:\ProgramData\RoTTD\ttd_runner.ps1 by setup_ttd_task.ps1; runs ELEVATED from the
# scheduled task "RoConstructTTD"). Reads the request file written by the non-elevated tools (ttdrun.py), validates it,
# records a Time Travel Debugging trace of the client, posts the requested WM_COMMANDs from inside the elevated session
# (UIPI blocks a non-elevated process from posting to an elevated window), waits for exit/crash, writes a done marker.
$ErrorActionPreference = 'Stop'
$Root = 'C:\Users\colin\RoConstruct\work\donorfree-route'
$Req = Join-Path $Root 'auto\ttd_request.json'
$Done = Join-Path $Root 'auto\ttd_done.json'
$Log = Join-Path $Root 'auto\ttd_runner.log'
function Out-Log($m) { Add-Content -Path $Log -Value ("{0} {1}" -f (Get-Date -Format s), $m) }
try {
    $r = Get-Content $Req -Raw | ConvertFrom-Json
    $exe = [IO.Path]::GetFullPath($r.exe); $out = [IO.Path]::GetFullPath($r.out)
    # validation: only client builds from run\ and output under auto\ (the task runs as administrator)
    if (-not $exe.StartsWith((Join-Path $Root 'run\'), [StringComparison]::OrdinalIgnoreCase) -or -not $exe.EndsWith('.exe')) { throw "exe outside run\: $exe" }
    if (-not $out.StartsWith((Join-Path $Root 'auto\'), [StringComparison]::OrdinalIgnoreCase)) { throw "out outside auto\: $out" }
    $posts = @($r.post | ForEach-Object { if ($_ -notmatch '^0x[0-9a-fA-F]{1,6}$') { throw "bad command $_" }; [Convert]::ToInt32($_.Substring(2), 16) })
    $secs = [Math]::Min([int]$r.secs, 600)
    New-Item -ItemType Directory -Force -Path $out | Out-Null
    Get-ChildItem $out -Include *.run,*.idx,*.out -Recurse -ErrorAction SilentlyContinue | Remove-Item -Force
    Add-Type -Namespace W -Name U -MemberDefinition @'
[DllImport("user32.dll")] public static extern bool PostMessageW(IntPtr h, uint m, IntPtr w, IntPtr l);
'@
    $ttd = Join-Path $env:LOCALAPPDATA 'Microsoft\WindowsApps\ttd.exe'
    if (-not (Test-Path $ttd)) { $ttd = 'C:\Users\colin\AppData\Local\Microsoft\WindowsApps\ttd.exe' }
    Out-Log "record $exe -> $out posts=$($r.post -join ',')"
    $p = Start-Process -FilePath $ttd -ArgumentList @('-accepteula', '-out', "`"$out`"", '-launch', "`"$exe`"") -WorkingDirectory (Split-Path $exe) -PassThru -WindowStyle Hidden
    $name = [IO.Path]::GetFileNameWithoutExtension($exe); $t0 = Get-Date; $h = [IntPtr]::Zero
    while (((Get-Date) - $t0).TotalSeconds -lt 120 -and -not $p.HasExited) {
        $c = Get-Process -Name $name -ErrorAction SilentlyContinue | Where-Object { $_.MainWindowHandle -ne 0 -and $_.MainWindowTitle -like '*Roblox*' } | Select-Object -First 1
        if ($c) { $h = $c.MainWindowHandle; break }
        Start-Sleep -Seconds 1
    }
    Start-Sleep -Seconds 4
    foreach ($cmd in $posts) {
        if ($h -ne [IntPtr]::Zero) { [W.U]::PostMessageW($h, 0x111, [IntPtr]$cmd, [IntPtr]::Zero) | Out-Null; Out-Log ("posted 0x{0:x}" -f $cmd) }
        Start-Sleep -Seconds 6
    }
    if (-not $p.WaitForExit($secs * 1000)) {
        Get-Process -Name $name -ErrorAction SilentlyContinue | Stop-Process -Force   # crash dialog / hang: end the recording
        $p.WaitForExit(60000) | Out-Null
    }
    $runs = @(Get-ChildItem $out -Filter *.run | ForEach-Object FullName)
    @{ ok = $true; runs = $runs; time = (Get-Date -Format s) } | ConvertTo-Json | Set-Content $Done
    Out-Log "done $($runs -join ';')"
} catch {
    @{ ok = $false; error = "$_"; time = (Get-Date -Format s) } | ConvertTo-Json | Set-Content $Done
    Out-Log "error $_"
}
