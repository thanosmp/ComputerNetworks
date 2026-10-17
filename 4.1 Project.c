#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF 1e9

/* Να αναπτυχθεί λογισμικό το οποίο θα υλοποιεί τους
αλγορίθμους δρομολόγησης link-state (π.χ. Dijkstra) και
distance vector (π.χ. Bellman-Ford).
Διαδικαστικά
❑ Να χρησιμοποιηθεί ως γλώσσα προγραμματισμού μια εκ των
Java ή C ή Python.
❑ Θα παραδοθεί εργασία, σε ηλεκτρονική μορφή, με τα
ακόλουθα: πρόβλημα προς επίλυση και σκεπτικό επίλυσης,
πηγαίος κώδικας, ενδεικτικά αποτελέσματα, εκτελέσιμο αρχείο
(εφόσον κάτι τέτοιο είναι σχετικό).
❑ Βαρύτητα: 20%
Είσοδος
❑ Σύνολο συνδέσμων μεταξύ των έξι (6) κόμβων.
❑ Για κάθε σύνδεσμο (I,J), στοιχεία για τον υπολογισμό του κόστους.
– Bit Rate ανά σύνδεσμο (I,J): BR(I,J)
❑ Μέσο μέγεθος πακέτου, L
❑ Επιλογή αλγορίθμου (ένας από τους δύο ή και οι δύο)
❑ Κόμβοι «αφετηρία»: χρήστης θα δίνει ένα σύνολο από κόμβους
«αφετηρία».
Κυρίως Πρόγραμμα
❑ Με βάση την είσοδο, δηλαδή το δίκτυο και κάποιον επιλεγμένο
κόμβο – αφετηρία, το πρόγραμμα θα πρέπει να βρίσκει τις
ελάχιστες διαδρομές με βάση τους επιλεχθέντες αλγορίθμους
δρομολόγησης.
Έξοδος
❑ Το πρόγραμμα θα πρέπει να παρουσιάζει τον πίνακα
δρομολόγησης του επιλεγμένου κόμβου αφετηρία, καθώς και τα
ενδιάμεσα βήματα εκτέλεσης των επιλεχθέντων αλγορίθμων (πως
καταλήγουν οι αλγόριθμοι στον πίνακα δρομολόγησης)
 */
 
 //Συνάρτηση για την εμφάνιση του δρομολογίου
 void path(int previous[], int i){
 	if (previous[i]==-1){
 		printf("%d", i+1);
 		return;
	 }
	path(previous, previous[i]);
	printf(" -> %d", i+1);
	 
 }
 
 //Συνάρτηση για την υλοποίηση του dijkstra
 void dijkstra(int node, double cost[10][10]){
 	double distance[6];
 	bool visited[6];
 	int previous[6], i, j;
 	
 	for (i=0; i<6; i++){
 		distance[i]=INF;
 		visited[i]=false;
 		previous[i]=-1;
	 }
	 distance[node]=0;
	 
	 for(i=0; i<6; i++){
	 	int n=-1;
	 	double min=INF;
	 	for (int u=0; u<6; u++){
	 		if(!visited[u] && distance[u]<min){
	 			min=distance[u];
	 			n=u;
			 }
		 }
		 if(n!=-1){
		 	visited[n]=true;
		 	for(j=0; j<6; j++){
		 		if(!visited[j] && cost[n][j]<INF){
		 			double new_distance=distance[n]+cost[n][j];
		 			if(new_distance<distance[j]){
		 				distance[j]=new_distance;
		 				previous[j]=n;
					 }
				 }
			 }
		 }
	 }
	 printf("Destination\tCost\tPath\n");
	 for (i=0; i<6; i++){
	 	if (i==node){
	 		continue;
		 }
		 printf("%d\t", i+1);
		 if(distance[i]==INF){
		 	printf("Unreachable\t");
		 }else{
		 	printf("\t%.3f\t", distance[i]);
		 	path(previous, i);
		 	printf("\n");
		 }
	 }
 }
 
 //Συνάρτηση για την υλοποίηση του bellman-ford
 void bellman_ford(int node, double cost[10][10]){
 	int previous[6], i, j, k;
 	double distance[6];
 	for (i=0;i<6;i++){
 		distance[i]=INF;
 		previous[i]=-1;
	 }
	distance[node]=0;
	for (i=0; i<5; i++){
		for (j=0; j<6; j++){
			for (k=0; k<6;k++){
				if (cost[j][k]<INF){
					if (distance[j]+cost[j][k]<distance[k]){
						distance[k]=distance[j]+cost[j][k];
						previous[k]=j;
					}
				}
			}
		}
	}
	printf("Destination\tCost\tPath\n");
	for (i=0; i<6; i++){
	 	if (i==node){
	 		continue;
		 }
		 printf("%d\t", i+1);
		 if(distance[i]==INF){
		 	printf("Unreachable\t");
		 }else{
		 	printf("\t%.3f\t", distance[i]);
		 	path(previous, i);
		 	printf("\n");
		 }
	 }
 }
 
 //Συνάρτηση για τον υπολογισμό του κόστους
 double calculate_cost(int from, int to, double bit_rate, double L){
 	double C=(8*L)/bit_rate;
 	return C;
 }

int main(int argc, char *argv[]) {
	int links_num, choice, source_nodes[6], source_num, i, j;
	double L, cost[10][10], c;
	
	//Αρχικοποιούμε τον πίνακα των κοστών
	for(i=0; i<10;i++){
		for (j=0; j<10;j++){
			if (i==j){
				cost[i][j]=0;
			}else{
				cost[i][j]=INF;
			}
		}
	}
	
	//Ζητάμε τα απαραίτητα στοιχεία από τον χρήστη
	printf("Enter the number of links between the 6 nodes.\t");
	scanf("%d", &links_num);
	printf("Enter the average packet size (L).\t");
	scanf("%lf", &L);
	printf("Please enter 1 to choose the Dijkstra algorithm, 2 to choose the Bellman-Ford algorithm or 3 for both.\t");
	scanf("%d", &choice);
	
	//Για κάθε σύνδεσμο ο χρήστης εισάγει τον αρχικό και τελικό κόμβο και το bit rate
	for (i=0; i<links_num; i++){
		int to, from;
		double bit_rate;
		printf("For link number %d, enter the number of the two nodes and the Bit Rate in bps.\t\n", i+1);
		printf("From node: ");
		scanf("%d", &from);
		printf("To node: ");
		scanf("%d", &to);
		printf("Bit Rate: ");
		scanf("%lf", &bit_rate);
		c=calculate_cost(from-1, to-1, bit_rate, L);
		cost[from-1][to-1]=c;
		cost[to-1][from-1]=c;
	}
	
	//Ζητάμε τον αριθμό των κόμβων αφετηρίας ο οποίος πρεπει να είναι μεταξύ του 1 και του 6
	do{
		printf("Enter the number of source nodes:\t");
		scanf("%d", &source_num);
		if(source_num<1 || source_num>6){
			printf("The number of source nodes must be between 1 and 6.");
		}
	}while(source_num<1 || source_num>6);
	printf("Enter the source nodes.");
	for (i=0;i<source_num;i++){
		scanf("%d", &source_nodes[i]);
		source_nodes[i]--;
	}
	
	//Ανάλογα με την επιλογή του χρήστη εκτελείται ο αντίστοιχος αλγόριθμος
	for (i=0; i<source_num; i++){
		printf("For source node: %d\n", source_nodes[i]+1);
		if(choice==1 || choice==3){
			printf("Dijkstra:\n");
			dijkstra(source_nodes[i], cost);
		}
		if(choice==2 || choice==3){
			printf("Bellman-Ford:\n");
			bellman_ford(source_nodes[i], cost);
		}
	}
	return 0;
}

