#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
	char cusName[21];
	char dressName[21];
	int counter = 0;
	int priceDress;
	Data *next;
	Data *prev;
}*head = NULL, *tail = NULL, ngecounter;

void delFront() {
	if (head != NULL) {
		struct Data *curr = head;
		if (head == tail) {
			head = tail = NULL;
		}
		else {
			head = head->next;
			head->prev = NULL;
		}
		printf("%s has been served!", curr->cusName);
		free(curr);
		ngecounter.counter--;
	}
}

void pushBack(char cName[], char dName[], int price) {
	struct Data *curr = (struct Data *)malloc(sizeof(struct Data));
	strcpy(curr->cusName, cName);
	strcpy(curr->dressName, dName);
	curr->priceDress = price;

	curr->next = curr->prev = NULL;
	if (head == NULL) {
		head = tail = curr;
	}
	else {
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}

}
void printQueue() {
	struct Data *curr = head;
	/*while (curr != NULL) {
		printf("%d. %s || %s || $   %d\n", ngecounter.counter, curr->cusName, curr->dressName, curr->priceDress);
		curr = curr->next;
	}*/
	for (int i = 0; i < ngecounter.counter; i++) {
		printf("| %d. %-3s|  %s %12s| %s %7s| $%d %4s|\n", i+1, "", curr->cusName, "", curr->dressName, "", curr->priceDress, "");
		curr = curr->next;
	}
}



int main() {
	char inputCust[21];
	char inputDress[21];
	int input, counter, inputPrice;
	struct Data *curr = (struct Data *)malloc(sizeof(struct Data));
	int menu;
	do {
		for (int i = 0; i < 30; i++) {
			printf("\n");
		}
		printf("BLUE DRESS SHOP CASHIER QUEUE\n");
		printf("#############################\n\n");
		printf("1. View Queue\n");
		printf("2. Add Customer to Queue\n");
		printf("3. Serve Customer\n");
		printf("4. Exit\n");
		printf(">> Input choice: ");
		scanf("%d", &menu);
		rewind(stdin);

		switch (menu) {
		case 1:
			for (int i = 0; i < 30; i++) {
				printf("\n");
			}
			printf("\n               --- QUEUE VIEW ---\n\n");
			printf("+-------+-------------------------+---------------+----------+\n");
			printf("| No.   |  Customer's Name        |  Dress Name   |  Price   |\n");
			printf("+-------+-------------------------+---------------+----------+\n");
			printQueue();
			printf("+-------+-------------------------+---------------+----------+\n");
			getchar();
			break;
		case 2:
			do {
				for (int i = 0; i < 30; i++) {
					printf("\n");
				}
				printf("Input customer name [3..20]: ");
				scanf("%[^\n]", &inputCust);
				rewind(stdin);
			} while (strlen(inputCust) < 3 || strlen(inputCust) > 20);
			do {
				for (int i = 0; i < 30; i++) {
					printf("\n");
				}
				printf("Input dress name [3..20]: ");
				scanf("%[^\n]", &inputDress);
				rewind(stdin);
			} while (strlen(inputDress) < 3 || strlen(inputDress) > 20);
			do {
				for (int i = 0; i < 30; i++) {
					printf("\n");
				}
				printf("Input dress price [$50..$999]: ");
				scanf("%d", &inputPrice);
				rewind(stdin);
			} while (inputPrice < 50 || inputPrice > 999);
			for (int i = 0; i < 30; i++) {
				printf("\n");
			}
			pushBack(inputCust, inputDress, inputPrice);
			ngecounter.counter++;
			printf("\n\nSuccess to add customer into queue list\n");
			getchar();
			break;
		case 3:
			for (int i = 0; i < 30; i++) {
				printf("\n");
			}
			if (ngecounter.counter == 0) {
				printf("There is no customer in queue!");
				getchar();
				break;
			}
			else {
				for (int i = 0; i < 30; i++) {
					printf("\n");
				}
				delFront();
			}

			getchar();
			break;
		}


	} while (menu != 4);
}