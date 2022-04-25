#ifndef HEADER_H
#define HEADER_h
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>


typedef struct profile
{
	char name[100];//Employees name
	char plan; //Plan A or B
	int talk_minutes; // Number of minutes used
	int data_MB; //amount of data used in MB
	double charges; // total charges for this customer
}Profile;

int read_file(FILE* infile, Profile customers[]);
void read_customer(FILE* infile, Profile* person);
void sort_array(Profile* customers, int num_customers);
void compute_charges_for_customer(Profile customers[], int num_customers);
void compute_charges(Profile* customers);
double compute_sum_charges(Profile customers[], int num_customers);
double compute_average(double sum_of_charges, int num_customers);
double max_payment(Profile customers[], int num_customers);
double min_payment(Profile customers[], int num_customers);
write_stats_to_outfile(FILE* outfile, double sum, double average, double max, double min);

#endif // !HEADER_H
