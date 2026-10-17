#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double delay_calculator(double bandwidth, double packet){
	double delay;
	delay=packet/(bandwidth*1000000)*1000;
	return delay;
}

int main(int argc, char *argv[]) {
	double n1, n2, ap_delay, bs_delay, ap_bandwidth, bs_bandwidth, path1_cost, path2_cost, packet;
	//Υπολογίζουμε το μέγεθος του πακέτου
	packet=10000*60+100;
	packet=packet*8;
	ap_bandwidth=50;
	bs_bandwidth=100;
	printf("Enter the N1 transmission delay in ms.\t");
	scanf("%lf", &n1);
	printf("Enter the N2 transmission delay in ms.\t");
	scanf("%lf", &n2);
	
	//Υπολγίζουμε την καθυστέρηση απο Α προς AP και BS
	ap_delay=delay_calculator(ap_bandwidth, packet);
	bs_delay=delay_calculator(bs_bandwidth, packet);
	
	//Υπολογίζουμε την συνολική καθυστέρηση για κάθε διαδρομή
	path1_cost=ap_delay+n1; //Α->AP->N1->S
	path2_cost=bs_delay+n2; //A->BS->N2->S
	
	//Εμφανίζουμε την γρηγορότερη διαδρομή και το κόστος της
	if (path1_cost<path2_cost){
		printf("Fastest route: A->AP->N1->S.\n");
		printf("Total cost: %.3f ms.", path1_cost);
	}else{
		printf("Fastest route: A->BS->N2->S.\n");
		printf("Total cost: %.3f ms.", path2_cost);
	}
	return 0;
}