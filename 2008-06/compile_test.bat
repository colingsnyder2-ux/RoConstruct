@echo off
setlocal
python "%~dp0scripts\compile_test.py" %*
set "result=%errorlevel%"
if "%~1"=="" pause
exit /b %result%
