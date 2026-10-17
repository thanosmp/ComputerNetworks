#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Συνάρτηση για τον υπολογισμό του μέγιστου αριθμού κόμβων Κ για τον οποίο θα συνέφερε να γίνει επεξεργασία στον Server
int K_max_calculation(double timeS, double timeE, double C, double L){
	double right_hand_side=((timeE-timeS)*C)/L;
	if (right_hand_side<0.0){
		return -1;
	}else {
		//Χρησιμοποιούμε την συνάρτηση floor για να στρογγυλοποιήσουμε προς τα κάτω (αφαιρούμε το δεκαδικό μέρος)
		return floor(right_hand_side+1e-12);
	}
}

int main(int argc, char *argv[]) {
	int K;
	double C, L, timeS, timeE, delay_E, delay_S;
	//Ζητάμε από τον χρήστη να εισάγει τα απαραίτητα δεδομένα με έλεγχο εγκυρότητας
	do{
		printf("Insert the number of K nodes.\t");
		scanf("%d", &K);
		if (K<0){
			printf("The number of nodes has to be positive.\n");
		}
	}while (K<0);

	do{
		printf("Insert the bit rate between the nodes in bits/sec.\t");
		scanf("%lf", &C);
		if (C<0.0){
			printf("The bit rate has to have a positive value.\n");
		}
	}while (C<0.0);
	
	do{
		printf("Insert the size of the packet in bits.\t");
		scanf("%lf", &L);
		if (L<0.0){
			printf("The size of the packet has to have a positive value.\n");
		}
	}while (L<0.0);
	
	do{
		printf("Insert the processing time on the server.\t");
		scanf("%lf", &timeS);
		if (timeS<0.0){
			printf("The processing time on the server has to have a positive value.\n");
		}
	}while (timeS<0.0);
	
	do{
		printf("Insert the processing time on the edge.\t");
		scanf("%lf", &timeE);
		if (timeE<0.0){
			printf("The processing time on the edge has to have a positive value.\n");
		}
	}while (timeE<0.0);
	
	//Υπολογίζουμε τις καθυστερήσεις στον Edge και στον Server αντίστοιχα
	delay_E=timeE;
	delay_S=(((double)K*L)/C)+timeS;
	//Εκτυπώνουμε τα αποτελέσματα
	printf("\nResults:\n");
	printf("Completion time if processed in Edge:\t%.6f sec.\n", delay_E);
	printf("Completion time if processed in server:\t%.6f sec.\n", delay_S);
	
	//Αν η καθυστέρηση στον Edge είναι μεγαλύτερη από αυτή του Server τότε προτιμάται ο Server
	if (delay_E>delay_S){
		printf("Processing in Server is preferred as the delay is smaller.\n");
	//Αν η καθυστέρηση του Edge είναι μικρότερη από αυτή του Server τότε προτιμάται ο Edge
	}else if (delay_E<delay_S){
		printf("Processing in Edge is preferred as the delay is smaller.\n");
		//Καλούμε την συνάρτηση υπολογισμού του μέγιστου αριθμού κόμβων Κ
		int K_max=K_max_calculation(timeS, timeE, C, L);
		//Αν η συνάρτηση επιστρέψει -1 τότε ο Server δεν προτιμάται για κανέναν αριθμό κόμβων
		if (K_max==-1){
			printf("The Server is not preferred for any value of K.");
		}else {
			printf("The maximum value of K for which the Server would be preferred is:\t%d.", K_max);
		}
	//Αν η δύο καθυστερήσεις είναι ίδιες τότε δεν υπάρχει κάποια προτίμηση
	}else {
		printf("Both the Server and the Edge have the same processing time.");
	}
	return 0;
}