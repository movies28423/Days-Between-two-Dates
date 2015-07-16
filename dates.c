int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,30};

int get_leap_years(int year){
    int years = (year - (year % 4))/4 - (year - (year % 100)) % 100 
                   + (year - (year % 400)) % 400;
    return years;
}


int main(void){

FILE * fp = NULL;
  //file contains two dates separated by line break
	fp = fopen("dates.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Cannot open file\n");
		exit(-1);
	}

int year = 0;
int month = 0;
int day = 0;

char line[12];

while (fgets(line, 12, fp)){

int date_values = sscanf(line, "%d-%d-%d",
		&year, &month, &day);

int add_year = (month < 2 || month == 2 && day <= 28) ? -1 : 0;
int days = year * 365 + get_leap_years(year - 1);

for(int i = 0; i < month; i++)
    days += month_days[i];

days -= (month_days[month - 1] - day);

printf("%d",days);
}
getchar();
return 0;
}
