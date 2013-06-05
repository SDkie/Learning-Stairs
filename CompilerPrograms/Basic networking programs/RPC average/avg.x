const MAXSIZE = 20;

struct input_data
{
	double list[200];
	int no_of_elements;
};

typedef struct input_data input_data;

program PROGAVG
{
	version VERAVG
	{
		double avg(input_data)=1;
	}=1;
}=12345;
