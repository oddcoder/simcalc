#include <stdio.h>
void banner()
{
	puts(" +--------------------------------------------------------------------+"      );
	puts(" | +----------------------------------------------------------------+ |"      );
	puts(" | |                            simcalc                             | |"      );
	puts(" | +----------------------------------------------------------------+ |"      );
	puts(" +--------------------------------------------------------------------+\n"    );
	puts("* Copyright 2015 Ahmed Mohamed Abd EL-Mawgood <ahmedsoliman0x666@gmail.com>\n");
	puts("* Licensed under the Apache License, Version 2.0 (the \"License\");"          );
	puts("  you may not use this file except in compliance with the License."           );
	puts("  You may obtain a copy of the License at\n"                                  );
	puts("* http://www.apache.org/licenses/LICENSE-2.0\n"                               );
	puts("* Unless required by applicable law or agreed to in writing, software"        );
	puts("  distributed under the License is distributed on an \"AS IS\" BASIS,"        );
	puts("  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied."   );
	puts("* See the License for the specific language governing permissions and"        );
	puts("  limitations under the License."                                             );
}
void credits()
{
	puts("This project didn't come to live on its own, and I am very grateful for");
	puts("their assistance and suppert with my project I thank you all for your efforts.");
	puts("	Ahmed Osama");
	puts("	professor David Malin and all of the CS50 staff and community ");
	puts("	Kareem Mesbah");
	puts("	Karim Abdel Salam");
	puts("	Sami Mamdouh Sami");
	puts("\t\t\t\tthank you all");
}
void help()
{
	puts("Allowed command");
	puts("\tbanner : view the interpreter's banner");
	puts("\tclear : clear the screan");
	puts("\tcredits : view credits ");
	puts("\thelp : view this help");
	puts("\tq : quit");
	puts("allowed operations");
	puts("max input length is 100 character");
}
