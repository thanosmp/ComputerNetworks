#include <stdio.h>
#include <stdlib.h>

/* Να δημιουργήσετε πρόγραμμα λογισμικού, το οποίο να υπολογίζει την συνολική καθυστέρηση στην επικοινωνία μεταξύ
δύο κόμβων (K1, K2). Παράλληλα, να υπολογίζει στοιχεία επίδοσης της σύνδεσης.
❖ Το πρόγραμμα θα πρέπει να δέχεται σαν εισόδους:
➢ Το μέσο μέγεθος πακέτου L.
➢ Το bit rate C του συνδέσμου (Κ1,Κ2).
➢ Την καθυστέρηση διάδοσης Prop.
➢ Το ποσοστό επιβάρυνσης, λόγω της καθυστέρησης επεξεργασίας και αναμονής (queueing and processing delay). Κάθε συνιστώσα να εκφράζεται
ως ποσοστό (%) της συνολικής καθυστέρησης.
❖ Έξοδος:
➢ Την συνολική καθυστέρηση που θα υπάρχει ως προς την λήψη ενός πακέτου, μήκους L, μέσω της επικοινωνίας με τα παραπάνω χαρακτηριστικά.
➢ Τον αριθμό των bits του πακέτου που θα έχει μεταδοθεί έως χρονική στιγμή t1, την οποία εισάγει ο χρήστης.
❖ Διαδικαστικά:
➢ Να χρησιμοποιηθεί μια γλώσσα προγραμματισμού εκ των Java ή C / C++ ή Python.
➢ Να γίνεται χειρισμός λανθασμένης εισαγωγής δεδομένων.
➢ Θα παραδοθεί εργασία, σε ηλεκτρονική μορφή, με υλικό όπως τα ακόλουθα: εκφώνηση της εργασίας και σκεπτικό επίλυσης, πηγαίος κώδικας,
ενδεικτικά αποτελέσματα, εκτελέσιμο αρχείο εάν απαιτείται.  */

//Συνάρτηση για τον υπολογισμό της συνολικής καθυστέρησης
double total_delay_calculator(double L, double C, double Prop, double queuing_percentage, double processing_percentage){
	double transmission_delay, propagation_delay, queuing_delay, processing_delay;
	//Υπολογίζουμε την καθυστέρηση μετάδοσης, την καθυστέρηση διάδοσης (η οποία ισούται με το Prop), την καθυστέρηση αναμονής και την καθυστέρηση επεξεργασίας
	transmission_delay=L/C;
	queuing_delay=(queuing_percentage/100)*(transmission_delay+Prop);
	processing_delay=(processing_percentage/100)*(transmission_delay+Prop);
	//Η συνολική καθυστέρηση είναι το άθροισμα των προηγούμενων καθυστερήσεων, το οποίο επιστρέφει η στνάρτηση
	return Prop+transmission_delay+queuing_delay+processing_delay;
}

//Συνάρτηση για τον υπολογισμό των bits που έχουν μεταδοθεί
double transmitted_bits_calculator(double C, double t){
	//Ο αριθμός των bits που έχουν μεταδοθεί ισούται με το γινόμενο του bit rate (C) και της χρονικής στιγμής t, το οποίο επιστρέφει η συνάρτηση
	return C*t;
}

int main(int argc, char *argv[]) {
	double L, C_bit_rate, Prop, queuing_percentage, processing_percentage, t, total_delay, transmitted_bits;
	//Ζητάμε από τον χρήστη την εισαγωγή των απαραίτητων εισόδων, την καθεμία από τις οποίες ελέγχουμε ως προς την εγκυρότητά της
	do{
		printf("Enter the average packet size (L) in bits.\t");
		scanf("%lf", &L);
		if (L<=0){
			printf("The packet size must have a positive value.\n");
		}
	}while(L<=0);
	
	//Ζητάμε το bit rate σε bps
	do{
		printf("Enter the bit rate (C) in bps.\t");
		scanf("%lf", &C_bit_rate);
		if (C_bit_rate<=0){
			printf("The bit rate must have a positive value.\n");
		}
	}while(C_bit_rate<=0);
	
	do{
		printf("Enter the propagation delay (Prop) in seconds.\t");
		scanf("%lf", &Prop);
		if (Prop<0){
			printf("The propagation delay must have a non-negative value.\n");
		}
	}while(Prop<0);
	
	do{
		printf("Enter the queuing delay percentage.\t");
		scanf("%lf", &queuing_percentage);
		if (queuing_percentage<0 || queuing_percentage>100){
			printf("The queuing delay percentage must be between 0 and 100.\n");
		}
	}while(queuing_percentage<0 || queuing_percentage>100);
	
	do{
		printf("Enter the processing delay percentage.\t");
		scanf("%lf", &processing_percentage);
		if (processing_percentage<0 || processing_percentage>100){
			printf("The processing delay percentage must be between 0 and 100.\n");
		}
	}while(processing_percentage<0 || processing_percentage>100);
	
	//Ζητάμε την χρονική στιγμή μέχρι την οποία θα υπολογιστούν τα bits που έχουν μεταδοθεί
	do{
		printf("Enter the time in seconds to calculate transmitted bits.\t");
		scanf("%lf", &t);
		if(t<0){
			printf("The time must have a non-negative value.\n");
		}
	}while(t<0);
	
	//Καλούμε την συνάρτηση total_delay_calculator για τον υπολογισμο της συνολικής καθυστέρησης
	total_delay=total_delay_calculator(L, C_bit_rate, Prop, queuing_percentage, processing_percentage);
	printf("The total delay is:\t%.5f seconds\n", total_delay);
	
	//Καλούμε την συνάρτηση transmitted_bits_calculator για τον υπολογισμό των bits που έχουν μεταδοθεί
	transmitted_bits=transmitted_bits_calculator(C_bit_rate, t);
	printf("The number of bits transmitted in %f seconds is:\t%.0f bits.\n", t, transmitted_bits);
	return 0;
}