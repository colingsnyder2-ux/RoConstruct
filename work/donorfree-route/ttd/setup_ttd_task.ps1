# ONE-TIME setup, run from an ADMINISTRATOR PowerShell:
#   powershell -ExecutionPolicy Bypass -File C:\Users\colin\RoConstruct\work\donorfree-route\ttd\setup_ttd_task.ps1
# Installs the TTD runner to C:\ProgramData\RoTTD (writable only by Administrators/SYSTEM) and registers the scheduled
# task "RoConstructTTD" (runs elevated, in your logged-on session, only when triggered). Afterwards any non-elevated
# process (Claude's tools) starts a recording with `schtasks /run /tn RoConstructTTD` -- no UAC prompt.
# Remove later with:  Unregister-ScheduledTask -TaskName RoConstructTTD -Confirm:$false; Remove-Item -Recurse C:\ProgramData\RoTTD
$ErrorActionPreference = 'Stop'
$dst = 'C:\ProgramData\RoTTD'
New-Item -ItemType Directory -Force -Path $dst | Out-Null
Copy-Item -Force (Join-Path $PSScriptRoot 'ttd_runner.ps1') (Join-Path $dst 'ttd_runner.ps1')
# lock the folder: only Administrators and SYSTEM may write; users read/execute (the task runs this file elevated)
icacls $dst /inheritance:r /grant:r 'Administrators:(OI)(CI)F' 'SYSTEM:(OI)(CI)F' 'Users:(OI)(CI)RX' | Out-Null
$user = "$env:USERDOMAIN\$env:USERNAME"
$action = New-ScheduledTaskAction -Execute 'powershell.exe' -Argument "-NoProfile -ExecutionPolicy Bypass -WindowStyle Hidden -File `"$dst\ttd_runner.ps1`""
$principal = New-ScheduledTaskPrincipal -UserId $user -LogonType Interactive -RunLevel Highest
$settings = New-ScheduledTaskSettingsSet -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries -ExecutionTimeLimit (New-TimeSpan -Minutes 20) -MultipleInstances IgnoreNew
Register-ScheduledTask -TaskName 'RoConstructTTD' -Action $action -Principal $principal -Settings $settings -Force | Out-Null
# let the normal (non-elevated) user trigger it: grant read+execute on the task to the user
$svc = New-Object -ComObject Schedule.Service; $svc.Connect()
$task = $svc.GetFolder('\').GetTask('RoConstructTTD')
$sd = $task.GetSecurityDescriptor(0xF)
$sid = (New-Object System.Security.Principal.NTAccount($user)).Translate([System.Security.Principal.SecurityIdentifier]).Value
if ($sd -notmatch [regex]::Escape($sid)) { $task.SetSecurityDescriptor($sd + "(A;;GRGX;;;$sid)", 0) }
Write-Host 'RoConstructTTD installed. Test (non-elevated):  schtasks /run /tn RoConstructTTD'
