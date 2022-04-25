# Cpts121-Final
Write a console application that computes and displays the total charges for each customer of a telecommunications company. Each customer’s profile is represented by a record in a file called customers.txt. A record consists of the following:
-	Customer name (last, first)
-	Customer plan (A or B)
-	Talk used in minutes
-	Data used in MB

You must read in all of the records from the file. You may assume the file does not consist of more than 100 records. You will need to write algorithms that sort customer plans based on their names (in reverse dictionary ordering ‘z’ – ‘a’) and that traverses through the records and determines charges for each customer based on the following:
       Plan A Customers:
-	Up to 1000 minutes of talk for $35; $0.50 per minute thereafter (overage)
-	Up to 10 GB of data for $25; $0.25 per MB thereafter (overage)
-	Monthly charge: $60, excluding extra charges for overages

      Plan B Customers:
-	Up to 2000 minutes of talk for $55; $0.40 per minute thereafter (overage)
-	Up to 20 GB of data for $30; $0.15 per MB thereafter (overage)
-	Monthly charge: $85, excluding extra charges for overages

You will need to write the following information to another file called charges.txt:
-	Total charges (sum of all customers’ charges)
-	Average charges per customer
-	Max charges
-	Min charges
Design Requirements:
For this problem you must define the following struct type:
typedef struct profile
{
	char name[100];     // customer's name - last, first
	char plan;          // plan 'A' or 'B'
	int talk_minutes;   // number of minutes used for talking
	int data_MB;        // amount of data used in MB
	double charges;     // total charges for this customer – you will compute!
} Profile;

 
You must also define an array of Profiles that contains a maximum of 100 customer profiles. For example,
Profile customers[100]; // the input file may not exceed 100 customer profiles		

You must also complete the following:
-	Open customers.txt for mode read
-	Read all records in customers.txt and store them into the array of Profiles
-	Sort the array based on customers names ‘z’ – ‘a’
-	Compute the charges for each customer based on the plan for the customer, and the talk and data usages – store the charges back into the Profile in the array; recall 1 GB = 1000 MB
-	Compute the total or sum of charges for all customers
-	Compute the average charges per customer
-	Compute the maximum charges 
-	Compute the minimum charges 
-	Open charges.txt for mode write
-	Write the total, average, maximum, and minimum charges to charges.txt
-	Close customers.txt and charges.txt
