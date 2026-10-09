@echo off
setlocal
cd /d "%~dp0"
title RoConstruct worker

rem Asks the setup questions in this terminal (username, client, cloud model),
rem then runs the worker in this window. Run it again any time to change your
rem mind; nothing is reinstalled.

py -3.12 roc.py launch
if errorlevel 1 (
  echo.
  echo Setup did not finish. Run: py -3.12 roc.py doctor
)
pause
