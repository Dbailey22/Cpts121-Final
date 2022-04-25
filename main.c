#include "header.h"


int main(void)
{
	//Customer profile cannot exceed 100 
	Profile *customers[100];


	// -Open customers.txt for mode read
	FILE* infile = fopen("customers.txt", "r");
	// - Read all records in customers.txt and store them into the array of Profiles
	int num_customers = read_file(infile, customers);

	//-Sort the array based on customers names ‘z’ – ‘a’
	//sort_array(customers, num_customers);

	// - Compute the charges for each customer based on the plan for the customer, and the talkand data usages – store the charges back into the Profile in the array; recall 1 GB = 1000 MB
	compute_charges_for_customer(customers, num_customers);

	// - Compute the total or sum of charges for all customers
	double sum = compute_sum_charges(customers, num_customers);

	// - Compute the average charges per customer
	double average = compute_average(sum, num_customers);

	// - Compute the maximum charges
	double max = max_payment(customers, num_customers);

	// - Compute the minimum charges
	double min = min_payment(customers, num_customers);

	// - Open charges.txt for mode write
	FILE* outfile = fopen("charges.txt", "w");
	// - Write the total, average, maximum, and minimum charges to charges.txt
	write_stats_to_outfile(outfile, sum , average, max, min);
	// - Close customers.txt and charges.txt
	fclose(infile);
	fclose(outfile);

	return 0;
}