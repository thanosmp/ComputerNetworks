#include <stdio.h>
#include <stdlib.h>

/* Να δημιουργήσετε πρόγραμμα λογισμικού, το οποίο να υπολογίζει την καθυστέρηση που θα υπάρχει στην
επικοινωνία μεταξύ δύο κόμβων (A1, A2) σε δίκτυο επικοινωνιών.
❑ Το πρόγραμμα θα πρέπει να δέχεται σαν εισόδους:
❑ Το μέσο μέγεθος πακέτου L.
❑ Το μέγεθος header H.
❑ Τον αριθμό των κόμβων που παρεμβάλλονται μεταξύ του ζεύγους κόμβων (A1, A2).
❑ Το bit rate, C, κάθε συνδέσμου.
❑ Το μέγεθος, F, του fragment.
❑ Έξοδος:
❑ Καθυστέρηση αν δεν χρησιμοποιηθεί fragmentation
❑ Καθυστέρηση αν χρησιμοποιηθεί fragmentation.
❑ Χρόνος στον οποίο θα φτάσει το πρώτο fragment.
❑ Διαδικαστικά:
❑ Να χρησιμοποιηθεί μια γλώσσα προγραμματισμού εκ των Java ή C ή Python.
❑ Να γίνεται χειρισμός λανθασμένης εισαγωγής δεδομένων. */

//Συνάρτηση για τον υπολογισμό της καθυστέρησης χωρίς fragmentation
double delay_without_fragmentation(double L, double H, int nodes, double C){
	double delay=(nodes+1)*((L+H)/C);
	return delay;
}

//Συνάρτηση για τον υπολογισμό της καθυστέρησης με fragmentation
double delay_with_fragmentation(double L, double H, int nodes, double C, double F){
	double delay=(L/F)*((F+H)/C)+((nodes-2)*((F+H)/C));
	return delay;
}

//Συνάρτηση για τον υπολογισμό του χρόνου στον οποίο θα φτάσει το πρώτο fragment
double first_fragment_delay(double H, int nodes, double C, double F){
	double delay=(nodes+1)*((F+H)/C);
	return delay;
}

int main(int argc, char *argv[]) {
	double L, H, C, F, delay_with, delay_without, delay_fragment;
	int nodes;
	//Ζητάμε από τον χρήστη να εισάγει τις απαραίτητες εισόδους κάνοντας και έλεγχο εγκυρότητας
	do{
		printf("Enter the average packet size (L).\t");
		scanf("%lf", &L);
		if (L<=0){
			printf("The average packet size must have a positive value.\n");
		}
	}while(L<=0);
	do{
		printf("Enter the header size (H).\t");
		scanf("%lf", &H);
		if(H<=0){
			printf("The header size must have a positive value.\n");
		}
	}while(H<=0);
	do{
		printf("Enter the number of nodes between the nodes A1 and A2.\t");
		scanf("%d", &nodes);
		if (nodes<0){
			printf("The number of nodes between the nodes A1 and A2 can't have a negative value.\n");
		}
	}while(nodes<0);
	
	//Ζητλαμε το bit rate σε bps
	do{
		printf("Enter the bit rate in bps (C).\t");
		scanf("%lf", &C);
		if (C<=0){
			printf("The bit rate must have a positive value.\n");
		}
	}while(C<=0);
	do{
		printf("Enter the fragment size (F).\t");
		scanf("%lf", &F);
		if(F<=0){
			printf("The fragment size must have a positive value.\n");
		}
	}while(F<=0);
	
	//Εκχωρούμε τα αποτελέσματα των συναρτήσεων στις μεταβλητές
	delay_without=delay_without_fragmentation(L, H, nodes, C);
	delay_with=delay_with_fragmentation(L, H, nodes, C, F);
	delay_fragment=first_fragment_delay(H, nodes, C, F);
	
	//Εμφανίζουμε τις τιμές των μεταβλητών
	printf("The total delay without fragmentation is: %.6f seconds\n", delay_without);
	printf("The total delay with fragmentation is: %.6f seconds\n", delay_with);
	printf("The first fragment will arive in: %.6f seconds\n", delay_fragment);
	
	return 0;
}