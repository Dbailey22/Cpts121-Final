#include "header.h"

int read_file(FILE *infile, Profile customers[])
{	
	int num_customers = 0;
	while (!feof(infile))//This means while we aren't at the end of the file
	{	
		read_customer(infile, &customers[num_customers]);
		num_customers++;
	}
	return num_customers;
}

void read_customer(FILE* infile, Profile* person)
{
	//read in name, plan, minutes, data
	char first_name[100] = { '\0' }; //Stores the first name
	char last_name[100] = { '\0' }; //Stores the last name
	fscanf(infile, "%s %s\n", last_name, first_name); //These are already pointers
	strcat(last_name, " ");//Had to add this to add a space 
	strcat(last_name, first_name);

	strcpy(person->name, last_name);//Copy to the prof struct
	fscanf(infile, "%c\n", &person->plan); //A or B
	fscanf(infile, "%d\n", &person->talk_minutes); // minutes used
	fscanf(infile, "%d\n", &person->data_MB); //amount of data used 
}
//Compute the charges for each customer based on the plan for the customer
//and the talkand data usages – store the charges back into the Profile in the array; recall 1 GB = 1000 MB
void compute_charges_for_customer(Profile customers[], int num_customers)
{
	for (int customer_index = 0; customer_index < num_customers; customer_index++)
	{
		compute_charges(&customers[customer_index]);
	}
}
//function to sort the array z-a
/*

 PLEASE NOTE, I SAW AN EXAMPLE OF THIS ON A WEBSITE. I GOT THE IDEA FROM IT BUT I SET THE TEMP VARIABLE TO THE STRUCT
 //https://www.geeksforgeeks.org/program-sort-string-descending-order/

*/
void sort_array(Profile *customers, int num_customers)
{	
	Profile temp;
	for (int j = 0; j < num_customers; j++)
	{
	for (int k = 0; k < (num_customers - 1 - j); k++)
		{
			if (strcmp(customers[k].name, customers[k + 1].name) < 0)
			{
				temp = customers[k];
				customers[j] = customers[k + 1];
				customers[j + 1] = temp;
			}
		}
	}
}
//Charges for the customers based on plan
//Going to be either A or B

//Plan A Customers :
//-Up to 1000 minutes of talk for $35; $0.50 per minute thereafter(overage)
//- Up to 10 GB of data for $25; $0.25 per MB thereafter(overage)
//- Monthly charge : $60, excluding extra charges for overages

//Plan B Customers :
//-Up to 2000 minutes of talk for $55; $0.40 per minute thereafter(overage)
//- Up to 20 GB of data for $30; $0.15 per MB thereafter(overage)
//- Monthly charge : $85, excluding extra charges for overages

void compute_charges(Profile* customers)
{
	//$60 and $85 for monthly charges but it doesnt tell me ho wmany months they were on the plan?
	double minutes_over = 0.0, data_over = 0.0, normal_minutes = 0;
	double charges = 0.0, overage = 0.0, total_charges = 0.0;
	//when it is over 1000 minutes I see how many minutes they're over by soi i can thedn multiply that number by .5

	/*

		My calculations should all be correct but the total and the average are incorrect while the max and min are?

		OMG I SPENT HOURS ON END TRYING TO FIX THIS CODE BUT THE SAMPLES WERE INCORRECT
		
		I thought the monthly charges were added onto what was calculated I see now that th emonthly charges are from the minutes and data lol

	*/
	if (customers->plan == 'A')
	{
		if (customers->talk_minutes <= 1000)
		{
			normal_minutes = 35;
		}
		else if (customers->talk_minutes > 1000)
		{
			normal_minutes = 35 + (((customers->talk_minutes) - 1000) * .5);
		}
		if (customers->data_MB <= 10000) //10GB = 10000B
		{ 
			total_charges = normal_minutes + 25;// +60;
		}
		else if (customers->data_MB > 10000)
		{	//I keep having some overflow error no matter how I make it
			total_charges = 25 + (((customers->data_MB) - 10000) * .25) + normal_minutes;// +60;
		}
	}
	
	if (customers->plan == 'B')
	{
		if (customers->talk_minutes <= 2000)
		{
			normal_minutes = 55;
		}
		else if (customers->talk_minutes > 2000)
		{
			normal_minutes = 55 + (((customers->talk_minutes) - 2000) * .4);
		}
		if (customers->data_MB <= 20000)
		{
			total_charges = normal_minutes + 30;// +85;
		}
		else if (customers->data_MB > 20000)
		{
			total_charges = 30 + (((customers->data_MB) - 20000) * .15) + normal_minutes;// +85;
		}
	}
	customers->charges = total_charges;
}

//Loop through all of the customers and sum all of their payments
double compute_sum_charges(Profile customers[], int num_customers)
{
	double temp_sum = 0.0;
	for (int customer_index = 0; customer_index < num_customers; customer_index++)
	{
		temp_sum += customers[customer_index].charges;
	}
	return temp_sum;
}
////use the sum to divide by number of customers
double compute_average(double sum_of_charges, int num_customers)
{
	double temp_average = 0.0;
	temp_average = sum_of_charges / num_customers;
	return temp_average;
}
//compute max
double max_payment(Profile customers[],int num_customers)
{	//setting it to 0 made it always 0
	double max = customers[0].charges;
	for (int customer_index = 1; customer_index < num_customers; customer_index++)
	{
		if (customers[customer_index].charges > max)
		{
			max = customers[customer_index].charges;
		}
	}
	return max;
}
//compute min
double min_payment(Profile customers[],int num_customers)
{
	double min = customers[0].charges;
	for (int customer_index = 1; customer_index < num_customers; customer_index++)
	{
		if (customers[customer_index].charges < min)
		{
			min = customers[customer_index].charges;
		}
	}
	return min;

}
//Now printing the stats into the outfile
write_stats_to_outfile(FILE *outfile, double sum, double average, double max, double min)
{
	fprintf(outfile, "Sum: $%.2lf\n", sum);
	fprintf(outfile, "Average: $%.2lf\n", average);
	fprintf(outfile, "Max: $%.2lf\n", max);
	fprintf(outfile, "Min: $%.2lf\n", min);
}