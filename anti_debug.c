#include <windows.h>
#include <stdio.h>

int main()
{
    if (IsDebuggerPresent())
    {
        MessageBox(NULL, "Debugger detected 1 !!!", "Debug title", MB_OK);
        ExitProcess(-1);
    }
    
    BOOL bDebuggerPresent;
    if (TRUE == CheckRemoteDebuggerPresent(GetCurrentProcess(), &bDebuggerPresent) && TRUE == bDebuggerPresent)
    {
        MessageBox(NULL, "Debugger detected 2 !!!", "Debug title", MB_OK);
        ExitProcess(-1);
    }

    MessageBox(NULL, "No Debugger detected", "No Debug title", MB_OK);

    return 0;
}
